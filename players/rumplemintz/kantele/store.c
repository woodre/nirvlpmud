#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        if (!present("money")) {\
      object money;\
     money = clone_object("obj/money");\
      call_other(money, "set_money",1);\
      move_object(money,this_object());\
}

ONE_EXIT("players/kantele/workroom" , "north" ,
         "store room",
        "Kitiaras store room.. \n", 1)
