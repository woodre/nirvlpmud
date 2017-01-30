inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("Meserir Forest");
set_long(
" The fog seems to disapate to the south.  Through the clearing a\n"+
"large fountain can be seen, it appears to be almost surreal.  The\n"+
"moans are almost inaudible here, making it seem very peaceful.  \n"+
"Perhaps this is the spot that the Shamot were talking about in the\n"+
"Yeroc legend.  The clearing looks very inviting but is it all just \n"+
"an illusion?\n");

items = ({
	"fog",
	"The fog is very light here making it easy to see the clearing",
	"clearing",
	"A fogless area looking almost like an illusion"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest12.c","north",
	"/players/catacomb/MF/rooms/Forest15.c","west",
	"/players/catacomb/MF/rooms/Forest17.c","east",
	"/players/catacomb/MF/rooms/Clearing1.c","clearing"
	});
}
