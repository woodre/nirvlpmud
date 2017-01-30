#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("fastiticalon");
set_alias("creature");
set_race("fish");
set_short(YEL + "Fastiticalon" + OFF);
set_long(
"The larger and uglier hybrid of the Fastiticalon species, this fish \n" +
"shares many traits with its smaller cousins.  Orange and gold in colour, \n" +
"it lives in the sand instead of the water.  It can attack with both its \n" +
"fins and mouth and is extremely vicious.\n");

set_level(18);
set_hp(450);
set_al(10 - random(20));
set_wc(28);
set_ac(16);
set_heal(4,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
load_chat("The fish glides gracefully through the sand.\n");
set_a_chat_chance(10);
load_a_chat("Fastiticalon lunges at you, taking a pound of flesh.\n");

}

heart_beat()
{
     int x; object *inv;
     ::heart_beat();
     if(!attacker_ob)
     {
     inv = all_inventory(environment(this_object()));
        for(x=0;x<sizeof(inv);x++)
        {
           if(inv[x]->id("fastiticalon-F") && inv[x]->query_attack())
           {
              tell_room(environment(this_object()), "Fastiticalon leaps to attack you!\n");
              attack_object(inv[x]->query_attack());
              return 1;
           }
        }
     }
}
monster_died()
{
	move_object(clone_object("/players/laera/balamb/beach/obj/crystal.c"),
      environment(this_object()));
    move_object(clone_object("/players/laera/balamb/beach/obj/crystal.c"),
      environment(this_object()));
   	tell_room(environment(this_object()),
     YEL+"Fastiticalon rises from the sand and collapses in a heap.\n"+OFF);
   return 0;
}
