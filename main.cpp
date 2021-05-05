#include <iostream>
#include "ManoVector.h"
#include <vector>
#include <chrono>

void VectorTestFuncs();
void emplacetest();
void memberswaptest();
void nonmemberswaptest();
void shrink_to_fittest();
void crendtest();
void push_backtest(int amt);
void orgpush_backtest(int amt);

//clockStart = std::chrono::steady_clock::now();
//accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
std::chrono::steady_clock::time_point clockStart;
double accumulatedTime;

int main()
{
    //VectorTestFuncs();
    
    int sizearr[5] = { 10000, 100000, 1000000, 10000000, 100000000};
    
    for(int i = 0; i < 5; i++)
    {
        push_backtest(sizearr[i]);
        orgpush_backtest(sizearr[i]);
    }
    
    VectorTestFuncs();
    return 0;
}

void VectorTestFuncs()
{
    
    emplacetest();
    memberswaptest();
    nonmemberswaptest();
    shrink_to_fittest();
    crendtest();
}

void emplacetest()
{
  ManoVector<int> myvector = {10,20,30};

  auto it = myvector.emplace ( myvector.begin()+1, 100 );
  myvector.emplace ( it, 200 );
  myvector.emplace ( myvector.end(), 300 );

  std::cout << "myvector contains:";
  for (auto& x: myvector)
    std::cout << ' ' << x;
  std::cout << '\n';
    
  std::cout << "Expected result: 10 200 100 20 30 300" << std::endl << std::endl;
}

void memberswaptest()
{
  std::cout << std::endl;
  ManoVector<int> foo (3,100);   // three ints with a value of 100
  ManoVector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
  
  std::cout << "Expected result:" << std::endl << "foo contains: 200 200 200 200 200" << std::endl << "bar contains: 100 100 100" << std::endl << std::endl;
}

void nonmemberswaptest()
{
  unsigned int i;
  ManoVector<int> foo (3,100);   // three ints with a value of 100
  ManoVector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ManoVector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ManoVector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
    
    std::cout << "Expected result:" << std::endl << "foo contains: 200 200 200 200 200" << std::endl << "bar contains: 100 100 100" << std::endl << std::endl;
}

void shrink_to_fittest()
{
  ManoVector<int> myvector (100);
  std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

  myvector.resize(10);
  std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

  myvector.shrink_to_fit();
  std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
    
  std::cout << "Expected result:" 
  << std::endl << "1. capacity of myvector: 100"
    << std::endl << "2. capacity of myvector: 100" 
        << std::endl << "3. capacity of myvector: 10" << std::endl << std::endl;
}

void crendtest()
{
  ManoVector<int> myvector = {1,2,3,4,5};

  std::cout << "myvector backwards:";
  for (auto rit = myvector.crbegin(); rit != myvector.crend(); ++rit)
    std::cout << ' ' << *rit;
  std::cout << '\n';
  
  std::cout << "Expected result: myvector backwards: 5 4 3 2 1" << std::endl << std::endl;
}

void push_backtest(int amt)
{
    clockStart = std::chrono::steady_clock::now();
    
    int cnt = 0;
    ManoVector<int> vect;
    
    for(int i = 0; i < amt; i++)
    {
        vect.push_back(i);
        if(vect.capacity() == vect.size()) cnt++;
    }
        
    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    std::cout << "Darbas su ManoVector " << amt << " implementacija truko: " << timeTaken << "s" << " ir ivykde " << cnt << " atminties perskirstymus!" << std::endl;
}

void orgpush_backtest(int amt)
{
    clockStart = std::chrono::steady_clock::now();
    
    int cnt = 0;
    std::vector<int> vect;
    
    for(int i = 0; i < amt; i++)
    {
        vect.push_back(i);
        if(vect.capacity() == vect.size()) cnt++;
    }
    
    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    std::cout << "Darbas su originalia vector " << amt << " implementacija truko: " << timeTaken << "s" << " ir ivykde " << cnt << " atminties perskirstymus!" << std::endl;
}