#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
set_name("catseye ring");
set_alias("ring");
set_short(HIY+"catseye "+NORM+BOLD+"({})"+HIY+" ring"+NORM);
set_long(
  "This is an amber colored catseye ring.  It has a large stone and\n"+
  "a delicate setting.  It can be worn or bartered for cash.\n");
set_ac(1);
set_params("magical",1,0,0); /* ill */
set_type("ring");
set_weight(1);
set_value(4500);
}

init() {
  ::init();
add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "catseye ring" || str == "ring") {
  if(worn == 1) {
    write("You must remove your "+HIY+"ring"+NORM+" before you can barter it!\n");
    return 1; }
  num = 4800 + random(100);
  write("With a final look at the dazzling catseye, you hand it over\n"+
        "to Sedjak who promptly gives you "+num+" coins for it.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
