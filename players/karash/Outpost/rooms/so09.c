
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so09.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the computer room where John Romero will spawn.
 * 
 * History:
 *          
 ******************************************************************************/

object jrpresent;
int jrhp, jrmhp;
void destroy_inventory();
 
 
reset(arg)
{
  ::reset(arg);
  
  jrpresent = present("john romero",this_object());
  
  if( !jrpresent ) 
  {
    move_object(clone_object("/players/karash/Outpost/mobs/romero"), this_object());
  }
  
  if(jrpresent)
  {
    jrhp = jrpresent->query_hp();
    jrmhp = jrpresent->query_mhp();
    
	/** For Testing **
	tell_room(this_object(),"HP = "+jrhp+"\n");
    tell_room(this_object(),"MaxHP = "+jrmhp+"\n");
	******************/
  }
  
  
  /**************************************************************************** 
   * If Romero-Proud or Romero-Criticized is present, but not being attacked  *
   * and at full health, then auto-reset will destruct mob and replace with   *
   * basic Romero mob.                                                        *
   * Note: Used query_level to identify mobs to replace since they have the   *
   * same name and I cannot find a way to query short description             *
   ****************************************************************************/
  if(jrpresent && jrpresent->query_level() > 22 && !jrpresent->query_attack() &&
      jrhp == jrmhp )
  {
    /*****************************************************************************
    /* Destroy John Romero and his inventory, then replace with basic Romero mob */
	/*****************************************************************************/
	tell_room(this_object(),"John Romero calms down and returns to normal.\n");
	destroy_inventory();
	destruct(jrpresent);
    move_object(clone_object("/players/karash/Outpost/mobs/romero"), this_object());
  }
  
  if(arg) return;
  short_desc = GRY+"Slipgate Command Center"+NORM;
  long_desc=
"    A chill of cold air hits you as you enter this area.  Computer\n\
equipment fills the entirety of this room.  Racks of servers occupy\n\
the far wall from the floor to the ceiling.  In front of the server\n\
racks, there is a line of backup power supplies stretching from one\n\
wall to the other.  Video displays showing indistinguishable graphs\n\
and images are lined across the near walls above a counter lined with\n\
keyboards.  There is a constant hum of computer fans, along with the\n\
hum of the air conditioner, almost drowning out the sound of the\n\
generator heard outside through the wall.\n";
  set_light(1);
  items=({
    "servers",
"Racks of computer equipment line the far wall.  Their use is not\n\
apparent",
    "racks",
"One might stretch their hands out in front of them and say, 'These\n\
are huge racks!'",
    "computers",
"There are a LOT of computers in this room.  What is their purpose?",
	"computer equipment","&computers&",
	"equipment","&computers&",
    "monitors",
"There are many graphs and images on display, but they don't make\n\
much sense at the moment",
    "graphs","&monitors&",
    "images","&monitors&",
    "displays","&monitors&",
    "keyboards",
"Did you know keyboards are germ carriers?  You wonder how clean\n\
these are",
	"power supplies",
"These large black power supplies line the floor with many cords\n\
stretching under the server racks",
	"cords",
"Various cords from all of this equipment seem to be bundled in all\n\
corners of the room",
	"corners",
"There seems to be computer equipment and various cords stretching\n\
from wall to wall",
	"wall",
"The back wall is blocked by the huge server rack with a counter full of\n\
computers lined along the other walls",
	"walls","&wall&",
	"counter",
"There's a counter that lines most of the walls here with many computer\n\
keyboards and displays on top",
    "generator",
"You cannot see the generator.  Because.It.Is.Out.Side. <sigh>",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so08","south",
  });

}


void init()
{
  ::init();
}


/************************************************************
 * This is to destroy John Romero inventory when destruction is called
 ************************************************************/
void destroy_inventory() {
  int ri, rsize;
  object *rinv;
  rinv = all_inventory( jrpresent );
  for( ri=0, rsize = sizeof(rinv); ri < rsize; ri++ )
  {
  destruct(rinv[ri]);
  }
}

