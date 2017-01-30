#define GUILD present("shardak_mark", find_player(bringer))
#define tp this_player()->query_real_name()
id(str) { return str == "bringob"; }
int DN;
string bringer;
reset() {
	call_out("timeout", 5);
}
init() {
     add_action("accept","accept");
     add_action("decline","decline");
	  add_action("stopdrag","stopdrag");
}
accept() {
     if(!find_player(bringer)) {
     write(capitalize(bringer)+" is not in this reality, terminating.\n");
     return 1; }
     if(!present(bringer, environment(this_player()))) {
     write(capitalize(bringer)+" must present for you to accept.\n");
     return 1; }
     if(!GUILD) {
     destruct(this_object());
     return 1; }
     DN = 1;
     GUILD->set_drag(DN);
     GUILD->set_dragwho(tp);
     write(capitalize(bringer)+" is now set to drag you.\n");
     write("Type 'stopdrag' at any time to stop being dragged.\n");
     tell_object(find_player(bringer), "You are now dragging "+capitalize(tp)+".\n");
	  remove_call_out("timeout");
     return 1; 
     }
stopdrag() {
     if(!find_player(bringer)) {
     write("You are no longer being dragged.\n");
     destruct(this_object());
     return 1; }
     if(find_player(bringer)) {
     write("You are no longer being dragged.\n");
     tell_object(find_player(bringer), capitalize(tp)+" has stopped being dragged by you.\n");
     DN = 0;
     GUILD->set_drag(DN);
	return 1; }
}
decline() {
     if(!find_player(bringer)) {
     destruct(this_object());
     return 1; }
     if(find_player(bringer)) {
     write("You decline the drag request.\n");
     tell_object(find_player(bringer), capitalize(tp)+" declines your drag request.\n");
     destruct(this_object());
     return 1; }
}
timeout() {
     if(!find_player(bringer)) {
     write("You time out of the drag request.\n");
     destruct(this_object());
     return 1; }
     if(find_player(bringer)) {
     write("You time out of the drag request.\n");
     tell_object(find_player(bringer), tp+" timed out of your drag request.\n");
     destruct(this_object());
     return 1; }
}
get() { return 1; }
set_bringer(bgr){ bringer = bgr; }
