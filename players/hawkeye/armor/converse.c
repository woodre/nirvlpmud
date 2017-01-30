#include "/open/ansi.h"
inherit "obj/armor";
reset(arg){
   ::reset(arg);
set_short(RED+"Converse All-Stars"+NORM);
   set_arm_light(0);
        set_long("A Pair of Red Converse All-Stars\n");
   set_ac(2);
   set_weight(3);
   set_value(500);
   set_alias("shoes");
   set_name("high tops");
   set_type("boots");
}

/* make save. -Bp
query_save_flag() { return 1; }
*/

/* Added by Snow, 11/99 */
do_special(owner) {
  if(creator(environment(owner)) != "hawkeye") {
    if(!random(100)) tell_object(owner,"You feel silly wearing tennis shoes for protection outside of MASH.\n");
    return -random(2)-1; }
  return 0; }
