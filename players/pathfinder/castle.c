#define NAME "Pathfinder"
#define DEST "room/forest5"
#define GUILD "/players/pathfinder/closed/shadow/shadow.c"
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
 
id(str) { return str == "city" || str == "detroit"; }
 
short() {
  return "City of Detroit (enter city)";
}
 
long() {
  write("The City of Detroit.  It is known as the Motor City across\n");
  write("the globe.  Inside this city there are some of the worst\n");
  write("neighborhoods there can be.  Not to mention the better\n");
  write("parts of the city.  Take a trip into Detroit.\n");
}
 
init() {
  add_action("enter", "enter");
}
 
reset(arg) {
  object can, can1;
  object man1, man2;
    if (arg)
        return;
  can = clone_object("/players/pathfinder/trashcan.c");
  can1 = clone_object("/players/pathfinder/trashcan.c");
  move_object(can1, "/room/vill_green");
  man1 = clone_object("/players/pathfinder/garbageman.c");
  man2 = clone_object("/players/pathfinder/garbageman.c");
  move_object(man1, "/room/church");
  move_object(man2, "/room/shop");
  move_object(can, "/room/shop");
/* Removed due to shadow guild no longer existing. -Snow 1/00
    call_other("/players/pathfinder/closed/shadow/shadow.c","????",0);
    call_other("/players/pathfinder/closed/shadow/new/shadow.c","????",0);
    call_other("/players/pathfinder/closed/shadow/rooms/castle.c","????",0);
*/
    move_object(this_object(), DEST);

}
 
is_castle(){return 1;}
 
enter(str) {
    if (!id(str))
      return;
    tell_object(this_player(),"You walk down the paved streets into the unknown of the city.\n");
    tell_room("room/forest5",capitalize(this_player()->query_name())+" walks into the city of Detroit.\n");
    call_other(this_player(),"move_player", "enter#players/pathfinder/detroit/rooms/entrance");
    return 1;
}
