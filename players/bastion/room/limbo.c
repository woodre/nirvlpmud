
reset(arg) {
     object board, vender;
     if(!present("bulletin board")) {
          board=clone_object("players/bastion/obj/bull_board");
          move_object(board, this_object()); }
/*
     if(!present("vender")) {
          vender=clone_object("players/bastion/obj/vender");
          move_object(vender,this_object());
     }
*/
     if(!arg)
          set_light(1);
}

init() {
     add_action("belgaers", "belgaers");
     add_action("citadel", "citadel");
     add_action("isle", "isle");
     add_action("cave", "cave");
     add_action("church", "down");
     add_action("up", "up");
}

belgaers() {
     this_player()->move_player("away#players/bastion/antaria/belgaers/road2");
     return 1;
}

citadel() {
     this_player()->move_player("away#players/bastion/antaria/citadel/gate");
     return 1;
}

church() {
     this_player()->move_player("down#players/bastion/room/limbo2");
     return 1;
}

isle() {
     this_player()->move_player("away#players/bastion/isle/wiz/cave3");
     return 1;
}

cave() {
     this_player()->move_player("away#players/bastion/isle/trans");
     return 1;
}

up() {
     this_player()->move_player("up#players/bastion/room/cafe");
     return 1;
}

short() { return ("Limbo"); }

long() {
   write(
     "You find yourself in a plane of swirling gasses and infinite stars.\n"+
     "Bits of matter in all orientations float through the heavens around\n"+
     "you. You feel you could travel to any place in the universe from\n"+
     "here.\n"+
     "     Obvious exits are: Belgaers, Citadel, Isle, Cave, Up, Down.\n");
}

realm() { return "NT"; }
