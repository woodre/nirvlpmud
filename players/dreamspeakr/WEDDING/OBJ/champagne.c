#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("What and waste a perfectly good glass of champagne?\n");
    return 1;
}

reset(arg){
   if(arg) return;
   
   set_id("champagne");
   set_weight(1);
   
   set_short("A tall glass of champagne"+NORM);
   set_long("A chilled crystal glass of Dom Perignon champagne.\n"+      
      "\n"+
      "You can "+HIM+"'toast'"+NORM+" someone.\n"+
      "\n"+      
      MAG+"                  Another creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("toast","toast");
}

int toast(string str){
   object ob;
   
   if(!str) { 
      write("You must toast someone.\n"); return 1; 
   }

   if(!find_living(str)) {
      write("You can't do that!\n");
      return 1;
   }
   
   ob = present(str,environment(this_player()));
   if(!ob){  
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(ob->query_invis() > 20){
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
  if(ob == this_player()){
    write("Not to yourself!  You should toast someone else!\n");
    return 1;
  }   

   tell_object(ob,this_player()->query_name()+" turns "+environment(this_object())->query_possessive()+" glass of champagne up towards you.  \n");
   tell_object(ob, "Smiling as "+environment(this_object())->query_pronoun()+" gives a heart felt toast to your happiness!  \n");
   write("You turn your glass towards "+capitalize(str)+" and say a special toast\n");
   write("of happiness and prosperity.\n");
   say(this_player()->query_name()+" turns and faces "+capitalize(str)+".  Smiling as "+environment(this_object())->query_pronoun()+" lifts the glass \n",ob);
   say("of champagne in honor of "+capitalize(str)+"\n",ob);
   destruct(this_object());
   return 1;
}

query_save_flag() { return 1; }
