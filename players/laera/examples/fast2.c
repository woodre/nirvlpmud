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
set_short(YEL + "Fastiticalon-F" + OFF);
set_long(
"The smaller hybrid of the Fastiticalon species, this fish shares many\n" +
"traits with its bigger cousins.  Orange and gold in colour, it lives in\n" +
"the sand instead of the water.  It can attack with both its fins and\n" +
"mouth and is extremely vicious.\n");

set_level(14);
set_hp(210);
set_al(70);
set_wc(18);
set_ac(11);
set_heal(4,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
load_chat("The fish glides gracefully through the sand.\n");
set_a_chat_chance(10);
load_a_chat("Fastiticalon lashes at you, ripping through your skin with its teeth.\n");

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
           if(inv[x]->id("fastiticalon") && inv[x]->query_attack())
           {
              tell_room(environment(this_object()), "Fastiticalon-F leaps to attack you!\n");
              attack_object(inv[x]->query_attack());
              return 1;
           }
        }
     }
}
monster_died()
{
   tell_room(environment(this_object()),
     YEL+"Fastiticalon-F rises from the sand and collapses in a heap.\n"+OFF);
   return 0;
}
