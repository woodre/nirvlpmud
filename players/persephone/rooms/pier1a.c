inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {
  set_light(1);
  short_desc="Wharf Head";
  long_desc="There is a lot of activity on this part of the wharf it appears as if\n" +
            "the ship that is docked here is being loaded with exotic fruit headed\n" +
            "for some unknown destination. The wharf continues Northeast and back\n" +
            "to the southwest is the Harbour Edge. There appears to be even more\n" +
            "action further up the wharf\n";
  dest_dir=({"players/persephone/rooms/pier1b","northeast",
            "players/persephone/rooms/harba","southwest"
  });
 }
}
realm() { return "NT"; }
