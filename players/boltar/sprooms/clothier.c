#include "std.h"
object ob;
string person;
string new_body;
int running;

init() {
   set_light(1);
   add_action("order","order");
   add_action("southeast","southeast");
   add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
  }

short() { return "The clothing shop";
   }

long() {
     write("You have enter what appears to be well stocked clothing store.\n"+
     "However, like many other shops in town the inventory sits behind\n"+
     "a counter in a closed off room. The top of the counter here is \n"+
     "blocked by a plexi-glass window, and there is a small buzzer door.\n"+
     "Above the counter, painted on the wall there is a motto, it reads\n"+
     "'We Can make Anything for 100 Coins!'. You look around and there\n"+
     "is a woman that can be seen in the back room. There is a closed\n"+
     "sliding door at the end of the counter where the counter meets the\n"+
     "wall. The only exit is to the southeast.\n");
     if(!running) call_out("ins",150);
     running +=1;
   }
look(str) {
   if (!str) return 0;
  if (str == "at counter") {
     write("The wood counter is painted a bright yellow and has a long\n"+
     "ruler bolted to it.\n");
     return 1;
   }
   if (str=="at plexi-glass window" || str=="window"||str=="plexi-glass"){
     write("Just a tough plexiglass window to prevent people from\n"+
     "going over the counter into the back room.\n");
     return 1;
   }
   if (str=="back room" || str=="room") {
    write("It appears to be a well stocked inventory room with an \n"+
    "area to make clothes as well.\n");
    return 1;
   }
   if (str=="at door") { 
     write("One door has a buzzer lock and allows people to enter the\n"+
      "back room. The other appears of the type goods would slide out of.\n");
     return 1;
  }
   if(str=="at woman") {
     write("A middleaged woman going about making clothes. She has blonde\n"+
     "hair, slightly overweight, with a large bustline. She is wearing\n"+
     "a shirt that shows some cleavage.\n");
     write("You may order clothes from her by starting with\n"+
      "what it is you would like.\n");
     return 1;
   }
  return 0;
}
southeast() {
    call_other(this_player(), "move_player", "southeast#room/northroad1.c");
    return 1;
  }
order(str) {
    if(!str) return 0;
    if (this_player()->query_money() < 100) {
        write("You do not have enough money.\n");
        return 1;
        }
   if(person) {
         write("The woman is busy with another customer.\n");
         write("You have to wait for "+person+" to finish.\n");
         return 1;
    }
    person = this_player()->query_name();
    ob=clone_object("/players/boltar/things/clothing.c");
    ob->set_ident(str);
    write("The woman says: the item will be known by _"+str+"_\n\n");
    say(this_player()->query_name() +" orders a "+str+"\n");
    write("The woman asks you give a short description of the object\n"+
          "Short Description:  ");
    input_to("get_short");
    return 1;
}
complete() {
    this_player()->add_money(-100);
    move_object(ob,this_player());
    write("You are buzzed in to the back room where the woman takes your\n"+
      "order and your money, measuring you for the clothes. The door \n"+
      "opens and you find yourself pulled back to the outer room by \n"+
      "forces unknown.\n");
    say(this_player()->query_name()+" is buzzed into the back room and\n"+
        "quickly returns\n"); 
    say("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "\n");
    write("The sliding door at the end of the counter opens and a "+ob->short()+"\n"+
    "slides down the counter into the hands of "+this_player()->query_name()+"\n"+
    "\n");
    this_player()->add_weight(1);
    person=0;
return 1;
     }
ins(){ 
   int bl;
   bl = random(2);
   if(bl==1)
     say("The woman says: Are you going to order some clothes or not?\n");
   if(bl==0)
     say("The woman peeks out at you and goes back to her work.\n");
   }
get_short(str) {
    ob->set_short(str);
    input_to("get_body");
    write("Give the long description, and terminate with '**' on a line by itself.\n");
    new_body="";
    write("*>");
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
   write("*>");
    input_to("get_body");
}

