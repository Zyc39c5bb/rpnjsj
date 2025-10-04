#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <stdexcept>

class RPNCalculator {
private:
    std::stack<double> stack;
    std::vector<std::string> history;

    bool isOperator(const std::string& token) const {
        return token == "+" || token == "-" || token == "*" || token == "/" || 
               token == "^" || token == "sqrt" || token == "sin" || 
               token == "cos" || token == "tan" || token == "fib";
    }

    bool isNumber(const std::string& token) const {
        if (token.empty()) return false;
        
        // 简单数字检测
        bool hasDecimal = false;
        bool hasDigit = false;
        for (size_t i = 0; i < token.length(); i++) {
            if (i == 0 && token[i] == '-') {
                if (token.length() == 1) return false;
                continue;
            }
            if (token[i] == '.') {
                if (hasDecimal) return false;
                hasDecimal = true;
                continue;
            }
            if (token[i] >= '0' && token[i] <= '9') {
                hasDigit = true;
                continue;
            }
            return false;
        }
        return hasDigit;
    }

    void ensureStackSize(int requiredSize, const std::string& operation) const {
        if (static_cast<int>(stack.size()) < requiredSize) {
            throw std::runtime_error("错误: 栈中元素不足，无法执行操作 '" + operation + "'");
        }
    }

public:
    void push(double value) {
        stack.push(value);
    }

    double pop() {
        if (stack.empty()) {
            throw std::runtime_error("错误: 尝试从空栈弹出元素");
        }
        
        double value = stack.top();
        stack.pop();
        return value;
    }

    void clear() {
        while (!stack.empty()) {
            stack.pop();
        }
    }

    void displayStack() const {
        if (stack.empty()) {
            std::cout << "栈: [空]" << std::endl;
            return;
        }
        
        std::cout << "栈: ";
        std::stack<double> temp = stack;
        std::vector<double> elements;
        
        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }
        
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return stack.empty();
    }

    size_t size() const {
        return stack.size();
    }

    void calculate(const std::string& operation) {
        double result = 0.0;
        
        if (operation == "+") {
            ensureStackSize(2, operation);
            double b = pop();
            double a = pop();
            result = a + b;
        }
        else if (operation == "-") {
            ensureStackSize(2, operation);
            double b = pop();
            double a = pop();
            result = a - b;
        }
        else if (operation == "*") {
            ensureStackSize(2, operation);
            double b = pop();
            double a = pop();
            result = a * b;
        }
        else if (operation == "/") {
            ensureStackSize(2, operation);
            double b = pop();
            double a = pop();
            
            if (b == 0.0) {
                push(a);
                push(b);
                throw std::runtime_error("错误: 除零错误");
            }
            
            result = a / b;
        }
        else if (operation == "^") {
            ensureStackSize(2, operation);
            double exponent = pop();
            double base = pop();
            result = std::pow(base, exponent);
        }
        else if (operation == "sqrt") {
            ensureStackSize(1, operation);
            double value = pop();
            
            if (value < 0) {
                throw std::runtime_error("错误: 不能对负数开平方根");
            }
            
            result = std::sqrt(value);
        }
        else if (operation == "sin") {
            ensureStackSize(1, operation);
            double value = pop();
            result = std::sin(value * M_PI / 180.0);
        }
        else if (operation == "cos") {
            ensureStackSize(1, operation);
            double value = pop();
            result = std::cos(value * M_PI / 180.0);
        }
        else if (operation == "tan") {
            ensureStackSize(1, operation);
            double value = pop();
            result = std::tan(value * M_PI / 180.0);
        }
        else if (operation == "fib") {
            ensureStackSize(1, "fib");
            int n = static_cast<int>(pop());
            
            if (n < 0) {
                throw std::runtime_error("错误: 斐波那契数列参数不能为负数");
            }
            
            if (n == 0) {
                result = 0;
            }
            else if (n == 1) {
                result = 1;
            }
            else {
                long long a = 0, b = 1;
                for (int i = 2; i <= n; i++) {
                    long long temp = a + b;
                    a = b;
                    b = temp;
                }
                result = static_cast<double>(b);
            }
        }
        else {
            throw std::runtime_error("错误: 未知操作 '" + operation + "'");
        }
        
        push(result);
        history.push_back("执行操作: " + operation + " -> 结果: " + std::to_string(result));
    }

    double evaluateExpression(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        std::vector<std::string> tokens;
        
        while (iss >> token) {
            tokens.push_back(token);
        }
        
        clear();
        
        for (const auto& t : tokens) {
            if (isNumber(t)) {
                push(std::stod(t));
            }
            else if (isOperator(t)) {
                calculate(t);
            }
            else {
                throw std::runtime_error("错误: 无法识别的token '" + t + "'");
            }
        }
        
        if (stack.size() != 1) {
            throw std::runtime_error("错误: 表达式不完整，栈中剩余多个值");
        }
        
        double finalResult = pop();
        history.push_back("表达式: " + expression + " = " + std::to_string(finalResult));
        return finalResult;
    }

    void showHistory() const {
        if (history.empty()) {
            std::cout << "历史记录: [空]" << std::endl;
            return;
        }
        
        std::cout << "计算历史:" << std::endl;
        for (size_t i = 0; i < history.size(); i++) {
            std::cout << i + 1 << ". " << history[i] << std::endl;
        }
    }

    void clearHistory() {
        history.clear();
        std::cout << "历史记录已清空" << std::endl;
    }

    void batchEvaluate(const std::vector<std::string>& expressions) {
        std::cout << "开始批量计算..." << std::endl;
        
        for (size_t i = 0; i < expressions.size(); i++) {
            try {
                double result = evaluateExpression(expressions[i]);
                std::cout << "表达式 " << (i + 1) << ": " << expressions[i] 
                          << " = " << result << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "表达式 " << (i + 1) << " 错误: " << e.what() << std::endl;
            }
        }
        
        std::cout << "批量计算完成" << std::endl;
    }
};

