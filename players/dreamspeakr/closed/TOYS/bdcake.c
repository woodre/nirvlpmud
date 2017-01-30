#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
   if(arg) return;
   
   set_id("cake");

   set_short(HIB+"A HUGE birthday cake"+NORM);
   set_long("A four foot tall chocolate birthday cake \n"+
            "     iced with blue and white roses says:  \n"+      
            "\n"+
                HIW+"   *"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*\n"+
            "\n"+
            HIB+"              "+HIW+"***"+HIB+"Happy Birthday Chelios"+HIW+"***"+NORM+"\n"+
                "\n"+
                HIW+"   *"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+HIB+"~"+HIW+"*"+NORM+"\n"+
            "\n"+
            "\n"+
            "     It almost looks like something could be inside of it.  \n"+
            "     Maybe the birthday boy should 'check' it and see.\n"+
      "\n"+
      MAG+"                   Another creation from Dreamspeakr\n"+NORM);

   set_value(0);
   set_weight(1000);

}
init(){
   ::init();
   add_action("check_cake","check");
}

check_cake(str){
   if (str != "cake"){
      write("What would you like to check?\n");
      return 1;
   }
   if (str == "cake"){
    if(this_player()->query_real_name() == "chelios"){
      write("You begin inspecting the cake closely, and notice a small\n");
      write("button on the top.\n");
      write("\n");
      write("Your finger touches it and all of a sudden the cake begins opening.\n");
      write("\n");
      write("The sexiest woman on the face of the earth pops out of it nakked \n");
      write("as a jay bird!\n");
      write("\n");
      say("Chelios inspects the cake and all of a sudden a nakked woman pops out.\n");
      emit_channel("msg", "\n");
      emit_channel("msg", HIB+"  .:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:.\n"+NORM);
      emit_channel("msg", HIW+"                          Happy Birthday Chelios! \n"+NORM);
      emit_channel("msg", HIB+"  .:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:._.:*"+HIW+"~"+HIB+"*:.\n"+NORM);
      emit_channel("msg", "\n");
      move_object(clone_object("/players/dreamspeakr/closed/toys/gal.c"), environment(this_object()));
    }
    if(this_player()->query_real_name() != "chelios"){
      write ("It's not your birthday!\n");
    }
   return 1;
   }
}
get(){ return 0; }
