#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
char buffer[10000];
vector <int>next;
/*
// Pay attention! 
// the prefix under index i in the table above is 
// is the string from pattern[0] to pattern[i - 1] 
// inclusive, so the last character of the string under 
// index i is pattern[i - 1]   

function build_failure_function(pattern[])
{
  // let m be the length of the pattern 

  F[0] = F[1] = 0; // always true
  
  for(i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
}
function Knuth_Morris_Pratt(text[], pattern[])
{
  // let n be the size of the text, m the 
  // size of the pattern, and F[] - the
  // "failure function"

  build_failure_function(pattern[]); 

  i = 0; // the initial state of the automaton is
         // the empty string

  j = 0; // the first character of the text
  
  for( ; ; ) {
    if(j == n) break; // we reached the end of the text

    // if the current character of the text "expands" the
    // current match 
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) // match found
    }

    // if the current state is not zero (we have not
    // reached the empty string yet) we try to
    // "expand" the next best (largest) match
    else if(i > 0) i = F[i];

    // if we reached the empty string and failed to
    // "expand" even it; we go to the next 
    // character from the text, the state of the
    // automaton remains zero
    else j++;
  }
}
*/ 
//implement later


void initnext(string &p)
{
    int i,j,m=p.length();
    next[0]=-1;
    for(i=0,j=-1;i<m;i++,j++,next[i]=j)
        while((j>=0) && (p[i]!=p[j])) j=next[j];    
}
int kmpsearch(string& p,string& s)
{
    int i,j,m=p.length(),n=s.length();
    initnext(p);
    for(i=0,j=0;j<m && i<n;i++,j++)
    while((j>=0) && (s[i]!=p[j])) j=next[j];
    
    if(j==m)
        return (i-m);
    else
        return i;   
}
int main()
{
next.clear();
scanf("%s",buffer);
string p(buffer);
scanf("%s",buffer);
string s(buffer);
cout<<p<<endl<<s<<endl;
next.reserve(p.length()+10);
printf("%d\n",kmpsearch(p,s));
system("PAUSE");
return 0;
}
