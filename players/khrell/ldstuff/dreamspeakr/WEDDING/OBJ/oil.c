#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("You cant put that in there!\n");
    return 1;
}

reset(arg){
   if(arg) return;
   
   set_id("oil");
   set_weight(1);
   
   set_short("A vial of warm body oil"+NORM);
   set_long("A small vial of sensual body oil.  Warmed to the perfect\n"+      
      "temperature to massage someone into heaven.\n"+
      "\n"+
      "You can "+HIR+"'oil'"+NORM+" someones body.\n"+
      "You can "+HIR+"'massage'"+NORM+" someone after placing the oil on them.\n"+
      
      MAG+"             Another X-Rated creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   add_action("oil","oil");
   add_action("massage", "massage");
}

oil(str) {
   object ob;
   
   if(!str) { 
      write("You must oil someone.\n"); return 1; 
   }

   ob = present(str,environment(this_player()));

   if(ob == this_player()){
      write("It would be much more fun if you did this to your mate!\n");
      return 1;
  }
   if(!ob){  
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(ob->query_invis() > 20){
      notify_fail("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(!find_living(str)) {
      notify_fail("You can't do that!\n");
      return 1;
   }
   
   tell_object(ob,this_player()->query_name()+" undresses you and lays you down.  "+this_player()->query_name()+" \n");
   tell_object(ob, "drops the oil on your back and begins massaging your body.  \n");
   tell_object(ob, "You begin moaning in pleasure.\n");
   write("You undress and lay "+capitalize(str)+" down upon the bed.  Dropping \n");
   write("small amounts of oil upon "+capitalize(str)+"'s back.  "+capitalize(str)+" \n");
   write("begins moaning at you.\n");
   say(this_player()->query_name()+" drops warm oil upon "+capitalize(str)+"'s soft skin.\n",ob);
   return 1;
}



massage(str) {
   object ob;
   
   if(!str) { 
      write("You must massage someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));

   if(ob == this_player()){
      write("It would be more fun if you did this to your mate!\n");
      return 1;
  }
   if(!ob){  
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(ob->query_invis() > 20){
      notify_fail("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(!find_living(str)) {
      notify_fail("You can't do that!\n");
      return 1;
   }
   
   tell_object(ob,"Sliding across your body, over the warmed oil, "+this_player()->query_name()+" \n");
   tell_object(ob,"controls you mind, body and soul with "+this_player()->query_possessive()+" hands.\n");
   write("You gently massage "+capitalize(str)+"'s sexy body with your hands.  \n");
   write("Moving slowly, sliding up and down, "+capitalize(str)+"'s soft skin \n");
   write("gives you great pleasure.\n");
   say(this_player()->query_name()+" massages "+capitalize(str)+"'s body with warm oil.\n",ob);
   return 1;
}
query_save_flag() { return 1; }

