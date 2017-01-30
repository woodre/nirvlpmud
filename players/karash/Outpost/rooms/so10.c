
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so10.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the slipgate room leading to other areas. 
 * 
 * History:
 *          
 ******************************************************************************/

 int jctalking;
 
reset(arg)
{
    ::reset(arg);
	
	if( !present("john carmack") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/j_carmack"), this_object());	
	
	if(arg) return;
   short_desc = GRY+"Slipgate Room"+NORM;
 long_desc=
"    This room is much darker than the other rooms and seems like the\n\
room has been soundproofed also.  The entire room is either painted or\n\
covered in black material, but the lights emanating from the large\n\
raised platform in the center of the room provides plenty of light to\n\
notice the podium in the corner with an open laptop sitting upon it.\n\
This must be the infamous 'slipgate' those in the compound have been\n\
blathering about.  What is going on here?  Who or what is this enemy\n\
they call 'Quake'?  Maybe you can 'enter' to help the cause.\n";
  set_light(1);
  items=({
    "podium",
"A podium stands about chest-high in the corner of the room.  There is\n\
a thick heavy-duty laptop opened on top of the podium",
    "laptop",
"This single laptop seems to be all that is visably connected to\n\
the 'slipgate'",
    "slipgate",
"    There is a platform in the center of the room made from some hard\n\
metal material.  It is raised about a foot from the ground and covers\n\
about a five-foot square area with lights on each corner lighting the\n\
room with a dull orange hue.  Slipgates are devices conceived and\n\
developed by a think-tank group calling themselves the 'id', which\n\
consisted of highly technical individuals and, surprisingly,\n\
gamesmasters.  Simply standing on the raise platform seems like the\n\
way to 'enter' this slipgate",
    "platform","&slipgate&",
	"lights",
"There is a small dome light on each corner of the raised platform in the\n\
center of the room, lighting the room with a dull orange hue",
    "door",
"The exit to the room is to the north.  The door is tinted completely\n\
black, but it remains propped open",
    "notice",
"There is no such thing in this room",
	"stool",
"It is a device for sitting and is currently being used by a brilliant man",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so08","north",
  });

}

void init()
{
  ::init();
  	add_action("get_laptop", "get");
	add_action("get_laptop", "take");
	add_action("quake_info", "enter");
	add_action("quake_info", "slipgate");
	
}


get_laptop(str)
{
  if(str == "laptop")
    tell_object(this_player(),"This laptop seems to be the main controlling device for the slipgate\n\
and the main tool used by John Carmack to work on it's engine.\n\
Taking this device will give him a sad face.  Don't give John a sad face.\n");
  return 1;
}


/***************************************************************************
 * When a player tries to enter the slipgate, this will trigger John Carmack 
 * to explain the purpose of this area and hint at future areas. 
 * Once other areas open, the slipgate will be functional and this explanation
 * will be changed.
 ****************************************************************************/
quake_info(str)
{
  if(jctalking) 
  {
    tell_object(this_player(),"Hold on. John is talking.\n");
	return 1; 
  }
  if(str == "slipgate" || "platform" || !str)
  {
    if(!present("john carmack"))
	{
	  tell_object(this_player(),"This is where John Carmack would explain to you about the slipgate and\n\
the the reason it is not currently working, but for some reason he is\n\
not here.  So, you'll have to come back later to get all the details.\n");
      return 1;
    }
    if(present("john carmack"))
	{
	  jctalking = 1;
	  tell_room(this_object(),"\n\John Carmack stops you and says:\n\n\
"+CYAN+"    Hold on there, strong one.  I admire your enthusiasm, but,\n\
unfortunately, we are not ready to send in new recruits yet.  In the\n\
meantime, let me give you some details."+NORM+"\n");
	  call_out("quake_info2",3);
	  return 1;
	}
  }
}

quake_info2()
{
  tell_room(this_object(),"\n"+CYAN+"    Slipgates were originally developed for instantaneous transport\n\
from one place to another, and with the right programming, the\n\
slipgate can access any other in existence.  I was part of the group"+NORM+"\n");
  call_out("quake_info2b",2);
  return 1;
}

quake_info2b()
{
  tell_room(this_object(),CYAN+"that created and developed the technology.  In fact, unbeknown to the\n\
general public, slipgates have been instrumental in many military"+NORM+"\n");
  call_out("quake_info2c",2);
  return 1;
}

quake_info2c()
{
  tell_room(this_object(),CYAN+"excursions in the past, including most of Commander Keen's missions\n\
and the classified "+HIC+"Project Doom"+NORM+".\n");
  call_out("quake_info3",3);
  return 1;
}

quake_info3()
{
  tell_room(this_object(),"\n"+CYAN+"    Unfortunately, the technology has been compromised.  An entity we\n\
have codenamed "+HIR+"Quake"+NORM+CYAN+" has hijacked our slipgates.  This enemy from a\n\
distant dimension, "+HIR+"Quake"+NORM+CYAN+", is preparing to launch an offensive assault"+NORM+"\n");
  call_out("quake_info3b",2);
  return 1;
}


quake_info3b()
{
  tell_room(this_object(),CYAN+"upon us all by instantly transporting its armies into strategic\n\
positions."+NORM+"\n");
  call_out("quake_info4",3);
  return 1;
}


quake_info4()
{
  tell_room(this_object(),"\n"+CYAN+"    Fortunately, I have made a breakthrough in the technology that will\n\
allow access to "+HIR+"Quake's"+NORM+CYAN+" world. Since then, this outpost has been the"+NORM+"\n");
  call_out("quake_info4b",2);
  return 1;
}

quake_info4b()
{
  tell_room(this_object(),CYAN+"headquarters for "+HIC+"Operation Counterstrike"+NORM+CYAN+", a mission to send a team\n\
to assault our enemy first."+NORM+"\n");
  call_out("quake_info5",3);
  return 1;
}


quake_info5()
{
  tell_room(this_object(),"\n"+CYAN+"    However, we have received word that our main "+HIC+"Slipgate Complex"+NORM+CYAN+",\n\
which connects this gate, has already been overrun by "+HIR+"Quake's"+NORM+CYAN+" minions."+NORM+"\n");
  call_out("quake_info5b",2);
  return 1;
}

quake_info5b()
{
  tell_room(this_object(),CYAN+"We believe "+HIC+"Operation Counterstrike"+NORM+CYAN+" has been wiped out, and in the\n\
chaos, all connections to the "+HIC+"Slipgate Complex"+NORM+CYAN+" have been severed due\n\
to containment protocol."+NORM+"\n");
  call_out("quake_info6",3);
  return 1;
}


quake_info6()
{
  tell_room(this_object(),"\n"+CYAN+"    I have been working to link back to the "+HIC+"Complex"+NORM+CYAN+" so that we may\n\
fight back, but it will take some time.  That is when you can help.\n\
Once I reopen this slipgate, I will let you know."+NORM+"\n\n");
  call_out("quake_info6b",2);
  return 1;
}

quake_info6b()
{
  tell_room(this_object(),HIC+"All of Nirvana depends on us... on YOU!"+NORM+"\n\n");
  jctalking = 0;
  return 1;
}