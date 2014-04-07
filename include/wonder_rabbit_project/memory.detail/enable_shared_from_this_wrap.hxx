#pragma once

#include <memory>

namespace wonder_rabbit_project
{
  namespace memory
  {

    template<class T_derived, class T_base = void>
    class enable_shared_from_this_wrap: public T_base
    {
    public:
      std::shared_ptr<T_derived> shared_from_this()
      { return std::static_pointer_cast<T_derived>(T_base::shared_from_this_wrap()); }
      
      std::shared_ptr<T_derived const> shared_from_this() const
      { return std::static_pointer_cast<T_derived const>(T_base::shared_from_this_wrap()); }
    };
    
    template<class T_derived>
    class enable_shared_from_this_wrap<T_derived, void>
      : public std::enable_shared_from_this<T_derived>
    {
      using base_type = std::enable_shared_from_this<T_derived>;
    protected:
      std::shared_ptr<T_derived> shared_from_this_wrap()
      { return base_type::shared_from_this(); }
      
      std::shared_ptr<T_derived const> shared_from_this_wrap() const
      { return base_type::shared_from_this(); }
    };
  
  }
}