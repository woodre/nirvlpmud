#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  add_money(500+random(100));
  set_name("armorer");
  set_alt_name("guard");
  set_short("An armorer");
  set_long(
    "This huge old man is the Goldcloak armorer.  He has served the\n"+
    "Goldcloaks for a long time and has become a little senile.  If\n"+
    "you can fool him into thinking you're a Goldcloak, then he\n"+
    "might be willing to 'sharpen' your weapon for you.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(650);
  set_chat_chance(5);
  load_chat("The armorer hums to himself.\n");
  load_chat("The armorer says: Do I know you?\n");
}

void init() {
  ::init();
  add_action("cmd_sharpen","sharpen");
}

cmd_sharpen(str) {
  object cloak;
  object wep;
  cloak=present("gold cloak",TP);
  if(!cloak || !cloak->query_worn()) {
    notify_fail("The armorer says: I only work for Goldcloaks.\n");
    return 0;
  }
  if(!str) {
    notify_fail("Sharpen what?\n");
    return 0;
  }
  wep=present(str,TP);
  if(!wep) {
    notify_fail("The armorer says: You don't have one of those.\n");
    return 0;
  }
  if(!wep->weapon_class()) {
    notify_fail("The armorer says: That is not a weapon.\n");
    return 0;
  }
  if(wep->query_wielded())
    command("unwield "+str,TP);  
  wep->set_hits(1);
  wep->set_misses(1);
  write("The armorer hones your "+wep->short()+" for you.\n"+
        "\t\"There you go!  Just like new.\"\n");
  TP->remote_say("The armorer hones "+TPN+"'s weapon.\n");
  return 1;
}
  
