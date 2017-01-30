#include <ansi.h>
inherit "/obj/treasure.c";
#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

reset(arg){
  if(arg) return;
  set_id("budweiser");
  set_alias("bud");
  set_short("a 12 ounce bottle of "+RED+"bud"+BLU+"wei"+WHT+"ser"+NORM+"");
set_long(
"This is a twelve ounce bottle of "+RED+"bud"+BLU+"wei"+WHT+"ser"+NORM+".\n"+
"It looks like it would go down nice and easy.\n");
  set_value(500);
  set_weight(2);
}
init () {
   ::init() ;
     add_action ("drink_bud","drink");
     }

drink_bud(str) {
if(!id(str)) { notify_fail("Drink what?\n");
 return 0; }
if (!call_other(this_player(), "drink_alcohol", 17)) {
  write("You appear to be too drunk to have anymore.\n");
  return 1;
}
     this_player()->heal_self(50);
     write("You drink down a "+RED+"bud"+BLU+"wei"+WHT+"ser"+NORM+".\n"+
           "<<<< HP "+HP+"/"+MHP+" SP "+SP+"/"+MSP+" >>>>\n");
     destruct(this_object());
     this_player()->recalc_carry();
     return 1;
}
id(str) { return (::id(str) || str == "beer" || str == "bottle"); }
