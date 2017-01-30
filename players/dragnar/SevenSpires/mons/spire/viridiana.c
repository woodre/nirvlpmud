inherit "/obj/monster";
#include <ansi.h>
#include "../../defs.h"
/******************************************************************************
 * Program: viridiana.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: July 25th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. This one is the leader
 *          of the Green spire. 
 * * Specials:
 *    1. She clones a mob that copies the attacker include eq and heals.
 *    2. Picks up dropped bags/heals so player can't avoid the clone.
 *    3. 
 *
 * History:
 *          07/25/2015 - Dragnar
 *            Created
 ******************************************************************************/
 int clone_flag;
 int clone_threshold;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "archedama viridiana", "archedama", }) );
  set_name("viridiana");
  set_race("human");
  set_short(RED+"Ar"+YEL+"ch"+GRN+"ed"+CYN+"ama"+NORM+" Viridiana");
set_long(
"An amazingly beautiful young woman with long wavy red hair.\n");

  set_gender("female");
  set_level(29);
  set_hp(2000+random(300));
  set_ac(28);
  set_wc(70);
  set_al(-200);
  clone_threshold = 30 + random(55);
  
  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"20-60","physical" );
}

calm() {
  object enemy, ob;
  int x;

  ob = all_inventory(environment());
  x = 0;
  while(x < sizeof(ob)) {
    if(ob[x]->query_attack()) {
      enemy = ob[x]->query_attack();
      ob[x]->stop_fight();
      enemy->stop_fight();
    }
    x += 1;
  }
}

init() {
  ::init();
}

heart_beat() {
  int hps;
  object mob, targ;
  
  ::heart_beat();
  
  if( !environment() || !attacker_ob )
    return;
  
  hps = query_hp() * 100 / query_mhp();
  if( hps < clone_threshold && !clone_flag ) {
    targ = attacker_ob;
    clone_flag = 1;
    calm();
    mob = clone_object(MONSDIR+"/clone.c");
    move_object( mob, environment() );
    mob->set_target( targ ); 
    mob->attacked_by( targ );
  }
}

query_long() {
  string str;
  str = ::query_long();
  if( !this_player() || this_player()->query_level() < 20 )
    return str;
  return str += "Clone Threshold: " + clone_threshold+"\nClone Flag: "+clone_flag+"\n";
}

attack() {
  int x;
  string obname;
  object *ob;
  
  ob = all_inventory(environment());
  x = sizeof(ob);
  while( x-- ) {
    if(  (!living(ob[x]) && ob[x]->can_put_and_get() ) || ob[x]->is_heal() ) {
      move_object( ob[x], this_object() );
      obname = ob[x]->query_name();
      tell_room( environment(), query_name() + " takes "+(obname ? obname : ob[x]->short()) +".\n" );
    }
  }
  ::attack();
}


/** fake player funcs **/
query_soaked() { return 1; }
int drink_soft(int i ) { return 1; }
query_stuffed() { return 1; }
eat_food( int i ) { return 1; }
query_intoxination() { return 1; }
drink_alcohol( int i ) { return 1; }
int query_max_intox() { return 1000; }
int query_max_soak() { return 1000; }
int query_max_stuff() { return 1000; }
