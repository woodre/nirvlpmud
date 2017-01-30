inherit "/obj/armor";
#include <ansi.h>
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("shield");
  set_short("Hero's Shield");
  set_long("The surface of this glass shield absorbs the light in the\n"+
           "room. It appears to reflect"+HIK+" shadows"+NORM+", oddly enough. A Goron\n"+
           "appears in the shield, and is gone. It is strangely cool to \n"+
		   "the touch. There are"+HIR+" magical"+NORM+" properties to this shield. \n");
  
  set_params("other|evil",0,25,0);
  set_ac(2);
  
  set_type("shield");
  set_weight(2);
  set_value(3000);
}
