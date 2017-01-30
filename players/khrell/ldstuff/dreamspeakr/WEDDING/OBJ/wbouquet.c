#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/weapon.c";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("bouquet");
set_alias("bouquet");
set_short("Wedding bouquet of "+HIR+"Roses"+NORM);
set_long(
  "The aroma from this beautiful bouquet fills the room.  \n"+
  "There must be 2 dozen red roses on it covered in babies \n"+
  "breath. \n"+
  "\n"+
  "When you are through and wish to throw your bouquet type:\n"+
  "'throw_bouguet <playername>\n");

set_type("bouquet");  /*  sword/knife/club/axe/bow/polearm  */
set_class(11);
set_weight(1);
set_value(50);
}

init()
{
   int i;
   
   add_action("throw_bouquet", "throw_bouquet");

}

throw_bouquet(str)
{
   object ob;     
   object room; 
   
   if(!str) 
   { 
      write("Who would you like to throw your bouquet to?\n");
      return 1;
   }
   
   ob = find_player(str);

   if(ob == this_player()){
      write("It would be more fun if you threw this to a friend?\n");
      return 1;
  }
   
   if(!ob || ob->query_invis() > 20)
   {
      return 0;
   }

   room = environment(ob);

   if(!room || !environment(this_player()))
   {
      return 0;
   }
   
   if(environment(this_player()) != room)
   {  
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }

   
   if(!ob->add_weight(1))
      return 0;
   
   move_object(this_object(), ob);

   tell_object(ob, this_player()->query_name() + 
      " turns her back to the crowd, and throws her bouquet over \n"+
      "her head.  You leap into the air catching it!  You hear wedding \n"+
      "bells ringing in your ears!\n");

   write("You turn your back to the crowd and throw your bouquet straight \n"+
         "at "+capitalize(str)+".\n");
   
   say(this_player()->query_name() +
      " turns around and throws her wedding bouquet high into \n"+
      "the air behind her.  "+capitalize(str)+" leaps through the crowd \n"+
      "and catches it!\n",ob);

   return 1;

}
query_save_flag() { return 1; }