/* approved by Mythos <4-6-98>
   any problems refer to me -mas */
#include "/players/llew/closed/ansi.h"

inherit "/obj/treasure";

string color,flavor;
int kind;

reset(flibble) {
   if(flibble) return;
   set_weight(1);
   set_value(200);
   set_id("pixie");
   set_alias("stick");
   set_read("Ingredients:\n\tSugar, sucrose, high fructose corn syrup,\n\tartificial flavoring, artifical colors, strychnine\n");
   set_long("duh");
   kind=random(6);   
   color=({RED,HIR,HIY,HIG,HIB,HIM});
   flavor=({"strawberry","cherry","lemon","lime","berry","grape"});

}

prevent_insert() {
   write("You don't want to cruch the pixie stick!\n");
   return 1;
}

short() {
   return color[kind]+"A "+flavor[kind]+" pixie stick"+NORM;
}

long() {
   write(color[kind]+capitalize(flavor[kind])+" pixie stick...\n\n\n"+NORM);
   picture();
   write("\n\n\n");
   write("The Pixie Stick is full of sugar induced happiness.\n");
   write("Eat sugar for a boost of energy.  Wheee!!!\n\n");
}

query_save_flag() { return 1; }

init() {
   ::init();
   add_action("eat","eat");
}

picture() {
   write(color[kind]+"\t _ "+NORM+BOLD+"_ "+NORM+color[kind]+"_ "+NORM+BOLD+"_ "+NORM);
   write(color[kind]+"_ "+NORM+BOLD+"_ "+NORM+color[kind]+"_ "+NORM+BOLD+"_ "+NORM);
   write(color[kind]+"_ "+NORM+BOLD+"_ "+NORM+color[kind]+"_ "+NORM+BOLD+"_ "+NORM);
   write(color[kind]+"_ "+NORM+BOLD+"_ "+NORM+color[kind]+"_ "+NORM+BOLD+"_ "+NORM);
   write("\n\t");
   write(BOLD+"|"+NORM);
   write(color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM+color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM);
   write(color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM+color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM);
   write(color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM+color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM);
   write(color[kind]+"\\_"+NORM+BOLD+"\\_"+NORM+color[kind]+"\\_"+NORM+BOLD+"\\"+NORM);
   write(BOLD+"|"+NORM);
}

eat(poison) {
   if(!poison || poison != "sugar") {
      notify_fail("Eat what?\n");
      return 0;
   }
   if(!this_player()->eat_food(random(4)+4) || !this_player()->drink_soft(random(6)+3) || !this_player()->drink_alcohol(random(3)+4)) {
      write("\nYou're knocked off your feet by the experience!!!\n\n");
      this_player()->heal_self(-(random(3)+3));
      destruct(this_object());
      return 0;
   }
   say(this_player()->query_name()+" sucks on a pixie stick.\n");
   write("You suck on the pixie stick...\n");
   picture();
   write("\n\n");
   switch(random(9)) {
      case 0:  write("It makes you feel tingly all over...\n");
               say(this_player()->query_name()+"'s body shakes...\n");
               break;
      case 1:  write("You're full of giddiness.\n");
               say(this_player()->query_name()+" is very giddy.\n");
               break;
      case 2:  write("You bounce all around the room!\n");
               say(this_player()->query_name()+" bounces around the room!\n");
               break;
      case 3:  write("You being to laugh uncontrollably.\n");
               say(this_player()->query_name()+" laughs uncontrollably.\n");
               break;
      case 4:  write("It makes you shiver with delight.\n");
               say(this_player()->query_name()+" shivers with delight.\n");
               break;
      case 5:  write("You being to feel a little loopy.  WHEEE!!!!\n");
               say(this_player()->query_name()+" shouts, \"WHEEE!!!!\"\n");
               break;
      case 6:  write("You come down with a fit of hysterical giggles.\n");
               say(this_player()->query_name()+" giggles hysterically.\n");
               break;
      case 7:  write("Your muscles start to twitch.\n");
               say(this_player()->query_name()+" twitches about.\n");
               break;
      case 8:  write("You drool for more sugar.\n");
               say(this_player()->query_name()+" drools all over "+this_player()->query_objective()+"self.\n");
               break;
   }
   this_player()->heal_self(random(11)+20);
   destruct(this_object());
   return 1;
}
