#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/fire/armor.c";

reset(arg){
  if(arg) return;
set_id("ring");
set_name("fire ring");
set_short("A "+RED+"fire"+OFF+" ring");
set_long("A ring inscribed with many sigils.\n");
set_value(0);
set_weight(1);
set_ac(1);
set_type("ring");
set_params("other|fire",0,0,"firespecial");
set_params("other|posion",0,50,0);
/* set_params("damagetype",ac,res%,"specialfunction"); */
}

firespecial(){
  tell_object(environment(this_object()),HIR+"{f} "+OFF+"Your ring protects you from the blast of heat.\n");
  return 5001; /* 50=resistance percentage 01 = class protectoin */
}
