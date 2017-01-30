/* Code provided by the great Jaraxle */
#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";

int how_many, c_name;
object x;
reset(arg){
   how_many = 4;
   if(arg) return;
   set_id("corpse pile");
   set_alias("pile");
   set_short(""+RED+"A large corpse pile"+NORM+"");
   set_value(0);
   set_weight(140);
}
long(){
   if(how_many <= 0){ 
      write("This is a very large pile of human corpses.  The corpses have been dragged\n"+
         "into here by the worker ants.  They put all the bloody corpses into a pile\n"+
         "to make it easier to dismember them, and make them into food for the queen.\n");
   }
   else{
      write("This is a very large pile of human corpses.  The corpses have been dragged\n"+
         "into here by the worker ants.  They put all the bloody corpses into a pile\n"+
         "to make it easier to dismember them, and make them into food for the queen.\n"+
         "You might be able to 'pull' some of the corpses out of the pile.\n"); 
   }
}

   init(){
      ::init();
      add_action("new_corpse","pull");
   }
   
   new_corpse(str){
      x = clone_object("/obj/corpse");
      switch(random(6)){
         case 0: c_name = "Mary";
         break;
         case 1: c_name = "Peter";
         break;
         case 2: c_name = "Calvin";
         break;
         case 3: c_name = "Samantha";
         break;
         case 4: c_name = "Thomas";
         break;
         case 5: c_name = "Jessica";
         break;
}
      
      if(present("corpse")){  write("A corpse has already been pulled from the pile!\n"); return 1; }
      if(str != "corpse from pile"){ notify_fail("You can only 'pull corpse from pile'.\n"); return 0; }
      if(how_many <= 0){ write("There are no full corpses left to pull out, only\nuseless body parts and decomposing bodies.\n"); return 1; }
      write("You pull a corpse from the pile.\n");
      say(TPN+" pulls the corpse of "+capitalize(c_name)+" from the pile.\n");
      x->set_name(c_name);
      move_object(x, environment());
      how_many -= 1;
      
      return 1; }
