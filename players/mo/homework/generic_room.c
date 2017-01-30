inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
   if(arg) return;

set_short("My motha fuckin' room");
set_long(
"This is my motha fuckin' room.  If you want to leave, you\n"+
"need a motha fuckin' pass.\n");
}
init() {
add_action("leave_me","leave");
}
leave_me() {
object pass;
pass = present("pass",this_player());
if(!pass) {
    write("That ain't no motha fuckin' pass.\n");
    return 1; }

if(!pass->query_pass()) {
write("Nope.\n");
return 1; }
write("That's ma shit.\n");
this_player()->move_player("on a boat#players/illarion/workroom.c");
return 1; }
