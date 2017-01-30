inherit "room/room";	/*  tower3.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, thestring;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;
	thestring = 1;

  if(arg) return;
 short_desc="Auseth's Tower";
 long_desc=
"This is a small side room of the tower.  The only exit is the open door\n"+
"that leads back to the entry of the tower.  The walls of the room are\n"+
"covered in various pieces of equipment, ranging from suits of armor to\n"+
"swords.  Numerous treasure chests are lying against the walls.  There\n"+
"are two sconces on the walls, however neither are lit.\n";
 set_light(0);
 items=({
	 "door",
"The simple oak door leads out to the main entry of the tower",
	 "walls",
"The walls are made of the dull grey stone.  They are covered in racks\n"+
"filled with equipment",
	 "equipment",
"Nearly every kind of equipment is hanging from the walls of the room.\n"+
"All of it is designed for use by a human, or someone of a similar body\n"+
"structure.  Most of the equipment is used, and not in very good shape",
	 "swords",
"Some battered old swords are lining the walls of the room.  One of them\n"+
"even appears to have some blood on it",
	 "suits",
"Numerous suits of armor are hanging from the walls.  Most of them have\n"+
"small dents and a few even have cracks in them",
	 "armor",
"All types of armor line the walls",
	 "racks",
"The racks are made of wood and look fairly rudamentary",
	 "chests",
"The treasure chests are all lined up against the wall, beneath the hanging\n"+
"equipment.  They are all rather plain looking.  Each one is locked and\n"+
"there is no way to open them",
	 "sconces",
"The sconces are hanging on the walls, one near the doorway and one near\n"+
"the back of the room.  Neither looks like it has been lit in ages",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower2.c", "west",
 });
}


void init(){
	::init();
	add_action("w_dir", "west");
	add_action("search_cmd", "search");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

status search_cmd(){
	if(!thestring)
		write("You search the room and discover nothing.\n");
	if(thestring){
	write(
	"You search the room and find a piece of string lying on the ground.\n");
	MO(CO("/players/zeus/realm/OBJ/string.c"), TP);
	thestring = 0;
	return 1;
	}
	return 1;
}