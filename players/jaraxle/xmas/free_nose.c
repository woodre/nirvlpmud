#include "/players/jaraxle/define.h"
inherit "obj/armor";

void
set_type(string str) {
   type = str;
}
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("nose");
   set_alias("rabbit nose");
   set_id("nose");
   set_long(
      "This is a cute little "+HIM+"pink"+NORM+" rabbit's nose with long whiskers.\n");
   
   set_ac(0);
   set_type("easter");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
short(){ return ""+HIW+"Rabbit's "+HIM+"nose"+NORM+""+(worn_by?" "+HIW+"("+NORM+"worn on face"+HIW+")"+NORM+"":""); }

do_special(owner) {
   if(!random(6)) {
      tell_object(owner, "\tYou wiggle your little "+HIM+"pink"+NORM+" nose.\n");
      return 1; }
}
query_save_flag(){ return 1; }
init(){
   ::init();
   
   add_action("wiggle_it","wiggle");
   
}
wiggle_it(arg){
if(arg == "rabbit nose" || arg == "nose"){
write("You wiggle your cute nose.\n");
say(TPN+" wiggles "+POS+" rabbit nose.\n");
return 1; }
}
