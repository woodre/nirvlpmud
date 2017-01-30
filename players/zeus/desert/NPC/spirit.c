#include <ansi.h>
inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

  set_name("sand spirit");
  set_alias("spirit");
  if(!random(3))
    set_short(YEL+"A sand spirit"+NORM);
  else if(!random(2))
    set_short(BOLD+BLK+"A sand spirit"+NORM);
  else
    set_short("A sand spirit");
  set_race("spirit");
  set_gender("female");
  set_long(
"This is a sand spirit, forever cursed to wander the sands in search of\n"+
"that one thing that torments her endlessly.  She glides over the ground\n"+
"smoothly as the sands seem to swirl around her.  Long waves of white\n"+
"hair seem to flow down her back.  Her hollow eyes have a slightly crazed\n"+
"appearance which worries you greatly as she approaches.\n");
  set_level(15);
  set_ac(9);        /*  12  */
  set_wc_bonus(2);
  set_wc(25);       /*  20  */
  set_hp(225);      /*  225 */
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("A sand spirit searches in vain.\n");
  load_chat("A sand spirit glances at you pleadingly.\n");
  load_chat("A sand spirit cries softly.\n");
  load_chat("A sand spirit drifts across the sands.\n");
  load_a_chat("A sand spirit cries out in pain.\n");
  load_a_chat("A sand spirit cries, \"Why... oh why....\"\n");
  set_dead_ob(this_object());
  }
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  tell_room(environment(), "\n\nThe spirit's essence fades away...\n\n");
  if(present("corpse", environment()))
  {
    destruct(present("corpse", environment()));
  }
  move_object(clone_object("/players/zeus/desert/OBJ/veil.c"), environment());
  if(!(random(12)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}

void heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  if(0 == random(9))
  {
    tell_object(attacker_ob,
      "The sand spirit fills you with desperation and sadness.\n");
    tell_room(environment(), attacker_ob->query_name()+
      " is filled with desperation and sadness.\n", ({ attacker_ob }));
    attacker_ob->hit_player(15, "magical");
  }
}
