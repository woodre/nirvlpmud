#include <ansi.h>
#include "../defs.h"

#define PATH "players/dragnar/WalkingDead/obj/walker_objs/"
/******************************************************************************
 * Program: WalkingDeadDM.c
 * Path: /players/dragnar/WalkingDead/obj
 * Type: Daemon
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: This is the main daemon for the WalkingDead area. It keeps track
 *          of all the walkers in the area, and objects check this daemon
 *          to see if it is possible to re-animate a corpse into a Walker.
 *          It also keeps track of walker obj treasure, and loads the
 *          forest rooms with Walkers. It also automates the cloning
 *          of walkers, which may include pulling a player .o file from
 *          players that have died in this area previously. This object
 *          resets every 90 mins so that more walkers can be re-animated.
 * History:
 *          06/09/2013 - Dragnar
 *            Created
 ******************************************************************************/

static object *walkers;

static mapping items;

/** Mapping array of possible tier of items on a walker corpse **/
static mapping item_tier_perc;

/** Total walker size, level 20 is size 1, 26 size 7 **/
static int current_walker_size;
static int total_walker_size;

/** Array of Rooms **/
static string *forest;
static string *town;
static string *area;

/** For walker item restore **/
string tier;
string name;
string *ids;
string item_short;
string item_long;
int weight;

/** For Dead Player restore **/
int level, ex_level, height_ft, height_in, player_weight, player_killing;
string player_name, gender, title, pretitle, race, clan_name, description, al_title;
string *extra_look;

initalizeDM() {
  if( !items )
    setup_walker_objs();
  
  if( !forest )
    forest = ({ 
      "/players/dragnar/WalkingDead/rooms/f1.c",
      "/players/dragnar/WalkingDead/rooms/f2.c",
      "/players/dragnar/WalkingDead/rooms/f3.c",
      "/players/dragnar/WalkingDead/rooms/f4.c",
      "/players/dragnar/WalkingDead/rooms/f5.c",
      "/players/dragnar/WalkingDead/rooms/f6.c",
      "/players/dragnar/WalkingDead/rooms/f7.c",
      "/players/dragnar/WalkingDead/rooms/f8.c",
      "/players/dragnar/WalkingDead/rooms/f9.c",
      "/players/dragnar/WalkingDead/rooms/f10.c",
      "/players/dragnar/WalkingDead/rooms/f11.c",
      "/players/dragnar/WalkingDead/rooms/f12.c",
      "/players/dragnar/WalkingDead/rooms/f13.c",
      "/players/dragnar/WalkingDead/rooms/f14.c",
      "/players/dragnar/WalkingDead/rooms/f15.c",
      "/players/dragnar/WalkingDead/rooms/f16.c",
      "/players/dragnar/WalkingDead/rooms/f17.c",
      "/players/dragnar/WalkingDead/rooms/f18.c",
      "/players/dragnar/WalkingDead/rooms/f19.c",
      "/players/dragnar/WalkingDead/rooms/f20.c",
      "/players/dragnar/WalkingDead/rooms/f21.c",
      "/players/dragnar/WalkingDead/rooms/f22.c",
      "/players/dragnar/WalkingDead/rooms/r1.c",
      "/players/dragnar/WalkingDead/rooms/r2.c",
      "/players/dragnar/WalkingDead/rooms/r3.c",
      "/players/dragnar/WalkingDead/rooms/r4.c",
      "/players/dragnar/WalkingDead/rooms/p1.c",
      "/players/dragnar/WalkingDead/rooms/p2.c",
    });
  
  if( !town )
    town = ({
    	"/players/dragnar/WalkingDead/rooms/t1.c",
    	"/players/dragnar/WalkingDead/rooms/t2.c",
    	"/players/dragnar/WalkingDead/rooms/t3.c",
    	"/players/dragnar/WalkingDead/rooms/t4.c",
    	"/players/dragnar/WalkingDead/rooms/t5.c",
    	"/players/dragnar/WalkingDead/rooms/t6.c",
    	"/players/dragnar/WalkingDead/rooms/t7.c",
    	"/players/dragnar/WalkingDead/rooms/shop.c",
    	"/players/dragnar/WalkingDead/rooms/r5.c",
    	"/players/dragnar/WalkingDead/rooms/r6.c",
    	"/players/dragnar/WalkingDead/rooms/r7.c",
    	"/players/dragnar/WalkingDead/rooms/r8.c",
    });
    
  if( !area ) {
  	area = forest;
  	area += town;
  }
            
  if( current_walker_size < 1 )
    initalize_rooms();
    
  /** Reset every 90 minutes **/
  if( find_call_out("ResetTotalWalkerSize") < 0 )
    call_out( "ResetTotalWalkerSize", 2700 );
    
  if( find_call_out("WalkingDeadDM_Animate") < 0 )
    WalkingDeadDM_Animate();
}

