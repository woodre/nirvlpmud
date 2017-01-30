inherit "obj/weapon";
#include "/players/persephone/rooms.h"
reset (arg){
 set_name("bat");
 set_alias("wiffle bat");
 set_short("A Wiffle Waffle Bat");
 set_long("This is a legendary Wiffle Waffle Bat tm. Despite its looks\n" +
          "it is great for bashing monsters over the head with\n\n");
 set_class(17);
 set_weight(2);
 set_value(2500);
 set_hit_func(TOB);
 set_save_flag(0);
}
