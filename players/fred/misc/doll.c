#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("doll");
      set_alias("figure");
	set_short(BOLD+"A "+HIY+"Fred"+NORM+GRN+" Action Figure "+NORM+BOLD+"["+RED+"tm"+NORM+BOLD+"]"+NORM);
	set_long("  This is the all "+BOLD+RED+"NEW"+NORM+" and "+BOLD+RED+"IMPROVED"+NORM+" patented Fred Action Figure [tm].\n"+
               "It now has the new Kung-Fu grip and little adjustable arms\n"+
               "and legs for your enjoyment. A string with a loop at the end\n"+
               "sticks out of the back. If you "+HIB+"<pull cord>"+NORM+" it would\n"+
               "probably talk to you.\n");
      set_value(0);
}
init() {
	::init();
        add_action("pullem","pull");
        add_action("move_it","adjust");
	}
pullem(str) {
  int a;
  string A;
  a = random(15);
  
  if(!str) { write("What would you like to pull?\n"); return 1; }
  if(str == "cord"){
    switch(a){
      case 0: A = "Next time somebody tells you to have a nice day. You tell them you have other plans."; break;
      case 1: A = "Pain is temporary, Glory last forever."; break;
      case 2: A = "Don't eat the yellow snow."; break;
      case 3: A = "Never hug a porcupine. They look all cute but they hurt =("; break;
      case 4: A = "It takes a big man to cry, but it takes a bigger man to laugh at that man."; break;
      case 5: A = "He who laughs last thinks the slowest."; break;
      case 6: A = "If at first you don't succeed, destroy all evidence that you tried."; break;
      case 7: A = "Remember, no one listens until you make a mistake."; break;
      case 8: A = "The early bird may get the worm, but the second mouse gets the cheese."; break;
      case 9: A = "Never trust a skinny cook."; break;
      case 10: A = "Eagles may soar, but weasels aren't sucked into jet engines."; break;
      case 11: A = "Money can't buy love, but it can rent it for a short time."; break;
      case 12: A = "Hard work pays off in the future, laziness pays off right NOW."; break;
      case 13: A = "Save the whales, collect the whole set."; break;
      case 14: A = "A conclusion is merely the place where you got tired of thinking."; break; }
   tell_room(environment(environment()), this_player()->query_name()+" pulls the cord on the doll.\n");
   tell_room(environment(environment()), "  As the cord slowly recoils...\n"+BOLD+
         "    {"+RED+"Fred"+NORM+BOLD+"}"+NORM+" doll says: "+A+"\n");
   return 1; }
   }

move_it(str){
  if(!str){ write ("Adjust what?\n"); return 1; }
  if(str == "arms"){
    say(this_player()->query_name()+" grabs the arms on the doll and jerks them around.\n");
    write("You grab the arms on the doll and move them around to your liking.\n");
    return 1; }
  if(str == "legs"){
    say(this_player()->query_name()+" grabs the legs on the doll and jerks them around.\n");
    write("You grab the legs on the doll and move them around to your liking.\n");
    return 1; }
 }
