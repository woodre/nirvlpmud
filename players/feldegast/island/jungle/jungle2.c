#include "/players/feldegast/closed/shortcut.h"
inherit "players/feldegast/island/jungle/jungle1";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  dest_dir=({
    "/players/feldegast/island/jungle/jungle3","east",
    "/players/feldegast/island/jungle/jungle5","south"
  });
}