initalize_rooms() {
  int i, size;
  
  size = 1 + random( WALKER_SIZE_LIMIT + 12 );
  if( size <= WALKER_SIZE_LIMIT - 10  )
    size = WALKER_SIZE_LIMIT - 10;
    
  /** Setup an inital swarm of Walkers **/
  for( i=0; i < size && CheckWalkerStatus(); i++ ) {
    move_object( clone_walker(), forest[random(sizeof(forest))] );
  }
}

status
CheckWalkerStatus(int roomcheck) {
  int size;
  size = WALKER_SIZE_LIMIT;
  if( roomcheck )
    size += 7;
  
  if( current_walker_size > size ||
      total_walker_size > size  )
    return 0;
  else
    return 1;
}

WalkingDeadDM_Animate() {
  int i, size;
  object room;
  
  for( i=0, size = sizeof(area); i < size; i++ ) {
    call_other(area[i], "combine_walker_check");
	
	if( CheckWalkerStatus( 1 ) )
      call_other(area[i], "reanimate_corpse");
    
  }
  
  if( find_call_out("WalkingDeadDM_Animate") < 0 )
    call_out( "WalkingDeadDM_Animate", 9 + random(9) );
}

print_mapping() {
  int i, size;
  object rm;

  for( i=0, size=sizeof(walkers); i < size; i++ ) {
    if( objectp(walkers[i]) ) {
      write("   level: "+ walkers[i]->query_level() + " HP: " + walkers[i]->query_hp() );
      rm = environment(walkers[i]);
      if( rm ) {
#ifndef __LDMUD__ 
        write(" env: "+ file_name( rm ) + "\n");
#else
        write(" env: "+ object_name( rm ) + "\n");
#endif
    }
    else
      write(" env: null\n");
        /*}*/
    }
  }
  if( this_player()->query_level() >= 40 ) 
    write("\tCurrent walker size: " + current_walker_size + "\tTotal size: "+ total_walker_size+"\n");
}

display() {
  int cols;
  string color;
  
  if( !walkers )
    walkers = ({  });
    
  initalizeDM();
    
  if( this_player() && this_player()->query_level() >= 40 ) {
    print_mapping();
  }
  
  write("\n\
       ___        __           _   _               _                   _\n\
      |_ _|_ __  / _| ___  ___| |_(_) ___  _ __   | |    _____   _____| |\n\
       | || '_ \\| |_ / _ \\/ __| __| |/ _ \\| '_ \\  | |   / _ \\ \\ / / _ \\ |\n\
       | || | | |  _|  __/ (__| |_| | (_) | | | | | |__|  __/\\ V /  __/ |\n\
      |___|_| |_|_|  \\___|\\___|\\__|_|\\___/|_| |_| |_____\\___| \\_/ \\___|_|\n\n");

  /** Calculate percentage of total walkers allowed **/
  cols = current_walker_size *100 / WALKER_SIZE_LIMIT;
  switch( cols ) {
    case 0..30:
      write(HIG);
      break;
    case 31..70:
      write(HIY);
      break;
    default:
      write(HIR);
      break;
  }
  
  /** Adjust to a line limit of 80 **/
  cols = cols * 80 / 100;
  
  if( cols == 0 )
    cols = 1;
    
  if( cols > 80 )
    cols = 80;
  
  write( pad("", cols, '#') );
  write( "\n" );
  write( pad("", cols, '#') );
  write( "\n" );
  write( pad("", cols, '#') );
  write( "\n" +NORM );
  return 1;
}

ResetTotalWalkerSize() { 
  total_walker_size = 0; 
  if( find_call_out("ResetTotalWalkerSize") < 0 )
    call_out( "ResetTotalWalkerSize", 2700 );
}

RegisterMob( object mob ) {
  int lev;

  if(!mob)
    return;
    
  if( !walkers )
    walkers = ({  });
    
  lev = mob->query_level();
  
  /** Verify mob is not already in the mapping **/
  if( member_array( mob, walkers ) >= 0 )
    return;
  
  if( lev == WALKER_START )
    total_walker_size += mob->query_walker_size();
  
  current_walker_size += mob->query_walker_size();
    
  walkers += ({ mob });
  
}

