#include "test_runner.h"
#include <iostream>
#include <cstddef>
#include <memory>  // нужно для nullptr_t

using namespace std;

// Реализуйте шаблон класса UniquePtr
template <typename T>
class UniquePtr {
public:
  UniquePtr() {}
  
  UniquePtr(T * ptr) : ptr_(move(ptr)) {} // Конструктор, принимающий T * и захватывающий владение этой динамической памятью.
  
  UniquePtr(const UniquePtr&) = delete;
  
  UniquePtr(UniquePtr&& other) { // Конструктор перемещения, получающий на вход rvalue-ссылку на другой UniquePtr и отбирающий у него владение ресурсом.
      if(ptr_) {
         this->~UniquePtr(); 
      }
      ptr_= other.Release();
  }
  
  UniquePtr& operator = (const UniquePtr&) = delete;
  
  UniquePtr& operator = (nullptr_t) {
      Reset(nullptr);
      return *this;
  }
  
  UniquePtr& operator = (UniquePtr&& other) { // Move-оператор присваивания, получающий на вход rvalue-ссылку на другой UniquePtr.
      if(ptr_) {
         this->~UniquePtr();  
      }
       ptr_= other.Release();
      return *this; // нужно ли возращать?
  }
  
  ~UniquePtr() {
      delete ptr_;
  }

  T& operator * () const {
      return *ptr_;
  }

  T * operator -> () const {
      return Get();
  }

  T * Release() {
      T* t = move(ptr_);
      ptr_ = nullptr;
      return move(t);
  }

  void Reset(T * ptr) {
      if(ptr_) {
         this->~UniquePtr(); 
      }
      ptr_ = move(ptr);
  }

  void Swap(UniquePtr& other) {
      T* t = other.Release();
      other.Reset(this->Release());
      ptr_ = move(t);
  }

  T * Get() const {
      return ptr_;
  }
  
  private:
      T* ptr_ = nullptr;
};


struct Item {
  static int counter;
  int value;
  Item(int v = 0): value(v) {
    ++counter;
  }
  Item(const Item& other): value(other.value) {
    ++counter;
  }
  ~Item() {
    --counter;
  }
};

int Item::counter = 0;


void TestLifetime() {
  Item::counter = 0;
  {
    UniquePtr<Item> ptr(new Item);
    ASSERT_EQUAL(Item::counter, 1);

    ptr.Reset(new Item);
    ASSERT_EQUAL(Item::counter, 1);
  }
  ASSERT_EQUAL(Item::counter, 0);

  {
    UniquePtr<Item> ptr(new Item);
    ASSERT_EQUAL(Item::counter, 1);

    auto rawPtr = ptr.Release();
    ASSERT_EQUAL(Item::counter, 1);

    delete rawPtr;
    ASSERT_EQUAL(Item::counter, 0);
  }
  ASSERT_EQUAL(Item::counter, 0);
}

void TestGetters() {
  UniquePtr<Item> ptr(new Item(42));
  ASSERT_EQUAL(ptr.Get()->value, 42);
  ASSERT_EQUAL((*ptr).value, 42);
  ASSERT_EQUAL(ptr->value, 42);
}

void MyTest() {
    { // проверка на пустоту
        UniquePtr<Item> ptr; // создание пустого птра
        ASSERT(!ptr.Get());
    }
    { // проверка на оператор перемещения
        UniquePtr<Item> ptr(new Item);
        ASSERT(ptr.Get());
        UniquePtr<Item> ptr2 = move(ptr);
        ASSERT(!ptr.Get());
        ASSERT(ptr2.Get());
    }
    { // проверка на конструктор перемещения
        UniquePtr<Item> ptr(new Item);
        ASSERT(ptr.Get());
        UniquePtr<Item> ptr2(move(ptr));
        ASSERT(!ptr.Get());
        ASSERT(ptr2.Get());
    }
    {
        
    }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLifetime);
  RUN_TEST(tr, TestGetters);
  RUN_TEST(tr, MyTest);
}