#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tailor");
  set_alt_name("tommy");
  set_short("Tommy Taylor the Tailor");
  set_long(
"Tommy is an obseqious man in his mid-thirties with a stooped back\n"+
"and a craven demeanor.  He carries a needle, thread, and some measuring\n"+
"tape which leads you to believe he might do something dealing with\n"+
"clothes.  You can suggest new clothes for him to make by typing:\n"+
"'idea I think you should make _______'\n");
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(155);
  set_al(350);
  set_chat_chance(4);
  load_chat("Tommy the Tailor says: Can I help you?\n");
  load_chat("Tommy the Tailor putters about his shop.\n");
}
