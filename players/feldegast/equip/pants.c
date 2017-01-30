#include "/players/feldegast/defines.h"
inherit "obj/armor";

reset(arg) {
  string color;
  switch(random(7)) {
    case 0: color=YEL+"yellow"+NORM;
            break;
    case 1: color=GRN+"green"+NORM;
            break;
    case 2: color=RED+"maroon"+NORM;
            break;
    case 3: color=MAG+"mauve"+NORM;
            break;
    case 4: color=BLU+"blue"+NORM;
            break;
    case 5: color="brown";
            break;
    case 6: color="cotton";
            break;
  }
  if(arg) return;
  set_name("pants");
  set_short("A pair of "+color+" pants");

  type="pants";
  set_ac(0);
  set_long(
"This is a simple, yet fashionable pair of "+color+" pants.\n"
  );
  set_weight(1);
  set_value(50);
}
