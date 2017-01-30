#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Arena Stands");
  set_long("\
The Dojo - Arena Stands.\n\
From here you can view the battles in the combat arena.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_arena","west",
  });
}

realm() {
  return "NT";
}

query_no_fight() { return 1; }
