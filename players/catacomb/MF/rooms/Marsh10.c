inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short(BLK+"A dark marsh"+NORM);
set_long(
"  The stench of mildew invades the area.  The bogs of the marsh\n"+
"consume everything that touch them.  Small rocks break the \n"+
"surface of the murky water.  Cattails and other weeds are scattered\n"+
"throughout the area.\n");

items = ({
	"bogs",
	"The muddy and murky water blends together to form the ground",
	"rocks",
	"Rocks break the surface forming paths through the marsh",
        "cattails",
        "Small vegetitation trying to survive in these conditions",
        "weeds",
        "Small vegitation trying to survive in these conditions",
        "surface",
        "The surface of the muddy waters sits unmoving waiting to engulf whatever touches it",
        "water",
        "The surface of the muddy waters sits unmoving waiting to engulf whatever touches it"
	});

dest_dir = ({
        "/players/catacomb/MF/rooms/Marsh9.c","west",
        "/players/catacomb/MF/rooms/Marsh6.c","north"
	});

}
