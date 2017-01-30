/* 
 * Forbin
 * Created:   2003.08.29
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

int found;

reset(arg) {
  if(arg) return;
  short_desc = "A "+HIW+"Snow"+NORM+"capped Peak";
  long_desc = 
    "  Several rocks push out from underneath thick layers of ice and\n"+
    "snow.  Most everything here is covered in one or both of the two.\n"+
    "Except for the rough, angular rocks, the landscape of the\n"+
    "mountain peak would be relatively flat but for the large lump at\n"+
    "the center of the peak.\n";
  add_item(({"rock","rocks"}),
    "Angular rocks stick out from the snow and ice.  Most have\n"+
    "broken and fractured by the ice");
  add_item(({"ice","snow"}),
    "Clear ice and bright white snow cover almost everything");
  add_item("landscape",
    "The mountain peak holds nothing but a frigid wasteland");
  add_item("peak",
    "You stand on the peak, and looking around you see that it is\n"+
     "bordered by lush forest, with a sandy beach far to the southeast");
  add_item("lump",
    "The lump of snow looks oddly out of place.\n");
  add_item("forest",
    "The mountain is surrounded by a thick, tropical forest");
  add_item("beach",
    "Far to the southeast, you see an sandy beach and ocean stretching\n"+
    "a great distance to the horizon\n"); 
  add_touch("snow",
    "It stings your hand with the cold.\n");
  add_taste("snow",
    "It doesn't taste like anything really...but it stings your tongue.\n");
  set_chance(random(5));
    add_msg("You breath heavily, very aware of your shortness of breath.");
    add_msg("Wind howls about the mountain peak.");
    add_msg("You shiver from the cold.");
    add_msg("Snow blows in your face, obscuring your vision.");
    add_msg("Fog drifts about the peak.");
    add_msg("Snow and ice swirl about you.");
  set_light(1);
  add_exit(ROOT+"rms/mountain01.c","down");
  found = 0;
}

short() { return "A "+HIW+"Snow"+NORM+"capped Peak"; }

init() {
  ::init();
  add_action("cmd_search","search");
}

cmd_search(string str) {
  object shell;
  if(str == "snow" || str == "lump") {
    if(!found) {
      write("You dig through the snow and uncover a conch shell.  How odd!!!\n");
      say(this_player()->query_name()+" digs up a conch shell.\n");
      shell = clone_object(ROOT+"obj/frozenconch.c");
      move_object(shell,this_player());
      found++;
        return 1;
    }
    write("You dig through the snow but find nothing.\n");
    say(this_player()->query_name()+" digs through the snow in vain.\n");
      return 1;
  }
}
