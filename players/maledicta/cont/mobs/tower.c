/* Sparrow's attempt of a re-hash of Mal's Vanishing tower */
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object gold;
int loc_now;
reset(arg)  {
  ::reset(arg);
  if(!arg) {
    no_clean = 1;
    set_name("tower");
    set_alt_name("stone tower");
    set_race("animated object");
    set_short(HIW+"The Vanishing Tower"+NORM);
    set_level(29);
    set_hp(2000);
    set_al(0);
    set_wc(90);
    set_wc_bonus(90);
    set_ac(20);
    set_aggressive(0);
    set_wander(1);
    set_wander_interval(3);
    set_heart_beat(1); 
    set_wander_realm("/players/maledicta/cont/rooms");
    set_dead_ob(this_object());
    set_heal(5,2);
    set_chance(20);
    set_spell_dam(50);
    set_spell_mess1(
      "The tower cracks and bends as it flattens its opponent!\n");
    set_spell_mess2(
      "The tower bends over and flattens you!\n");
    add_money(23000 + random(4000));
    loc_now = 0;
    enable_commands();
  }
}

long(){
  write("  This is a large stone tower with two arrow slits above\n\
a large door.  The battlements atop the tower are about\n\
sixty feet off the ground.  Two arrow slits can be seen\n\
from where you are.\n"); 
return 1;
}

 heart_beat(){
  ::heart_beat();
if(attacker_ob){
  if(random(100) < 60){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
      "The Tower tramples you!!!\n");
      tell_room(environment(),
      "The Tower rushes forward and tramples "+attacker_ob->query_name()+"!!!\n", 
      ({attacker_ob}));
      attack();
      }
   }
  if(random(100) < 40){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
      "The Tower tramples you!!!\n");
      tell_room(environment(),
      "The Tower rushes forward and tramples "+attacker_ob->query_name()+"!!!\n", 
      ({attacker_ob}));
      attack();
      }
   }
  }
}

monster_died(){
object misc_treas;
object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(),
  HIW+"As the huge animated tower dies, it collapses over onto the ground\n"+
  "with a great rumbling sound.  It breaks apart and you discover \n"+
  "something within the rubble...\n"+NORM);  
  move_object(clone_object("/players/maledicta/cont/armor/guard_of_health.c"), environment());
  if(corpse)
  destruct(corpse);
 return 1;
}

