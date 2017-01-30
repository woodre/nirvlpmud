#include "/obj/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("fighting spirit");
  set_alias("spirit");
  set_short(BOLD+HIY+"Saiyan fighting spirit"+NORM);
  set_long(
	"Being born into a race of warriors, all Saiyans possess one spirit.  When the\n"+
	"moon becomes full, they take their fighting spirits to levels unheard of on the \n"+
	"material plane.\n\n");
  set_type("bow");
  set_class(16);
  set_weight(1);
  set_value(1);
   		
		 }

  
