#include "std.h"

reset (arg) {
    if(arg)
	return;
    set_light(1);
}

short() {
  write("You have climbed the rather steep ladder up to the top of the\n");
  write("slide and realize you cannot get back down that way.  Looking\n");
  write("down to the pool, you see a constant stream of water pouring\n");
  write("down the slide, which makes sliding easier and keeps the slide\n");
  write("cool under the rays of the sun.  You stop a minute to look \n");
  write("around when an impatient little kid climbs up the ladder, and \n");
  write("with a cry of glee, pushes you down the slide!  You slip, trying\n");
  write("to hold onto the edges for dear life, but you cannot retain your\n");
  write("balance, and....\n\n");
  write("Wheeeeee........\n\n");
  write("The air rushes past you and you land with a SPLASH in the pool!\n\n");
 
  call_other (this_player(), "move_player", "down#players/aislinn/pool_shallow");
}

long() {
  write("You have climbed the rather steep ladder up to the top of the\n");
  write("slide and realize you cannot get back down that way.  Looking\n");
  write("down to the pool, you see a constant stream of water pouring\n");
  write("down the slide, which makes sliding easier and keeps the slide\n");
  write("cool under the rays of the sun.  You stop a minute to look \n");
  write("around when an impatient little kid climbs up the ladder, and \n");
  write("with a cry of glee, pushes you down the slide!  You slip, trying\n");
  write("to hold onto the edges for dear life, but you cannot retain your\n");
  write("balance, and....\n\n");
  write("Wheeeeee........\n\n");
  write("The air rushes past you and you land with a SPLASH in the pool!\n\n");
 
  call_other (this_player(), "move_player", "down#players/aislinn/pool_shallow");
}
