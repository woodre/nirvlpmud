inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short(BLK+"A dark marsh"+NORM);
set_long(
"  The stench of mildew invades the area.  A small dwelling is placed\n"+
"unafflicted by the darkness of the marsh in front of you.  There is\n"+
"almost a walkway of sort leading up to the door.  The dwelling is just\n"+
"a small makeshift hut.\n");

items = ({
	"dwelling",
	"A small hut of maybe one room",
	"walkway",
	"Rocks form a path that leads up to the hut",
        "hut",
        "The hut has a crude door, and no windows",
        "door",
        "The door to the hut almost begs to be "+MAG+"open"+NORM+"ed",
        "path",
        "A small rock path leading up to the hut"
	});

dest_dir = ({
        "/players/catacomb/MF/rooms/Marsh8.c","east",
        "/players/catacomb/MF/rooms/Marsh1.c","north"
	});

}
init(){
  ::init();
      add_action("KnockKnock","open");  
  }

KnockKnock(str)
{
  if (str != "door")
  {
	write("What?\n");
	return 1;
  }
  else
  {
  	write("You walk up the pathway and slowly open the door, entering into Yeroc's\n"+
      	  "humble home.\n");
  	TP->move_player("open#players/catacomb/MF/rooms/shelter1.c");
  	return 1;
  }
}