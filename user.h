#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "comment.h"
#include "post.h"
class User{
    std::string m_userid; 
    std::string m_password;
    std::string m_email;
    std::string m_description;
    //std::vector<Comment> m_comments;
    std::vector<Post> m_posts;
    std::vector<std::weak_ptr<User>> m_friends;
    std::vector<std::weak_ptr<User>> m_requests;
public:
    User() = default;
    bool login(const std::string& userid,  const std::string& password);
    User(const std::string& userid,  const std::string& password,const std::string email,  const std::string description);
    void Update(const std::string email,  const std::string description);
    void CreatePost();
    void friendrequest();
    std::string& getuserid();
    void addrequest(std::shared_ptr<User> from);
    void AddFriend(std::weak_ptr<User> a);

};

#endif