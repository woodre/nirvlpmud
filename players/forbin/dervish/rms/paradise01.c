/* 
 * Forbin
 * Created:   2003.08.28
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int found;

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = GRN+HBGRN+
    "  Smooth, rain-slicked stone feathers out in several directions  \n"+
    "before walls of overgrown jungle overtake it to both the north   \n"+
    "and west.  To the south, a small cave is located in a sheer rock \n"+
    "face that towers into the air.  The stone outcropping runs east a\n"+
    "bit before toppling over the edge, forming a cliff.  A quick     \n"+
    "moving stream runs down the rock face, barely missing the cave,  \n"+
    "then across the stone and feeds over the cliff as a waterfall.   \n"
    "    There is one obvious exit: jump                              \n"+NORM;
  add_item("stone",
    "You stand on a smooth stone surface that forms an outcropping");
  add_item("jungle",
    "A thick wall of trees, vines, and bushes block make a barrier to\n"+
    "both the northern and western directions");
  add_item(({"tree","trees"}),
    "Several different species of trees tower over the area");
  add_item(({"vine","vines"}),
    "Many twisted vines drap and hang down from the trees");
  add_item(({"bush","bushes"}),
    "These small, rounded bushes look oddly out of place in the jungle");
  add_item("cave",
    "A dark cave lies set back into the rock face.  You could enter it");
  add_item(({"rock","face","rock face"}),
    "A towering face of solid rock stretches vertical, its surfaced\n"+
    "marked only by the single darkened hole of the cave");
  add_item(({"outcropping","cliff"}),"");
  add_item(({"stream","waterfall"}),
    "The stream creates a striking waterfall at the cliffs edge");
  add_listen("main", 
    "The water roars down the rock face and thunders over the falls.\n");
  add_touch("stone",
    "The stone is damp from both the stream and a recent rain.\n");
  add_touch("rock",
    "The rock is damp from both the stream and a recent rain.\n");
  add_touch("face",
    "The face is damp from both the stream and a recent rain.\n");
  add_touch("stream",
    "The water is crystal clear and ice cold.\n");
  add_taste("stream",
    "The cool, clear water is quite refreshing.\n");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/paradise03.c","jump");
  found = 0;
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_jump","jump");
  add_action("cmd_enter","enter");
  add_action("cmd_descend","descend");
  add_action("cmd_search","search");
}

cmd_jump() {
  write("You peer over the cliff as you ready to jump.  On second thought,\n"+
        "maybe it'd be better to find an alternate route down.\n");
  say(this_player()->query_name()+" peers over the edge of the cliff and whistles fearfully.\n");
    return 1; 
}

cmd_enter(string str) {
  if(!str || (str != "cave")) { 
    notify_fail("Enter what?\n"); 
      return 0; 
  }
  write("You enter the cave.\n");
  say(this_player()->query_name()+" enters a cave.\n");
  move_object(this_player(),ROOT+"rms/cave.c");
  command("look",this_player());
  say(this_player()->query_name()+" arrives.\n");
    return 1; 
}

cmd_descend(string str) {
  if(!found) { 
    notify_fail("What?\n"); 
      return 0; 
  }
  if(!str || (str != "trail")) { 
    notify_fail("Descend what?\n"); 
      return 0; 
  }
  write("Methodically, you pick and choose your way as you descend the trail.\n");
  say(this_player()->query_name()+" leaves down the trail.\n");
  move_object(this_player(),ROOT+"rms/paradise02.c");
  command("look",this_player());
  say(this_player()->query_name()+" wanders down from the cliffs.\n");
    return 1; 
}

cmd_search(string str) {
  if(str == "bush" || str == "bushes") {
    if(!found) {
      write("Cafefully parting the bushes, you find a hidden trail.\n");
      say(this_player()->query_name()+" searches the bushes.\n");
      found_it();
    }
    write("There is a trail hidden behind the bushes.\n");
    say(this_player()->query_name()+" searches the bushes.\n");
      return 1;
  }
  if(str == "trail") {
    if(!found) {
      write("You don't see a trail here.\n");
      say(this_player()->query_name()+" looks around confused.\n");
        return 1;
    }
    write("You should look at the trail.\n");
    say(this_player()->query_name()+" looks around confused.\n");
      return 1;
  }
}

found_it() {
  long_desc = GRN+HBGRN+
    "  Smooth, rain-slicked stone feathers out in several directions  \n"+
    "before walls of overgrown jungle overtake it to both the north   \n"+
    "and west.  A small trail leads a way through the jungle to below \n"+
    "the cliff.  To the south, a small cave is located in a sheer rock\n"+
    "face that towers into the air.  The stone outcropping runs east a\n"+
    "bit before toppling over the edge, forming a cliff.  A quick     \n"+
    "moving stream runs down the rock face, barely missing the cave,  \n"+
    "then across the stone and feeds over the cliff as a waterfall.   \n"+
    "    There is one obvious exit: jump                              \n"+NORM;
  add_item("trail", 
    "A seldom used trail snakes away from the bushes, leading down\n"+
    "the side of the cliff.  One could descend it if they wished");
  found++;
    return 1;
}
