#define ROOMDIR "/players/mizan/etheriel/ROOMS/"

string terminus;
string room_path;

set_terminus(str) {
   terminus = str;
   room_path = ROOMDIR + str;
   return 1;
}

id(str) { return str == "tunnel" || str == "wormhole" || str == "liquid-tunnel"; }

short() { return "A tunnel in the ether-muck [" + terminus + "]"; }

long() {
   write("This anomaly appears to be a tunnel of some sort, leading into\n"+
      "the mental direction of " + terminus + ". Maybe you could 'enter'\n"+
      "the tunnel...\n");
}

init() {
   if(1 == random(12)) {
      tell_room(environment(this_object()), "The wormhole goes unstable and suddenly collapses.\n");
      destruct(this_object());
      return 1;
   }
   add_action("enter_me","enter");
   if(terminus) {
      add_action("enter_me_short",terminus);
   }
}

enter_me(str) {
   if(!str || str != "tunnel") return 0;
   enter_me_short();
   return 1;
}

enter_me_short() {
   write("\nYou duck into the tunnel and emerge elsewhere.\n\n");
   this_player()->move_player("into the tunnel#" + room_path);
   return 1;
}

