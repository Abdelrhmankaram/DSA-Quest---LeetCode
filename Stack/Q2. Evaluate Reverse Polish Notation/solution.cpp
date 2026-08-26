class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();

                if (token == "+")
                    nums.push(num1 + num2);
                else if (token == "-")
                    nums.push(num1 - num2);
                else if (token == "*")
                    nums.push(num1 * num2);
                else
                    nums.push(num1 / num2);

            } else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};