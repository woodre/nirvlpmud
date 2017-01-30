#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("bite bug");
set_alias("creature");
set_race("bug");
set_gender("creature");
set_short(HIB + "Bite Bug" + OFF);
set_long(
	"A bite bug is a very large mosquito.  It is the size of a crow, with\n" +
	"a long syringe-like mouth that it uses to drain blood from its prey.\n" +
	"Bite bugs are very adept at flying and only land to bite.  Their \n" +
	"favourite meal is the warm blood of travellers and it is not unusual.\n" +
	"for them to attack in swarms.\n");

set_level(10);
set_hp(150);
set_al(10 - random(20));
set_wc(14);
set_ac(8);
set_heal(4,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("The Bite Bug buzzes by your ear.\n");
set_a_chat_chance(10);
load_a_chat(HIB + "Swooping at you, Bite Bug lands and bites, withdrawing blood.\n" + OFF);
set_chance(14);
set_spell_dam(10 + random(5));
set_spell_mess1(
     HIB + "Bite bug darts over and bites its attacker hard!\n" + OFF);
set_spell_mess2(
     HIB + "Bite bug sucks a pint of blood from you!\n" + OFF);

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
           if(inv[x]->id("bite bug") && inv[x]->query_attack())
           {
              tell_room(environment(this_object()), HIB + "The Bite Bugs swarm to the attack!\n" + OFF);
              attack_object(inv[x]->query_attack());
              return 1;
           }
        }
     }
}

monster_died()
{
	move_object(clone_object("/players/laera/balamb/forests/obj/mstpiece.c"),
      environment(this_object()));
   	tell_room(environment(this_object()),
     HIB+"Bite Bug crashes to the ground, dead.\n"+OFF);
   return 0;
}
