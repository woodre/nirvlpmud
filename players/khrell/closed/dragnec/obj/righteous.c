/* Part of a armor set for good aligned guilds  *
 * Though it does benefit templars, it will not *
 * be limited to them alone.                    *
 *                                              *
 * -Khrell      (2005)                          *
 * -Now with Input from Fred 07/12/05-          */
 
inherit "obj/armor";
#include "/players/khrell/ansi.h"

reset(arg){
   ::reset(arg);
  set_name("breastplate");
  set_short(HIW+"Breastplate of the"+NORM+HIY+" Righteous"+NORM);
  set_alias("plate");
  set_long(
  "A shining silver breastplate with a golden crucifix\n");
  set_ac(4);
  set_params("magical",4,0,0);
  set_params("other|evil",0,20,0);
  set_params("other|good",0,-20,0);
  set_weight(3);
  set_value(5000);
  call_out("goodly",40);
}
 
goodly() {
  if(!environment(this_object())) return 1;  
  if(worn) {
    if(environment(this_object())->query_alignment() < 1000) {
      call_other(environment(this_object()),"add_alignment",1000);
    }
  }
  call_out("goodly",40);
return 1;
}