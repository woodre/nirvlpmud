inherit "obj/armour";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_id("scouter");
set_type("helmet");
set_level(20);
set_short("A power level scouter");
set_long(
"This is a scouter used by the Saiyan Elite to measure an opponents"+
"strength. Although this scouter no longer works, at one time "+
"this scouter was used to show the power level of your opponent in "+ 
"comparison to your own.");
}
