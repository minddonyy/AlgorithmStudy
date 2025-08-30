using namespace std;
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>
struct Product
{
	int num, cost;
};

struct ProductData
{
	int num, cost, cat, com;
};
struct cost_compare
{
	bool operator () (const Product& a, const Product& b) const {
		if (a.cost == b.cost) {
			return a.num < b.num;
		}
		return a.cost < b.cost;
	}
};
struct que_compare
{
	bool operator () (const Product& a, const Product& b) const {
		if (a.cost == b.cost) {
			return a.num < b.num;
		}
		return a.cost < b.cost;
	}
};
unordered_map<int, ProductData> datas;
set<Product, cost_compare> cat_com[6][6];
int discounts[6][6];



struct RESULT
{
	int cnt;
	int IDs[5];
};

void init()
{
	datas.clear();
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cat_com[i][j].clear();
			discounts[i][j] = 0;
		}
	}
	return;
}

int sell(int mID, int mCategory, int mCompany, int mPrice)
{
	int newprice = discounts[mCategory][mCompany] + mPrice;
	datas[mID].num = mID;
	datas[mID].cat = mCategory;
	datas[mID].com = mCompany;
	datas[mID].cost = newprice;

	cat_com[mCategory][mCompany].insert({ mID, newprice });

	return cat_com[mCategory][mCompany].size();
}

int closeSale(int mID)
{
	if (datas.find(mID) == datas.end()) {
		return -1;
	}
	auto product = datas[mID];
	cat_com[product.cat][product.com].erase({ mID, product.cost });
	datas.erase(mID);
	return product.cost - discounts[product.cat][product.com];
}

int discount(int mCategory, int mCompany, int mAmount)
{
	vector<int> arr;
	discounts[mCategory][mCompany] += mAmount;
	auto it = cat_com[mCategory][mCompany].upper_bound({ 999999999, discounts[mCategory][mCompany] });

	while (it != cat_com[mCategory][mCompany].begin())
	{
		--it;
		arr.push_back((*it).num);

	}
	for (auto& n : arr) {
		closeSale(n);
	}

	return cat_com[mCategory][mCompany].size();
}

struct quedata
{
	int cat, com;
	set<Product, cost_compare>::iterator it;
};



RESULT show(int mHow, int mCode)
{	
	queue<quedata> que;
	if (mHow == 0) {
		for (int i = 1; i <= 5; ++i) {
			for (int j = 1; j <= 5; ++j) {
				if (!cat_com[i][j].empty())
					que.push({ i, j, cat_com[i][j].begin()});
			}
		}
	} else if (mHow == 1) {
		for (int i = 1; i <= 5; ++i) {
			if (!cat_com[mCode][i].empty())
				que.push({ mCode, i, cat_com[mCode][i].begin() });
		}
	}
	else {
		for (int i = 1; i <= 5; ++i) {
			if (!cat_com[i][mCode].empty())
				que.push({ i, mCode, cat_com[i][mCode].begin() });
		}
	}

	RESULT ret;
	priority_queue<Product, vector<Product>, que_compare> pq;
	quedata cur;
	while (!que.empty())
	{	
		cur = que.front(); que.pop();
		if (cur.it == cat_com[cur.cat][cur.com].end()) continue;
		if (pq.size() < 5) {
			pq.push({ (*cur.it).num, (*cur.it).cost - discounts[cur.cat][cur.com] });
			++cur.it;
			que.push(cur);
			continue;
		}
		int realcost = (*cur.it).cost - discounts[cur.cat][cur.com];
		if (( pq.top().cost == realcost) && (pq.top().num > (*cur.it).num)) {
			pq.pop();
			pq.push({ (*cur.it).num, realcost });
			++cur.it;
			que.push(cur);
		}
		else if (pq.top().cost > realcost) {
			pq.pop();
			pq.push({ (*cur.it).num, realcost });
			++cur.it;
			que.push(cur);
		}
	}
	ret.cnt = pq.size();
	for (int i = pq.size() - 1; i >= 0; --i) {
		ret.IDs[i] = pq.top().num; pq.pop();
	}
	return ret;
}

