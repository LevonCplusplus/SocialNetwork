#include "user.h"
User:: User(const std::string& userid,  const std::string& password,  const std::string email,  const std::string description)
:m_userid(userid),m_password(password),m_email(email),m_description(description){};
bool User:: login(const std::string& userid,  const std::string& password){
    
    return (userid == m_userid) && (m_password == password);
   
}
void User:: Update(const std::string email,const std::string description)
{
    m_email = email;
    m_description = description;
}

void User:: AddFriend(std::weak_ptr<User> a){
   m_friends.push_back(a);
}

void User:: addrequest(std::shared_ptr<User> from){
    m_requests.push_back(from);
}

std::string& User:: getuserid(){
    return m_userid;
}

void User::friendrequest( ){
    std::cout << "your requests:\n";
    if(m_requests.size()== 0)
    {
        std::cout <<"no friend requests\n";
        return;
    }
    for(int i = m_requests.size()-1; i >= 0; --i)
    {
        std::cout << m_requests[i].lock()->getuserid() << "\nif you want to accept insert 1 else 0\n";
        int k;
        std::cin >> k;
        if(k)
        {
            AddFriend(m_requests[i]);
            m_requests[i].lock()->AddFriend(std::weak_ptr<User>(std::shared_ptr<User>(this)));
            m_requests.pop_back();
        }
        else {
            m_requests.pop_back();
        }
    } 

}
void User:: showposts(){
  for(int i=0;i < m_posts[i];++i ){
    m_posts[i].showpost();
  }
}

void User:: CreatePost(){
    std::cout << "insert your post\n";
    std::string post;
    std::cin >> post;
    m_posts.push_back(Post (post));
}

