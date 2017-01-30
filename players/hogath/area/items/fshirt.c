#include <ansi.h>

inherit "obj/armor";

reset(arg)
{
    ::reset(arg);
    set_short(HIC+"F"+HIR+"i"+HIG+"n"+HIM+"e"+HIB+" S"+HIW+"h"+NORM+"i"+BOLD+"r"+HIC+"t"+NORM);
    set_long(
"This is a Ulatha's Shirt.  It is hand woven and looks\n"+
"like a lot of care went into it's creation.  It is really\n"+
"colorful.\n");
    set_ac(2);
      set_value(150);
      set_alias("shirt");
      set_name("shirt");
      set_type("chest");
      set_weight(1);
      } 


        
