#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout << "Waiting... \n";
    cv.wait(lk, []{return i == 10;});
    std::cout << "...finished waiting. i == "<<i<<"\n";
    done = true;
}

void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //std::cout << "Notifying falsely..."<<i<<"\n";
    // waiting thread is notified with i == 0.
    // cv.wait wakes up, checks i, and goes back to waiting
    //cv.notify_one();

    std::unique_lock<std::mutex> lk(cv_m);
    //lk.unlock();
    //cv.notify_one();
    //lk.lock();
    //i = 0;
    while (!done)
    {
        std::cout << "Notifying..."<<i<<"\n";
        lk.unlock();
        // waiting thread is notified with i == 1, cv.wait returns
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        lk.lock();
        ++i;
    }
}

int main()
{
    std::thread t1(waits), t2(signals);
    t1.join();
    t2.join();
}
