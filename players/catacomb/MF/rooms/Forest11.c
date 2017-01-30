inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  A giant willow tree stands to the east grieving for all of the\n"+
"lost souls.  Each branch touching the ground is an unfortunate \n"+
"death of an adventurer.  The bark on the trunk of the tree even\n"+
"appears to be frowning in mourning. \n");

items = ({
	"willow",
	"An extremely large tree that has survived the horrors of the forest",
	"tree",
	"An extremely large tree that has survived the horrors of the forest",
	"branch",
	"Hundreds of the branches reach to the ground in rememberence of the dead",
	"branches",
	"Hundreds of the branches reach to the ground in rememberence of the dead",
	"ground",
	"The ground is torn up as if something dug it's way out",
	"bark",
	"The bark of the tree gives the appearance of an eerie face",
	"trunk",
	"The bark of the tree gives the appearance of an eerie face",
	"face",
	"The face formed looks as if it is a crying elf"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Forest7.c","northwest",
	"/players/catacomb/MF/rooms/Forest14.c","southwest"
	});
}
