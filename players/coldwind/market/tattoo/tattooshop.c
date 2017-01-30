#include "std.h"
#include "/players/coldwind/ansi.h"
#include "/players/coldwind/define.h"
object ob;
string person;
    string new_body;
init() {
    set_light(1);
   add_action("order","ordertattoo");
   add_action("southeast","southeast");
 }
short() { return "The clothing shop";
   }
long() {
     write("You have enter what appears to be well stocked clothing store.\n"+
     "Above the counter, painted on the wall there is a motto, it reads\n"+
     "'We Can make Anything for 2500 Coins!'. You look around and oddly there\n"+
     "seems to be nobody around. There is a closed sliding door at the end of\n"+
     "the counter where the counter meets the wall.\n");
    write("The only exit is to the southeast.\n");
     call_out("ins", 15);
   }
southeast() {
    call_other(this_player(), "move_player", "southeast#room/northroad1.c");
    return 1;
  }
order(str) {
     short_desc = (str);
    if (!str) return 0;
    if (this_player()->query_money() < 2500) {
        write("You do not have enough money.\n");
        return 1;
        }
   if(person) {
         write("You have to wait for "+person+" to finish.\n");
         return 1;
    }
    person = this_player()->query_name();
    ob=clone_object("/players/boltar/things/clothing.c");
     ob->set_ident("cool tattoo");
     say(this_player()->query_name() +" asks for a cool tattoo\n");
     write("Note: This item must be refered to as: Cool Tattoo\n");
     write("The artists asks you: How would you like your tattoo?");
     input_to("tattoo_short");
      return 1;
}
complete() {
    this_player()->add_money(-2500);
    move_object(ob,this_player());
    say("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "and one hundred coins float away from "+this_player()->query_name()+"'s\n"+
    "pockets and through the sliding door just before it closes.\n");
    write("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "and one hundred coins float away from "+this_player()->query_name()+"'s\n"+
    "pockets and through the sliding door just before in closes.\n");
    this_player()->add_weight(1);
    person=0;
return 1;
     }
ins(){ 
   say("A voice says: Are you going to order some clothes or not?\n");
   }
tattoo_short(str) {
    ob->set_short(str);
    input_to("tattoo_body");
    write("The artist says: You can tell me how you would you like the\n"+ 
	"detailed description to be like, but please end the description with '**'.\n");
      new_body="";
     write("~~>");
    return 1;
}

tattoo_body(str) {
    if (str == "**") {
      ob->set_long(new_body);
	write("Ok.\n");
        complete();
	return;
    }
    new_body = new_body + str + "\n";
   write("*>");
    input_to("tattoo_body");
}

