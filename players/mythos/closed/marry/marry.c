#include "/players/mythos/closed/ansi.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("amulet");
    set_short("A small "+RED+"ruby"+NORM+" amulet");
    set_long("The power to 'grant' rings of marriage is hidden\n"+
      "within the depths of this ruby amulet.\n");
    set_weight(0);
    set_value(0);
}
init() {
  ::init();
  add_action("grant","grant");
}

grant(str) {
object ob, ob2;
string who, spo;
  sscanf(str,"%s %s",who,spo);
  ob=clone_object("/players/bastion/closed/ring.c");
  ob2=clone_object("/players/bastion/closed/ring.c");
  ob->set_owner(who);
  ob->set_spouse(spo);
  ob2->set_owner(spo);
  ob2->set_spouse(who);
  say("\n");
  say(capitalize(this_player()->query_real_name())+" gestures.\n"+
    "\n"+
    "Two tiny mist "+BLU+"dragons"+NORM+" fly in and entwine\n"+
    "themselves around the couple's ring fingers.\n"+
    "The dragons solidify into two "+BLU+"rings"+NORM+"!\n\n");
  move_object(ob,find_player(who));
  move_object(ob2,find_player(spo));
  emit_channel("gossip",HIR+"	 "+capitalize(who)+" and "+capitalize(spo)+" are now married"+"!\n"+
  "	 Let all rejoice!\n"+NORM);
  write(HIR+"You have married "+capitalize(who)+" and "+capitalize(spo)+"!\n"+
  "Let all rejoice!\n"+NORM);
return 1; }
