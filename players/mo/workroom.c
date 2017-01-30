inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
   if(arg) return;

set_short("My motha ^%$$#'$ room");
set_long(
"This is my motha fuckin' room.  If you want to leave, you\n"+
"need a motha fuckin' pass.\n");
}
init() {
add_action("leave_me","leave");
add_action("push","push");
add_action("xcreate","makeafile");
}
xcreate() {
write("You created a file.\n");
save_object("/players/mo/yo.o");
return 1;
}
push(string str) {
if(!str) {
write("Push what?\n");
return 1; }
if(str != "button") {
write("You can only push button.\n");
return 1; }
write("You push the button and receive a pass.\n");
move_object(clone_object("/players/mo/homework/pass.c"),this_player());
return 1; }
leave_me(string str) {
object pass;
pass = present("pass",this_player());
if(!pass) {
    write("That ain't no motha fuckin' pass.\n");
    return 1; }

if(!pass->query_pass()) {
write("Nope.\n");
return 1; }
if(!str) {
write("Go where?\n");
return 1; }
if(str == "mash") {
write("Going to M.A.S.H.\n");
this_player()->move_player("to M.A.S.H.#/players/hawkeye/room/entrance.c");
return 1; }
if(str == "shrine") {
write("Going to the Marble Shrine.\n");
this_player()->move_player("to the Shrine#/players/feldegast/shrine");
return 1; }
if(str == "nexus") {
write("Going to the Nexus.\n");

return 1; }
if(str == "trix") {
write("Going to Trix.\n");
this_player()->move_player("to Trix#/players/trix/castle/center.c");
return 1; }
if(str == "derellia") {
write("Going to Derellia.\n");
this_player()->move_player("to Derellia heal shop#/players/maledicta/town/rooms/t10.c");
return 1; }
if(str == "rings") {
write("Going to the RINGS area.\n");
this_player()->move_player("to RINGS area#/players/angel/area/nox/entrance.c");
return 1; }
if(str == "warp") {
write("Going to the Time Warp.\n");

return 1; }
if(str == "rig") {
write("Going to the Oil Rig.\n");

return 1; }
write("That's ma shit.\n");
this_player()->move_player("on a boat#players/illarion/workroom.c");
return 1; }
