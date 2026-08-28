class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            // Operand
            if (isdigit(arr[i][0]) ||
                (arr[i][0] == '-' && arr[i].size() > 1)) {

                st.push(stoi(arr[i]));
            }

            // Operator
            else {
                int top1 = st.top();
                st.pop();

                int top2 = st.top();
                st.pop();

                if (arr[i] == "+") {
                    st.push(top2 + top1);
                }

                else if (arr[i] == "-") {
                    st.push(top2 - top1);
                }

                else if (arr[i] == "*") {
                    st.push(top2 * top1);
                }

                else if (arr[i] == "/") {
                    int res = top2 / top1;

                    // Floor division for negative result
                    if ((top2 < 0) != (top1 < 0) && top2 % top1 != 0) {
                        res--;
                    }

                    st.push(res);
                }

                else if (arr[i] == "^") {
                    st.push(pow(top2, top1));
                }
            }
        }

        return st.top();
    }
};