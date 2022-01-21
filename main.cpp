#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
int num_of_words(string& s);
string remove_punc(string& s);
int occurance_of_letters(string& s);
string remove_blanks(string& s);
int main()
{
    string s;
    int n;
    cout<<"Enter sentence:"<<endl;

    cin.ignore();
    getline(cin, s);
    cout<<"num of words:"<<num_of_words(s)<<endl;
    cout<<endl;
    cout<<"number of occurance:"<<occurance_of_letters
    (s)<<endl;
    return 0;
}

int num_of_words(string& s){
    int n, i;
    string temp(s);
    temp = remove_punc(temp);
    for(i=1; i<temp.length(); i++){
        if(temp[i]==' '){
            n++;
        }
    }
    n++;//en sonda . var boþluk yok
    return n;
}
string remove_punc(string& s){
    int i;
    string temp(s);
    for(i=0; i<temp.size(); i++){
        if(ispunct(temp[i]) || (temp[i]=='.')){
            temp.erase(i--,1);
        }
    }
    return temp;
}

int occurance_of_letters(string& s){
    string temp(s);
    temp=remove_blanks(temp);
    int i, j;
    int alphabet[26] = {0};
    while(temp[i]!='\0'){
        if(temp[i]>='a' && temp[i]<='z'){
            j=temp[i]-'a';
            ++alphabet[j];
        }
        ++i;
    }
    cout<<"Frequency:\n"<<endl;
    for(i=0; i<26; i++){
        cout<<char(i + 'a')<<" : "<<alphabet[i]<<endl;
    }
}

string remove_blanks(string& s){
    string temp(s);
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    return temp;
}
