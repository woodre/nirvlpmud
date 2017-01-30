inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: clone.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: July 25th, 2015 by Dragnar
 *
 * Purpose: A high monster in the Seven Spires area. This mob is summoned
 *          by viridiana. It is a copy of the player attacking her. It
 *          is able to use heals and get them from bags. Some of the code
 *          taken from Michelangelo, the ninja turtle I coded for wicket
 *          that steals heals.
 * * Specials:
 *    1. Uses heals.
 *    2. Offwields weapons.
 *    3. Will copy spells cast by the player.
 *
 * History:
 *          07/25/2015 - Dragnar
 *            Created
 ******************************************************************************/
 object target;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("viridiana");
  set_race("human");
  set_short("Noone");
set_long(
"None.\n");
  
  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"20-60","physical" );
}

init() {
  ::init();
}

heart_beat() {
  object *heals;
  
  ::heart_beat();
  if( query_hp() < query_mhp() ) {
#ifndef __LDMUD__
  heals = filter_array(deep_inventory(this_object()),"filter_heals",this_object());
#else
  heals = filter(deep_inventory(this_object()), "filter_heals", this_object());
#endif
    use_heal( heals );  
  }
}

status filter_heals( object ob ) {
  return (status) ob->is_heal() ||
    ob->id( "heal") || ob->id("potion") || ob->id("bottle") || ob->id("ice sphere");
}

/** Ensure we get an exp bonus for the heals this mob uses **/
heal_self( int amt ) {
  set_hp_bonus( query_hp_bonus() + amt );
  ::heal_self( amt );
}

add_hit_point( int amt ) {
  set_hp_bonus( query_hp_bonus() + amt );
  ::add_hit_point( amt ); 
}

use_heal( object *heals ) {
  int i, s, charges;
  object heal;
  string *cmds;
  
  s = sizeof( heals );
  /** Damn we ran out of heals **/
  if( !s )
    return;
  
  heal = heals[ random(s) ];
  move_object( heal, this_object() );
  if( heal->is_heal() ) {
    cmds = (string *) heal->query_cmds();
    if( sizeof( cmds ) > 0 ) {
      charges = (int) heal->query_charges();
      for( i=charges; i > 0 && query_hp() < query_mhp(); i-- ) {
        command(cmds[0]+ " " + heal->query_name());
      }
    }
  }
  else {
    command("heal");
    command("drink potion");
    command("pop pill");
    command("pop pill");
    command("pop pill");
    command("apply sphere");
    command("apply sphere");
    command("apply sphere");
  }

}

clone_inventory( object ob, int bag_flag ) {
  int i, size;
  object obj, bag;
  mixed *inv;
  
  if( !ob )
    return;
  
  inv = all_inventory( ob );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    if( inv[i]->id("player_soul") )
      continue;
    obj = clone_object( basename( inv[i] ) );
    move_object( obj, bag_flag ? ob : this_object() );
    if( obj->is_container() )
      clone_inventory( obj, 1 );
  }
}

setup_mob() {
  int level, ex_level, height_ft, height_in, player_weight, player_killing;
  int a_or_an, x, size;
  string gender, title, pretitle, race, player_name, clan_name, pdescription, al_title;
  string *extra_look;
  string strs, strl;
  
  if(!target)
    destruct( this_object() );
  
  set_level(20);
  player_name = target->query_real_name();
  level = target->query_level();
  ex_level = target->query_extra_level();
  gender = target->query_gender();
  height_ft = target->query_phys_at( 1 );
  height_in = target->query_phys_at( 2 );
  player_weight = target->query_phys_at( 3 );
  title = target->query_title();
  pretitle = target->query_pretitle();
  race = target->query_race();
  clan_name = target->query_clan_name();
  player_killing = target->query_pl_k();
  pdescription = target->query_description();
  al_title = target->query_al_title();
  
  set_name( player_name );
  set_gender( gender );
  strs = capitalize(player_name) + " " + title;
  if( pretitle )
    strs = pretitle + " " + strs;
  if( al_title )
    strs += " ("+al_title+")";
  if( clan_name )
    strs += " <"+capitalize(clan_name)+" Clan>";
  if( player_killing )
    strs = HIR+"[PK]"+NORM+" " +strs;

  set_short( strs );
  
  strs = race;
  race = lower_case(delete_colour(race));
  if(race[0] == 'a' || race[0] == 'e' || race[0] == 'i' ||
     race[0] == 'o' || race[0] == 'u')
    a_or_an = 1;
  race = strs;
  
  if( pdescription && strlen( pdescription ) > 5 )
    strl = capitalize(player_name) + " " +pdescription+"\n";

  strl = (strl ? strl : "") + capitalize(player_name)+" is"+(a_or_an ? " an " : " a ") +race+ ", "+height_ft+" feet "+height_in+" inches tall, "+player_weight+" lbs.\n";
  if( player_killing )
    strl += RED+capitalize(player_name)+" can fight other players.\n"+NORM;
  for( x=0, size=sizeof( extra_look ); x < size; x++ ) {
    if( extra_look[x] )
      strl += extra_look[x] + ".\n";
  }
  set_long( strl );
  
  clone_inventory( target, 0 );
  
}

set_target( object ob ) { 
  target = ob;
  setup_mob();  
}
query_target() { return target; }

/** fake intox funcs **/
query_soaked() { return 1; }
int drink_soft(int i ) { return 1; }
query_stuffed() { return 1; }
eat_food( int i ) { return 1; }
query_intoxination() { return 1; }
drink_alcohol( int i ) { return 1; }
int query_max_intox() { return 1000; }
int query_max_soak() { return 1000; }
int query_max_stuff() { return 1000; }
