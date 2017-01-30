#define NAME "Shinshi"
#define DEST "room/south/sforst41"
object ROGUES, SCAR, MAKO, SYMBIO, DERVISH;
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "bus"; }

short() {
    return "A large yellow school bus";
}

long() {
    write("A large, yellow bus perfectly symmetrical lined with\n");
    write("twelve windows on each side runs idle. The bus is used\n");
    write("to transport people from one place to another (mainly\n");
    write("used for transporting kids to and from school). The\n");
    write("door to the bus is wide open. One could always 'enter'\n");
    write("it.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
	if(!str){
		write("What would you like to enter?\n");
		return 1;
	}
	
	if(str != "bus"){
		write("You can only enter the bus.\n");
		return 1;
	}
	
	if(str == "bus"){
		write("You climb aboard the bus.\n");
		say(capitalize(this_player()->query_name())+" walks onto the bus.\n");
		this_player()->move_player("onto the bus#players/shinshi/entrancehall");
		return 1;
	}
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
   
    ROGUES = clone_object("/players/shinshi/closed/rogue/gob2.c");
    SCAR = clone_object("/players/shinshi/closed/rogue/objects/scar.c");
    MAKO = clone_object("/players/shinshi/closed/objects/makoaura.c");
    SYMBIO = clone_object("/players/shinshi/closed/objects/symbioaura.c");
    move_object(ROGUES, this_object());
    move_object(SCAR, this_object());
    move_object(MAKO, this_object());
    move_object(SYMBIO, this_object());
    destruct(ROGUES);
    destruct(SCAR);
    destruct(MAKO);
    destruct(SYMBIO);
}



is_castle(){return 1;}
