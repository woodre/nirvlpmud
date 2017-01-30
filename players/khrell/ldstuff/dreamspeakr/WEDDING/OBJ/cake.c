#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

object eater_ob;

prevent_insert() {
    write("That would make a BIG mess!  Don't think you wanna do that.\n");
    return 1;
}


reset(arg){
   if(arg) return;
   
   set_id("cake");
   set_weight(1);
   
   set_short("A piece of wedding cake"+NORM);
   set_long("A slice of wedding cake, small roses made of sweet icing\n"+      
            "decorate it.\n"+
      "\n"+
      "You can "+HIM+"'feed_cake'"+NORM+" someone your cake.\n"+
      "\n"+      
      MAG+"                   Another creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("feed","feed_cake");
}

feed(str){
   object ob;
   object new;   
   eater_ob=str;   

   if(!str) { 
      write("You must feed your cake to someone.\n"); return 1; 
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
      write("It would be more appropriate to feed this to someone else!\n");
      return 1;
  }
   tell_object(ob,this_player()->query_name()+" takes the piece of cake and shoves it into your mouth.\n");
   tell_object(ob, "Icing and crumbs smear across your face.  Boy your a mess!\n");
   write("You shove a piece of cake into "+capitalize(str)+"'s mouth smearing icing all over "+capitalize(str)+"'s face! \n");
   say(this_player()->query_name()+" shoves cake into "+capitalize(str)+"'s mouth.  Icing covers "+capitalize(str)+"'s face!.\n",ob);
   destruct(this_object());
   if(present("face", find_player(str))){
    return 1;
   }
   new=clone_object("/players/dreamspeakr/WEDDING/OBJ/face.c");
   move_object(new, find_player(eater_ob));
   eater_ob=0;
   return 1;
}

query_save_flag() { return 1; }
