#define NAME "Quicksilver"
#define DEST "room/forest1"
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
 
id(str) { return str == "village"; }
 
short() {
    return "A small village (growing).\nA large sign forged from pure silver";
}
 
long() {
    write("As you look at the village in the distance, you notice that it\n");
    write("is growing rapidly.  Unfortunately, the main road is currently\n");
    write("closed.\nPerhaps the large sign before you will provide more information.\n");
   write("In other words, it's not open.\n");
}
 
init() {
    add_action("enter","enter");
    add_action("examine","examine");
    add_action("sit","sit");
}
 
reset(arg) {
    if (arg)
        return;
}
 
is_castle(){return 1;}
 
enter(str) {
    if (!id(str))
        return 0;
    write("A large bar blocks the road.  You decide it would be best not\n");
    write("to attempt to enter.\n");
    return 1;
}
 
read(str) {
    if (!str)
        return 0;
    if (str != "sign")
        return 0;
    write("Welcome to Silverville!\n\n");
    write("We thank you for stopping by, and apologise for the mess.\n");
    write("The village is growing rapidly and we must have time to adapt\n");
    write("and further improve the economic base of the city.  If growth\n");
    write("growth continues at its current rate, it should reach metropolis\n");
    write("status in no time.\n");
    write("Thanks for stopping by, and please check back in a few weeks.\n");
    write("\n\t-- Quicksilver  (mayor)\n");
    return 1;
}
 
examine(str) {
    if (!str)
        return 0;
    if (str != "sign")
        return 0;
    write("It is a large sign made of pure silver.  Perhaps you should read it.\n");
    return 1;
}
 
sit(str) {
  if(str != "on bench") return 0; 
  if(this_player()->query_real_name() == "quicksilver") {
  this_player()->move_player("on a large bus, headed to Silverville"+
    "#players/quicksilver/silverville/rooms/main&jones");
    return 1; }
  if(this_player()->query_real_name() == "alison") {
  this_player()->move_player("on a large bus, headed to Silverville"+
    "#players/quicksilver/silverville/rooms/main&jones");
    return 1; }
  return 0;
}
