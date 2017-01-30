#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("You cant put that in there!\n");
    return 1;
}


reset(arg){
   if(arg) return;
   
   set_id("handcuffs");
   set_weight(1);
   
   set_short("A pair of fuzzy handcuffs");
   set_long(HIR+" "+NORM+"\n"+      
      "\n"+
      "Soft fur lines the inside of these leather handcuffs.  \n"+
      "\n"+
      "Maybe you could "+HIB+"'handcuff'"+NORM+" someone.\n"+
      "\n"+      
      MAG+"             Another X-Rated creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("handcuff","handcuff");
}

handcuff(str) {
   object ob;
   
   if(!str) { 
      write("You must handcuff someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));

   if(ob == this_player()){
      write("You can't do that to yourself!\n");
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
   
   tell_object(ob,this_player()->query_name()+" handcuffs you to the bedposts.  "+this_player()->query_name()+"'s hands \n");
   tell_object(ob, "move all about your body teasing and pleasing you.\n");
   write("You gently put the handcuffs on "+capitalize(str)+", and begin pleasing \n");
   write("and teasing "+capitalize(str)+".\n");
   say(this_player()->query_name()+" handcuffs "+capitalize(str)+".  Oh my how KINKY!\n",ob);
   return 1;
}
query_save_flag() { return 1; }
