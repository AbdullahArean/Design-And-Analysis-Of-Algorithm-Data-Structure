#include<iostream>
#include<vector>
using namespace std;

void findSubsets(char* input, char* output, int i, int j){
    //Base Case
    if(input[i]=='\0'){
        output[j]= '\0';
        if(output[0]=='\0') cout<<"NULL\n";
        else cout<<output<<"\n";
        return;
    }
    //reccase
    //Include ith letter
    output[j]=input[i];
    findSubsets(input, output, i+1, j+1);

    //exclude letter ith 
    findSubsets(input, output, i+1, j);
;
}

int main(){
    char input[100];
    char output[100];
    cin>>input;
    findSubsets(input, output, 0, 0);

    return 0;

}