#include "timeWheel.h"
#include <thread>
#include <chrono>
// 假设你的头文件中的回调函数定义为这样
void callback(client_data* data) {
    printf("Timer callback called \n");
}

int main() {
    // 创建时间轮对象
    time_wheel timer_wheel;

    // 添加定时器，假设在 5 秒后触发
    tw_timer* timer = timer_wheel.add_timer(5);

    // 设置定时器的回调函数
    timer->cb_func = callback;

    // 每隔一秒调用一次 tick() 方法
    while (true) {
        timer_wheel.tick(); // 调用时间轮的 tick() 方法

        // 等待一秒钟
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    printf("退出程序\n");

    return 0;
}
