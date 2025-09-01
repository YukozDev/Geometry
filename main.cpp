#include <iostream>
#include "includes/core/Vectors/VectorBase.hpp"
#include "includes/core/Vectors/Vector3.hpp"
#include "includes/core/Vectors/Vector2.hpp"
#include "includes/core/Geometry/Point.hpp"
#include "includes/core/Geometry/GeoUtils.hpp"
#include "includes/core/Geometry/line.hpp"
#include "includes/core/Geometry/intersection.hpp"
#include "includes/operations/Vector.hpp"

int main() {

    VectorBase<int, 3> V1;

    int V1Size = V1.size();

    std::cout << "V1 SIZE : " << V1Size << std::endl;
 
    for(int i = 0; i < V1Size; i++) {
        std::cout << "V1["<< i <<"] = " << V1[i] << std::endl;
    }

    VectorBase<int, 3> V2({2, 4, 6});

    for(int i = 0; i < V2.size(); i++) {
        std::cout << "V2["<< i <<"] = " << V2[i] << std::endl;
    } 
    
    VectorBase<int, 3> V3 = V2;

    for(int i = 0; i < V3.size(); i++) {
        std::cout << "V3["<< i <<"] = " << V3[i] << std::endl;
    }
    
    std::array<int, 3> arr = { 1, 2, 3 };
    VectorBase<int, 3> V4 = arr;
    
    for(int i = 0; i < V4.size(); i++) {
        std::cout << "V4["<< i <<"] = " << V4[i] << std::endl;
    }
    
    VectorBase<int, 3> V5 = V4 - V2;

    for(int i = 0; i < V5.size(); i++) {
         std::cout << "V5["<< i <<"] = " << V5[i] << std::endl;       
    }

    V5 = V5 + V2;

    for(int i = 0; i < V5.size(); i++) {
         std::cout << "V5["<< i <<"] = " << V5[i] << std::endl;       
    }

    VectorBase<int, 3> V6;
    V6 = 4 * V3;

    for(int i = 0; i < V6.size(); i++) {
         std::cout << "V6["<< i <<"] = " << V6[i] << std::endl;  
    }

    Vector3 Vec3_1(3,6,9);

    Vector3 Vec3_2 = V5;
    Vec3_2 = { 5, 7, 0 };

    for (int i = 0; i < Vec3_2.size(); i++) {
         std::cout << "Vec3_2["<< i <<"] = " << Vec3_2[i] << std::endl;  
    }

    Vec3_2 = 45 * Vec3_2;

    for (int i = 0; i < Vec3_2.size(); i++) {
         std::cout << "Vec3_2["<< i <<"] = " << Vec3_2[i] << std::endl;  
    }

    Vector3 Vec3_3 = { 2, 2, 2 };
    Vector3 Vec3_4 = { 2.0, -1.0, 2.0 };
    Vector3 Vec3_4N = normalize(Vec3_4);

    for (int i = 0; i < Vec3_4N.size(); i++) {
         std::cout << "Vec3_4N["<< i <<"] = " << Vec3_4N[i] << std::endl;  
    }

    Vector2 Vec2_1(2, 2);

    std::cout << "Norme : " << norm(Vec2_1) << '\n';
    std::cout << "Norme : " << norm(Vec3_3) << '\n';

    Vector2 v(-6, 7);
    Vector2 w(-2, 8);
    std::cout << "dotP : " << dotProduct(v, w) << '\n';

    std::cout << "isPerPendicular : " << std::boolalpha << isPerpendicular(Vec3_3, Vec3_2) << std::endl;

    std::cout << "isPerPendicular : " << std::boolalpha << isPerpendicular(Vec3_3, Vec3_3) << std::endl;

    for (int i = 0; i < 3; i++) {
         std::cout << "(crossProduct) " << "["<< i <<"] = " << crossProduct(Vec3_3, Vec3_1)[i] << std::endl;  
    }

    std::cout << "Det = " << determinant(v, w) << std::endl;  
    
    Point2D p1 = Point2D(5.0, 3.0);
    Point2D p2 = Point2D(2.0, 8.0);
    Point2D p3 = Point2D(4.0, 9.0);

    std::cout << "Area of trianlge = " << areaOfTriangle(p1, p2, p3) << std::endl; 

    Point2D p4(12.0, 1.0);
    Point2D p5(4.0, 10.0);
    //Point2D p6(20.0, -8.0); //BEHIND
    //Point2D p6(-4.0, 19.0); //BEYOND
    Point2D p6(8.0, 5.5); // BETWEEB
    //Point2D p6(12.0, 1.0);
    //Point2D p6(4.0, 10.0);

    RELATIVE_POSITION T = relativePosition2D(p4, p5, p6);
    std::cout << "PT C Position : " << T << std::endl; 

    Line l(p4, p5);
    std::cout << "Line L : " << l.getDirection().X() << std::endl;    
    std::cout << "Line L : " << l.getDirection().Y() << std::endl;    

    Point2D p7(1.0, 2.0);
    Point2D p8(12.0, 9.0);
    Point2D p9(2.0, 8.0);
    Point2D p10(9.0, 3.0);

    Point2D intersect = intersection(p7, p8, p9, p10);
    std::cout << "[" << intersect.x << "," << intersect.y << "]" << '\n';
}
