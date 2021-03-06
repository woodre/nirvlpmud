/*
 * Portal room. Fast passage to important rooms
 * Balowski@Nirvana, October '95
 * revised by Vertebraker
 * 030715 - added color, fixed exits, and made exits visible
 *          only to shardaks [linus]
 * 030717 - fixed exits so only shardaks can use them properly.
 *          if a non-shardak uses them, they get sent to a random
 *          area defined in bad_exits below. 
 *          Changed the northeast direction to chamber of realms
 *          instead of marble shrine (Feldegast area no longer in game)
 *          [linus]
 * 030717 - removed inheritance of verte's room.c, changed it to
 *          inherit /room/room.c, and added look capability for the holes
 *          manually, recode this all later on I suppose. [earwax]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"

inherit "/room/room.c";

string *bad_exits; /* an array of all the nasty places to send people */

void
create()
{
    set_light(1);
     set_property("PK");
     set_property("NT");
    bad_exits = ({ "/players/linus/Newbie/room/n9a" , "players/eurale/Fiend/mm1" , "/players/wocket/graveyard/crypt4" ,
"/players/mythos/aroom/forest/clear" , "/players/beck/room/venus5" , "/players/dune/closed/guild/rooms/entrance" ,
"/players/arrina/tunnel/tunnel7" , "/players/maledicta/cont/rooms/419" , "/players/softly/winter/rooms/pond9" ,
"/players/jenny/wings/rooms/ice2" });

}

string
short() {
  return RED+"The Portals"+NORM;
}

int move_out(string arg) {
  this_player()->move_player("out#/players/earwax/closed/shardak/room/grotto.c");
  return 1;
}

void
long(string arg) {
 string desc;
 desc = "";
 if((int)this_player()->query_brief() != 2) 
   desc += RED+"The Portals\n"+NORM;
 desc += HIK+"\
Changing winds whirl around, arising from nowhere. One instant biting\n\
cold, the next burning hot. Wailing voices of imprisoned souls cross\n\
dimensions in this warped space. Many wavering holes torn in the fabric\n\
of space provide swift passage to several key locations in Nirvana.\n"+NORM;
 if (present("shardak_mark",this_player())) {
 desc += "\t"+NORM+RED+"\The exits are: north, south, east, west, northwest, northeast,\n\
                       southwest, southeast, and out.\n"+NORM;
  }
 write(desc);
}

int do_look(string arg) {

  int item;
  string what;

  if (!arg) {
    long(0);
    return 1;
  }

  if (sscanf(arg,"at %s",what) != 1)
    what = arg;

  if (what != "holes" && what != "portals" && what != "wavering holes")
    return 0;

  write("  The northern     portal leads to the village green.\n\
  The northeastern portal leads to the chamber of realms.\n\
  The eastern      portal leads into a rift in the space/time continuum.\n\
  The southeastern portal leads to the sea.\n\
  The southern     portal leads to the thieves' lockers.\n\
  The southwestern portal leads to the wheel of time.\n\
  The northwestern portal leads to the ravine.\n\
  The western      portal leads to the dark forests.\n");
  return 1;
}

int
shard_exit(string arg) {
   
  string dest;

  if (!present("shardak_mark",this_player())) {
    dest = bad_exits[random(10)];
    write(RED+"From far off you can hear Shardak laughing...\n"+NORM);
  }
  else {
    string cmd;

    cmd = query_verb();

    switch(cmd) {
      case "north"     : dest = "/room/vill_green"; break;
      case "south"     : dest = "/players/catwoman/tl"; break;
      case "northwest" : dest = "/room/ravine"; break;
      case "northeast" : dest = "/players/mythos/enterance.c"; break;
      case "southwest" : dest = "/room/eastroad5"; break;
      case "southeast" : dest = "/room/sea"; break;
      case "east"      : dest = "/players/saber/ryllian/rift"; break;
      case "west"      : dest = "/room/south/sforst24"; break;
    }
    write("You step into the portals...\n");

  }

  move_object(this_player(),dest); /* should be silent move with this func */
  return 1;
}

void
init(){   
    add_action("shard_exit", "north");
    add_action("shard_exit", "south");
    add_action("shard_exit", "east");
    add_action("shard_exit", "west");
    add_action("shard_exit", "northwest");
    add_action("shard_exit", "northeast");
    add_action("shard_exit", "southwest");
    add_action("shard_exit", "southeast");
    add_action("do_look", "look");
    add_action("do_look", "l");
    add_action("move_out","out");
}

void reset(status arg) {

  if (arg) {
    ::reset(arg);
    return;
  }

  ::reset(0);
  create();
}
