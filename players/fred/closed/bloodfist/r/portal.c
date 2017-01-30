inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){
	if(arg) return;

  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "sconces",
      "There are four sconces mounted on the walls of the room",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "portal",
      "The swirling red portal of light leads to some unknown\n"+
      "place.  To enter it just walk east into the light",
  });

  dest_dir=({
    DIR + "r/meeting.c",               "west",
    "/players/saber/ryllian/portal.c", "east",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
     write("It is dark.\n");
     return;
  }
long_desc =
"  This is a narrow room that has been dug out of the mountain.  It\n"+
"connects with the meeting room to the west.  The room slants down\n"+
"at a slight angle to the east, towards a mass of swirling red light.\n"+
"The magical portal makes up all of the eastern wall of the room.  Two\n"+
"sconces are mounted on either side of the room, however neither of\n"+
"them are lit.\n"+
"    There is one obvious exit: west\n";
  if(!str)
    write(long_desc);
  if(!items)
	  return;
  i = 0;
  while(i < sizeof(items))
  {
	  if(items[i] == str)
    {
	    write(items[i+1] + ".\n");
	    return;
    }
	i += 2;
  }
}
