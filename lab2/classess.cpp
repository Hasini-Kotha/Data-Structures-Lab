#include<iostream>
using namespace std;
class area{
public :
int length;
int breadth;
int height;
public :
    int square(int side){
        int area = side *side ;
        cout<<"The area of the square is   : \n"<<area<<endl;
        return 0;
    }
    int cube (int side){
        int area = 6 *side *side;
        cout<<"The area of the cube is  :\n"<<area<<endl;
        return 0;
    }
    int rectangle(int length , int breadth ){
        int area = length*breadth;
        cout<<"The area of rectangle is  : \n"<<area << endl;
        return 0;
    }
    int cuboid (int l , int b , int h){
        int area ;
        area = 2*(l*b+ b*h + h*l);
        cout<<"The area of cuboid is  : \n"<<area <<endl;
        return 0;
    }
};
int main(){
    int choice ;
    area obj;
    do{
        cout<<"Enter 1 : To find area of square"<<endl;
        cout<<"Enter 2 : To find the area of cube"<<endl;
        cout<<"Enter 3 : To find the area of rectangle"<<endl;
        cout<<"Enter 4 : To find the area of cuboid"<<endl;
        cout<<"Enter 5 : Exit the prograam!"<<endl;
        cout<<"Enter choice"<<endl;
        cin>> choice;
         switch(choice){
            case 1:
            cout<<"Enter the side of a square  :\n"<<endl;
            cin>> obj.length;
            obj.square(obj.length);
            break;
            case 2 :
            cout<<"Enter the side of cube :\n"<<endl;
            cin>>obj.length;
            obj.cube(obj.length);
            break;
            case 3 :
            cout<<"Enter the length of the rectangle :"<<endl;
            cin>>obj.length;
            cout<<"Enter the breadth of the rectangle :"<<endl;
            cin>>obj.breadth;
            obj.rectangle(obj.length , obj.breadth);
            break;
            case 4:
            cout<<"Enter the length of the cuboid :"<<endl;
            cin>>obj.length;
            cout<<"Enter the breadth of the cuboid :"<<endl;
            cin>>obj.breadth;
            cout<<"Enter the height of the cuboid :"<<endl;
            cin>>obj.height;
            obj.cuboid(obj.length ,obj.breadth , obj.height);
            break;
            case 5 :
             cout<<"Program ended"<<endl;
             break;
            default:
            cout<<"The number is not valid, Enter a valid number"<<endl;
         }
    }
    while(choice != 5);
}