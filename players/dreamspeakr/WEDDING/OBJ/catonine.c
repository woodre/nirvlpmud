#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

object whipee_ob;

prevent_insert() {
    write("You cant put that in there!\n");
    return 1;
}

reset(arg){
   if(arg) return;
   
   set_id("cat");
   set_weight(1);
   
   set_short("A leather cat of nine tails"+NORM);
   set_long("A small hand held whip with 9 pieces of leather strips.\n"+      
      "\n"+
      "You can "+HIR+"'cwhip'"+NORM+" someone.\n"+
      "\n"+
      MAG+"             Another X-Rated creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   add_action("whip_them","cwhip");
}

whip_them(str) {
   object ob;
   object new;   
   whipee_ob=str;
   
   if(!str) { 
      write("You must whip someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));
   if(ob == this_player()){
      write("Why not whip someone else with that?\n");
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
   
   tell_object(ob,this_player()->query_name()+" takes out "+this_player()->query_possessive()+" cat of nine tails and begins spanking \n");
   tell_object(ob, "you with it.  You moan in pleasure as the tingles run through \n");
   tell_object(ob, "your body.\n");
   write("You pull out your cat of nine tails and begin whiping "+capitalize(str)+".  "+capitalize(str)+" \n");
   write("moans in pleasure.\n");
   say(this_player()->query_name()+" whips "+str+".\n",ob);
   if(present("sting", find_player(str))){
    return 1;
   }
   new=clone_object("/players/dreamspeakr/WEDDING/OBJ/sting.c");
   move_object(new, find_player(whipee_ob));
   whipee_ob=0;
   return 1;
}
query_save_flag() { return 1; }

