/**********************************************
| mugger for high/room/nystreet.  invis, but will
| occasionally make a half-hearted attempt to accost
| players for money.
********************************************/
inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  if(!present("knife",this_object())) {
    move_object(clone_object(HOBJ+"mknife"),this_object());
    init_command("wield knife");
  }
  if(!present("amulet",this_object())) {
    move_object(clone_object(HOBJ+"wamulet"),this_object());
  }
  set_name("mugger");
  set_race("human");
  set_long(
"A filthy man of indeterminate age adept in hiding in the\n"+
"shadows along the wall.  He seems to cower away from you, but a glint\n"+
"in his eyes speaks of greed he'd alleviate if he could.\n");
  set_level(7);
  set_hp(105);
  set_wc(11);
  set_ac(6);
  set_al(-200);
  set_gender("male");
}
short() { return 0; }
init() {
  ::init();
  call_out("hey_buddy",0);
}
hey_buddy() {
  if(!environment()) return;
  tell_room(environment(),
"A figure in the shadows you hadn't noticed speaks up:\n"+
"\"Hey buddy, spare some change?\"\n"+
capitalize(query_pronoun())+
" shifts slightly, and you see a knife.  It appears you\n"+
"have found a mugger.\n");
}
