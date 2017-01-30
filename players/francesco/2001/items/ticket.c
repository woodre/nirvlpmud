#include "/players/francesco/univ/ansi.h"
inherit "obj/treasure.c";

reset(arg) {
set_weight(1);
set_value(100);
set_id("ticket");
}
short() { return HIB+"A ticket to the cinema"+NORM; }

long(str) {
    write("This ticket entitles you to enter the cinema of the University.\n"+
          "Only one show can be attended.  'Refund'able before entrance\n"+
          "at a 20% loss of full price.\n");
   return;}
  

init() {
    add_action("refund","refund");
    return 1;
}
  
refund(arg) {
    if(arg=="ticket")
     {
      if(!present("hope",environment(this_player())))
     {write("The ticket is not refundable here.\n"); return 1;}
      call_other(this_player(),"add_money",(80)); 
      write("Hope says:  "+call_other(this_player(),"query_name")+", if you really dont want to attend the show anymore,\n"+
            "I can refund you 80 coins for this ticket.\n");
      destruct(this_object());
      return 1; 
     }
    notify_fail("What do you want to be refunded?\n"); return 0;
}  
