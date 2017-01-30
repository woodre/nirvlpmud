#define NAME "Maledicta"
#define DEST "room/ravine"
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

id(str) { return str == "path"; }

short() {
    return "A small path leading into a ravine";
}

long() {
    write("This is a small path that leads west into the mountains.\n"); 
}

init() {
   ::init();
add_action("enter", "west");
add_action("enter", "w");
}

enter(str) {
    this_player()->move_player("path#players/maledicta/castle/rooms/m1.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
 /* Autoload for Venom */
 clone_object("/players/maledicta/venom/venom.c");   
 /* Sigil autoloads */
 clone_object("/players/maledicta/closed/sigils/fire_sigil.c");
 clone_object("/players/maledicta/closed/sigils/ice_sigil.c");  
 clone_object("/players/maledicta/closed/sigils/elec_sigil.c");
/* Symbiote advance block */
move_object(clone_object("/players/maledicta/venom/block.c"),
			"/room/adv_guild.c");
}

is_castle(){return 1;}
