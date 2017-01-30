
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

int door_found;

extra_init() {
     add_action("search", "search");
     add_action("east", "east");
     add_action("west", "west");
}

extra_reset() {
     door_found=0;
}

ONE_EXIT("players/bastion/isle/wiz/up_hall1", "south",
     "Guest Bedroom",
     "You are in a large bedroom. A queen bed lies north, resplendant in\n"+
     "white, silken comfort. A wardrobe stands open and empty to you left, a\n"+
     "dressing table to your right. The room appears devoid of any personal\n"+
     "affects. A door leads south.\n",
     1)

west() {
     if(door_found) {
          write("You enter a secret passageway.\n");
          say(call_other(this_player(), "query_name") +
               " enters a secret passageway.\n");
          this_player()->move_player("west#players/bastion/isle/wiz/secret2");
          return 1; }
}

search(str) {
     int chance;
     chance=call_other(this_player(), "query_attrib", "int") + call_other(this_player(), "query_level");
     if(random(100) < chance) {
          write("You find secret doors in the east and west walls.\n");
          say(call_other(this_player(), "query_name") +
               " finds a secret door.\n");
          door_found=1;
          return 1; }
     else {
          write("You find nothing of interest.\n");
          return 1; }
}

east() {
     if(door_found) {
          write("You enter a secret passageway.\n");
          say(call_other(this_player(), "query_name") +
               " enters a secret passageway.\n");
          this_player()->move_player("east#players/bastion/isle/wiz/secret1");
          return 1; }
}

