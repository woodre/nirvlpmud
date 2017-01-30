inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The fog takes away all the hope from all who enter into its mists.\n"+
"Several have died after becoming lost deep within the fogs of Meserir\n"+
"Forest.  The portraits of the trees and their frowning branches along\n"+
"with the ever-hungry ground have been enough to drive even the strongest\n"+
"explorer into a psychotic lunatic.\n");

items = ({
	"fog",
	"The fog is very thick making vision very difficult",
	"mists",
	"The fog is very thick making vision very difficult",
	"mist",
	"The fog is very thick making vision very difficult",
	"trees",
	"The trees frown low in their ever-lasting sadness",
	"tree",
	"The trees frown low in their ever-lasting sadness",
	"ground",
	"The ground tries to devour any thing that touches it"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest17.c","west",
	"/players/catacomb/MF/rooms/Forest14.c","north",
	"/players/catacomb/MF/rooms/Forest20.c","southeast"
	});

}
