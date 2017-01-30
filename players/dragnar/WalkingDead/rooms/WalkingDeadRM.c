#include "../defs.h"

inherit "room/room";

#define CO_TIME 10
#define REANIMATING1 "reanimating_corpse1"
#define REANIMATING2 "reanimating_corpse2"
#define REANIMATING3 "reanimating_corpse3"
/******************************************************************************
 * Program: WalkingDeadRM.c
 * Path: /players/dragnar/WalkingDead/rooms
 * Type: Room
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: This room is inherited by all of the rooms in the Walking Dead
 *          area. It controls the re-animation of corpses in the room, as well
 *          as having Walkers join into larger mobs. The main Daemon is checked
 *          before re-animation occurs to make sure the number of walkers is
 *          limited. It also has some functions used by the Walker groan spell
 *          which calls Walkers from nearby rooms.
  * History:
 *          06/09/2013 - Dragnar
 *            Created
 ******************************************************************************/


reset(arg) {
	if(arg) return;
  
  short_desc = "You do not belong here";
  long_desc=
"You do not belong here. This room is inherited.\n",
  set_light(1);
  dest_dir=({
    "players/dragnar/WalkingDead/rooms/entrance.c","south",
  });
  
}

query_walker_realm() { return 1; }

init() {
	::init();
  add_action("Search","search");
}

status move(string str)
{
  ::move( str );
  DEADDM->initalizeDM();
  return 1;
}

Search(string str) {
  if( !str ) {
    write("You search blindly about but don't find anything.\n");
    say( this_player()->query_name()+" searches about but doesn't turn up anything\n");
    return 1;
  }
}

clone_walker() {
  if( !present("walker") )
    move_object(clone_object("/players/dragnar/WalkingDead/mons/walker"), this_object());
}

string convert_size( int nbr ) {
  switch( nbr ) {
    case 1:
      return "one";
      break;
    case 2:
      return "two";
      break;
    case 3:
      return "three";
      break;
    case 4:
      return "four";
      break;
    case 5:
      return "five";
      break;
    case 6:
      return "six";
      break;
    default:
      return "seven";
      break;
  }
}

status check_walker_basic(object ob) {
  return (status) ob->query_npc() && ob->id("geek") && ob->id("biter") && !ob->query_attack();
}

status check_walker(object ob) {
  return (status) ob->query_npc() && ob->id("geek") && ob->id("biter") && !ob->query_attack() &&
                  ob->query_walker_level() < WALKER_MAX;
}

status check_regular_corpse(object ob) {
  return (status) ob->is_corpse() && ob->id("corpse") && !ob->id( WALKER_CORPSE ) &&
                  DEADDM->CheckWalkerStatus( 1 );
}

combine_walkers( object walker1, object walker2 ) {
  int walker_size1, walker_size2, reduced_size;
  
  if( !walker1 || !walker2 )
    return;
  
  walker_size1 = walker1->query_walker_size();
  walker_size2 = walker2->query_walker_size();
  
  DEADDM->DeregisterMob( walker1 );
  /*DEADDM->DeregisterMob( walker2 );*/
  
  if( (walker_size1 + walker_size2) > WALKER_MAX_SIZE ) {
    /** Walkers leave 1 mob to join another **/
    reduced_size = WALKER_MAX_SIZE - walker_size1;
    tell_room(this_object(), capitalize(convert_size( reduced_size )) + " Walker"+(reduced_size > 1 ? "s" : "")+" break"+(reduced_size == 1 ? "s" : "")+" away from "+walker2->short()+" to join "+walker1->short()+".\n");
    
    walker1->reset_walker_ids();
    walker1->add_walker_level( reduced_size );
    DEADDM->RegisterMob( walker1 );
    
    DEADDM->DeregisterMob( walker2 );
    walker2->reset_walker_ids();
    walker2->del_walker_level( reduced_size );
    DEADDM->RegisterMob( walker2 );
  }
  else {
    /** Second walker is totally absorbed my first mob **/
    if( walker_size1 == 1 )
      tell_room(this_object(), "Two walkers join into a pair of Walkers.\n");
    else {
      if( walker_size1 == walker_size2 )
        tell_room(this_object(), "Two "+walker2->short()+" join together to form a larger mob of Walkers.\n");
      else
        tell_room(this_object(), walker2->short()+" shambles over to join the larger "+walker1->short()+".\n");
    }
    transfer_inventory( walker2, walker1 );
    destruct( walker2 );
    walker1->reset_walker_ids();
    walker1->add_walker_level( walker_size2 );

    DEADDM->RegisterMob( walker1 );
  }
}

combine_walker_check() {
  int i, size, idx;
  object *walkers;
  object walker1, walker2;
  
#ifndef __LDMUD__ 
    walkers = filter_array(all_inventory(this_object()),"check_walker", this_object());
#else
    walkers = filter(all_inventory(this_object()), "check_walker", this_object());
#endif  
  
  size = sizeof(walkers);
  if(size > 1 && !random(1)) {
    /** First walker **/
    walker1 = walkers[random(size)];
    walkers -= ({ walker1 });
    size = sizeof(walkers);
    /** Second walker **/
    walker2 = walkers[random(size)];
    
    /** Always pass bigger mob as first argument **/
    if( walker1->query_walker_size() > walker2->query_walker_size() )
      combine_walkers( walker1, walker2 );
    else
      combine_walkers( walker2, walker1 );
  }
}

