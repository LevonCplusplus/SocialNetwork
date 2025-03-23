#ifndef NETWORK_H
#define NETWORK_H
#include "user.h"
class Network{
   std::vector<std::shared_ptr<User>> m_users;
public:
   void RegisterUser();
   void Userlogin();
   void showmenu();
   void menu();
   //void FriendRequest(User * from, User * to); 
};
//network.cpp
void Network::RegisterUser(){
    std::string password1;
    std::string password2;
    std::string userid;
    bool cond = true;
    std::cout << "please enter your UserId" << std::endl;
    while(true){
        std::cin >> userid;
       for(int i = 0; i < m_users.size(); ++i)
       {
            if(m_users[i]->getuserid() == userid){
                std::cout << "this userid already exists try again";  
                cond = false;
                break;  
            }
        } 
       if(cond)
       {
         break;
       }
    }
    
    while(true){
       std::cout << "please enter your password" << std::endl;
       std::cin >> password1;
       std::cout << "enter your password again" << std::endl;
       std::cin >> password2;
       if(password1 != password2)
       {
         cond = false;
         std::cout << "passwords isn't same please try again\n"; 
       }
       else {
          break;
       }
    }
    std::string email,description;
    std::cout << "please enter your email\n";
    std::cin >> email;
    std::cout << "please enter your description\n";
    std::cin >> description;       
    m_users.push_back(std::make_shared<User>(userid,password1,email,description));
    std::cout<< "now you can login\n";
}
// void FriendRequest(std::weak_ptr<User> from,std::weak_ptr<User> to){
//     from 
// }
void Network:: showmenu(){
    std::cout << "1. create post\n2. search friend\n3.my posts\n 4. log out"<<std::endl;
    
}
void Network:: menu(){
    std::cout<<"welcome to facebook!!!" << std::endl;
    std::cout<<"if you want to register insert 1 else 0" << std::endl;
    int k;
    std::cin >> k;
    if(k){
        
        RegisterUser();

    }
    else{
        std::cout<< "bye!!!";
        return;
    }
    Userlogin();
}
void Network::Userlogin(){
    std::string password;
    std::string userid;
    int i{};
    while(true){
        std::cout << "please enter your UserId" << std::endl;
        std::cin >> userid;
        std::cout << "please enter your password" << std::endl;
        std::cin >> password;
        bool cond = false;
        for(i = 0 ;i < m_users.size();++i)
        {
            if(m_users[i]->login(userid,password)){
                std::cout << "you logged in succesfully\n";
                cond = true;
                break;
            }
        } 
        if(!cond){
            std::cout << "encorrect password or userid\n try again\n";
        }
        else{
            break;
        }
    }
    m_users[i]->friendrequest();
    showmenu();
    int p;
    std::cin >> p;
    if(p == 3){
       m_users[i]->CreatePost(); 
    }
    else if(p == 4){
        menu();
    }
}


#endif