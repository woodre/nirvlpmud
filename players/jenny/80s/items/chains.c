#include "/players/jenny/define.h"
inherit "/obj/armor.c";
int num;
id(str) { return str == "Several Gold Chains" ||  str == "necklace" || str == "chains" || str == "chain" || str == "several gold chains"; } 
reset(arg) {
 ::reset(arg);
    set_name("gold chains");
set_ac(1);
set_value(600);
set_weight(1);
    set_type("amulet");
    set_short(HIY+"Several Gold Chains"+NORM);
    set_long(
      "These are several thick 24 carrot gold necklaces.  They look like\n"+
      "little gold chains.  These particular necklaces were worn by Mr. T.\n"+
     "They seem to glimmer when the sun catches them just right.\n");
}
do_special(owner)
{
num = random(14);
  if(num == 6)
  {
tell_object(owner,HIY+"Your gold chains glimmer as the sun catches them just right."+NORM+"\n");
return 1;}
return 0;}
