inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
/******************************************************************************
 * Program: splinter.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: Sat Oct  4 08:21:17 2014 CST by Wicket
 *
 * Special Abilities:
 *  1. Multi cast with high damage / high % spells.
 *  2. Once Attacked he stops you from running.
 *  3. Has 3 spells for damage.
 *  Want it place in: /players/airwoman/sewage/room3.c
 ******************************************************************************/

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/ninja_turtles/weapons/hamato.c"), this_object()); 
  command("wield hamato", this_object());
  move_object(clone_object("/players/wicket/ninja_turtles/armor/robe.c"), this_object());
  command("wear robe", this_object());
  move_object(clone_object("/players/wicket/ninja_turtles/obj/wstick.c"), this_object());

  set_name("splinter");
  set_alt_name("master");
  set_race("mutant rat");
  set_alias("master splinter");
  set_short(RED+"Master Splinter"+NORM+", the "+BOLD+"Ancient Sensei"+NORM+" to the "+HIR+"Ninja"+NORM+GRN+" Turtles"+NORM);
  set_long("\
   An old and tired mutant rat. He is the Sensei of the ancient ninja turtles.\n\
  He has been around for ages and is very knowledgeable in the arts of ninjutsu and\n\
  the form of Hamato ninjutsu in general. He looks very tired and is wearing an\n\
  old, dusty, woven, red robe that ties in the front and uses a cane staff to assist\n\
  him when he walks.\n");
 
  set_level(22);
  set_hp(700);
  set_ac(15);
  set_wc(38);
  set_al(0);
  set_chat_chance(9);
  load_chat("Master Splinter says: 'Focus and balance the inner chi. This will make things clear.\n");
  load_chat("Master Splinter says: 'Where have those young Turtles gone now?'\n");
  load_chat("Master Splinter says: 'You must first master self control before you can become stronger.'\n");
  load_chat("Master Splinter says: 'The way to master Ninjutsu is not only in body, but also in mind!'\n");
  add_money(random(3500)+1500);
  set_heal(75,2);
  set_multi_cast(2);
    add_spell("cane_whack",
  "$HK$#MN#$N$ shakes his head as he whacks you with his cane for your stupidity\n"+
  "$HK$                >>>BANG<<<                          $N$\n"+
  "$HK$                   >>>CRASK<<<                      $N$\n"+
  "$HK$         >>>THWACK<<<                               $N$\n"+ 
  "$HK$                   >>>CRUSH<<<                      $N$\n"+
  "$HK$             >>>WOOSH<<<                            $N$\n",
  "$HK$#MN#$N$ shakes his head as he smacks #TN# with his cane for #TP# stupidity!\n",
75,100,0,0);
   add_spell("pressure_shock", 
   "$HK$#MN#$N$ lunges forward and$HR$ G R A B S$N$ you, applying pressure to your neck!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$dazed$N$ and $HG$confused$N$!\n",
   "$HK$Splinter$N$ lunges forward and $HR$ G R A B S$N$ #TN# applying pressure to the neck!\n",
75,100,0,0);
    add_spell("hip_thow",
  "$HK$Splinter$N$ steps back as he grabs your shoulders. He rolls and flips you over him.\n"+
  "$HK$       CCC               BBB              TTT                $N$\n"+
  "$HK$          RRR              OOO              HHH              $N$\n"+
  "$HK$             AAA              OOO              UUU           $N$\n"+ 
  "$HK$                SSS              MMM             DDD         $N$\n"+
  "$HK$                  HHH                                        $N$\n",
  "#MN# steps back as he grabs #TN#'s shoulders. He rolls and flips #TN# over him.\n!\n",
75,100,0,0);
}

stop_move(){
  if(this_player()->query_ghost()) return;
  if( attacker_ob ) {
    write(RED+"Master Splinter"+NORM+" jumps in your way blocking the exit!\n");
    return 1;
  }
  return 0;
}
init(){
::init();
add_action("stop_move", "west", 1);
}
