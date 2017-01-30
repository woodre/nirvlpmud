#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("balkeen");
set_alt_name("armor_owner");
set_alias("armorer");
set_race("human");
set_short("Balkeen the Templar Armorer");
set_long(
"  Before you is a man that stands nearly seven feet tall. He has a huge\n"+
"barrel chest and his arms are strong and well muscled. Deep scars line\n"+
"both arms, with several dark burn marks along the forearms. He is dressed\n"+
"in a loose fitting tunic.\n");

set_level(10);
set_hp(225);
set_al(800);
set_wc(19);
set_ac(10);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Balkeen says: Greetings.\n");
  load_chat("The armorer polishes a heavy shield.\n");
  load_chat("Balkeen says: How may I serve you today?\n");
set_a_chat_chance(15);
  load_a_chat("Balkeen growls: You will die!!!\n");
  load_a_chat("Armorer swings a heavy hammer at you!\n");
gold = clone_object("obj/money");
gold->set_money(200);
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
"Balkeen bows low to you.\n");
return 1;
}