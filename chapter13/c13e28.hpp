class TreeNode {
public:
    TreeNode();
    ~TreeNode();
    TreeNode(const TreeNode &p);
    const TreeNode &operator=(const TreeNode &rhs);
    void CopyTree();
    int ReleaseTree();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode()
    : value("")
    , count(1)
    , left(nullptr)
    , right(nullptr) { }

TreeNode::~TreeNode() {
    if (--count == 0) {
        delete left;
        delete right;
    }
}

TreeNode::TreeNode(const TreeNode &tn)
    : value(tn.value)
    , count(++tn.count)
    , left(tn.left)
    , right(tn.right) { }

const TreeNode &TreeNode::operator=(const TreeNode &rhs) {
    ++rhs.count;
    auto t_value = rhs.value;
    auto t_count = rhs.count;
    auto t_left = rhs.left;
    auto t_right = rhs.right;
    if (--count == 0) {
        delete left;
        delete right;
    }
    value = t_value;
    count = t_count;
    left = t_left;
    right = t_right;
}

class BinStrTree {
    BinStrTree() : root(nullptr) { }
    ~BinStrTree();
    BinStrTree(const BinStrTree &bst);
    const BinStrTree &operator=(const BinStrTree &rhs);
private:
    TreeNode *root;
};

BinStrTree::BinStrTree(const BinStrTree &bst)
    : root(bst.root) { }

BinStrTree::~BinStrTree() {
    delete root;
}

const BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
    auto temp = rhs.root;
    delete root;
    root = temp;
}
