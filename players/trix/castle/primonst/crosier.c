#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("crosier");
   set_alt_name("sceptre");
   set_alias("stick");
	set_short(HIY+"Golden crosier"+NORM);
   set_long("You're looking at the holy sceptre, made of gold and precious stones, you feel\n"+
       "the enormous power that can explode out of it.\n");
   set_class(18);
   set_weight(2);
   set_value(1000);
  set_params("other|good",0,"good_hit"); /*ill*/
}
good_hit(target) {
  if(!wielded_by) return;
  if(wielded_by->query_alignment() < -250) {
    write("The power of the holy cross rejects your evil soul!\n");
   wielded_by->hit_player(10,"other|good");
  } else if(wielded_by->query_attrib("pie") > random(150)) {
    write("An aura of goodness surrounds the cross!\n");
    say("An aura of goodness surrounds "+wielded_by->query_name()+"'s cross!\n");
    return 6;
  }
}
