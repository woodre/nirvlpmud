#define NAME "Astaroth"
#define DEST "room/big_tree"

id(str) { return str == "castle"; }

short() {
    return "The castle of " + NAME +" is to your north.";
}

long() {
    write("Astaroth just opened this place, go in and check\n");
    write("it out.\n");
}

init() {
  add_action("enter", "enter");
  add_action("enter", "north");
}

enter(str) {
    call_other(this_player(), "move_player", "leaves north#players/astaroth/entrance");
    return 1;
}
is_castle() {return 1; }


object aura, ring, bank;
reset(arg) {
    if (arg)
	return;
/*
    aura = clone_object("players/astaroth/aura");
    aura = clone_object("players/mistress/closed/mist");
*/

/* added by mizan 

 Autoloading wiztools are a drain on the mud's resources.
  An autoload for a single player? Use a login script or plain batch file instead.

  Wiztools are illegal for level 60< anyway.
  Clone /obj/wiz_tool.c instead.
 */
/* commented out by Vertebraker [5.31.01] 
    this ring doesn't exist anymore. */
/*
    ring = clone_object("players/astaroth/obj/wring");
*/
/*
    bank = clone_object("players/astaroth/bank/bankinfo");
 */
}
