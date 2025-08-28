using namespace std;
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

struct RESULT
{
	int cnt;
	int IDs[5];
};
struct Movie
{
	int num, genre, total, order;
};
struct movie_compare
{
	bool operator () (const Movie& a, const Movie& b) const {
		if (a.total == b.total) {
			return a.order < b.order;
		}
		return a.total < b.total;
	}
};
struct Rating
{
	int mov, rating;
};
struct User
{
	int num;
	vector<Rating> arr;
	unordered_set<int> watched;
};


int cnt;
unordered_map<int, Movie> movies;
set<Movie, movie_compare> all_genre;
vector<set<Movie, movie_compare>> genre_movie(6);
unordered_map<int, User> users;
void init(int N)
{	
	cnt = 0;
	movies.clear();
	all_genre.clear();
	
	genre_movie[1].clear();
	genre_movie[2].clear();
	genre_movie[3].clear();
	genre_movie[4].clear();
	genre_movie[5].clear();

	users.clear();
	return;
}

int add(int mID, int mGenre, int mTotal)
{	
	if (movies.find(mID) != movies.end()) {
		return 0;
	}
	++cnt;
	movies[mID] = { mID, mGenre, mTotal, cnt };
	all_genre.insert(movies[mID]);
	genre_movie[mGenre].insert(movies[mID]);
	return 1;
}

int erase(int mID)
{	
	if (movies.find(mID) == movies.end()) {
		return 0;
	}
	Movie delmovie = movies[mID];
	genre_movie[delmovie.genre].erase(delmovie);
	all_genre.erase(delmovie);
	movies.erase(mID);
	return 1;
}

int watch(int uID, int mID, int mRating)
{	
	auto& user = users[uID];
	if (movies.find(mID) == movies.end() || user.watched.find(mID) != user.watched.end()) {
		return 0;
	}
	user.arr.push_back({ mID, mRating });
	user.watched.insert(mID);

	all_genre.erase(movies[mID]);
	genre_movie[movies[mID].genre].erase(movies[mID]);

	movies[mID].total += mRating;

	all_genre.insert(movies[mID]);
	genre_movie[movies[mID].genre].insert(movies[mID]);

	return 1;
}



RESULT suggest(int uID)
{
	RESULT res;
	res.cnt = 0;
	auto& user = users[uID];
	int mID, max_rat = -1, max_num = -1;
	vector<Rating> marr;
	int c = -1;
	for (int i = user.arr.size() - 1; i >= 0; --i) {
		if (marr.size() >= 5) break;
		mID = user.arr[i].mov;
		if (movies.find(mID) == movies.end()) {
			continue;
		}
		marr.push_back(user.arr[i]);
	}

	if (marr.empty()) {
		auto temp = all_genre.end();
		if (!all_genre.empty()) {
			for (int i = all_genre.size() - 1; i >= 0; --i) {
				--temp;
				if (user.watched.find((*temp).num) != user.watched.end()) continue;
				++c;
				res.IDs[c] = (*temp).num;
				++res.cnt;
				if (temp == all_genre.begin() || c == 4) break;
			}
		}
	}
	else {
		for (Rating& n : marr) {
			if (n.rating > max_rat) {
				max_rat = n.rating;
				max_num = n.mov;
			}
		}
		int g = movies[max_num].genre;
		auto temp = genre_movie[g].end();
		if (!genre_movie[g].empty()) {
			for (int i = genre_movie[g].size() - 1; i >= 0; --i) {
				--temp;
				if (user.watched.find((*temp).num) != user.watched.end()) continue;
				++c;
				res.IDs[c] = (*temp).num;
				++res.cnt;
				if (temp == genre_movie[g].begin() || c == 4) break;
			}
		}
	}
	


	
	return res;
}