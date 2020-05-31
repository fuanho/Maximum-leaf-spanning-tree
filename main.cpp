#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class branch {
public:
	int index;
	int nodeX;
	int nodeY;
};

class node {
public:
	int index;
	int color;
	int distance;
	int father;
	vector<int> children;
};

vector<int> counting(vector<int> num, int max) {
	vector<int> result = num;
	result.at(max-1)++;
	for (int i = max-1; i >= 0; i--) {
		if (result.at(i) == 2) {
			result.at(i) = 0;
			if(i < max) result.at(i - 1)++;
		}
	}
	return result;
}

bool check(vector<int> a, vector<int> b) {
	bool result = true;
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) != b.at(i)) {
			result = false;
			break;
		}
	}
	return result;
}

int visiting(vector<branch*> B, vector<int> spanningTree, map<int, int> necessaryNodes, int nodeSize) {
	int result = 0;
	int root = necessaryNodes.begin()->first;
	map<int,node*> tree;
	

	for (int i = 0; i < nodeSize; i++) {
		node* tmpN = new node();
		tmpN->index = i;
		tmpN->color = 0;
		tmpN->distance = 0;
		tmpN->father = -1;
		tree.insert(pair<int, node*>(i, tmpN));
	}
	for (int i = 0; i < spanningTree.size(); i++) {
		branch* tmpB = new branch();
		if (spanningTree.at(i) == 1) {
			tmpB = B.at(i);
			tree.at(tmpB->nodeX)->children.push_back(tmpB->nodeY);
			tree.at(tmpB->nodeY)->children.push_back(tmpB->nodeX);
		}
		
	}

	int count = 0;
	int min = 0;
	queue<int> q;
	if (tree.at(root)->color == 0) {
		tree.at(root)->color = 1;
		tree.at(root)->distance = 0;
		tree.at(root)->father = -1;
		q.push(root);
		while (!q.empty()) {
			int f = q.front();
			for (int i = 0; i < tree.at(f)->children.size(); i++) {
				int a = tree.at(f)->children.at(i);
				if (tree.at(a)->color == 0) {
					tree.at(a)->color = 1;
					tree.at(a)->distance = tree.at(f)->distance + 1;
					tree.at(a)->father = f;
					q.push(a);
				}
			}

			q.pop();
			tree.at(f)->color = 2;
			count++;
		}

	}
	int goodPoint = 0;
	for (int i = 0; i < tree.size(); i++) {
		int c = tree.at(i)->color;
		if (c == 2 && necessaryNodes.find(i) != necessaryNodes.end()) goodPoint++;
	}
	if (count < necessaryNodes.size() || goodPoint != necessaryNodes.size()) result = nodeSize + 1;
	else {
		map<int,int> fathers;
		for (int i = 0; i < tree.size(); i++) {
			int f = tree.at(i)->father;
			if (fathers.find(f) == fathers.end() && f != -1) {
				fathers.insert(pair<int, int>(f, f));
			}
		}
		min = fathers.size();
		if (tree.at(root)->children.size() == 1) min--;
		result = min;
	}
	return result;
}

int main() {
	vector<branch*> B;
	vector<int> maxSpanning;
	vector<int> minSpanning;
	vector<int> spanningTree;
	map<int,int> necessaryNodes;
	vector<int> result;
	int minimumNodes;
	int minimumBranches;

	int nodesSize;
	cin >> nodesSize;
	while (nodesSize > 0) {
		minimumBranches = nodesSize;
		for (int i = 0; i < nodesSize; i++) {
			for (int j = 0; j < nodesSize; j++) {
				int node;
				cin >> node;
				if (j > i && node != 0) {
					branch* tmpBranch = new branch();
					tmpBranch->index = B.size();
					tmpBranch->nodeX = i;
					tmpBranch->nodeY = j;
					B.push_back(tmpBranch);
				}
			}

		}
		for (int i = 0; i < nodesSize; i++) {
			int node;
			cin >> node;
			if (node != 0) necessaryNodes.insert(pair<int, int>(i,i));
		}

		minimumNodes = necessaryNodes.size();
		for (int i = 0; i < B.size(); i++) {
			maxSpanning.push_back(1);
			minSpanning.push_back(0);
		}
		for (int i = B.size()-1; i >= 0 ; i--) {
			if (i < B.size() - minimumNodes) {
				minSpanning.at(i) = 0;
			}
			else {
				minSpanning.at(i) = 1;
			}
		}
		spanningTree = minSpanning;
		do{
			int count = 0;
			for (int i = 0; i < spanningTree.size(); i++) 
				if (spanningTree.at(i) == 1) count++;
			if (count >= necessaryNodes.size()-1) {
				
				int min = visiting(B, spanningTree, necessaryNodes, nodesSize);
				if (min < minimumBranches) minimumBranches = min;
			}
			spanningTree = counting(spanningTree, B.size());
			
		} while (!check(spanningTree, maxSpanning));

		result.push_back(minimumBranches);
		B.clear();
		maxSpanning.clear();
		minSpanning.clear();
		spanningTree.clear();
		necessaryNodes.clear();
		cin >> nodesSize;
	}
	

	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << endl;
	}
}