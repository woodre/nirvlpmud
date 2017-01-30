#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Master Skritt");
  set_alt_name("master");
  set_alias("skritt");
  set_short(HIK+"Master Skritt"+NORM);
  set_long("\
A deadly assassin, steeped in the ways of his clan.  Master Skritt\n\
has traveled far and wide perfecting his art, even now he trains  \n\
those select few he deems worthy.  Garbed in black robes, a dark  \n\
shadowed hooded cloak and a dark cowl that hides his rat like face\n\
leaving only his haggard whiskers and nose protruding.  His teeth \n\
have been sharpened to fine points and his incisors resemble razor\n\
sharp chisels.  His pawed hands are swathed in similar cloth to  \n\
his body and sport wickedly pointed talons.                       \n");
  set_gender("male");
  set_race("skaven");
  set_level(27);
  set_wc(58);
move_object(clone_object("/players/khrell/armors/skaven/acowl.c"));
init_command("wear cowl");
move_object(clone_object("/players/khrell/armors/skaven/warpamulet.c"));
init_command("wear amulet");  
  set_ac(30);
  set_hp(1500);
  set_heal(20,2);
  set_al(-1000);
  set_aggro(1, 10, 100);
  add_money(10000);  

  set_chat_chance(10);
  load_chat(HIK+"Master Skritt"+NORM+" slaps you upside the head and sneers.\n");
   
  set_a_chat_chance(20);
  load_a_chat(HIK+"Master Skritt"+NORM+" dodges your attack with ease.\n");
  load_a_chat(HIK+"Master Skritt"+NORM+" sidesteps your attack.");
  load_a_chat(HIK+"Master Skritt"+NORM+" squeaks: Die-die!");
  load_a_chat("You reel from the attack!");
  
  set_multi_cast(1);
  
  add_spell("shuriken tempest",
  "A number of $G$warpstone$N$ shuriken slice into you!\n",
  "#MN# becomes a blur of motion as it spins suddenly about releasing many glittering $G$shrukien$N$!\n",
  20,({60,60}),({"other|physical","other|poison"}),1);
}

stop_move(){
if(this_player()->query_ghost()) return;
write(HIK+"Master Skritt"+NORM+" jumps in your way blocking the exit!\n");
return 1;
}
init(){
::init();
add_action("stop_move", "exit", 1);
}

monster_died() {
  tell_room(environment(this_object()),
  "\n"+HIK+"Master Skritt"+NORM+" gurgles and coughs up dark "+RED+"blood"+NORM+" staggers then collapses dead!\n");
    return 0; 
}
