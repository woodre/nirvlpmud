#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

prevent_insert() {
    write("That would be unkind to deprive the birds of that.\n");
    return 1;
}


reset(arg){
   if(arg) return;
   
   set_id("birdseed");
   set_weight(1);
   
   set_short("Birdseed"+NORM);
   set_long("Birdseed to throw at the happy couple!\n"+      
      "\n"+
      "You can "+HIM+"'throw_seed'"+NORM+" at someone.\n"+
      "\n"+      
      MAG+"              Another creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("throw_seed","throw_seed");
}

int throw_seed(string str){
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

  if( ob == this_player() ) {
    write("You should throw it at someone other then yourself!\n");
    return 1;
  }
   write("You toss the birdseed at "+capitalize(str)+".\n");
   write(HIW+"\n");
   write("     `     `     `     `          `    `     `     `  \n");
   write("   `    `     `     `          `     `     `     `  \n");
   write("           `     `     `     `     `     `     `\n");
   write("      `       `     `          `      `     `\n");
   write(NORM+"\n");
   say(this_player()->query_name()+" tosses the birdseed at "+capitalize(str)+".\n");
   say(HIW+"\n");
   say("     `     `     `     `          `    `     `     `  \n");
   say("   `    `     `     `          `     `     `     `  \n");
   say("           `     `     `     `     `     `     `\n");
   say("      `       `     `          `      `     `\n");
   say(NORM+"\n");
   destruct(this_object());
   return 1;
}

query_save_flag() { return 1; }
