inherit "obj/treasure";
#include <ansi.h>
/******************************************************************************
 * Program: lava.c
 * Path: /players/dragnar/SevenSpires/obj
 * Type: Object
 * Created: September 3rd, 2015 by Dragnar
 *
 * Purpose: This object is cast as a death curse from the Aspect of the Red 
 *          tower, the Fire Mages. This object does room damage to all living
 *          objects in the room. It spreads to adjoining rooms and will continue
 *          to spread. It has a limited life span, after a period of time the 
 *          heart beat turns off and it turns into volcanic rock. The rock will
 *          damage players when they exit the room. When in lava form it will
 *          also randomly block exits for a period of time.
 *    NOTE: This object will only spread in my areas, however wizards that do not
 *          understand this object should not mess with it or make copies as it 
 *          could easily cause issues.
 * History:
 *          09/03/2015 - Dragnar
 *            Created
 ******************************************************************************/
#define DEBUG 0

int heat;
int cool_flag;
string *dest_dir;
string *blocked_dir;

void
reset(int arg) {
  if (arg) return;

  SetMultipleIds( ({"lava", "inferno", "inferno of lava", "spire_lava"}) );
  set_short(HIR+"An "+HIY+"I"+HIR+"n"+HIY+"f"+HIR+"e"+HIY+"r"+HIR+"n"+HIY+"o"+HIR+" of Lava"+NORM);
  set_long( "Super heated lava that flows around the room.\n");
  set_weight(0);
  set_value(0);
  /* Initially set heart beat so lava spreads */
  set_heart_beat(1);
  heat = 15 + random(20);
  blocked_dir = ({ });
}

init() {
  int i;

  ::init();
  /* Only allow lava to cool once player has entered */
  if( id("lava") && this_player() && this_player()->is_player() && !cool_flag ) {
    cool_flag = 1;
    set_heart_beat(1);
    heat = 15 + random(10);
  }

  if( id("rock") && this_player() && this_player()->is_player() && environment() ) {
    add_room_exits( environment() );
  }

  /** Set the blocked dirs when in Lava form */
  if( id("lava") && this_player() && this_player()->is_player() ) {
    if( blocked_dir ) {
      for( i=0; i < sizeof(blocked_dir); i++ ) {
#if DEBUG
        tell_room( environment(), "Lava: blocked_dir: "+blocked_dir[i]+"\n");
#endif
        add_action( "block_exit", blocked_dir[i] );
      } 
    }
  }
}

/** When in Rock mode, add exits that mimic room exits that do damage **/
add_room_exits( object rm ) {
  int i;

  dest_dir = rm->query_dest_dir(); 
  if(!dest_dir) return;
    i = 1;
    while(i < sizeof(dest_dir)) {
#if DEBUG
  tell_room(rm, "Lava add_action: "+dest_dir[i]+"\n");
#endif  
     add_action("exit_damage", dest_dir[i]);
     i += 2;
    }
}

/** Function to the damage the player when they leave the room (Rock Mode) **/
int exit_damage(string str) {
  int i;

#if DEBUG
  tell_room(environment(), "Lava exit_damage: "+ query_verb()+"\n");
#endif  
  if((i = member_array(query_verb(), dest_dir)) > -1) {
    write( HIK+"\n\n\nThe Volcanic rock "+HIY+"rips"+HIK+" at your"+HIR+" flesh "+HIK+
	       "as you tread on it.\n\n\n"+NORM);
    this_player()->hit_player( 20+random(20), "physical");
    return 0;
  }
}

/** Function that blocks the exit (Lava mode) **/
int block_exit(string str) {
  int i;

#if DEBUG
  tell_room(environment(), "Lava block_exit: "+ query_verb()+"\n");
#endif  
  if((i = member_array(query_verb(), blocked_dir)) > -1 && id("lava") ) {
    write( HIK+"\n\nThe "+HIY+"I"+HIR+"n"+HIY+"f"+HIR+"e"+HIY+"r"+HIR+"n"+HIY+"o"+NORM+
	           " is too hot and blocks your way "+query_verb()+".\n\n"+NORM);
    return 1;
  }
}

