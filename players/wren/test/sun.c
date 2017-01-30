	/*   a small sun, cause i keep wondering into dark rooms 
             and the light on wiz_tool didn't work   */

#include <ansi.h>
inherit "/obj/treasure";

reset(arg)  {
     set_id("sun");
     set_alias("light");
     set_short(HIY+"a small sun"+NORM);
     set_weight(1000);
     set_value(1);
     set_light(10);
     set_long("A medium sized yellow star.\n");

}


