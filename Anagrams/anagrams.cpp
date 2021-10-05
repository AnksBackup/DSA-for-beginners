//Author : Sundar
#include<iostream>
#include<vector>
using namespace std;
//Queation is in  readme

//This method is popularly known as SLIDING WINDOW TECHNIQUE
#define pb push_back

vector<int> anagrams(string s,string t)
{
    vector<int> indices; //s vector to store the starting indices of anagrams
    
    vector<int> store_b(26);
    vector<int> store_a(26);
    int n=s.length(),m=t.length();
    if(n<m)
    {
        return indices;
    }

    for(int i=0;i<m;i++)
    {
        store_b[t[i]-'a']++; //storing the characters that appear in String t
        store_a[s[i]-'a']++; //Stroring the first m characters of String s
    }   

    if(store_a==store_b)
    {
        indices.pb(0);
    }

    for(int i=m;i<n;i++)
    {
        store_a[s[i]-'a']++;
        store_a[s[i-m]-'a']--;

        if(store_a==store_b)
            indices.pb(i-m+1); //i-m+1 gives the starting index of the anagram

    }
    return indices;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    string s,t;
    cin>>s>>t;

    vector<int> ret=anagrams(s,t);

    if(ret.size()==0)
        cout<<"No anagrams exist "<<endl;
    else{
        cout<<"Count of anagrams of t in s : "<<ret.size()<<endl;

        cout<<"The anagrams are \n";

        int num=1;
        for(int j:ret)
        {
            cout<<num++<<". ";
            for(int i=j;i<j+t.length();i++)
            {
                cout<<s[i];
            }
            cout<<'\n';
        }


    }
    return 0;
} 