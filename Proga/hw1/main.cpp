#include <iostream>

int fact(int x){
    int res,i;
    res = 1;
    for(i=1;i<=x;i++){
        res = res*i;
    }
    return res;
}

int main(){
    int x;
    std::cout<<"Enter the number: "<<std::endl;
    std::cin>>x;
    std::cout<<fact(x)<<std::endl;
    return 0;
}