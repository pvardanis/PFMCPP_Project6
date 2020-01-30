/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
#include <assert.h>

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
        assert (a != nullptr && b != nullptr);
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float t1 { 0 }, t2 { 0 };
    float t1Update(float* t1_)      //12
    {
        assert (t1_ != nullptr);
        std::cout << "U's t1 value: " << t1 << std::endl;
        t1 = *t1_;
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
    static float t1Update(U* that, float* t1_ )        //10
    {
        assert (that != nullptr && t1_ != nullptr);
        std::cout << "U's t1 value: " << that->t1 << std::endl;
        that->t1 = *t1_;
        std::cout << "U's t1 updated value: " << that->t1 << std::endl;
        
        while( std::abs(that->t2 - that->t1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            if (that->t2 > that->t1)
            {
                // std::cout << "WOW" << std::endl;
                that->t1 += 0.001f;
            }
            else
            {
                that->t2 += 0.001f;
            }            
        }
        std::cout << "U's t2 updated value: " << that->t2 << std::endl;
        std::cout << "t1: " << that -> t1 << "t2: " << that -> t2 << std::endl;
        return that->t2 * that->t1;
    }
};
        
int main()
{
    T p1(4.5f, "Panos");                                             //6
    T p2(3.2f, "Matkat");                                             //6
    
    Struct1 f;                                            //7
    auto* smaller = f.compare(&p1, &p2);           
    assert (smaller != nullptr);
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Struct2::t1Update(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.t1Update(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        
