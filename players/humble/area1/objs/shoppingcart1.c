#include "../defs.h"

    inherit "obj/treasure";

reset(arg)
{
    ::reset(arg);
    set_short(HIW+"A shopping cart"+NORM);
    set_long(
    HIW+"This is a shopping cart. At the front there is a button attatched to the cart.\n"+NORM+
    HIW+"It reads "+HIY+"Q F C."+HIW+" It's pretty much useless.\n"+NORM);
    set_value(200);
    set_alias("cart");
    set_name(HIW+"A shopping cart"+NORM);
    set_weight(20);
      } 


        
