#include <iostream>
#include <vector>

using namespace std;

class graphNode {
public:
    int index;
    vector<int> neighborNode;
};

class treeNode {
public:
    int index;
    graphNode* upper;
    graphNode* right;
    graphNode* left;
};

vector<graphNode*> buildGraph(vector<int> point) {

}

vector<treeNode*> buildtree(vector<int> point) {
    
}

int findTreenumber() {

}

int main() {
    int nodeSize;
    vector<int> result;
    vector<graphNode*> graph;
    cin >> nodeSize;
    if(nodeSize != 0) { // Check quantity of nodes
        for (size_t i = 0; i < nodeSize; i++) { // Input datas
            graphNode* tmpGraph;
            tmpGraph->index = i;
            for (size_t j = 0; j < nodeSize; j++) {
                int pointNum;
                cin >> pointNum;
                if(pointNum == 1) tmpGraph->neighborNode.push_back(j);
            }
            graph.push_back(tmpGraph);
        }
        int a;
        
        cin >> nodeSize;
    }

    for (size_t i = 0; i < result.size(); i++) { // print out results
        cout << result.at(i) << endl;
    }
}