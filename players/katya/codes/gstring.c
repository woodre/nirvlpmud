#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("red g-string");
   set_alias("g-string");
   set_short("a "+HIR+"red"+NORM+" g-string");
   set_long(
      "This is a very small g-string, that has been worn by one\n"+
      "of the strippers at the famous Pesty's Place.  When worn\n"+
      "it rides up ones butt, making for a very tight fit.\n"
   );
   set_ac(1);
   set_type("misc"); 
   set_weight(1);
   set_value(2000);

}

/*
init () {
   ::init() ;
     add_action ("read_inscription","read");
     }

read_inscription(str) {
   if(str != "inscription") { notify_fail("Read what?\n");
 return 0; }
     write("With this ring I grant you the power of my life.\n");
      return 1;
}
*/

do_special(owner)
{

int z;
object ob;
  z = random(50);
   if (z<5){
 environment()->add_hit_point(-random(5));
/*
 environment()->add_spell_point(random(5));
*/
tell_room(environment(owner), "A rotten "+YEL+"stench"+NORM+" from the g-string covers "+environment()->query_name()+"'s body.\n");
return 2;
}
      return 0; 
   }

/*
query_save_flag(){
  return 1;
  }
*/
