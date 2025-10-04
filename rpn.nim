import nimib

nbInit

nbText: """
# RPN计算器使用手册

<div style="text-align: center; color: #666; margin-bottom: 2rem;">
  基于C++实现的逆波兰表示法计算器
</div>
"""

nbText: "## 🚀 编译和运行"

nbText: "### 一键编译并运行"
nbText: "```bash"
nbText: "g++ F_rpn.cpp -o F_rpn && ./F_rpn"
nbText: "```"

nbText: "## 📚 基础使用示例"

nbText: "### 简单四则运算"
nbText: "```"
nbText: "&gt; 5 3 +"
nbText: "结果: 8"
nbText: "栈: 8"
nbText: "```"

nbText: "### 复杂表达式计算"
nbText: "```"
nbText: "&gt; 2 3 + 4 *"
nbText: "结果: 20"
nbText: "栈: 20"
nbText: "```"

nbText: "### 连续运算"
nbText: "```"
nbText: "&gt; 5"
nbText: "已压入: 5"
nbText: "栈: 5"
nbText: "&gt; 3" 
nbText: "已压入: 3"
nbText: "栈: 5 3"
nbText: "&gt; +"
nbText: "操作完成"
nbText: "栈: 8"
nbText: "```"

nbText: "## 🔢 数学函数示例"

nbText: "### 幂运算和平方根"
nbText: "```"
nbText: "&gt; 2 3 ^"
nbText: "结果: 8"
nbText: "栈: 8"
nbText: "&gt; 16 sqrt"
nbText: "结果: 4" 
nbText: "栈: 4"
nbText: "```"

nbText: "### 三角函数（角度制）"
nbText: "```"
nbText: "&gt; 90 sin"
nbText: "结果: 1"
nbText: "栈: 1"
nbText: "&gt; 0 cos"
nbText: "结果: 1"
nbText: "栈: 1"
nbText: "&gt; 45 tan"
nbText: "结果: 1"
nbText: "栈: 1"
nbText: "```"

nbText: "### 斐波那契数列"
nbText: "```"
nbText: "&gt; 5 fib"
nbText: "结果: 5"
nbText: "栈: 5"
nbText: "&gt; 6 fib"
nbText: "结果: 8"
nbText: "栈: 8"
nbText: "```"

nbText: "## 📖 操作符参考手册"

nbText: "### 基础运算符"
nbText: """
| 操作符 | 功能说明 | RPN表达式 | 计算结果 |
|--------|----------|-----------|----------|
| `+`    | 加法运算 | `a b +`   | a + b    |
| `-`    | 减法运算 | `a b -`   | a - b    |
| `*`    | 乘法运算 | `a b *`   | a × b    |
| `/`    | 除法运算 | `a b /`   | a ÷ b    |
"""

nbText: "### 高级数学函数"
nbText: """
| 操作符 | 功能说明 | RPN表达式 | 计算结果 |
|--------|----------|-----------|----------|
| `^`    | 幂运算   | `a b ^`   | aᵇ       |
| `sqrt` | 平方根   | `a sqrt`  | √a       |
| `sin`  | 正弦函数 | `a sin`   | sin(a°)  |
| `cos`  | 余弦函数 | `a cos`   | cos(a°)  |
| `tan`  | 正切函数 | `a tan`   | tan(a°)  |
| `fib`  | 斐波那契 | `n fib`   | fib(n)   |
"""

nbText: "## ⚙️ 系统命令"

nbText: "### 栈操作命令"
nbText: """
| 命令 | 功能说明 |
|------|----------|
| `stack` | 显示当前栈内容 |
| `clear` | 清空栈 |
"""

nbText: "### 历史记录命令"
nbText: """
| 命令 | 功能说明 |
|------|----------|
| `history` | 显示计算历史 |
| `clearhistory` | 清空历史记录 |
"""

nbText: "### 程序控制命令"
nbText: """
| 命令 | 功能说明 |
|------|----------|
| `batch` | 进入批量计算模式 |
| `help` | 显示帮助信息 |
| `q` | 退出程序 |
"""

nbText: "## 📦 批量计算模式"

nbText: "### 批量计算示例"
nbText: "```"
nbText: "&gt; batch"
nbText: "=== 批量计算模式 ==="
nbText: "输入多个表达式，每行一个，空行结束:"
nbText: "表达式 1: 1 2 + 3 *"
nbText: "表达式 2: 10 5 / 2 +"
nbText: "表达式 3: "
nbText: "开始批量计算..."
nbText: "表达式 1: 1 2 + 3 * = 9"
nbText: "表达式 2: 10 5 / 2 + = 4"
nbText: "批量计算完成"
nbText: "```"

nbText: "## ❌ 错误处理示例"

nbText: "### 常见错误情况"
nbText: "```"
nbText: "&gt; 5 0 /"
nbText: "错误: 除零错误"
nbText: "```"

nbText: "```"
nbText: "&gt; +"
nbText: "错误: 栈中元素不足，无法执行操作 '+'"
nbText: "```"

nbText: "```"
nbText: "&gt; abc"
nbText: "错误: 无法识别的token 'abc'"
nbText: "```"

nbText: "```"
nbText: "&gt; -5 sqrt"
nbText: "错误: 不能对负数开平方根"
nbText: "```"

nbText: "## 💬 交互式会话示例"

nbText: "### 完整会话流程"
nbText: "```"
nbText: "C++ RPN 计算器"
nbText: "输入 'help' 查看使用说明，'q' 退出程序"
nbText: "&gt; 5 3 +"
nbText: "结果: 8"
nbText: "栈: 8"
nbText: "&gt; 2 *"
nbText: "结果: 16" 
nbText: "栈: 16"
nbText: "&gt; sqrt"
nbText: "结果: 4"
nbText: "栈: 4"
nbText: "&gt; history"
nbText: "计算历史:"
nbText: "1. 表达式: 5 3 + = 8"
nbText: "2. 执行操作: * -> 结果: 16"
nbText: "3. 执行操作: sqrt -> 结果: 4"
nbText: "&gt; q"
nbText: "感谢使用RPN计算器！"
nbText: "```"

nbText: """
## 🎯 技术特点

- **算法效率**: O(n) 时间复杂度处理表达式
- **错误处理**: 完整的异常处理机制  
- **扩展性**: 易于添加新的数学函数
- **用户友好**: 清晰的错误提示和栈状态显示

---

<div style="text-align: center; color: #999; margin-top: 3rem;">
  文档生成时间: 2025年10月   编者：赵奕宸   🤖辅助编写：)
</div>
"""

nbSave