DeregisterMob( object mob ) {
  int lev;
  int i, size;
  int found;
  mixed *k;
  
  if( !walkers )
    walkers = ({  });
    
  if( !mob )
    return;
    
  if( member_array( mob, walkers) < 0 )
    return;
  
  if( objectp(mob) ) {
    lev = mob->query_level();
    current_walker_size -= mob->query_walker_size();
  }
  
  walkers -= ({ mob });
  
}

setup_walker_objs() {
  int x, size;
  string *dir;
  string obj;
  mapping map;
  
  dir = get_dir( "/" + PATH + "*.o" ); 
  /******************************************************************
   * Items is a mapping, with arrays of mappings 
   * items["1"] will return an array of tier 1 items, each one being
   * a mapping with name, ids, short, long, and weight of the item.
   *****************************************************************/
  items = ([ "1": ({ })
            ,"2": ({ })
            ,"3": ({ })
            ,"4": ({ })
            ,"5": ({ })	]);

  for( x = 0, size = sizeof( dir ); x < size; x ++ ) {
    
    if( sscanf(dir[x], "%s.o", obj) ) 
    {
      if( restore_object(PATH+obj) ){
        items[tier] += ({ ([ "name": name
                         ,"ids": ids
                         ,"short": item_short
                         ,"long": implode(explode(item_long, "|"), "\n") + "\n"
                         ,"weight": weight 
                ]) });
      }
    }
  }
  
}

mapping
get_walker_obj( mixed tier ) {
  mixed *objs;
  string str;
  
  if( !tier )
    return 0;
  
  if( intp( tier ) ) {  
    switch( tier ) {
      case 1:
        str = "1";
        break;
      case 2:
        str = "2";
        break;
      case 3:
        str = "3";
        break;
      case 4:
        str = "4";
        break;
	  case 5:
	    str = "5";
		break;
      default:
        str = "1";
        break;
    }
  }
  else
    str = tier;
  
  if( !items )
    setup_walker_objs();

  objs = items[ str ];
  
  if( sizeof(objs) == 0 ) {
    setup_walker_objs();
    objs = items[ str ];
  }
    
  /** Return a random object from the tier requested **/
  return objs[random(sizeof(objs))];
}

setup_item_tier_perc() {
  /**********************************************************************
   * Matrix that is used when a corpse is searched
   * Tier 1 -  1000 =  500 + r1000
   * Tier 2 -  2500 = 1000 + r3000
   * Tier 3 -  5000 = 2000 + r6000
   * Tier 4 - 10000 = 3000 + r14000
   * Tier 5 - 20000 = 6000 + r28000
   *
   * Example: Level 23 mob has 10% chance of getting 3 items tiers 3, 2,
   *          and 1. Odds are impossible but max could be as high as
   *          8000 + 4000 + 1500 = 13,500 but will average 8500. Higher
   *          than allowed 8k for level 23, but mob will average 7850 due
   *          to the other 90% being lower amounts. On the other extreme
   *          payout could be as low as 3000.
   *
   * Level  Avg Payout
   * 20      4,900
   * 21      5,900
   * 22      6,700
   * 23      7,850
   * 24      9,900
   * 25     10,800
   * 26     14,000
   ***********************************************************************/
  item_tier_perc = ([ 
    "20": ({ "2,1", "2,1", "2,2,1", "2,1,1", "3," , "3," , "3," , "3,1", "3,1", "3,1" })
   ,"21": ({ "3,1", "3,1", "3,1", "2,2,1", "2,2,1", "2,2,1", "2,1,1", "2,1", "3,2", "3,2" })
   ,"22": ({ "3,1", "3,1", "3,1", "3,1", "3,1", "3,1", "3,1", "3,2", "3,2", "4"  })
   ,"23": ({ "2,2,2", "2,2,2", "2,2,2", "2,2,2", "3,2", "3,2", "3,2", "3,2", "3,2,1", "4"  })
   ,"24": ({ "3,2", "3,2", "3,2", "3,2", "4,1", "4,1", "4,1", "4,1", "4,2", "4,2" })
   ,"25": ({ "4", "4", "4", "4", "4", "4", "4,1", "4,1", "4,1", "4,3" })
   ,"26": ({ "4,2", "4,2", "4,2", "4,2", "3,3",  "3,3,2",  "4",  "4,4", "4,5", "5"  })
     ]);
 }

