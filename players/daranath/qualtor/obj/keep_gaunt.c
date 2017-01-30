#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("gauntlets");
   set_short("A pair of Powered Gauntlets");
   set_alias("gauntlet");
   set_long("A pair of dark red gauntlets that belonged to the Keeper of\n"+
            "the Red Tower, these gauntlets hum with a life of their\n"+
            "own. A magical energy pulses throughout them, although you\n"+
            "cannot seem to harness it.\n");
   set_type("gloves");
   set_ac(1);
   set_weight(2);
   set_value(950);
   set_params("other|water",       2,0,"water_special");
}

int water_special(object ob)
{
  if(!random(5))
    tell_object(ob, BOLD + "Your gauntlets absorbs some of the water damage.\n" + NORM);
}
