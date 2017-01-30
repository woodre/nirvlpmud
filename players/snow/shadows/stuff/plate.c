/* 11/01/05 Earwax: Changed this from setting align to -1000 every
 * 40 hb to lowering it by 100.
 * 3/21/06 Earwax: moved callout to init()
 */
inherit "obj/armor";
#include "/players/snow/closed/color.h"
reset(arg){
   ::reset(arg);
   set_name("death plate");
   set_short(BOLD+"Black Platemail"+OFF);
   set_alias("platemail");
   set_long(
"Fabulously worked platemail with engraved black roses.\n");
   set_ac(5);
  set_params("magical",5,0,0);
  set_params("other|evil",0,20,0);
  set_params("other|good",0,-20,0);
   set_weight(4);
   set_value(5000);
}

void init() {
  ::init();
  if (!environment()) return;
  if (!living(environment(this_object()))) return;
  call_out("corrupt", 40);
}
 
corrupt() {
  if (!environment()) return 1;
  if(!environment(this_object())) return 1;
  if(worn) {
    if(environment(this_object())->query_alignment() > -1000) {
      call_other(environment(this_object()),"add_alignment",-100);
    }
  }
  while(remove_call_out("corrupt") != -1);
  call_out("corrupt",40);
return 1;
}
