#ifndef  __DOGRUN2_DOG__
#define  __DOGRUN2_DOG__

#include <string>
#include <vector>

using std::string;
using std::vector;

class Dog;

class User {
public:
    // attr
    const string& id() {return id_;};
    const string& title();
    int money();
    int heart();

    static User *current() {return current_;};
    static void InitCurrent();
    static void set_current(User *u) {current_ = u;}

    void set_id(const string& id) {id_ = id;}
    void set_title(const string& title) {title_ = title;}
    void set_money(int money) {money_ = money;}
    void set_heart(int heart) {heart_ = heart;}

    int AddDog(Dog *dog);
    Dog *dogs(int idx) {return dogs_[idx];}
    size_t dogs_count(void) {return dogs_.size();}
protected:
    string id_;
    string title_;
    int money_;
    int heart_;

    vector<Dog *> dogs_;
    static User* current_;
};

class Dog {
public:
    Dog();
    virtual int Feed(int foodtype);
    virtual int Train(int traintype);

    // attr
    const string& name();
    int lv();
    int star();
    int str();
    int speed();
    int intimacy();
    User *owner();

    // set methods for attr
    void set_owner(User *owner) {owner_ = owner;}
protected:
    string name_;
    int lv_;
    int star_;
    int str_;
    int speed_;
    int intimacy_;
    time_t feedcd_;
    time_t traincd_;
    User *owner_;
};
#endif // ! __DOGRUN2_DOG__
