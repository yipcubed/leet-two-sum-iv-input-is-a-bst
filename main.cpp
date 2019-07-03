#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool findItem(TreeNode* r, int item) {
        if (!r) return false;
        if (r->val == item) return true;
        if (item < r->val)
            return findItem(r->left, item);
        else
            return findItem(r->right, item);
    }

    void DFS(TreeNode* r, TreeNode *root, int k, bool& found) {
        if (!r) return;
        // not allowed to use the same value
        found = k - r->val != r->val ? findItem(root, k - r->val) : false;
        if (!found && r->left)
            DFS(r->left, root, k, found);
        if (!found && r->right)
            DFS(r->right, root, k, found);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        bool found = false;
        DFS(root, root, k, found);
        return found;
    }
};

void test1() {
    vector<int> v1{5, 3, 6, 2, 4, 7};
    auto t1 = new TreeNode(v1);

    cout << "1? " << Solution().findTarget(t1, 9) << endl;
    cout << "0? " << Solution().findTarget(t1, 28) << endl;

    vector<int> v2{1};
    auto t2 = new TreeNode(v2);
    cout << "0? " << Solution().findTarget(t2, 2) << endl;
}

void test2() {

}

void test3() {

}