check_corpse() {
  int i, size;
  object *corpses;

#ifndef __LDMUD__ 
    corpses = filter_array(all_inventory(this_object()),"check_regular_corpse", this_object());
#else
    corpses = filter(all_inventory(this_object()), "check_regular_corpse", this_object());
#endif 
  
  for( i=0, size = sizeof(corpses); i < size; i++ ) {
    if( !corpses[i]->id( REANIMATING1 ) )
      reanimate_corpse1( corpses[i] );
    else if( !corpses[i]->id( REANIMATING2 ) )
      reanimate_corpse2( corpses[i] );
    else
      reanimate_corpse3( corpses[i] );
  }
  
  return 1;
}

reanimate_corpse() {
  check_corpse();
  /* call_out("reanimate_corpse", 8 + random(CO_TIME)); */
}

transfer_inventory(object mob1, object mob2 ) {
  int i, size;
  object *inv;
  
  if( !mob1 || !mob2 )
    return;
  
  inv = all_inventory( mob1 );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    if( inv[i]->id("kill_check_object" ) )
      destruct(inv[i]);
    else
      move_object(inv[i], mob2 );
  }
}

reanimate_corpse1( object corpse ) {
  string name;
  string msg;
  if( corpse ) {
     name = corpse->short();
     corpse->add_id( REANIMATING1 );
     switch( random(5) ) {
       case 0:
         msg = " growls and thrashes around.\n";
         break;
       case 1:
         msg = " clenches their teeth and writhes about on the ground.\n";
         break;
       case 2:
         msg = "'s fingers slowly move.\n";
         break;
       case 3:
         msg = " inhales a shallow un-human breath.\n";
         break;
       default:
         msg = " twitches suddenly.\n";
         break;
     }
     tell_room(this_object(), capitalize(name)+ msg);
  }
}

reanimate_corpse2( object corpse ) {
  string name;
  string msg;
  if( corpse ) {
     name = corpse->short();
     corpse->add_id( REANIMATING2 );
     switch( random(3) ) {
       case 0:
         msg = " suddenly lurches to a sitting position.\n";
         corpse->set_short(name + " (sitting)" );
         break;
       case 1:
         msg = " starts snarling wildly\n";
         corpse->set_short(name + " (snarling wildly)" );
         break;
       default:
         msg = "'s eyes snap open.\n";
         corpse->set_short(name + " (dead eyes open)" );
         break;
     }
     tell_room(this_object(), capitalize(name)+ msg );
  } 
}

reanimate_corpse3( object corpse ) {
  object walker;
  string name;
  
  if( corpse ) {
    /* Clone a walker, set attributes */
    name = corpse->query_name();
    tell_room(this_object(), corpse->short()+ " stumbles to their feet and emits a feral growl.\n");
    walker = clone_object("/players/dragnar/WalkingDead/mons/walker");
    walker->set_short( "A Walking Dead " + name );
    /* Add id of original mob */
    walker->add_walker_id( name );
    DEADDM->RegisterMob( walker );
    walker->set_registered_flag(); 
    move_object( walker, this_object());
    
    /** Transfer inv from corpse to mob **/
    transfer_inventory( corpse, walker );
    destruct(corpse);
  } 
}

summon_walkers( string room_path ) {
  object *walkers;
  string dir;
  int idx, i, size;
  
  idx = member_array(room_path, dest_dir);
  
  if( idx >= 0 ) {

#ifndef __LDMUD__ 
    walkers = filter_array(all_inventory(this_object()),"check_walker_basic", this_object());
#else
    walkers = filter(all_inventory(this_object()), "check_walker_basic", this_object());
#endif

    dir = dest_dir[idx+1];
    for( i=0, size = sizeof(walkers); i < size; i++ ) {
      walkers[i]->move_me( dir );
    }
  }
}

void call_summon_walkers( int flag, string* exclude ) {
  int i, size;
  object targ;
  string room_path;
  string *exclude_rooms;
  
  if( !dest_dir || !(size = sizeof(dest_dir)) ) 
    return;
    
#ifndef __LDMUD__ 
  room_path = file_name( this_object() );
#else
  room_path = object_name( this_object() );
#endif
  
  /** Ensure sure room_path is absolute **/
  if( room_path[0..0] != "/" )
    room_path = "/" + room_path;
      
  if( exclude )
    exclude_rooms = exclude += ({ room_path });
  else
    exclude_rooms = ({ room_path });
    
  /**
  for( i=0; i < sizeof(exclude_rooms); i++ ) {
    tell_room(this_object(), "exclude_rooms["+i+"] "+ exclude_rooms[i] + "\n");
  }
  **/
  
  for( i=0; i < size; i += 2 ) {
    targ = find_object( dest_dir[i] );
    /** tell_room(this_object(), "dest_dir["+i+"] "+ dest_dir[i] + "\n"); **/
    
    if( targ && (!exclude ||  member_array(dest_dir[i], exclude_rooms)  < 0 ) ) {
      targ->summon_walkers( room_path );
      if( flag < 3 ) {
          targ->call_summon_walkers( flag + 1, exclude_rooms );
      }
    }
    
  }
}
