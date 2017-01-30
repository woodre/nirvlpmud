#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("t-shirt");
set_short(HIK+"Limp Bizkit T-shirt"+NORM);
   set_long(
      "This is a "+HIK+"gray"+NORM+" Limp Bizkit T-shirt.  It has a picture of the.\n"+
      "band of the front and tour dates on the back from 2000.\n"
   );
   set_ac(3);
   set_type("armor"); 
   set_weight(2);
   set_value(2000);
call_out("durst_sing", 2);

}

durst_sing(){
int z;
object ob;

ob = environment(this_object());
  if(!ob) return 1;
if(living(ob)){
  z = random(30);
  if (z>0){
environment(this_object())->add_spell_point(random(10)+2);
say("You feel a glow come across your body as the music flows through you.\n");
/*
tell_room(environment(owner)){
write("Fred Durst starts to sing: I did it all for the Nookie...  the Nookie.\n");
}
*/
}
call_out("durst_sing",10);
      return 0; 
   }
}
