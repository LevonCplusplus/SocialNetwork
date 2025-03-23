#ifndef POST_H
#define POST_H
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
class Post{
  std::string m_post;
  std::string m_posttime;
public:
  Post(const std::string& post ){
    m_post = post;
    auto now = std::chrono::system_clock::now();       // Получаем текущее время
    std::time_t now_c = std::chrono::system_clock::to_time_t(now); // Преобразуем в time_t
    m_posttime = std::ctime(&now_c);
  }
  void showpost(){
    std::cout << m_post << "\time:" << m_posttime << std::endl;
  }
};




#endif