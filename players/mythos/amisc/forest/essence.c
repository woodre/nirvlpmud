#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("essence");
    set_alias("sheet");
    set_short("A beautiful white sheet of spirit essence");
    set_long("Spirit essence.  'sell to trader' and see what you\n"+
       "can get for it.....though...legend says that\n"+
       "hidden powers lie within.\n");
    set_weight(4);
    set_value(5000);
}

init() {
  ::init();
  add_action("ssell","sell");
  add_action("invoke","invoke");
}

ssell(str) {
int nm;
  if(str == "to trader") {
  nm = 4000 + random(2000);
  write("You sell the essence to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}

invoke() {
  if(pp) {
    write("You invoke the powers within the Spirit Essence!\n");
    write("It flares and suddenly you feel power erupt from it!\n");
    pp->set_ward(1);
    pp->save_dark();
    command("uu",tp);
    write("The power to ward versus demons and spirits infuses you!\n"+
          "To use type <ward <direction>  (direction is optional)>\n");
    destruct(this_object());
    return 1;}
}
