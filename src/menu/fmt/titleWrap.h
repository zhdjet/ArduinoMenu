/* -*- C++ -*- */
#pragma once
/**
* @author Rui Azevedo
* @brief ArduinoMenu format, wrap the title between characters, default: '[' ']'
*/

#include <menu.h>

// namespace Menu {
  template<typename O,char open='[',char close=']'>
  struct TitleWrapFmt:public O {
    template<bool io,typename I,typename Out,typename Nav>
    static inline void fmtTitle(Idx n,Nav& nav) {
      if (io) {
        Out::raw(open);
        O::template fmtTitle<io,I,Out,Nav>(n,nav);
      } else {
        O::template fmtTitle<io,I,Out,Nav>(n,nav);
        Out::raw(close);
      }
    }
  };
// };
