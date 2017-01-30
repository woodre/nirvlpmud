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
         "players/zeus/realm/taus/circle8",
         "players/zeus/realm/taus/circle9",  });

  meats = 0;
  set_name("Creature of the Mist");
  set_short(HIW+"A Creature of the Mist"+NORM);
  set_gender("creature");
  set_race("spirit");
  set_long(
"This is a giant creature that has taken shape from the mists that lurk\n"+
"among the trees of the forest.  The shape of the creature is hard to\n"+
"define, however it appears to tower high above the trees.  You get the\n"+
"feeling that attacking this creature directly would be futile.\n");
  set_level(23);
  set_hp(10000);
/* hp has been devalued so this is no longer necessary - illarion dec 2004
  set_hp_bonus(-6000);
*/
  set_hp_bonus(-2000);
  set_ac(35);
  set_wc(65);
  set_al(-1200);
  set_aggressive(1);
  set_chat_chance(1);
  set_a_chat_chance(1);
  load_chat("The creature screams at you.\n");
  load_chat("The creature crashes through the trees.\n");
  load_chat("The creature burns with fury.\n");
  load_a_chat("Mist drifts among the trees.\n");
  set_dead_ob(this_object());
  call_out("special", 40);
  call_out("make_vortex", 26);
   }
}

id(str){ return str == "zzqyb" || str == "creature" || str == "mist creature"
|| str == "creature of the mist"; }

set_meats(int x){ 
  meats = x; 
  pain = 2100 - (meats * 100);
}

vortex_death(){  
  int i;
  hit_point -= pain; 
  if(hit_point <= 50)
  {
    for(i = 0; i < sizeof(x); i++)
    {
      tell_room(x[i], 
       "The Creature of the Mist screams as it dissipates into the trees.\n");
    }
    this_object()->hit_player(666);
  }
  else
  {
    for(i = 0; i < sizeof(x); i++)
    {
      tell_room(x[i], "The Creature of the Mist screams in agony.\n");
    }
  }
}

monster_died(){
  int y;
  for(y = 0; y < sizeof(x); y++)
    x[y]->set_nt(random(2)); /* make NT random */
  x[3]->set_wall(0);         /* unblock exit   */
  write_file("/players/zeus/log/circle", ctime(time())+" - Big Misty Died\n");
  if(present("corpse", environment()))
    destruct(present("corpse", environment()));
  emit_channel("junk",
    "You hear an agonizing scream far off in the distance as a\n"+
    "strange mist slowly spreads across the Fallen Lands.\n");
}

make_vortex(){
  object zoof;
  if(!environment()) return;
  zoof = x[random(sizeof(x))];
  MO(CO("/players/zeus/realm/NPC/mist_vortex.c"), zoof);
  tell_room(zoof, "\nA vortex of mist emerges from the trees...\n\n");
}

special(){
  int i,j, *c, type;
  type = random(4);
  if(!environment()) return;
  for(i = 0; i < sizeof(x); i++)
  {
    c = all_inventory(x[i]);
    for(j = 0; j < sizeof(c); j++)
    {
      if(c[j]->is_player() && !c[j]->query_ghost())
      {
        if(0 == type)
        {
          tell_object(c[j], HIR+
            "\nA giant FIREBALL erupts all around you!\n\n"+NORM);
        }
        else if(1 == type)
        {
          tell_object(c[j], HIW+
            "\nThe mists seep into your soul, draining your strength!\n\n"+NORM);
        }
        else if(2 == type)
        {
          tell_object(c[j], BOLD+BLK+
            "\nA sharp pain shoots through your body!\n\n"+NORM);
        }
        else if(3 == type)
        {
          tell_object(c[j], BOLD+BLK+
            "\nWaves of energy rip through you, weakening your body!\n\n"+NORM);
        }
        if(0 == type)
          c[j]->hit_player(130);
        else if(1 == type || 2 == type)
          c[j]->hit_player(90+random(40));
        else if(3 == type)
          c[j]->heal_self(-50-random(30));
      }
    }
  }
  call_out("special", 20+random(15));
}

