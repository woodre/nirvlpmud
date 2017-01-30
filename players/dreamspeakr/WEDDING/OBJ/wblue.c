/*Sincere appreciation goes out to Mizan for his help in the functions 
  of this object, without his guidence i might never have worked this 
  through!  Thanks Mizan!*/

#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) 
{
   set_name("garter");
   set_alias("garter");
   set_short("Sexy Garter (" + HIB + "Something Blue" + NORM + ")");
   set_long(
  "You had best not let her beloved catch you looking at this.  White \n"+
  "and blue satin look so good on her long sexy legs.\n"+
  "\n"+
  "You can 'allow_removal <playername>' to slide it off your leg.  \n"+
  "Then he can 'throw_garter' at a friend.\n"+
  "\n");

   set_ac(0);
   set_type("ring");  
   
   set_weight(1);
   set_value(50);
}

init(){
    ::init();
   
   add_action("throw_garter", "throw_garter");

   add_action("allow_removal","allow_removal");

}

throw_garter(str)
{
   object ob;     
   object room; 
   
   if(!str) 
   { 
      write("Who would you like to throw it to?.\n"); return 1; 
   }
   
   ob = find_player(str);

   if(ob == this_player()){
      write("Don't be stingy!  Throw it at a friend!\n");
      return 1;
  }
   
   if(!ob || ob->query_invis() > 20)
   {
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
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
   
   if(this_player()->query_gender() != "male")
   {
      write("Shouldn't you let your husband do this?\n");
      return 1;
   }

   if(!ob->add_weight(1))
      return 0;
   
   move_object(this_object(), ob);

   tell_object(ob, this_player()->query_name() + 
      " throws the garter high into the air, heading straight for you, you leap into the air and catch it. \n");
   
   write("You take the garter in your hands, turn around, and toss it high into the air.\n");

   say(this_player()->query_name() + 
      " throws the garter high in the air.  "+capitalize(str)+" leaps in the air and catches it.\n", ob);

   return 1;
}


allow_removal(str)
{
   object ob;     
   object room; 
   
   if(!str) 
   { 
      write("Who are you going to allow to remove it?\n");
      return 1;
   }
   
   ob = find_player(str);

   if(ob == this_player()){
      write("Maybe your husband would prefer to help you with that!\n");
      return 1;
  }   

   if(!ob || ob->query_invis() > 20)
   {
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
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

   if(this_player()->query_gender() != "female")
   {
      write("Men shouldn't be wearing such things!\n");
      return 1;
   }

   
   if(!ob->add_weight(1))
      return 0;
   
   move_object(this_object(), ob);

   tell_object(ob, this_player()->query_name() + 
      " slowly raises her dress, you lean down and remove the garter with your teeth. \n");


   write("You slowly lift your dress, "+capitalize(str)+" reaches over and slides \n"+
         "the "+HIB+"garter "+NORM+"from your leg with his teeth.\n");
   
   say(this_player()->query_name() +
      " lifts her dress slowly, "+capitalize(str)+" reaches down with his teeth and slides the garter off.\n",ob);

   return 1;

}
query_save_flag() { return 1; }
