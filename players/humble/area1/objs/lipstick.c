#include "../defs.h"

inherit "obj/treasure";

reset(arg)
{
    ::reset(arg);
    set_short(RED+"Alice's Lipstick"+NORM);
    set_long(
     HIW+"A small brass container that splits into two.  Just like chapstick, one has the cover\n"+NORM+
    HIW+"and the other side has thw twisty thing and the red lipstick.\n"+NORM+
    HIW+"Alice uses this to put on her lipstick inbetween, doing everything!\n"+NORM);
    set_alias("lipstick");
    set_value(1200);
    set_name(RED+"Alice's Lipstick"+NORM);
      set_weight(1);
      } 


        
