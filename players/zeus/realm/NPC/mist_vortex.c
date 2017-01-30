inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int pain, meats;
object *x;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  x =({  "players/zeus/realm/taus/circle1",
         "players/zeus/realm/taus/circle2",
         "players/zeus/realm/taus/circle3",
         "players/zeus/realm/taus/circle4",
         "players/zeus/realm/taus/circle5",
         "players/zeus/realm/taus/circle6",
         "players/zeus/realm/taus/circle7",
         "players/zeus/realm/taus/circle8",  });

  meats = 0;
  set_name("Vortex of Mist");
  set_short(HIW+"A Vortex of Mist"+NORM);
  set_alt_name("vortex");
  set_alias("mist vortex");
  set_gender("creature");
  set_race("spirit");
  set_long(
"This is a spiraling vortex of mist.  The mists are drifting from it\n"+
"into the forest towards the giant creature.\n");
  set_level(17);
  set_hp(400);
  set_ac(7);
  set_wc(36);
  set_heal(3,1);
  set_al(-100);
  set_chance(15);
  set_spell_dam(40);
  set_spell_mess2("The vortex drains your strength.\n");
  set_spell_mess1("Mists seep from the vortex.\n");
  set_chat_chance(1);
  set_a_chat_chance(1);
  load_chat("The vortex of mist spins.\n");
  load_a_chat("The vortex of mist erupts.\n");
  set_dead_ob(this_object());
  call_out("monkies_fly_from_my_butt", 20);
   }
}

monster_died(){
  object zoof;
  if(find_living("zzqyb"))
    find_living("zzqyb")->vortex_death();
  if(find_living("zzqyb"))
  {
    zoof = x[random(sizeof(x))];
    MO(CO("/players/zeus/realm/NPC/mist_vortex.c"), zoof);
    tell_room(zoof, "\nA vortex of mist emerges from the trees...\n\n");
    tell_room(environment(),
      "\nThe vortex of mist dissipates into the trees...\n\n");
  }
  if(present("corpse", environment()))
    destruct(present("corpse", environment()));
}

monkies_fly_from_my_butt(){
  if(!environment()) return;
  if(!attacker_ob)
  {
    if(find_living("zzqyb"))
    {
      if(!environment(find_living("zzqyb")))
        destruct(this_object());
    }
    else
      destruct(this_object());
  }
  else
    call_out("monkies_fly_from_my_butt", 20);
}
