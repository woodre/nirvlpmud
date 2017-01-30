/*  There are a number of changes that need to be made before any
    castle can be put into play.  First, copy the ansi file from
    /open/ansi.h into your home directory so you can use it at your
    convenience.  Then do the following:
      *Change NAME in  line 8 to our name
      *Copy ansi file from /open/ansi.h to your own dir
      *Change the 'castle location' to where your castle will be
      *Change the short() to your castle entry
        is where ALL your areas will be accessed from
      *Change the long()
*/

#define NAME "Brittany"
#define DEST "room/forest8"
#include "/players/brittany/ansi"

id(str) { return str == "sphere"; }

short() { return "Netherlands ""MAG+"Sphere""+NORM"; }

long() { write(
  "A sperical body suspended in mid-air, 'spin globe' to enter.\n");
}

init() {
  add_action("spin_sphere","spin");
}

spin_sphere() {
if(!str) {  
    notify_fail("Spin what?\n");
    return 0;
}
if(str=="sphere") {  
    write("You spin the globe it turns and turns, then lands in the Netherlands.\n");
    say(this_player()->query_name()+" spins the globe and then disappears.\n");
  this_player()->move_player("spin#players/brittany/globe.c");
    return 1;
}

reset(arg) {
  if(arg) return;
    move_object(this_object(), DEST);


}

is_castle(){return 1;}
