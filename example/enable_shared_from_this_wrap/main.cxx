#include <iostream>

#include <wonder_rabbit_project/memory.hxx>

namespace
{
  using wonder_rabbit_project::memory::enable_shared_from_this_wrap;
  
  class A
    : public enable_shared_from_this_wrap<A>
  {
  public:
    auto virtual f() -> void { std::cerr << "hello, "; }
  };
  
  class B
    : public enable_shared_from_this_wrap<B, A>
  {
  public:
    auto f() -> void override { std::cerr << "world!\n"; }
  };
}

auto main() -> int
{
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  
  a->shared_from_this()->f();
  b->shared_from_this()->f();
  
  std::cerr
    << typeid(a).name() << "\n"
    << typeid(b).name() << "\n"
    ;
}