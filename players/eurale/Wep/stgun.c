/*  A Tazer stun gun  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("gun");
  set_alias("tazer");
set_alt_name("stun gun");
set_short("A Tazer stun gun");
set_long(
	"  This high-voltage stun gun is designed to knock down the biggest\n"+
	"target.  It charges and then 'explodes' with enough electricity \n"+
	"to stop the heart of the fiercest beast. \n");
set_type("bow");
  set_class(18);
  set_weight(5);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>10)  {
  say("\n\nYou are temporarily blinded by the flash.....\n\n"+
 BOLD+"      ZZZZZZZZZZZZZZZZZZZ \n"+
      "               AAAAAAAAAAAAAAAAAA   \n"+
      "                       PPPPPPPPPPPPPPPPPPPPPP \n\n"+NORM+
       "                        as the Tazer discharges into its target!!! \n");

  write("\n\nYou feel the tingle and then are temporarily blinded..\n\n"+
   BOLD+"   ZZZZZZZZZZZZZZZZZZZZZZZZ  \n"+
        "                AAAAAAAAAAAAAAAAAAAAAAAA \n"+
        "                            PPPPPPPPPPPPPPPPPPPPPPPPPPPP \n\n"+NORM+
        "                  as the Tazer discharges into the target!! \n\n");
  return 4;
   }
return;
}