void printHelp() {
    std::cout << "\n=== RPN计算器使用说明 ===" << std::endl;
    std::cout << "输入表达式如: '5 5 +' 或 '1 2 + 3 + 7 7 * +'" << std::endl;
    std::cout << "支持操作: + - * / ^ sqrt sin cos tan fib" << std::endl;
    std::cout << "特殊命令: stack, clear, history, clearhistory, batch, help, q" << std::endl;
    std::cout << "========================\n" << std::endl;
}

void batchMode(RPNCalculator& calc) {
    std::cout << "\n=== 批量计算模式 ===" << std::endl;
    std::cout << "输入多个表达式，每行一个，空行结束:" << std::endl;
    
    std::vector<std::string> expressions;
    std::string line;
    
    while (true) {
        std::cout << "表达式 " << (expressions.size() + 1) << ": ";
        std::getline(std::cin, line);
        
        if (line.empty()) {
            break;
        }
        
        expressions.push_back(line);
    }
    
    if (!expressions.empty()) {
        calc.batchEvaluate(expressions);
    }
}

int main() {
    RPNCalculator calc;
    std::string input;
    
    std::cout << "C++ RPN 计算器 (完整单文件版本)" << std::endl;
    printHelp();
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "q" || input == "quit") {
            break;
        }
        else if (input == "help") {
            printHelp();
        }
        else if (input == "stack") {
            calc.displayStack();
        }
        else if (input == "clear") {
            calc.clear();
            std::cout << "栈已清空" << std::endl;
        }
        else if (input == "history") {
            calc.showHistory();
        }
        else if (input == "clearhistory") {
            calc.clearHistory();
        }
        else if (input == "batch") {
            batchMode(calc);
        }
        else if (!input.empty()) {
            try {
                // 直接使用 evaluateExpression 处理所有输入
                double result = calc.evaluateExpression(input);
                std::cout << "结果: " << result << std::endl;
                calc.displayStack();
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    
    std::cout << "感谢使用RPN计算器！" << std::endl;
    return 0;
}