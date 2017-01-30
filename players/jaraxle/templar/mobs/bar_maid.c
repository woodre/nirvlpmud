#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("christana");
set_alt_name("bar_maid");
set_alias("maid");
set_race("human");
set_short("Christana the Serving Maid");
set_long(
"  Standing before you is a beautiful serving girl. Her\n"+
"clothes are of the finest quality, and her mood the\n"+
"liveliest.  Her blonde hair falls about her narrow\n"+
"shoulders.  She has a wonderful smile that makes you\n"+
"feel right at home.\n");

set_level(3);
set_hp(55);
set_al(500);
set_wc(6);
set_ac(2);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Christana smiles and says: Greetings, how may I serve you?\n");
  load_chat("The serving maid carries a tray over to a table.\n");
  load_chat("You smell delicious food as it wafts from the kitchen.\n");
gold = clone_object("obj/money");
gold->set_money(20);
move_object(gold,this_object());
}

init(){
::init();
if(present("KnightTemplar", this_player())){
call_out("bow_motion", 3, this_player());
  }
}


bow_motion(object who){
if(!present(who, environment())){
return 1;
}
tell_object(who,
"Christana smiles and bows low to you.\n");
return 1;
}
