class Solution {
    int get_answer(stack<int>& s, int number) {
        while (!s.empty()) {
            if (s.top() <= number) {
                return s.top();
            }
            s.pop();
        }

        return number;
    }

public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> mono_stack;

        int n = static_cast<int>(prices.size());

        vector<int> answer(n);

        for (int i = n - 1; i >= 0; i--) {
            int discount = get_answer(mono_stack, prices[i]);

            if (discount == prices[i] && mono_stack.empty()) {
                answer[i] = prices[i];
            } else {
                answer[i] = prices[i] - discount;
            }

            mono_stack.push(prices[i]);
        }

        return answer;
    }
};