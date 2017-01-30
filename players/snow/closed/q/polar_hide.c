/* Polar Bear Hide found on ~/MONSTERS/polar_bear.c */

inherit "/obj/armor";
#define TP this_player()
#define TO this_object()
#define ENV environment
#define TPN TP->query_name()
#define TPRN TP->query_real_name()

#include "/players/snow/closed/cyber/color.h"

reset(arg){
   ::reset(arg);
   set_name("polar hide");
   set_short("A polar bear hide");
   set_alias("hide");
   set_long(
"This is the hide of a polar bear. It is dazzlingly white in some parts and\n"+
"hideously bloody in others. It is very thick and looks like it would \n"+
"provide good protection against blows. It also looks like you could eat it\n"+
"if you were in really bad shape...\n");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(5000);
}

init() {
  ::init();
  add_action("eat_hide","eat");
  add_action("reanimate","reanimate");
   }

eat_hide(str) {
  if(!str) { write("Eat what?\n"); return 1; }
  if(str != "hide") { notify_fail("Eat what?\n"); return 0; }
  if(str == "hide") {
    say(TPN+" gnaws a polar bear hide to shreds!\n"+
        capitalize(TP->query_possessive())+" body seems to heal.\n");
    write("You gnaw the polar bear hide to shreds!\n"+
          "Your body loses almost all trace of wounds!\n");
    TP->heal_self(200);
    if(TO->worn()) command("remove hide", TP);
    destruct(TO);
    return 1;
   }
}

reanimate() {
  object soul, sphere;
  soul = present("vampire soul", TP);
  sphere = present("ice sphere", TP);
  if(!soul || !sphere) return 0;
  write("You press the vampire soul and the ice sphere into\n"+
        "the polar bear hide...\n\n");
  destruct(soul); destruct(sphere);
  if(TO->worn()) {
    write("You are wearing the hide as it animates!\n\n");
    TP->hit_player(80);
    write("The reanimation fails.\n");
    return 1; }
  tell_room(ENV(TP),
      BOLD+" Ursa Major, the Bear Spirit appears!"+OFF+"\n");
  write("\n\n  The Bear Spirit enfolds you in its great arms..\n\n");
  say(TPN+" is enfolded in the Bear Spirit's great arms..\n");
  move_object(TP, "/room/church.c");
  TP->set_quest("Ursa");
  write_file("/players/snow/closed/q/ursa_complete",
    ctime(time())+" "+TPRN+" completed the Ursa Quest.\n");
  write("You have completed the Ursa Major quest!\n");
  command("look", TP);
  destruct(TO);
  return 1;
}

quest_ob() { return 1; }
