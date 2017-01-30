/*  meant to be used in zeus' museum arena  */
/*
// 2005.08.20 -Forbin
// Changes:
//  AC 17 -> 20
//  WC 70 -> 80
//  HP 1200 -> 1400
//  set_heal 1,1 -> 5,2
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
object nmy;
string xy;
int z;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  z = 0;
  set_name("enchanted light");
  set_alias("light");
  set_short(HIY+"Enchanted light"+NORM);
  set_race("creature");
  set_gender("creature");
  set_long(
"What lies before you is enchanted light.  It is constantly moving, beams\n"+
"of light exploding outward.  You are mesmerized by the blend between\n"+
"dark magic and pure energy.\n");
  set_level(23);
  set_wc(105);
  set_ac(40);
  set_heal(5,2);
  set_wc_bonus(75);
  set_hp_bonus(130);
  set_hp(1900);
  set_aggressive(1);
  set_al(-1000);
  set_dead_ob(this_object());
  call_out("hunt", 10+random(20));
  call_out("wimpy", 20+random(15));
   }
}

query_z_museum_mob() { return 1; }

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	  capitalize((string)TP->QRN)+" defeated Enchanted Light.\n");
 tell_room(environment(),
"As the light blinks out, a dagger is left in its place.\n");
  MO(CO("/players/zeus/museum/OBJ/light_dagger.c"), environment());
   "/players/zeus/museum/lounge.c"->npc8();
  if(corpse)
    destruct(corpse);
  emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
    capitalize((string)this_player()->query_real_name())+
    " has defeated Enchanted Light.\n\n"+NORM);     
  return 1; 
}


boom(){
  int f;
  f = random(3);
  switch(f){
  case 0:
    tell_object(AO, HIY+"Light explodes all around you...\n"+NORM);
    break;
  case 1:
    tell_object(AO, HIY+"Light burns your eyes...\n"+NORM);
    break;
  case 2:
    tell_object(AO, HIY+"Beams of light burn your skin...\n"+NORM);
    break;
  }
  AO->hit_player(35+random(35), "other|light");
  if(!AO->query_ghost() && !random(3))
  {
    already_fight = 0; 
    ::attack();
  }
}

wimpy(){
  string *dirs, str;
  int x, rand;
  if(!environment()) return;
  if(!sscanf(file_name(environment(this_object())), 
    "players/zeus/museum/arena/%s", xy))
  {
    TR(ENV, HIY+"The light explodes in a brilliant flash!\n"+NORM);
    return destruct(this_object());
  }
  if(!environment()->query_dest_dir()) return;
  TR(environment(),			"\n");
  dirs = environment()->query_dest_dir();
  rand = random(sizeof(dirs)-1);
  x = rand / 2 * 2;
  str = dirs[x + 1];
  str += "#";
  str += dirs[x];
  this_object()->move_player(str);
  call_out("wimpy", 20+random(15));
}

doom(){
  int dmg;
  if(!present(attacker_ob, environment())) return;
  tell_room(environment(), HIY+
	  "\n\tBeams of light explode in every direction!\n\n"+NORM);
  if(AO->query_hp() > 300)
	  dmg = 190;
  else if(AO->query_hp() > 140)
	  dmg = 120;
  else
	  dmg = 60;
  attacker_ob->hit_player(dmg, "other|light");
}

hunt(){
  string w;
  if(!environment()) return;
  if(!sscanf(file_name(environment()), "players/zeus/museum/arena/%s", w))
	return;
  call_out("hunt", 10+random(20));
  if(!nmy) return;
  if(!sscanf(file_name(environment(nmy)), 
	  "players/zeus/museum/arena/%s", w)) return;
  if(!nmy->query_ghost()){
	move_object(this_object(), environment(nmy));
	TO->attack_object(nmy);
	return;
  }
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return ;
  if(!attacker_ob) return;
  if(attacker_ob == this_object())
  {
    stop_fight();
    stop_fight();
  }
  nmy = AO;
  hit_point += 2;
  if(!random(8)) 
    boom();
  else if(!random(10))
    doom();
}
