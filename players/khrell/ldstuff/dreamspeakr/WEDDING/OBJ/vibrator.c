#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("You cant put that in there!\n");
    return 1;
}

reset(arg){
   if(arg) return;
   
   set_id("vibrator");
   set_weight(1);
   
   set_short("A realistic vibrator"+NORM);
   set_long("A very realistic looking vibrator.\n"+      
      "\n"+
      "You can "+HIM+"'tease'"+NORM+" someone with your vibrator.\n"+
      "You can "+HIM+"'please'"+NORM+" someone with your vibrator.\n"+
      "\n"+      
      MAG+"             Another X-Rated creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("tease","tease");
   add_action("please", "please");
}

int tease(string str){
   object ob;
   
   if(!str) { 
      write("You must tease someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));
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
   
   tell_object(ob,this_player()->query_name()+" teases you with the vibrator.  You begin to moan\n");
   tell_object(ob, "as the pleasure grows. \n");
   write("You gently tease "+capitalize(str)+" with the vibrator.  "+capitalize(str)+" \n");
   write("begins moaning at you.\n");
   say(this_player()->query_name()+" teases "+capitalize(str)+".\n",ob);
   return 1;
}

please(str) {
   object ob;
   
   if(!str) { 
      write("You must please someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));
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
   
   tell_object(ob,this_player()->query_name()+" moves the vibrator over your body.  You begin \n");
   tell_object(ob, "breathing harder and harder until you can no longer hold back \n");
   tell_object(ob, "the waves of your climax.  \n");
   write("You move the vibrator gently across "+capitalize(str)+"'s body.  "+capitalize(str)+"\n");
   write("begins moaning louder and breathing harder as "+capitalize(str)+"'s body \n");
   write("rocks with the waves of a climax.\n");
   say(this_player()->query_name()+" pleases "+capitalize(str)+".\n",ob);
   return 1;
}
query_save_flag() { return 1; }
