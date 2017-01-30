#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("ngana");
  set_alias("prince");
  set_short("Prince Ngana");
  set_long(
"     Prince Ngana is a tall, handsome man in his early twenties\n"+
"with curly hair and a broad chest.  His eyes appear intelligent\n"+
"and yet his smile is insidiously infectious.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(75);
  set_al(50);
}

