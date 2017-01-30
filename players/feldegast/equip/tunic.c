#include "/players/feldegast/defines.h"
inherit "obj/armor";

reset(arg) {
  string color;
  switch(random(5)) {
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
  }
  if(arg) return;
  set_name("tunic");
  set_short("A "+color+" tunic");
  type="shirt";
  set_ac(0);
  set_long(
"This is a simple, yet fashionable "+color+" tunic.\n"
  );
  set_weight(1);
  set_value(50);
}
