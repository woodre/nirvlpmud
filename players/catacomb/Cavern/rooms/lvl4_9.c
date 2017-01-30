#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
" The cavern walls stop abruptly here.  On the side walls some \n"+
"kind of substance is smeared.  The wall to the south blocks passage\n"+
"to the south.  A low rumbling can be heard on the other side of\n"+
"southern wall.\n");

if(!present("lich"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/lich2.c"),
	    this_object());

items = ({
  "walls",
  "The walls have some substance smeared about them",
  "substance",
  "The substance appears to be some kind of sludge",
  "sludge",
  "The sludge drips down the side walls forming something that looks like a rune",
  "rune",
  "The rune appears to say 'recite'",
  "wall",
  "The wall to the south is a sturdy structure of rocks",
  "rocks",
  "The rocks stop all from proceeding further south",
  "rock",
  "One rock appears to be loose and could possible be 'move'd"
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_8.c","north"
});
}

init(){
  ::init();
      add_action("moveShit","move");  
  }

moveShit(str)
{
  if (str != "rock")
  {
	write("What?\n");
	return 1;
  }
  else
  {
  	write("You move the loose rock and open the pathway into Shimmergloom's\n"+
      	  "cavern.\n");
  	TP->move_player("move#players/catacomb/Cavern/rooms/dc1.c");
  	return 1;
  }
}
