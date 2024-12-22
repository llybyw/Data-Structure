#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Calculator {
private:
    vector<string> exprTokens; // 存储解析后的中缀表达式
    int tokenCount;            // 解析后的表达式元素数量

    /**
     * @brief 表达式树类，用于存储和计算表达式
     */
    class ExprTree {
    private:
        /**
         * @brief 表达式树节点类
         */
        class TreeNode {
        private:
            double val;          // 节点的数值
            string content;      // 节点内容（操作数或运算符）
            TreeNode* left;      // 左子节点
            TreeNode* right;     // 右子节点
            int priority;        // 节点的优先级（用于运算符）

            /**
             * @brief 根据内容确定优先级
             * @param token 节点内容
             * @return 优先级值
             */
            int getPriority(const string& token) {
                switch (token[0]) {
                case '*':
                case '/':
                    return 1; // 乘除优先级最高
                case '+':
                case '-':
                    if (token.size() > 1) return 0; // 处理负数
                    return 2; // 加减优先级较低
                default:
                    return 0; // 操作数优先级最低
                }
            }

            friend class ExprTree;

        public:
            /**
             * @brief 用字符串初始化节点
             * @param token 节点内容
             */
            TreeNode(const string& token) 
                : val{}, content{token}, left{nullptr}, right{nullptr}, priority{0} {
                priority = getPriority(content);
                if (priority == 0) val = stod(content); // 如果是数值，直接转换
            }

            /**
             * @brief 用数值直接初始化节点
             * @param num 数值
             */
            TreeNode(const double& num) 
                : val{num}, left{nullptr}, right{nullptr}, priority{0} {}
        };

        TreeNode* root;             // 表达式树的根节点
        stack<TreeNode*> nodeStack; // 用于构建表达式树的栈

        /**
         * @brief 执行四则运算
         * @param left 左操作数
         * @param op 运算符
         * @param right 右操作数
         * @return 计算结果
         */
        double compute(const double& left, const string& op, const double& right) {
            switch (op[0]) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/':
                if (right == 0) {
                    cout << "ILLEGAL" << endl;
                    throw 1;
                }
                return left / right;
            default:
                cout << "ILLEGAL" << endl;
                throw 1;
            }
        }

        /**
         * @brief 清空以指定节点为根的子树
         * @param node 子树根节点
         */
        void clear(TreeNode*& node) {
            if (node != nullptr) {
                clear(node->left);
                clear(node->right);
                delete node;
            }
            node = nullptr;
        }

        /**
         * @brief 递归计算表达式树
         * @param node 当前节点
         */
        void calculate(TreeNode*& node) {
            if (node != nullptr) {
                calculate(node->left);
                calculate(node->right);
                if (node->priority != 0) { // 如果是运算符
                    if (node->left == nullptr || node->right == nullptr) {
                        cout << "ILLEGAL" << endl;
                        throw 1;
                    }
                    node->val = compute(node->left->val, node->content, node->right->val);
                }
            }
        }

    public:
        ExprTree() : root{nullptr} {}
        ~ExprTree() { clear(root); }

        /**
         * @brief 将元素插入表达式树
         * @param token 元素内容
         */
        void insert(const string& token) {
            TreeNode* newNode = new TreeNode(token);
            TreeNode* topNode{nullptr};

            if (root == nullptr) {
                root = newNode;
                nodeStack.push(newNode);
            } else {
                topNode = nodeStack.top();
                if (topNode->priority >= newNode->priority) {
                    topNode->right = newNode;
                    nodeStack.push(newNode);
                } else {
                    while (!nodeStack.empty() && nodeStack.top()->priority <= newNode->priority) {
                        topNode = nodeStack.top();
                        nodeStack.pop();
                    }
                    newNode->left = topNode;
                    if (!nodeStack.empty()) {
                        topNode = nodeStack.top();
                        topNode->right = newNode;
                    } else {
                        root = newNode;
                    }
                    nodeStack.push(newNode);
                }
            }
        }

        /**
         * @brief 将数值插入表达式树
         * @param num 数值
         */
        void insert(const double& num) {
            TreeNode* newNode = new TreeNode(num);
            if (!nodeStack.empty()) {
                TreeNode* topNode = nodeStack.top();
                topNode->right = newNode;
            } else {
                root = newNode;
            }
            nodeStack.push(newNode);
        }

        /**
         * @brief 计算表达式树结果
         */
        void solve() {
            calculate(root);
        }

        /**
         * @brief 获取表达式结果
         * @return 计算结果
         */
        double getResult() {
            return root->val;
        }
    };

    /**
     * @brief 递归计算表达式
     * @param start 起始索引
     * @param end 结束索引
     * @return 计算结果
     */
    double solveRange(const int& start, const int& end) {
        ExprTree tree;
        for (int i = start; i <= end; i++) {
            if (exprTokens[i] != "(") {
                tree.insert(exprTokens[i]);
            } else {
                int depth = 1, j = i + 1;
                for (; j <= end; j++) {
                    if (exprTokens[j] == "(") depth++;
                    if (exprTokens[j] == ")") depth--;
                    if (depth == 0) break;
                }
                tree.insert(solveRange(i + 1, j - 1));
                i = j;
            }
        }
        tree.solve();
        return tree.getResult();
    }

    /**
     * @brief 检查表达式是否包含语法错误
     */
    void validate() {
        bool error = false;
        int bracketBalance = 0;

        for (int i = 0; i < tokenCount; i++) {
            if (exprTokens[i] == "(") bracketBalance++;
            if (exprTokens[i] == ")") {
                bracketBalance--;
                if (bracketBalance < 0) {
                    error = true;
                    break;
                }
            }
        }
        if (bracketBalance > 0) error = true;

        for (int i = 0; i < tokenCount - 1; i++) {
            if (exprTokens[i] == "(" && exprTokens[i + 1] == ")") {
                error = true;
                break;
            }
        }

        for (const auto& token : exprTokens) {
            if (!(token == "+" || token[0] == '-' || token == "*" || token == "/" ||
                  token == "(" || token == ")" || (token[0] >= '0' && token[0] <= '9'))) {
                error = true;
                break;
            }
            if( token[0] >= '0' && token[0] <= '9' ){
                int flag = 0;
                for( auto & ex : token ) 
                if( ex == '.' ) 
                flag ++;                    
                if( flag > 1 ){
                    error = true;
                    break; 
                }
            }
        }

        if (error) cout << "ILLEGAL" << endl;

        if (error) throw 1;
    }

