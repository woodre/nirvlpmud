inherit "obj/armor";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name(""+HIG+"John Deere Hat"+NORM+"");
   set_alias("hat");
   set_short("a "+HIG+"John Deere Hat"+NORM+"");
   set_long(
      "This is a hat that was worn by Ray Johnson.  It is very\n"+
      "greasy and dirty from all the work on the tractor he has done.\n"+
      "On the front of the hat reads "+HIG+"John Deere"+NORM+".\n"
   );
   set_ac(1);
   set_type("helmet"); 
   set_weight(1);
   set_value(1000);

}

id(str) { return (::id(str) || str == "john deere hat"); }


do_special(owner)
{

int z;
object ob;
  z = random(50);
   if (z<5){
tell_room(environment(owner), "Dirt from "+environment()->query_name()+"'s hat helps deflect the blow.\n");
return 1;
}
}
