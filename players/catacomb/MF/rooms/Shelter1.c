inherit "room/room";
#include <ansi.h>
#define TP this_player()

reset(arg){
    if(arg) return;
set_light(1);
set_short(BLU+"Yeroc's hut"+NORM);
set_long(
"  The room is filled with debris.  The floor is made up of nothing\n"+
"but dirt.  Deep scars cover the floor as if something was trying to\n"+
"claw its way around.  Three doors lead off from the entrance room.\n"+
"One door leads out to the dark marsh.  A second door is intricately\n"+
"carved in the form of an elven maiden.  The third door is covered \n"+
"in stained glass.\n");

items = ({
	"debris",
	"The debris is scattered throughout the room making a mess",
	"floor",
	"The floor is covered in deep scratches",
   	"scars",
	"They seem to be from some sort of creature",
 	"scratches",
	"The scars seem to be from some ort of creature",
	"doors",
	"Three doors are here to choose from",
    	"door",
	"Which door do you want to look at 'maiden', 'glass', and 'wood'",
   	"maiden",
	"The door has been carved in the form of a maiden, perhaps you could 'open' it",
	"glass",
	"The stained glass cast different color lights about the room",
	"lights",
	"The lights beckon you to 'open' the 'glass' door",
	"wood",
	"The wood door leads out to the marsh"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Marsh7.c","out"
	});
}
init(){
  ::init();
      add_action("OpenUp","open");  
  }

OpenUp(str)
{
  if ((str != "maiden") || (str != "glass"))
  {
	write("Try open maiden or open glass\n");
	return 1;
  }
  if (str == "maiden")
  {
  	write("As you open the door, the carving of the maiden seems to\n"+
      	  "watch your every move\n");
  	TP->move_player("open#players/catacomb/MF/rooms/shelter2.c");
  	return 1;
  }
  if (str == "glass")
  {
      write("A bright "+RED+"light"+NORM+" almost blinds you as you open\n"+
	      "the stained glass door\n");
	TP->move_player("open#players/catacomb/MF/rooms/shelter3.c");
	return 1;
  }
  else
  {
	write("What you talking bout Willis?\n");
	return 1;
  }
}
