#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("p'salin");
  set_alias("apothecary");
  set_alt_name("salin");
  set_short("P'salin the Apothecary");
  set_long(
"P'salin is a middle-aged p'kalian, his green hide just beginning\n"+
"to show splotches of brown.  His eyes, on their stalks, are pink\n"+
"and inquisitive.  He wears a loose white cotton robe and leather\n"+
"sandals.  He is the village healer and apothecary.\n"+
"Commands: list, purchase\n"
  );
  set_gender("male");
  set_race("p'kalian");
  set_level(12);
  set_wc(15);
  set_ac(8);
  set_hp(185);
  set_al(450);
  set_chat_chance(3);
  add_money(500+random(200));
  load_chat("P'salin mixes herbs with a mortar and pestle.\n");
  load_chat("P'salin putters about his workshop.\n");
  add_talk("key", "P'salin says: I believe I gave the well key to P'chilik.\n");
  add_talk("p'chilik", "P'salin says: He's good for business.  I often sell potions to the\n"+
                       "\thumans he beats up.\n");
  add_talk("p'salin", "P'salin says: I am well.  Thanks for asking.\n");
  add_talk("p'lila", "P'salin says: Ah, if I were only a few decades younger...\n");
  add_talk("tully", "P'salin says: He is a stupid man who doesn't realize he doesn't belong here.\n");
  add_talk("potions","P'salin says: The secrets of my trade have been passed down\n"+
                     "\tfrom generation to generation.  I cannot say anymore.\n");
}
