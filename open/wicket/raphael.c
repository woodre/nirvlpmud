inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
object katana;

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  move_object(clone_object("/players/wicket/rsai.c"),
        this_object());
  command("wield");
        katana=clone_object("/players/wicket/rsai.c"),
        move_object(katana, this_object());
  katana->offwield( this_object() );
  set_name("raphael");
  set_alt_name("turtle");
  set_alias("raph");
  set_race("mutant_turtle");
  set_short(HIR+"Raphael"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
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
  load_chat("Raphael says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Raphael says: 'Stupid pizza guy, I'm hungry I wish he would Hurry up!'\n");
  load_chat("Raphael says: 'Where is Master Splinter? \n");
  load_chat("Raphael says: 'I wonder where my numb skull brothers have gone now!'\n");
  set_ac(22+random(4));
  set_wc(70);
  set_heal(10,5);
  set_multi_cast(1);
  add_spell("sai_stab",
  "$HR$Screams$N$ echo from $HR$Raphael$N$ as he stabs you with inner strength!\n"+
  "$HR$                >>>                                 $N$\n"+
  "$HR$                   >>>                              $N$\n"+
  "$HR$         >>>Blood Sprays Everywhere<<<              $N$\n"+ 
  "$HR$                         <<<                        $N$\n"+
  "$HR$                            <<<                     $N$\n",
  "#MN# screams as he grabs his sai stabbing with a deep inner strength!\n",
75,100,0,0);
   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lundges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused$N$!\n",
   "Room Message\n",
75,100,0,0);
   }
