#include <iostream>
#include <math.h>

using namespace std;

    class Point{
    private:
         float x,y;

    public:
        //default contructor
        Point (){
        }
        //parameter constructor

        Point (float x1, float y1){
            x = x1;
            y = y1;
        }

        float getX(){return x;}
        float getY(){return y;}
        void setX(float x1){x = x1;}
        void setY(float y1){y = y1;}

        void printPoint(){
       cout << '(' << x << ", " << y << ')';
       }

       float getDistance(Point p){
            return sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
       }
};

class Segment{
     private:
        Point point1, point2;
     public:
         //default constructor
        Segment():Segment(point1,point2){}
        //parameter segment
        Segment(Point p1,Point p2):point1(p1),point2(p2){}
           float getLength(){return point1.getDistance(point2);}

    Point *getIntersect(Segment secondSegment){

        if (point1.getDistance(secondSegment.point1) == 0 || point1.getDistance(secondSegment.point2) == 0){
            return &point1;
        }
        if (point2.getDistance(secondSegment.point1) == 0 || point2.getDistance(secondSegment.point2)){
            return &point2;
        }

        float det = -1 *((point1.getX() - secondSegment.point1.getX())/((point2.getX() - point1.getX()) - (secondSegment.point2.getX() - secondSegment.point1.getX())));
        float x = point1.getX() + (point2.getX() - point1.getX())*det;
        float y = point1.getY() + (point2.getY() - point1.getY())*det;

        int t;
        Point *IntersectionP = new Point(x, y);
        return (t >=0 && t <=1)?IntersectionP : NULL;
        }

    };
