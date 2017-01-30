/* This is from Fred's area. */
#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("helmet");          
  set_short(RED+"Small"+NORM+BOLD+" helmet"+NORM);
  set_long(
  "  A tiny little helmet used by the fighting\n"+
  "paratrooping squirrels of the "+BOLD+"Crazed Forest"+NORM+".\n"+
  "It is much to small for you to wear.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(150);
}
  
init(){
  ::init();
    add_action("wearem", "wear");
  }

wearem(str){
if(str == "helmet") {write("You can't wear this helmet, sorry.\n"); return 1; }
else { return 0; }
}

