class Solution {

public:

    int longestValidParentheses(string s) {

        

        int n = s.length();

        stack<int> st;

        

        for(int i=0; i<n; i++){

            if(s[i] == '(') st.push(i);

            

            else{

                if(!st.empty()){

                    if(s[st.top()] == '('){

                        st.pop();

                    }

                    else st.push(i);

                }

                else{

                    st.push(i);

                }

            }

        }

        

        int largest = 0;

        

        if(st.empty()) largest = n;

        else{

            int a = n, b = 0;

            

            while(!st.empty()){

                b = st.top();

                st.pop();

                

                largest = max(largest, a-b-1);

                a = b;

            }

            largest = max(largest, a);

        }

        return largest;

    }

};