/** Clear 1 or all blocked exists (Lava mode) **/
int clear_blocked_exits( object rm, string str ) {
  int i;

  if( str ) {
    remove_action( str );
    blocked_dir -= ({ str });
    tell_room( rm, HIW+"\nSteam clears from the "+str+" and opens the exit!\n"+NORM);
  }
  else {
#if DEBUG
  tell_room( rm, "Lava: size of blocked_dir: "+sizeof(blocked_dir)+"\n");
#endif
    for(i=0; i < sizeof(blocked_dir); i++ ) {
#if DEBUG
  tell_room( rm, "Lava: removing blocked dir["+i+"]: "+blocked_dir[i]+"\n");
#endif
      remove_action( blocked_dir[i] );
    }
    blocked_dir = ({ });
  } 
}

/** Function to randomly block an exit (Lava mode) **/
add_exit_block( object rm ) {
  int i;
  string *rm_dir;

#if DEBUG
    write("\tLava exit_block\n");
#endif

  if( ! dest_dir )
    dest_dir = rm->query_dest_dir(); 

  if(!dest_dir) 
    return;

  for(i=1, rm_dir = ({ }); i < sizeof(dest_dir); i += 2 ) {
#if DEBUG
    write("\tLava rm_dir: "+dest_dir[i]+"\n");
#endif
    /* Make sure it isn't already blocked */
    if( member_array( dest_dir[i], blocked_dir ) == -1 ) {
      rm_dir += ({ dest_dir[i] });
    }
  }
  if( !rm_dir || sizeof(rm_dir) == 0 )
    return; 

  blocked_dir += ({ rm_dir[ random(sizeof(rm_dir)) ] });
  tell_room( rm, HIW+"\n\nSteam hisses to the "+blocked_dir[sizeof(blocked_dir)-1]+" and blocks the exit!\n\n"+NORM);
  move_object( this_object(), "/room/void");
  move_object( this_object(), rm );
}

heart_beat() {
  object rm;

  rm = environment();
  if( !rm ) {
    set_heart_beat(0);
    destruct( this_object() );
  }
  heat -= 1;

  if( heat < 1 ) {
    set_heart_beat(0);
    /** Only do this if a player has entered the room **/
    if( cool_flag ) {
      tell_room( rm, HIK+"The lava cools and turns into volcanic rock.\n"+NORM);
      set_short(HIK+"Volcanic Rock"+NORM);
      set_long("Sharp volcanic rock that has cooled from super heated lava.\n");
      SetMultipleIds( ({"rock", "volcanic rock", "spire_lava"}) );

      /** Setup the rock to do damage upon exit **/
      clear_blocked_exits( rm );
      move_object( this_object(), "/room/void");
      move_object( this_object(), rm );
    }
    return;
  }

  /**********************************************************
    * Control what action the Lava takes
    * 1. Damage room
	* 2. Flow out of the room
	* 3. Block an exit
	* 4. Clear a blocked exit 
	**********************************************************/
  switch( random(21) ) {
    case 0:
      do_room_damage( rm, HIR+"The lava bubbles and splatters onto your skin!\n"+NORM, 
	                  "other|fire" );
      break;
    case 1:
      do_room_damage( rm, HIK+"Searing hot air from the burning rock burns your lungs!\n"+NORM, 
	                  "other|fire" );
      break;
    case 2..3:
      do_room_damage( rm, YEL+"~"+GRN+"* "+YEL+"~"+GRN+"*"+NORM+ " A cloud of "+YEL+"noxious "+GRN+
                          "fumes"+NORM+" fills the air "+ GRN+"*"+YEL+"~ "+GRN+"*"+YEL+"~\n"+NORM, 
				      "other|poison" );
      break;
    case 4:
      do_room_damage( rm, HIK+"Smoke boils up from the "+HIR+"Lava"+HIK+" blinding you!\n"+NORM, 
	                  "other|fire" );
      break;
    case 5:
      do_room_damage( rm, RED+"Rocks "+HIY+"explode "+NORM+"from the "+HIR+"heat"+NORM+" tearing you to shreds!\n"+NORM, 
	                  "physical" );
      break;
    case 6:
      do_room_damage( rm, HIW+"Steam shoots from the "+HIR+"Lava "+NORM+"and "+YEL+"scalds your face!\n"+NORM, 
	                  "other|water" );
      break;
    case 7..8:
      if( blocked_dir && sizeof(blocked_dir) > 0 )
        clear_blocked_exits( rm, blocked_dir[ random(sizeof(blocked_dir)) ] );
      break;
    case 9..12:
      add_exit_block( rm ); 
      break;
    default:
      flow_lava( rm );
      break; 
  }
}

