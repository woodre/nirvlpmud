#include "/players/snow/dervish/def.h"

scatter(str) {
  object ob;
  int num, mult;
  ob = present("corpse", environment(TP));
  if(!ob) ob = present("corpse", TP);
  if(!ob) {
   notify_fail("There is no corpse present.\n"); return 0; }
  num = ob->heal_value();
  write("You lift the "+ob->short()+" into the air.\n\n");
  say(TP->query_name()+" lifts the "+ob->short()+" into the air.\n\n");
  tell_room(environment(TP),BOLD+"\tA WHIRLWIND APPEARS BEFORE YOU!\n\n"+OFF);
  tell_room(environment(TP),"Sand swirls away...\n");
  destruct(ob);
  if(str && (str == "to the sand" || str == "to the sands")) {
    present(GID, TP)->add_sand_points(num*(random(10)+1));
    write(BOLD+"\nThe Sand receives your sacrifice.\n\n"+OFF); return 1; }
  TP->heal_self(num);
  return 1; }
