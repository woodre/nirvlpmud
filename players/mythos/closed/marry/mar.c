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
  if(!find_player(who) || !find_player(spo)) {
    write("????\n");
  return 1;}
  ob=clone_object("/players/bastion/closed/ring.c");
  ob2=clone_object("/players/bastion/closed/ring.c");
  ob->set_owner(who);
  ob->set_spouse(spo);
  ob2->set_owner(spo);
  ob2->set_spouse(who);
  tell_room(environment(this_player()),"\n");
  tell_room(environment(this_player()),
    capitalize(this_player()->query_real_name())+" gestures.\n"+
    "\n"+
    "Mist swirls around "+capitalize(who) +" and "+ capitalize(spo)+"...\n"+
    "From Above all hear the sound of the Silver Horn of Power\n"+
    "heralding the blessed couple in their time of Joining!"+
    "\n\n");
  move_object(ob,find_player(who));
  move_object(ob2,find_player(spo));
  emit_channel("gossip","\nSuddenly firey letters appear in the sky:\n\n"+
              HIR+"\tLet All Rejoice!"+"\n\t"+
              capitalize(who)+" and "+capitalize(spo)+" have been "+
              "joined in Holy Matrimony!\n"+
              "\n"+NORM);
return 1; }
