inherit "obj/monster";

#include <ansi.h>

#define LOG "/players/dragnar/WasteLands/log/MONS_DEATH"

/******************************************************************************
 * Program: dragon.c
 * Path: /players/dragnar/WasteLands/mons
 * Type: Mob
 * Created: 1993 by Dragnar
 *
 * Purpose: A high level monster in the Wastelands area& part of the Wastelands
 *          quest. master.c and ogre.c must be killed just to get to this mob,
 *          plus the ice caves maze. Mob has high WC and a room attack spell
 *          that does high damage. As the mobs health decreases his 4 heads
 *          will awaken, which simply adds a spell. Each spell does between 20
 *          and 80 damage and will select a random player attacker. If a 
 *          single player tries to kill this mob it is almost certain death.
 *          Chances improve dramatically as the number of players increases.
 *          With a single attacker there is a 2% chance of 380 dam, 0.5% chance
 *          of 480 damage, and a very slight chance of 680 damage. This is due
 *          to the multicast flag being set.
 * History:
 *          09/18/2013 - Dragnar
 *            Updated stats, spells.
 ******************************************************************************/
 
reset(arg){
  
  ::reset(arg);
  if(arg) return;
  
  set_name("shardik");
  set_race("dragon");
  set_gender("creature");
  set_alias("keeper");
  set_short(HIBLK+"Shardik"+NORM+", Keeper of the "+HIB+"Portal"+NORM);
  set_level(30);
	set_hp(random(3500)+6000);
  set_al(-500);
  set_wc(80);
  set_ac(65);
  set_dead_ob(this_object());
  add_money( 20000 + random(50000) );
  set_heal(50, 3);
  
  set_multi_cast(1);
  /** Reduction in EXP needed since spells are not added at start **/
  set_wc_bonus(-50);
  
  /** Room Damage **/
  add_spell("tail_spike",
      "$\n\n\t\t$HK$#MN#'s sweeps its tail around the room and IMPALES you with a bone spike!$N$\n",
      "$HK$#MN# 's swings his tail and #TN# is IMPALED on a spike.$N$\n",
      8,"100-200","physical", 3 );
  
}

long() {
	write("Shardik is a black, four headed dragon. He is the biggest creature\n\
you have ever seen. His tail curls around him and spikes at the end of\n\
his tail look deadly. Even in his deep slumber he looks dangerous.\n");
}

monster_died() {
    say(HIB+"The Portal pulses with a deep blue light."+NORM+"\n");
    write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed Shardik.\n");
}
heart_beat(){
  int hps;
  
	object attacker, room;
  ::heart_beat();
   hps = query_hp() * 100 / query_mhp();
  
  if( hps < 80 && !query_spell_info("frost_head") ) {
    tell_room( environment(), HIB+"Shardik's head of Frost awakens with a Scream of Fury!"+NORM+"\n" );
    add_spell("frost_head",
      "$HB$#MN#'s head of Frost breathes shards of I C E at you.$N$\n",
      "$HB$#MN# 's head of Frost breathes shards of I C E at #TN#.$N$\n",
      25,"20-80","other|ice", 5 );
  }
  
  if( hps < 60 && !query_spell_info("fire_head") ) {
    tell_room( environment(), HIR+"Shardik's head of Fire awakens with a Roar of Rage!"+NORM+"\n" );
    add_spell("fire_head",
      "$HR$#MN#'s head of Fire engulfs you in a storm of pure F I R E.$N$\n",
      "$HR$#MN# 's head of Fire engulfs #TN# in a storm of F I R E.$N$\n",
      25,"20-80","other|fire", 5 );  
  }
      
  if( hps < 40 && !query_spell_info("electricity_head") ) {
    tell_room( environment(), YEL+"Shardik's head of Electricity awakens with a Bellow of Anger!"+NORM+"\n" );
    add_spell("electricity_head",
      "$Y$#MN#'s head of Electricity shoots L I G H T N I N G at you.$N$\n",
      "$Y$#MN# 's head of Electricity shoots L I G H T N I N G at #TN#.$N$\n",
      25,"20-80","other|electric", 5 );
  }
  
  if( hps < 26 && !query_spell_info("poison_head") ) {
    tell_room( environment(), HIG+"Shardik's head of Poison awakens with a Snarl!"+NORM+"\n" );
    add_spell("poison_head",
      "$HG$#MN#'s head of Poison injects poison in your veins with its F A N G S.$N$\n",
      "$HG$#MN# 's head of Poison injects #TN# with poison from its F A N G S.$N$\n",
      25,"20-80","other|poison", 5 );
  }

}
