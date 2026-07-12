//building an online store with STL 

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>         
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>


using namespace std;
struct Product{
    int ProductID;
    string name;
    string categary;

};

struct Order{
    int orderID;
    int ProductID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main(){
    vector<Product> products = {
        {101,"Laptop","Electronics"},
        {102,"Smartphone","Electronics"},
        {103,"Headphones","Electronics"},
        {104,"Shoes","Fashion"},
        {105,"T-shirt","Fashion"}
    };
    cout << "=== Product List ===\n";
    for(const auto& product : products){
        cout << "Product ID: " << product.ProductID << ", Name: " << product.name << ", Category: " << product.categary << endl;
    }

    deque<string> recentCustomers = {"C001","C002","C003","C004"};
    recentCustomers.push_front("C005");
    cout << "Recent Customers: ";
    for(const auto& customer : recentCustomers){
        cout << customer << endl;
    }
    

    list <Order> orderHistory;
    orderHistory.push_back({1,101,1,"C001",time(0)});
    orderHistory.push_back({2,102,2,"C002",time(0)});
    orderHistory.push_back({3,103,1,"C003",time(0)});

    set<string> categories;
    for(const auto& product: products){
        categories.insert(product.categary);
    }
    cout << "\n=== Product Categories ===\n";
    for(const auto& category : categories){
        cout << category << endl;
    }

    map<int,int> productStock ={
        {101,10},
        {102,20},
        {103,15},
        {104,30},
        {105,25}
    };
    cout << "\n=== Product Stock ===\n";
    for(const auto& stock : productStock){
        cout << "Product ID: " << stock.first << ", Stock: " << stock.second << endl;
    }

    multimap<string,int> customerOrders;
    for(const auto& order: orderHistory){
        customerOrders.insert({order.customerID,order.orderID});
    }
    cout << "\n=== Customer Orders ===\n";
    for(const auto& entry : customerOrders){
        cout << "Customer ID: " << entry.first << ", Order ID: " << entry.second << endl;
    }

    unordered_map<string,string> customerData = {
        {"C001","Alice"},
        {"C002","hitesh"},
        {"C003","max"},
        {"C004","David"},
        {"C005","harry"},
    };
    cout << "\n =====Customer Details===== \n";
    for(const auto& customer : customerData){
        cout << "Customer ID: " << customer.first << ", Name: " << customer.second << endl;
    }

    unordered_set<int> uniqueProductIDs;
    for(const auto &product : products){
        uniqueProductIDs.insert(product.ProductID);
    }
    cout << "\n =====Unique Product IDs=====\n";
    for(const auto& id : uniqueProductIDs){
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
