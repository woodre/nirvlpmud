inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short(BOLD+GRN+"Shamot village"+NORM);
set_long(
"  The dirt road turns through the village.  A large tree has been\n"+
"formed into a tavern to the east.  Above the door hangs a sign with\n"+
"a goblet engraved on it.  From within the open doors the sound of \n"+
"talking and laughing can be heard.\n");

items = ({
	"tree",
	"The tree has been hollowed out to provide patrons into the tavern",
	"road",
        "The dirt road bends leading to the south and the west",
	"sign",
        "An old weathered sign with a picture of a goblet on it",
        "door",
        "The door to the tavern lay open to allow all to enter the fine establishment"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/village1.c","southwest",
	"/players/catacomb/MF/rooms/village5.c","tavern",
        "/players/catacomb/MF/rooms/village6.c","west"
	});
}
init(){
  ::init();
      add_action("party","listen");  
  }

party(str)
{
  if (!str)
  {
	write("What?\n");
	return 1;
  }
  else
  {
  	write("The sound of mumbled voices and laughter can be heard from within\n"+
      	  "the tavern.\n");
  	return 1;
  }
}