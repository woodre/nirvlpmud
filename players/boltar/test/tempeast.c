init() {
 add_action("east","east");
}
id(str){return str=="tempeast"; }
east() {
 call_other(this_player(), "move_player","east#players/boltar/hotel/lostandfound.c");
   return 1;
}
