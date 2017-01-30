/* 
 * Forbin
 * Created:   2003.08.29
 * Last edit: 2003.10.30 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

int mfixed, mrandom;
int attempted;

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  The forest thins here, slowly melding with a lush grassland of\n"+
    "ferns and bushes.  The ground gently slopes north before sharply\n"+
    "rising up into a high mountain.  A swirling gray fog hugs the\n"+
    "upper crags of the mountain, yet every now and then a glimpse of\n"+
    "the peak, capped in white, shows through.\n";
  add_item("forest",
    "The forest gives way to a wonderful grassland");
  add_item(({"grassland","grass","fern","ferns","bush","bushes"}),
    "Tall grass, wide-leaved ferns and squat bushes grow abundantly here");
  add_item("ground",
    "The ground slopes gently before giving birth to the mountain");
  add_item("mountain",
    "A large mountain towers to the north.  Both Beautiful and\n"+
    "majestic, you could attempt to climb to its peak");
  add_item(({"crag","crags","peak","snow","white"}),
    "Beautiful white snow dots the upper mountainscape");
  add_item("fog",
    "A dark fog swirls about the mountain");
  set_light(1);
  add_exit(ROOT+"rms/paradise05.c","south");
  add_exit_msg("south", "You head off into the jungle.\n",
		                "heads off into the jungle.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_climb","climb");
  add_action("cmd_search","search");
  attempted = 0;
}

cmd_climb(string str) {
  if(!str || (str != "mountain" && str != "the mountain")) { 
    notify_fail("Climb what?\n"); 
      return 0; 
  }
  if(attempted > 2) {
  write("It is hopeless - the mountain cannot be climbed from here.\n");
  say(this_player()->query_name()+" studies the mountain hopelessly.\n");
    return 1;
  } 
  write("You begin to climb the mountain, but the loose rocks cause you to fall.\n");
  say(this_player()->query_name()+" tries to climb the mountain, but falls down.\n");
  attempted ++;
    return 1; 
}

cmd_search(string str) {
  int totalmoss;
  int x;
  object moss;
  if(!str || (str != "grassland" && str != "grasslands" && str != "fern"
    && str != "ferns" str != "bush" && str != "bushes") return 0;
  if(mfixed == 0 && mrandom == 0) {
    write("You carefully search the "+str+", but find nothing of interest.\n");
    say(this_player()->query_name()+" searches the "+str+".\n");
      return 1;
  }
  totalmoss = mfixed + random(1+mrandom));
  say(this_player()->query_name()+" searches the "+str+".\n");
  write("You carefully search the "+str+", and find some moss growing underneath.\n");
  for(x = 0; x < totalmoss; x++) {
    moss = clone_object(ROOT+"obj/moss.c");
    move_object(moss,this_player());
  }
  mfixed = 0;
  mrandom = 0;
  return 1; 
}

/*
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~= 
 * initializing functions for setting up the moss search - these
 * are called from /players/snow/dervish/trials/trial1/rms/entrance.c
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */
set_moss_fixed(int x)  { mfixed = x; }
add_moss_fixed(int x)  { mfixed += x; }
query_moss_fixed()     { return mfixed; }
set_moss_random(int x) { mrandom = x; }
add_moss_random(int x) { mrandom += x; }
query_moss_random()    { return mrandom; }
