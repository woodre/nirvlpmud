#include "/players/jareel/define.h"
inherit "obj/treasure.c";
#define DIS HIK+"("+NORM+RED+"Disabled"+HIK+")"+NORM
#define MID HIK+"("+NORM+GRN+"Mid"+HIK+")"+NORM
#define HiG HIK+"("+NORM+HIR+"High"+HIK+")"+NORM
#define LOW HIK+"("+NORM+HIY+"Newbie"+HIK+")"+NORM
#define MH HIK+"("+NORM+RED+"Mid - High"+HIK+")"+NORM
#define LM HIK+"("+NORM+HIG+"Newbie - Mid"+HIK+")"+NORM
#define EXIT HIK+"("+NORM+BOLD+"Exit:"+NORM
#define ELI HIK+"("+NORM+HIM+"Elite"+HIK+")"+NORM


reset(arg)
{

  if(arg) return;
  set_short(HIB+"A Swirling Magical Portal"+NORM);
  set_alias("portal");
  set_name("sign");

  set_long("This is magical rift to take you to a new place.  A sign hangs near it.\n");

  set_read("\n"+NORM+
     BOLD+"     Area Name                    Portal         Status"+NORM+"\n"+
 GRN+"OROBOROS"+NORM+"---------------------- "+EXIT+GRN+" dragon"+HIK+")  "+DIS+"\n"+
 HIK+"Ammass"+NORM+"------------------------ "+EXIT+HIK+" ammass"+HIK+")  "+DIS+"\n"+
 BLU+"The Light Bringer"+NORM+"------------- "+EXIT+BLU+" light"+HIK+")   "+DIS+"\n"+
 RED+"The Wanning Moon"+NORM+"-------------- "+EXIT+RED+" moon"+HIK+")    "+DIS+"\n"+
 HIY+"Humakti Death Quest"+NORM+"----------- "+EXIT+HIY+" humakt"+HIK+")  "+DIS+"\n"+
BOLD+"Elemental"+NORM+"--------------------- "+EXIT+BOLD+" element"+HIK+") "+DIS+"\n"+
 HIY+"Chaos Slayer"+NORM+"------------------ "+EXIT+HIY+" chaos"+HIK+")   "+DIS+"\n"+
           "\n"+NORM);
}
get() { return 0; }
