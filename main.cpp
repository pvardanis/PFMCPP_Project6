/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
//#include <assert.h> don't include what you don't use

struct T
{
    float value;
    std::string name;
    T(float v, const char* myName) :
    value(v),   //1
    name(myName)
    {}
};

struct Struct1                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;   
        }
        return nullptr; 
    }
};

struct U
{
    float t1 { 0 }, t2 { 0 };
    float t1Update(const float& t1_)      //12
    {
        std::cout << "U's t1 value: " << t1 << std::endl;
        t1 = t1_;
        std::cout << "U's t1 updated value: " << t1 << std::endl;
        while( std::abs(t2 - t1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            if (t2 > t1)
            {
                t1 += 0.001f;
            }
            else
            {
                t2 += 0.001f;
            }            
        }
        std::cout << "U's t2 updated value: " << t2 << std::endl;
        return t2 * t1;        
    }
};

struct Struct2
{
    static float t1Update(U& that, const float& t1_ )        //10
    {
        std::cout << "U's t1 value: " << that.t1 << std::endl;
        that.t1 = t1_;
        std::cout << "U's t1 updated value: " << that.t1 << std::endl;
        
        while( std::abs(that.t2 - that.t1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            if (that.t2 > that.t1)
            {
                // std::cout << "WOW" << std::endl;
                that.t1 += 0.001f;
            }
            else
            {
                that.t2 += 0.001f;
            }            
        }
        std::cout << "U's t2 updated value: " << that.t2 << std::endl;
        std::cout << "t1: " << that.t1 << " t2: " << that.t2 << std::endl;
        return that.t2 * that.t1;
    }
};
        
int main()
{
    T p1(4.5f, "Panos");                                             //6
    T p2(3.2f, "Matkat");                                             //6
    
    Struct1 f;                                            //7
    auto* smaller = f.compare(&p1, &p2);           
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "p1 equals p2, or one of them is nullptr" << std::endl; 
    }
    

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Struct2::t1Update(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.t1Update(updatedValue) << std::endl;
}

        
        
        
        
        
        
        
