/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Starport          */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

reset(arg) {
  if(!arg) {

object monster;

set_light(1);

short_desc = "";
long_desc =
  ".\n ";

items = ({
  "item",
  "item's description",
  "item2",
  "item2's description"
});

dest_dir = ({
    "destination_one","destination_command",
    "destination_two","destination_command"
  });

init() {
  add_action("search_me","search");
  add_action("action_function","action");
  }

action_function(arg) {
  
  }

  if(!monster) {
     monster = CO("obj/monster");
     MO(monster, TO);
  }
  }
}

init() {
  ::init();
  add_action("search_me","search");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the "+str+" but find nothing.\n");
  return 1;
}