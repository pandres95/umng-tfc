#ifndef TAB_H_DEFINED
#define TAB_H_DEFINED

#include <iostream>

namespace std {
  template <typename _CharT, typename _Traits>
  inline basic_ostream<_CharT, _Traits> &
  tab(basic_ostream<_CharT, _Traits> &__os) {
    return __os.put(__os.widen('\t'));
  }
}

#endif // TAB_H_DEFINED
