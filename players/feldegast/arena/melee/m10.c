#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Ford"+NORM;
  long_desc=
"  A muddy road leads to the banks of a wide river.  The water appears\n\
slow enough and shallow enough to cross here.  To the west, the road\n\
leads up to a low hill.  To the east, the road continues to the horizon.\n\
The river seems to bend to the west further downstream.\n";
  items=({
    "road","A muddy dirt track with wagon tracks furrowing through it",
    "river","A wide, not particularly clear river which flows south",
    "hill","Be honest.  Don't I look like god material to you?",
    "horizon","Where the earth meets the sky",
  });
  dest_dir=({
    PATH+"m9","west",
    PATH+"m11","east",
   });
}
void long(string str) {
  if(str=="hill") view_room(PATH+"m9");
  else ::long(str);
}
void init() {
  ::init();
  call_out("river",3,this_player());
}
int river(object targ) {
  string dest;
  if(!targ) return 1;
  if(environment(targ)!=this_object()) return 1;
  if(!targ || !targ->is_player()) return 1;
    
  if(targ->query_attrib("str") < random(25)) {
    tell_room(this_object(),targ->query_name()+" is swept away by the stream.\n");
    switch(random(3)) {
      case 0: dest=PATH+"m7";
              break;
      case 1: dest=PATH+"m8";
              break;
      case 2: dest=PATH+"m9";
              break;
    }
    move_object(targ,(string)master->query_room(dest));
    command("look",targ);
    tell_room(environment(targ),targ->query_name()+" arrives, completely soaked.\n");
    return 1;
  }
  call_out("river",5,targ);
return 1;
}
