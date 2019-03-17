#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0){
      if (a_size > N){
          throw invalid_argument("size bigger than capacity!");
      } else {
        size_ = a_size;
      }
  }

  T& operator[](size_t index){
      return arr[index];
  }
  
  const T& operator[](size_t index) const{
      return arr.at(index);
  }

  auto begin() {
      return arr.begin();
  }
  
  auto end() {
      return arr.begin() + size_;
  }
  
  auto begin() const {
      return arr.begin();
  }
  
  auto end() const {
      return arr.begin() + size_;
  }

  size_t Size() const {
      return size_;
  }
  
  size_t Capacity() const {
      return N;
  }

  void PushBack(const T& value){
      if (size_ >= N){
          throw overflow_error("You can't pushback more!");
      } else {
        arr[size_++] = value;
      }
  }
  
  T PopBack(){
      if (size_ == 0){
          throw underflow_error("Stack Vector is Empty!");
      } else {
        return arr.at(--size_);
      }
  }

private:
    size_t size_ = 0;
    array<T, N> arr;
};
