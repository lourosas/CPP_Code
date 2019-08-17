#ifndef THREAD_Z_H
#define THREAD_Z_H
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

class ThreadZ{
   public:
		ThreadZ();
		~ThreadZ();
		void doSomething(std::mutex&, std::condition_variable& );
		int  getCount() const;
		void setDone(bool );
   private:
		bool done;
		int count;
		enum{ DELAY = 3 };
		void setCount(int );
};
#endif
