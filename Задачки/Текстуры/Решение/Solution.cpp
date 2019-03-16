#include <memory>
#include "Common.h"

using namespace std;


// Проверка точки на выход за границы
bool Prov(Point p, Size s) {
    return p.x >= 0 && p.y >= 0 && p.x < s.width && p.y < s.height;
}

Size RealSize(const Image& image) {
  auto w = static_cast<int>(image.empty() ? 0 : image[0].size());
  auto h = static_cast<int>(image.size());
  return {w, h};
}

class Shape : public IShape {
public:    
   void SetPosition(Point p) override {
       point_ = p;
   } 
   Point GetPosition() const override {
       return point_;
   }
   void SetSize(Size s) override {
       size_ = s;
   }  
   Size GetSize() const override {
       return size_;
   }
   void SetTexture(shared_ptr<ITexture> t) override {
       texture_ = move(t);
   }     
   ITexture* GetTexture() const override {
       return texture_.get();
   }
   void Draw(Image& image) const override {
       Point p;
       Size s = RealSize(image);
       for(p.y = 0; p.y < size_.height; ++p.y){
           for(p.x = 0; p.x < size_.width; ++p.x) {
               if(IsPointInShape(p)) { // для прямогуольника - всегда тру, для эллипса - специальная функция
                   char pixel = '.'; // дефолтный пиксель всегда точка
                   if(texture_ && Prov(p, texture_->GetSize())){ // если есть текстура и у нас проходят условие точки
                       pixel = texture_->GetImage()[p.y][p.x]; // то меняем пиксель на тот, что был на этой текстуре
                   }
                   Point p2 = {point_.x + p.x, point_.y + p.y};
                   if (Prov(p2, s)) {
                       image[p2.y][p2.x] = pixel;
                   }
               }
           }
       }
   }
   
private:
    Point point_ = {};
    Size size_ = {};
    shared_ptr<ITexture> texture_;
    virtual bool IsPointInShape(Point) const = 0;
    
   
};

class RectangleShape : public Shape {
public:

  unique_ptr<IShape> Clone() const override {
       return make_unique<RectangleShape>(*this);
   } 
   
private:
    bool IsPointInShape(Point) const override {
        return true;
    }
};


class EllipseShape : public Shape {
public:

   unique_ptr<IShape> Clone() const{
       return make_unique<EllipseShape>(*this);
   }

   
private:
     bool IsPointInShape(Point p) const override {
    return IsPointInEllipse(p, GetSize());
  }   
};

// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
   switch (shape_type) {
    case ShapeType::Rectangle:
      return make_unique<RectangleShape>();
    case ShapeType::Ellipse:
      return make_unique<EllipseShape>();
  }
  return nullptr;
}

