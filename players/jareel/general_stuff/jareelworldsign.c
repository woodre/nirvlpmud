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
  set_short("A Large "+HIM+"Neon"+NORM+" Sign");
  set_alias("sign");
  set_long("This is a large Neon sign showing you destinations around the realm\n");
  set_read("\n"+NORM+
     BOLD+"     Area Name                       Portal       Status   Difficulty"+NORM+"\n"+
 GRN+"Earwaxian National Guard Fields"+NORM+"-- "+EXIT+GRN+" Guard"+HIK+") "+DIS+" "+MID+"\n"+
 HIK+"Mondar's Forge"+NORM+"------------------- "+EXIT+HIK+" Forge"+HIK+") "+DIS+" "+HiG+"\n"+
 BLU+"Space Marines"+NORM+"-------------------- "+EXIT+BLU+" Space"+HIK+") "+DIS+" "+MH+"\n"+
 RED+"The Luner Empire"+NORM+"----------------- "+EXIT+RED+" Luner"+HIK+") "+DIS+" "+MH+"\n"+
 HIY+"The Unicorn Shire"+NORM+"---------------- "+EXIT+HIY+" Shire"+HIK+") "+DIS+" "+LOW+"\n"+
BOLD+"The Hero Plane"+NORM+"------------------- "+EXIT+BOLD+" Plane"+HIK+") "+DIS+" "+ELI+"\n"+
           "\n"+NORM);
}
get() { return 0; }
