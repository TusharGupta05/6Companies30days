/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    vector<vector<int>> grid;
    Node* recurr(int x, int y, int sz){
        int sum=0;
        for(int i=x;i<x+sz;i++){
            for(int j=y;j<y+sz;j++){
                sum+=grid[i][j];
            }
        }
        if(sum==0||sum==sz*sz){
            return new Node(grid[x][y], true);
        }
        sz>>=1;
        return new Node(0, false, recurr(x, y, sz), recurr(x, y+sz, sz), recurr(x+sz, y, sz), recurr(x+sz, y+sz, sz));
    }
public:
    Node* construct(vector<vector<int>>& g) {
        grid = g;
        return recurr(0, 0, g.size());
    }
};
