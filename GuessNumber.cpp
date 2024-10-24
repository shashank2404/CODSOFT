#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int x;
    cout<<"Enter Your input value:";
    cin>>x;
    int random_number = rand()%101; 
   while(x!=random_number){
    if(x>random_number){
        cout<<"Your input value is higher than the randomly generated number:"<<endl;
    }
    else{
        cout<<"Your input value is lower than the randomly generated number:"<<endl;
    }
    cout<<"Enter the value again:";
    cin>>x;
   }
   cout<<"Congratulation Your Enter the correct value:"<<x<<endl;
    return 0;
}