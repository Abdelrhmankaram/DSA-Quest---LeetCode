class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        stack<int> mono_stack; // stores indices

        for (int i = n - 1; i >= 0; i--) {

            // Remove temperatures that are not warmer
            while (!mono_stack.empty() &&
                   temperatures[mono_stack.top()] <= temperatures[i]) {
                mono_stack.pop();
            }

            // The top is now the next warmer day
            if (!mono_stack.empty()) {
                answer[i] = mono_stack.top() - i;
            }

            mono_stack.push(i);
        }

        return answer;
    }
};