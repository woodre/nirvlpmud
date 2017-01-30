inherit "obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: orge.c
 * Path: /players/dragnar/WasteLands/mons
 * Type: Mob
 * Created: 1993 by Dragnar
 *
 * Purpose: A high level monster in the Wastelands area& part of the Wastelands
 *          quest. master.c must be killed just to get to this mob,
 *          plus the ice caves maze. Mob has high WC/AC and higher than normal
 *          spell damage. Also has a spell that will clone a stone wolf that
 *          has high WC and attacks the player for random number of rounds.
 *          Also has a special to steal sps but unlike demon does not heal.
 * History:
 *          09/18/2013 - Dragnar
 *            Updated stats, spells, special attack to steal sps.
 ******************************************************************************/

object gold, key;

reset(arg){
  ::reset(arg);
  if(arg) return;
  
  set_name("creighton");
  set_race("orge");
  set_alias("creighton");
	set_short(HIB+"Creighton"+NORM+", Orge-Magi Shaman");
	set_long("This is a huge orge-magi that the darkside cult has summoned to do\n\
their bidding for them. His skin is a "+HIB+"dark shade of blue"+NORM+" and stands\n\
over 7 feet tall. His body bulges with muscle and he wields an impossibly\n\
large club. His eyes look empty as he looks right past you.\n");
  set_level(25);
  set_hp(1000);
  set_al(-1000);
  set_wc(50);
  set_ac(30);
  set_heal(50,5);
  set_wc_bonus(30);
  
	set_aggressive(1);
  gold = clone_object("obj/money");
	gold->set_money(random(12000)+5000);
  move_object(gold,this_object());
	key=clone_object("/players/dragnar/WasteLands/obj/quest/mag2.c");
	move_object(key, this_object());
  
  add_spell("stomp",
    "#MN# $Y$S T O M P S$N$ his large foot on your head!\n",
    "#MN# $Y$S T O M P S$N$ #TN# on the head!\n",
    15,"25-75","physical", 5 );
    
  add_spell("stone_wolf",
    "#MN# $HK$CHANTS$N$ some words in his strange guttural language.\n",
    "#MN# $HK$CHANTS$N$ some words in his strange guttural language.\n",
    7,0,0,0, "call_wolf" );
}

heart_beat() {
  int amt, sps;
	object att;
  
	::heart_beat();

  amt = 50+random(25);
	att=(this_object()->query_attack());
  
  if(att && !random(12)) {
    tell_object(att, HIB+"The Orge-Magi slashes the air with his hand and the room explodes with blue light."+NORM+"\n");
    sps = att->query_spell_point();
    
    if( sps < amt && sps > 0 )
      amt = sps;
    if( sps > 0 )
      att->add_spell_point( -amt );
      
    this_object()->heal_self( amt );
	}
}

call_wolf( object target, object room, int damage ) {
  object wolf;
  if( target && room && target ) {
    wolf = clone_object("/players/dragnar/WasteLands/mons/stone_wolf");
    move_object( wolf, room );
    wolf->attacked_by( target );
  }
  
}
