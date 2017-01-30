#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("You cant put that in there!\n");
    return 1;
}


reset(arg){
   if(arg) return;
   
   set_id("confetti");
   set_weight(1);
   
   set_short(HIB+"C"+HIR+"o"+HIG+"l"+HIY+"o"+HIW+"r"+HIB+"f"+HIR+"u"+HIG+"l"+HIY+" C"+HIW+"o"+HIB+"n"+HIR+"f"+HIG+"e"+HIY+"t"+HIW+"t"+HIB+"i"+NORM);
   set_long("A bucket full of confetti!\n"+      
      "\n"+
      "You can "+HIM+"'throw_confetti'"+NORM+" at someone.\n"+
      "\n"+      
      MAG+"              Another creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("throw_confetti","throw_confetti");
}

int throw_confetti(string str){
   object ob;
   
   if(!str) { 
      write("You must throw that at someone.\n"); return 1; 
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
    write ("Why not thoss it at someone other then yourself!\n");
    return 1;
  }
   write("You toss confetti at "+capitalize(str)+".\n");
   write(HIB+"\n");
   write("     ~"+HIR+"     ~ "+HIG+"    ~"+HIY+"     ~ "+HIW+"         ~ "+HIB+"   ~  "+HIR+"   ~  "+HIG+"   ~  \n");
   write(HIY+"   ~ "+HIW+"   ~ "+HIB+"    ~  "+HIR+"   ~  "+HIG+"        ~   "+HIY+"  ~  "+HIW+"   ~ "+HIB+"    ~  \n");
   write(HIR+"           ~ "+HIG+"    ~ "+HIY+"    ~"+HIW+"     ~ "+HIB+"    ~  "+HIR+"   ~  "+HIG+"   ~"+HIY+"\n");
   write(HIW+"      ~ "+HIB+"      ~ "+HIR+"    ~  "+HIG+"        ~ "+HIY+"     ~   "+HIW+"  ~"+HIB+"\n");
   write(NORM+"\n");
   say(this_player()->query_name()+" tosses the confetti at "+capitalize(str)+".\n");
   say(HIB+"\n");
   say("     ~"+HIR+"     ~ "+HIG+"    ~"+HIY+"     ~ "+HIW+"         ~ "+HIB+"   ~  "+HIR+"   ~  "+HIG+"   ~  \n");
   say(HIY+"   ~ "+HIW+"   ~ "+HIB+"    ~  "+HIR+"   ~  "+HIG+"        ~   "+HIY+"  ~  "+HIW+"   ~ "+HIB+"    ~  \n");
   say(HIR+"           ~ "+HIG+"    ~ "+HIY+"    ~"+HIW+"     ~ "+HIB+"    ~  "+HIR+"   ~  "+HIG+"   ~"+HIY+"\n");
   say(HIW+"      ~ "+HIB+"      ~ "+HIR+"    ~  "+HIG+"        ~ "+HIY+"     ~   "+HIW+"  ~"+HIB+"\n");
   say(NORM+"\n");
   destruct(this_object());
   return 1;
}

query_save_flag() { return 1; }
