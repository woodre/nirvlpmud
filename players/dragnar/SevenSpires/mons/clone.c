inherit "/obj/monster";
#include <ansi.h>
#include "../defs.h"
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
#define DEBUG_MSG 0
 
 object target;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("nobody");
  set_race("human");
  set_short("Nobody");
set_long(
"None.\n");
    
  set_dead_ob(this_object());
}

init() {
  ::init();
}

monster_died() {
  object corpse;

  corpse = present( "corpse", environment() );
  if( corpse ) {
    corpse->destruct_inventory();
  }
  return;
}

heart_beat() {
  object *heals;
  
  ::heart_beat();
  if( (query_hp() * 10 )/ query_mhp() <= 6 ) {
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

clone_inventory( object ob, object dest ) {
  int i, size;
  object obj;
  mixed *inv;
  
  if( !ob )
    return;
  
  inv = all_inventory( ob );
  for( i=sizeof(inv)-1; i >= 0; i-- ) {
    /* Check for special items that we shouldn't clone */
    if( inv[i]->id("player_soul") )
      continue;
#if DEBUG_MSG
    tell_room(environment(), "Obj: "+basename(inv[i])+"\n");
#endif
    if( inv[i]->id("GI") || inv[i]->query_auto_load() ) {
      obj = clone_object( OBJDIR+"/gen_obj.c" );
      obj->set_short( inv[i]->short() );
      obj->set_long( inv[i]->query_long() );
      obj->set_extra_look( inv[i]->extra_look() );
    }
    else
      obj = clone_object( basename( inv[i] ) );
    
    if( !obj )
      continue;
    move_object( obj, dest ? dest : this_object() );
    
    /** Equip Gear **/
    if( !dest && inv[i]->is_weapon() && inv[i]->query_wielded() && !inv[i]->query_offwielded() ) {
#if DEBUG_MSG
      tell_room(environment(), "\t\tWielded.\n");
#endif
      obj->set_wielded(1);
      obj->set_wielded_by( this_object() );
      this_object()->wield( obj );
    }
    if( !dest && inv[i]->is_armor() && inv[i]->query_worn() ) {
#if DEBUG_MSG
      tell_room(environment(), "\t\tWorn.\n");
#endif
      command("wear "+(string)obj->query_name());
    }
    if( !dest && inv[i]->is_weapon() && inv[i]->query_offwielded() ) {
#if DEBUG_MSG
      tell_room(environment(), "\t\tOffwielded.\n");
#endif
      obj->offwield( this_object() );
    }

    if( inv[i]->can_put_and_get()  ) {
#if DEBUG_MSG
      tell_room(environment(), "\t\tcan_put_and_get\n");
#endif
      if( first_inventory(inv[i]) ) {
#if DEBUG_MSG
        tell_room(environment(), "\t\tnot empty bag "+obj->short()+"\n");
#endif
        clone_inventory( inv[i], obj );
      }
    }
  }
}

setup_player_info() {
  int level, ex_level, height_ft, height_in, player_weight, player_killing;
  int a_or_an, x, size;
  string gender, title, pretitle, race, player_name, clan_name, pdescription, al_title;
  string strs, strl;
  
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
#if 00
  if( al_title )
    strs += " ("+al_title+")";
#endif
  if( clan_name )
    strs += NORM +" <"+capitalize(clan_name)+" Clan>";
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

  set_long( strl );
}

setup_mob_info() {
  int i;
  string *spells;
  mixed *spell_info;
  
  set_level( target->query_level() );
#if DEBUG_MSG
  tell_room( environment(), "Target name is: "+target->query_real_name()+"\n");
#endif
  set_name( target->query_real_name() );
  set_short( target->short() );
  set_race( target->query_race() );
  set_long( target->query_long() );
  set_hp( target->query_mhp() );
  set_wc( target->query_wc() );
  set_ac( target->query_ac() );
  set_multi_cast( target->query_multi_cast() );
  
  spells = target->query_spells();
  for( i=sizeof(spells)-1; i >=0; i-- ) {
    spell_info = target->query_spell_info( spells[i] );
    add_spell( spells[i], spell_info[1], spell_info[2], spell_info[3], spell_info[4],
               spell_info[5], spell_info[6], spell_info[7], spell_info[8] );
  }
}

setup_mob() {
  
  if(!target)
    destruct( this_object() );
  
  if( target->is_player() && target->query_level() > 19 ) {
    tell_room( environment(), query_name()+ " explodes and spatters the room with gore!\n");
    destruct( this_object() );
    return;
  }
  set_level(20);
  
  if( target->is_player() )
    setup_player_info();
  else
    setup_mob_info();
  
  clone_inventory( target );
}

set_target( object ob ) { 
  target = ob;
  setup_mob();  
}
query_target() { return target; }

/** fake player funcs **/
query_prestige_level() { return 10; }
query_extra_level() { return 100; }
query_soaked() { return 1; }
int drink_soft(int i ) { return 1; }
query_stuffed() { return 1; }
eat_food( int i ) { return 1; }
query_intoxination() { return 1; }
drink_alcohol( int i ) { return 1; }
int query_max_intox() { return 1000; }
int query_max_soak() { return 1000; }
int query_max_stuff() { return 1000; }
