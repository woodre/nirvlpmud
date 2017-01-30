#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

reset(){
  set_name("sword");
   set_short("A claymore");
  set_type("sword");
  set_class(18);
}

long(){
write(""+
"                                     "+BYEL+"    \n"+OFF+
"                                      "+BYEL+"  \n"+OFF+
"    "+BWHT+"                                  "+BYEL+"  "+OFF+"               "+BYEL+"OOO\n"+OFF+
"  "+BWHT+"               "+HIC+"_____________________"+BYEL+"                     \n"+OFF+
"  "+BWHT+"               "+CYN+"~~~~~~~~~~~~~~~~~~~~~"+BYEL+"                     \n"+OFF+
"    "+BWHT+"                                  "+BYEL+"  "+OFF+"               "+BYEL+"OOO\n"+OFF+
"                                      "+BYEL+"  \n"+OFF+
"                                     "+BYEL+"    \n"+OFF+
BBLK);
}