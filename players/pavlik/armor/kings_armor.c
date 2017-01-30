inherit "obj/armor";
#include "/players/pavlik/closed/colors.h"

reset(arg){
 ::reset(arg);
 set_short("the "+MAG+"Royal Crest"+NORM+" of Arcydia");
 set_long(
 "A magnificent breastplate of enchanted steel, the "+MAG+"Royal Crest\n"+
 "of Arcydia"+NORM+" has shielded the just King through many battles.\n"+
 "Although the Royal Crest is countless years old the polished steel\n"+
 "surface is still unscratched.  The crest seems to glow with a light\n"+
 "of its own.\n");
 set_name("Crown of Arcydia");
 set_ac(4);
 set_weight(3);
 set_value(2500);
 set_alias("crest");
 set_arm_light(1);
 set_type("armor");
}

id(str) {
  return str == "royal crest" || str == "breastplate" ||
  str == name || str == alias || str == type;
}