object *
get_walker_objs( int corpse_level ) {
  int i, size;
  string str;
  string *ob_tier;
  string *tiers;
  object *treasure;
  
  if( !item_tier_perc )
    setup_item_tier_perc();
  
  switch( corpse_level ) {
    case 21:
      str = "21";
      break;
    case 22:
      str = "22";
      break;
    case 23:
      str = "23";
      break;
    case 24:
      str = "24";
      break;
    case 25:
      str = "25";
      break;
    case 26:
      str = "26";
      break;
    default:
      str = "20";
      break;
  }
  
  ob_tier = item_tier_perc[str];
  str = ob_tier[random(sizeof(ob_tier))];
  tiers = explode( str, "," );
  size = sizeof( tiers );
  treasure = allocate( size );
  for( i = 0; i < size; i++ ) {
    if( !random(4) && atoi(tiers[i]) == 2 ) {
      treasure[i] = clone_object("/players/dragnar/WalkingDead/heals/mons/advil");
    }
    else if( !random(3) && atoi(tiers[i]) == 3 ) {
      treasure[i] = clone_object("/players/dragnar/WalkingDead/heals/mons/vicodin");
    }
    else if( !random(4) && atoi(tiers[i]) == 4 ) {
      treasure[i] = clone_object("/players/dragnar/WalkingDead/heals/mons/percocet");
    }
    else { 
      treasure[i] = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
      treasure[i]->set_value_tier( atoi(tiers[i]) );
      treasure[i]->set_object_stats();
    }
  }
  if( !random(5) )
    treasure += ({ clone_object("/players/dragnar/WalkingDead/heals/mons/meth.c") });
  
  return treasure;
}

set_player_attributes( object walker ) {
  int x,size;
  string strl, strs;
  
  if( ex_level > 0 )
    DEADDM->DeregisterMob( walker );
  
  switch( ex_level ) {
    case 1..15:
      walker->set_walker_level( 21 );
      break;
    case 16..31:
      walker->set_walker_level( 22 );
      break;
    case 32..47:
      walker->set_walker_level( 23 );
      break;
    case 48..63:
      walker->set_walker_level( 24 );
      break;
    case 64..79:
      walker->set_walker_level( 25 );
      break;
    case 80..1000:
      walker->set_walker_level( 26 );
      break;
  }
   
  walker->set_name( player_name );
  walker->set_gender( gender );
  walker->add_walker_id( player_name );
  strs = BOLD + BLK +"Walking Dead "+NORM+capitalize(player_name) + " " + title;
  if( pretitle )
    strs = pretitle + " " + strs;
  if( al_title )
    strs += " ("+al_title+")";
  if( clan_name )
    strs += " <"+capitalize(clan_name)+" Clan>";
  if( player_killing )
    strs = HIR+"[PK]"+NORM+" " +strs;
  
  walker->set_short( strs );
  if( description )
    strl = capitalize(player_name) + " " +description+"\n";
  
  strl = (strl ? strl : "") + capitalize(player_name)+" is an "+race+ ", "+height_ft+" feet "+height_in+" inches tall, "+player_weight+" lbs.\n";
  if( player_killing )
    strl += RED+capitalize(player_name)+" can fight other players.\n"+NORM;
  for( x=0, size=sizeof( extra_look ); x < size; x++ ) {
    if( extra_look[x] )
      strl += extra_look[x] + ".\n";
  }
  walker->set_long( strl );
  
  if( ex_level > 0 )
    DEADDM->RegisterMob( walker );
}

restore_dead_player( object walker ) {
  int x,size;
  string obj;
  string *dir;
  
  dir = get_dir( "/" + SAVE_PATH + "*.o" );


  size = random( sizeof( dir ) );

  if( sizeof(dir) > 0 && sscanf(dir[size], "%s.o", obj) ) 
  {
    if( restore_object(SAVE_PATH+obj) ){
      set_player_attributes( walker );
    }
  } 
}

object
clone_walker( int level ) {
  object walker;
  
  if( !level )
    level = WALKER_START;
    
  walker = clone_object("/players/dragnar/WalkingDead/mons/walker");
  walker->set_walker_level( level );
  RegisterMob( walker );
  walker->set_registered_flag(); 
  if( !random(7) )
    restore_dead_player( walker );
  return walker;
}
