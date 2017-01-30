#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("belinda");
  set_alt_name("waittress");
  set_short("Belinda the Waittress");
  set_long(
"Belinda practically lights up the room with her smile.  Her skin\n"+
"is a healthy bronze color, her hair, which is tied up in a braid,\n"+
"is a pale yellow and her eyes are like twin pools of cool water.\n"+
"She wears a low-cut skirt and carries a wooden tray.\n");
  set_gender("female");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(350);
  add_money(500+random(100));
  set_chat_chance(5);
  load_chat("Belinda hurries among the tables serving drinks.\n");
  load_chat("Belinda stops a moment to gossip with a group of young men.\n");
  load_chat("Belinda acknowledges a wolf whistle from the peanut gallery\n"+
            "with a smile and a blown kiss.\n");
  load_chat("Belinda smiles brightly as she walks back and forth among\n"+
            "the patrons.\n");
}

