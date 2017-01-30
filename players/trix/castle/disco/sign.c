#include "/players/boltar/things/esc.h"
reset(arg) {
        if(arg) return;
}
id(str) {
        if(str=="sign") return 1;
        return 0;
}
short()
  {  return esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
            "A blinking sign about EclYpsE"+esc+"[0m"; }
long() { write("A blinking sign, 'read sign'.\n"); }
init()
{ add_action("read","read");
}
read(str)
  { if(str=="sign") {
              write("EclYpsE has been restyled, its map changed, to see the new one look in the\n"+
                    "board at the entrance of the Realm. Alcohols are sold in EclYpsE's Bar.\n");
              return 1;
            }
  }
