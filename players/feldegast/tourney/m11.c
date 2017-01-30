#include "def.h"

inherit AROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=YEL+"Desert"+NORM;
  long_desc=
"  Rolling dunes of sand surround you as far as the eye can see.  You\n\
try to shade your eyes against the unremitting glare, but to no\n\
avail.  The course, grainy sand seems to ooze into every fold of your\n\
clothing, making you itch in the most awkward places.  A stiff breeze,\n\
an ominous sign in the desert, chokes the air with tiny particles.\n";
  dest_dir=({
    PATH+"m10","west",
  });
}
void init() {
  ::init();
  call_out("twister",6,this_player());
}
int twister(object targ) {
  if(!targ) return 1;
  if(!environment(targ)) return 1;
    if(environment(targ) != this_object()) return 1;
     if(!targ->is_player()) return 1;

  if(targ->query_attrib("luc") < random(22)) {
    tell_object(targ,"A whirling tornado of sand twirls in and picks you up!\n");
    tell_room(this_object(),
      "A whirling tornado of sand swirls in and sweeps up "+targ->query_name()+"!\n",({ targ }));
    move_object(targ,PATH+"tornado.c");
    tell_room(environment(targ),
      targ->query_name()+" is swept up into the tornado!\n");
  }
  else call_out("twister",6,targ);
return 1;
}