/** Do damage to everything living in the room **/
do_room_damage( object rm, string message, string dtype ) {
  int x;
  object *ob;
  
  if( !cool_flag )
    return;

  ob = all_inventory( rm );
  x = 0;
  tell_room( rm, message );
  for( x=0; x < sizeof(ob); x++ ) {
    if( living( ob[x] ) )
      ob[x]->hit_player( 5+random(10), dtype );
  }
}

/** Clone a copy to an adjoining room **/
flow_lava( object rm ) {
  int i,siz;
  string targ, junk;
  string *exits;
  object Room;

  if( !rm )
    return;

  if( !dest_dir )
    dest_dir = rm->query_dest_dir();

  exits = ({});

  if( !dest_dir || !(siz = sizeof(dest_dir))) {
    return;
  }

  /** Lava flows to adjoining rooms **/
#if DEBUG
  tell_room(rm, "Lava Flows\n");
#endif  
  /** Build Exit array **/
  for( i=0; i<siz; i+=2 ) {
#if DEBUG
  tell_room(rm, "Lava exit: "+dest_dir[i]+"\n");
#endif  
    if (!exits || !sizeof(exits))  
      exits = ({ dest_dir[i] });
    else exits += ({ dest_dir[i] });
  }

  if( !exits || sizeof(exits) == 0 )
    return;

  targ = exits[ random(sizeof(exits)) ];
  /** Ensure the lava will only spread in my areas that have full path names **/
  if( sscanf(targ, "/players/dragnar/%s",junk) != 1 ) {
#if DEBUG
  tell_room(rm, "Lava unable to flow.\n");
#endif  
    return;
  }
#if DEBUG
  tell_room(rm, "Lava targ: "+targ+" size: "+sizeof(exits)+"\n");
  tell_room(rm, "Lava exits: "+exits[0]+"\n");
#endif  
    /** Ensure the room is loaded **/
    Room = find_object( targ );
    if( !Room )
      call_other( targ, "load_file" );

    if( !present("spire_lava", find_object(targ) ) ) { 
#if DEBUG
  tell_room(rm, "Lava flowing\n");
#endif  
      move_object( clone_object(basename(this_object())), targ);
      i = member_array( targ, dest_dir );
      tell_room( rm, HIR+"Lava flows from the room to the "+dest_dir[i+1]+"!\n"+NORM);
      tell_room( targ, HIR+"\n\nLava flows into the room!\n"+NORM );
    }
}

string query_long() {
  string str;
  str = long_desc;
  if( blocked_dir && sizeof(blocked_dir) > 0 ) {
    str += "\tLava is blocking exits: "+HIR+
           implode( blocked_dir, ", ")
           +NORM+"\n";
  }
  return str;
}

remove_object() {
  set_heart_beat(0);
  destruct( this_object() );
  return 1;
}

get() { return 0; }
