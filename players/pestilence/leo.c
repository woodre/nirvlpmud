inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("leonardo");
  set_alt_name("turtle");
  set_alias("leo");
  set_race("mutant_turtle");
  set_short(HIB+"Leonardo"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
  set_long(
    "  An ancient ninja turtle, he is one of four that make up the team\n"+
    "of the ninja turtles. He is very well fit in strength and stamina\n"+
    "and is a force to be reckon with if ever attacked. He stays forever\n"+
    "defending the good and honorable in this realm.\n");
  add_money(10000+random(3387));
  set_level(30);
  set_hp(3000+random(100));
  set_al(-800);
    set_chat_chance(4);
  load_chat("Leonardo says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Leonardo says: 'Wow when is the pizza delivery guy gonna get here?!'\n");
  load_chat("Leonardo says: 'Have you seen Master Splinter? \n");
  load_chat("Leonardo says: 'I wonder where my brothers have gone now!'\n");
  set_ac(52+random(4));
  set_wc(70);
  set_heal(40,2);
  set_multi_cast(1);
  add_spell("katana_slash",
  "$HR$Screams$N$ echo from $HB$Leonardo$N$ as he slashes you with inner strength!\n"+
  "$HR$                SSS                                 $N$\n"+
  "$HR$                   LLL                              $N$\n"+
  "$HR$                      AAA                           $N$\n"+ 
  "$HR$                         SSS                        $N$\n"+
  "$HR$                            HHH                     $N$\n",
  "#MN# screams as he grabs his katana slashing with a deep inner strength!\n",
75,100,0,0);
   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lundges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused!\n", 
   "Room Message",
75,100,0,0);
   }
