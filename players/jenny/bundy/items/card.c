#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(arg) {
   if(arg) return;
   set_id("card");
   set_alias("membership card");
   set_weight(1);
   set_value(100);
   set_short(RED+"A Card"+NORM);
   set_long(
      "This is a membership card for NO MA'AM.  The National\n"+
      "Organization of Men Against Amazonian Masterhood.  You\n"+
      "might be able to use this card to join NO MA'AM.\n"); 
}

init() { 
   ::init();
   add_action("NOMAAM","join");
}
NOMAAM(arg)  {
   if(TP->query_gender() == "male") {
      TP->set_title(""+BOLD+""+WHT+"("+RED+"+"+WHT+")"+RED+" member of NO MA'AM "+WHT+"("+RED+"+"+WHT+")"+NORM+"");
      write(""+RED+"Congratulations on joining NO MA'AM."+NORM+"\n");
      write_file("/players/jenny/logs/nomam", ""+TPN+" joined NO MA'AM at "+ctime()+"\n");
      command("score",TP);
      destruct(this_object()); TP->recalc_carry();
      
      return 1;  }
   if(TP->query_gender() != "male") {
      write(
         ""+RED+"Only men can join NO MA'AM."+NORM+"\n");
      return 1; 
      if(!arg) { return 0; }
      
   }}
