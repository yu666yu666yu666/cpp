#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// 定义业务类型
enum BusinessType {
    DEPOSIT,  // 存款
    WITHDRAW, // 取款
    REPORT_LOSS, // 挂失
    LOAN_REPAY // 还贷
};

// 每种业务的服务时间和优先级
const int SERVICE_TIMES[] = {5, 8, 15, 10}; // 单位：分钟
const int PRIORITIES[] = {2, 2, 1, 3};     // 数字越小优先级越高

// 客户类
struct Customer {
    int arrival_time;   // 到达时间
    int id;             // 编号
    BusinessType business; // 办理的业务类型
    int start_time;     // 开始办理的时间
    int end_time;       // 结束办理的时间

    // 构造函数
    Customer(int time, int id, BusinessType business)
        : arrival_time(time), id(id), business(business), start_time(-1), end_time(-1) {}
};

// 比较客户优先级的函数（用于优先队列）
struct ComparePriority {
    bool operator()(const Customer* a, const Customer* b) {
        if (PRIORITIES[a->business] == PRIORITIES[b->business]) {
            return a->arrival_time > b->arrival_time; // 到达时间早的优先
        }
        return PRIORITIES[a->business] > PRIORITIES[b->business]; // 优先级高的优先
    }
};

// 模拟系统类
class BankSimulation {
private:
    int total_time; // 模拟一天的时间（单位：分钟）
    int num_windows; // 窗口数量

    priority_queue<Customer*, vector<Customer*>, ComparePriority> waiting_queue; // 等待队列
    vector<Customer*> windows; // 窗口当前正在办理的客户
    vector<int> window_customer_count; // 每个窗口办理的客户数
    vector<int> business_count; // 每种业务的办理数

    vector<int> customer_wait_times; // 记录所有客户的逗留时间

public:
    BankSimulation(int total_time, int num_windows)
        : total_time(total_time), num_windows(num_windows),
          window_customer_count(num_windows, 0), business_count(4, 0) {
        windows.resize(num_windows, nullptr);
    }

    // 生成随机业务类型
    BusinessType random_business() {
        return static_cast<BusinessType>(rand() % 4);
    }

    // 模拟客户到达
    void customer_arrival(int time, int id) {
        BusinessType business = random_business();
        Customer* customer = new Customer(time, id, business);
        waiting_queue.push(customer);
    }

    // 处理窗口业务
    void process_windows(int current_time) {
        for (int i = 0; i < num_windows; ++i) {
            // 如果窗口空闲，从等待队列中取优先级最高的客户
            if (windows[i] == nullptr && !waiting_queue.empty()) {
                Customer* customer = waiting_queue.top();
                waiting_queue.pop();
                customer->start_time = current_time;
                customer->end_time = current_time + SERVICE_TIMES[customer->business];
                windows[i] = customer;

                // 更新统计数据
                window_customer_count[i]++;
                business_count[customer->business]++;
                customer_wait_times.push_back(customer->end_time - customer->arrival_time);
            }

            // 如果窗口正在办理业务，检查是否完成
            if (windows[i] != nullptr && current_time >= windows[i]->end_time) {
                delete windows[i]; // 释放内存
                windows[i] = nullptr;
            }
        }
    }

    // 运行模拟
    void run_simulation() {
        int id = 1; // 客户编号从1开始
        for (int current_time = 0; current_time < total_time; ++current_time) {
            // 每分钟随机生成一个客户到达
            if (rand() % 10 < 3) { // 30%的概率有客户到达
                customer_arrival(current_time, id++);
            }

            // 处理窗口业务
            process_windows(current_time);
        }

        // 清理剩余客户
        while (!waiting_queue.empty()) {
            delete waiting_queue.top();
            waiting_queue.pop();
        }
    }

    // 输出统计结果
    void print_statistics() {
        // 计算平均逗留时间
        double total_wait_time = 0;
        for (int wait_time : customer_wait_times) {
            total_wait_time += wait_time;
        }
        double average_wait_time = customer_wait_times.empty() ? 0 : total_wait_time / customer_wait_times.size();

        cout << fixed << setprecision(2);
        cout << "客户在银行内的平均逗留时间: " << average_wait_time << " 分钟" << endl;

        // 每个窗口办理的客户数
        for (int i = 0; i < num_windows; ++i) {
            cout << "窗口 " << i + 1 << " 办理的客户数: " << window_customer_count[i] << endl;
        }

        // 每种业务的办理数
        cout << "每种业务的办理数:" << endl;
        cout << "  存款: " << business_count[DEPOSIT] << endl;
        cout << "  取款: " << business_count[WITHDRAW] << endl;
        cout << "  挂失: " << business_count[REPORT_LOSS] << endl;
        cout << "  还贷: " << business_count[LOAN_REPAY] << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // 初始化随机数种子

    int total_time = 8 * 60; // 银行每天工作8小时，单位：分钟
    int num_windows = 4; // 服务窗口数量

    BankSimulation simulation(total_time, num_windows);
    simulation.run_simulation();
    simulation.print_statistics();

    return 0;
}