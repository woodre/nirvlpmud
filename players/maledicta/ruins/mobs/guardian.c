#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object anhk;
  ::reset(arg);
  if(arg) return;

set_name("guardian");
set_alias("twilight");
set_race("darkling");
set_short(""+BOLD+""+BLK+"Guardian"+NORM+" "+BLU+"of Twili"+BOLD+""+BLU+"ght"+NORM+"");
set_long(
  "  This four-legged monstrosity stands blocking further passage\n"+
  "into the ruins. Its head is covered with thick plates of scaly\n"+
  "armor, as well as its chest and forelegs. The remaining parts\n"+
  "of this beast have long thick red hair growing from it, the\n"+
  "strands clinging together from dried blood and other gore that\n"+
  "has collected on it. Its eyes are of deep blue, seemingly out\n"+
  "of place for such a creature, you look into them and feel peace\n"+
  "even while at the same time your heart races in fear. It is\n"+
  "shackled to the floor by thick rusted chains. Something shiny\n"+
  "hangs from its neck.\n");

set_level(20);
set_hp(650);
set_al(1000);
set_wc(32);
set_ac(10);
set_aggressive(0);
set_chat_chance(15);
  load_chat("Guardian looks at you closely.\n");
  load_chat("Guardian pulls at its shackles.\n");
set_a_chat_chance(15);
  load_a_chat("Guardian unleashes a roar as it slams you!\n");
  load_a_chat("Guardian ROARS!\n");
  

set_chance(10);
set_spell_dam(20);

set_spell_mess1(
  "Guardian strikes its victim, drawing deep lines of"+BOLD+""+RED+" BLOOD"+NORM+".\n");
set_spell_mess2(
  "\n\n\n"+BOLD+""+RED+"Guardian"+NORM+" claws at you, drawing deep lines of blood!\n\n\n");
anhk = clone_object("/players/maledicta/ruins/obj/anhk.c");
move_object(anhk, this_player());
}

init(){
    ::init();
    
   
    add_action("no_move", "east");
       
}


no_move(){
	write(
	"Guardian moves to block you!\n"
	);
	return 1;
}
	