#include "std.h"
object ob;
string person;
    string new_body;
init() {
    set_light(1);
   add_action("order","order");
   add_action("out","out");
   add_action("out","leave");
   add_action("out","exit");
 }
short() { return "Tattoo Shop";
   }
long() {
     write("You have entered what looks like an artist's tent. Beautiful designs\n"+
	       "are drawn on the walls of the tent as well as on piles of hides\n"+
		   "thrown with ignorance by the northeast corner. Large cushions takes\n"+
		   "most of the west side of the tent. Behind the cushions, you notice\n"+
		   "a small sign.\n");
     call_out("ins", 15);
   }
out() {
    call_other(this_player(), "move_player", "southeast#room/northroad1.c");
    return 1;
  }
order(str) {
    if(!str) return 0;
    if (this_player()->query_money() < 5000) {
        write("The artist yells: Do not bother me unless you have enough money!!.\n");
        return 1;
        }
   if(person) {
         write("Please wait for "+person+" to finish.\n");
         return 1;
    }
    person = this_player()->query_name();
    ob=clone_object("/players/boltar/things/clothing.c");
     ob->set_ident("A "+str+" tattoo");
     say(this_player()->query_name() +" gets a "+str+" tattoo.\n");
     write("You got a "+str+" tattoo\n");
     input_to("get_short");
      return 1;
}
complete() {
    this_player()->add_money(-5000);
    move_object(ob,this_player());
    say("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "and one hundred coins float away from "+this_player()->query_name()+"'s\n"+
    "pockets and through the sliding door just before it closes.\n");
    write("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "and one hundred coins float away from "+this_player()->query_name()+"'s\n"+
    "pockets and through the sliding door just before in closes.\n");
    person=0;
return 1;
     }
ins(){ 
   say("The artist says: Why don't sit and let me decorate your body?\n");
   }
get_short(str) {
    ob->set_short(str);
    input_to("get_body");
    write("Add a detailed description, and terminate with '**'.\n");
      new_body="";
     write(">>");
    return 1;
}

get_body(str) {
    if (str == "**") {
      ob->set_long(new_body);
	write("Ok.\n");
        complete();
	return;
    }
    new_body = new_body + str + "\n";
   write(">>");
    input_to("get_body");
}