public:
    /**
     * @brief 解析用户输入的表达式
     * @param expr 用户输入字符串
     */
    void parse(const string& expr) {
        int len = expr.size();
        int idx = 0;
        while (idx < len) {
            string token;
            token.push_back(expr[idx]);
            if ((expr[idx] >= '0' && expr[idx] <= '9') || expr[idx] == '.') {
                idx++;
                while ((expr[idx] >= '0' && expr[idx] <= '9') || expr[idx] == '.') {
                    token.push_back(expr[idx]);
                    idx++;
                    if (idx >= len) break;
                }
            } else if (expr[idx] == '-') {
                if (idx == 0 || expr[idx - 1] == '(') {
                    idx++;
                    while ((expr[idx] >= '0' && expr[idx] <= '9') || expr[idx] == '.') {
                        token.push_back(expr[idx]);
                        idx++;
                        if (idx >= len) break;
                    }
                } else {
                    idx++;
                }
            } else {
                idx++;
            }
            exprTokens.push_back(token);
        }
        tokenCount = exprTokens.size();
    }

    /**
     * @brief 计算表达式
     */
    void solve() {
        try {
            validate();
        } catch (int) {
            exprTokens.clear();
            return;
        }

        double result;
        try {
            result = solveRange(0, tokenCount - 1);
        } catch (int) {
            exprTokens.clear();
            return;
        }

        cout << result << endl;
        exprTokens.clear();
    }

};
