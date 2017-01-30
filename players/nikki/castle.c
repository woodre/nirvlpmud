#include "/players/nikki/ansi.h"
#define NAME "nikki"
#define DEST "room/forest8"
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

id(str) { return str == "theatre"; }

short() {
    return HIR+"Tintagel"+NORM;
}

long() {
    write("This is the " + short() + ".\n");
    write(HIY+"                              '-.  __  .-'\n");
write(HIR+"           .  "+HIY+"               _._ ,'  ', _._"+HIR+"       .\n");
write("          //\\"+HIY+"                    '.__.'   "+HIR+"       //\\\n");
write("         / \\ \\"+HIY+"                 .-'     '-."+HIR+"      / / \\\n");
write("        / / / \\                                / \\ \\ \\\n");
write("       /_/__\\__\\                              /__/__\\_\\\n");
write("       | _____ |  |--|   |--|    |--|   |--|  | _____ |\n");
write("       |__|__|----|  |---|  |----|  |---|  |----|__|__|\n");
write("       ||__|_|    '~~\\   '~~\\    /~~'   /~~'    |_|__||\n");
write("       |__|__|       ## "+HIW+".-''''''''''-."+HIR+" ##       |__|__|\n");
write("       |_|__||"+HIW+"  _/\\_  (| - :   _  : - |)  _/\\_"+HIR+"  ||__|_|\n");
write("       |___|_|"+HIW+"  |  |   |   . -    .   |   |  |"+HIR+"  |_|___|\n");
write("       |_|___|"+HIW+"  |__|   |"+HIB+"===+======+==="+HIW+"|   |__|"+HIR+"  |___|_|\n");
write("      _|__|__|_"+HIW+"        | _ :    _ :   |       "+HIR+" _|__|__|_\n");
write(HIG+"_____"+HIR+"|.,.,.,.,.|"+HIG+"_______"+HIW+"|___:-_____:___|"+HIG+"_______"+HIR+"|.,.,.,.,.|"+HIG+"____\n"+NORM);
write("                      /______________/|\n");
write("                      |______________|/\n");  
write("                     /______________/\n");
write("\n\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("\nDoo\n\t Bee\n\t\t Doo-Bee\n\t\t\t\t Doooo....\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
