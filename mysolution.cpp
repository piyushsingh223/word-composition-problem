#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

static bool mycmp(string &a,string &b){
    if(a.size()==b.size()) return a<b;
    else return a.size()<b.size(); 
}
void solve(){
    string inputstr;
    vector<string> strstore;
    unordered_set<string> st;

    while(cin >> inputstr){
        strstore.push_back(inputstr);
        st.insert(inputstr);
    }
        string longest,secondlongest;

        sort(strstore.begin(),strstore.end(),mycmp); // sorting on basis of length of strings.

        int index=strstore.size()-1;  // last index of strsotre(vector of strings).

        int maxlength=1001;  // maxm size of DP vector

        vector<bool> dp(maxlength);

        while(maxlength>-1){

            string &temp = strstore[index--]; 
            int templen = temp.size();

            for(int i=0;i<maxlength;i++){
                dp[i]=0;   //initiala\ising the DP vector to 0
            }

          for(int i=0; i<templen; i++){

            for(int j=0;j<=i;j++){

                if(st.count(temp.substr(j,i-j+1))){   //checking for the subpart of the string in the set

                    if(j==0 && i!=templen-1 ){
                        dp[i]=true;
                        break;
                    }
                    else if(j>=1 && dp[j-1]==true){
                        dp[i]=true;
                        break;

                    }

                }
            }
            }

            if(dp[templen-1]==true){
                if(longest.empty()==true) longest=temp;
                else if(secondlongest.empty()==true) secondlongest=temp;
                else break;
          }

        }

        cout<<"Longest compound word : " << longest << endl;
        cout<<"Second longest compound word : " << secondlongest;

}

int main()
{   
    ios_base::sync_with_stdio(0);   //used to increase the run time speed of code a little bit
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto starttime = high_resolution_clock::now();  //clock initialised


        solve();   // function called which will print the output
        cout<<endl;
    

   auto endtime = high_resolution_clock::now();  // clock stopped
   auto timetaken = duration_cast <milliseconds> (endtime - starttime);
   cout<<"Time taken to process input file : "<< timetaken.count() << " milliseconds";
}