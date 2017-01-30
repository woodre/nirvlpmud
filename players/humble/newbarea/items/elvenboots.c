#include "../defs.h"

inherit "obj/armor";

reset(arg)
{
    ::reset(arg);
    set_short(HIG+"Elven Boots"+NORM);
    set_name(HIG+"Elven Boots"+NORM);
    set_ac(1);
    set_value(35);
    set_type("boots");
    set_weight(1);
    set_long(HIW+"These are knee high elven boots made from leather and\n"+NORM+
    HIW+"twine.  They aren't very comfortable and seem incredibly thin, as you\n"+NORM+
     HIW+"can feel rocks beneath your feet pretty well.  They are however very light.\n"+NORM);
      } 
