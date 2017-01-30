inherit "/obj/armor";
#include "/players/tallos/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("shirt");
  set_alias("shirt");          
  set_short("An I "+HIR+"Heart"+HIB+" Tallos"+NORM+" Shirt");
  set_long(
  " This is a T-Shirt that says\n"+
  " \n"+
  "IIIIIIIII"+HIR+"   HH      HH  EEEEEEEEE     AAAA     RRRRRRRRR  TTTTTTTTT"+NORM+"\n"+
  "IIIIIIIII"+HIR+"   HH      HH  EEEEEEEEE    AA  AA    RR      RR TTTTTTTTT"+NORM+"\n"+
  "  IIIII	"+HIR+"    HH      HH  EE          AA    AA   RR      RR   TTTTT"+NORM+"\n"+
  "  IIIII	"+HIR+"    HHHHHHHHHH  EEEEEE     AAAAAAAAAA  RRRRRRRRRR   TTTTT"+NORM+"\n"+
  "  IIIII	"+HIR+"    HHHHHHHHHH  EEEEEE     AAAAAAAAAA  RRRRRRRRR    TTTTT"+NORM+"\n"+
  "  IIIII	"+HIR+"    HH      HH  EE         AA      AA  RR  RR       TTTTT"+NORM+"\n"+
  "IIIIIIIII"+HIR+"   HH      HH  EEEEEEEEE  AA      AA  RR   RR      TTTTT"+NORM+"\n"+
  "IIIIIIIII"+HIR+"   HH      HH  EEEEEEEEE  AA      AA  RR    RR     TTTTT"+NORM+"\n"+
  " \n"+
  ""+HIB+"TTTTTTTTT   AAAA     LL        LL        OOOOOOOOOOO  SSSSSSSSSSS\n"+
  "TTTTTTTTT  AA  AA    LL        LL        OO       OO  SSSSSSSSSSS\n"+
  "  TTTTT   AA    AA   LL        LL        OO       OO  SS\n"+
  "  TTTTT   AAAAAAAAA  LL        LL        OO       OO  SSSSSSSSSSS\n"+
  "  TTTTT   AAAAAAAAA  LL        LL        OO       OO  SSSSSSSSSSS\n"+
  "  TTTTT   AA     AA  LL        LL        OO       OO           SS\n"+
  "  TTTTT   AA     AA  LLLLLLLL  LLLLLLLL  OO       OO  SSSSSSSSSSS\n"+
  "  TTTTT   AA     AA  LLLLLLLL  LLLLLLLL  OOOOOOOOOOO  SSSSSSSSSSS"+NORM+"\n"+
  " \n");  
  set_type("chest");
  set_ac(0);
  set_weight(0);
  set_value(0);
}
