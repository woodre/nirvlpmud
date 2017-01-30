inherit "obj/armor";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("blue g-string");
   set_alias("g-string");
   set_short("a "+HIB+"blue"+NORM+" g-string");
   set_long(
      "This is a very small g-string, that has been worn by one\n"+
      "of the strippers at the famous Pesty's Place.  When worn\n"+
      "it rides up ones butt, making for a very tight fit.\n"
   );
   set_ac(1);
   set_type("underwear"); 
   set_weight(1);
   set_value(2000);

}


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
