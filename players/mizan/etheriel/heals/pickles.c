#include "std.h"
int drinks, price;
id(str) { return str == "jar" || str =="pickles"; }
reset(arg) {        if (!arg) drinks = 13;
   price = drinks * 100; }
long() {
   write("This is a jar of homemade pickles with ["+drinks+"] pickles left.\n");
}
short() { return "A jar of pickles"; }
query_save_flag() {return 1;}
query_value()
{ return price; }
#if 0
init() { add_action("use"); add_verb("eat"); }
#else
init() { add_action("use", "eat"); }
#endif
use(arg){
   object tp;
   tp = this_player();
   if(!arg || arg != "pickle"){
      return 0;
   } else {
      if(!tp->eat_food(4)){
         return 1;
        } else {
         if(arg == "pickle"){
            drinks=drinks - 1;
            tp->heal_self(13);
            write("You screw off the jar top, grab a pickle and chomp on it noisily.\n"+
               "There are ["+drinks+"] pickles left.\n");
            say(capitalize(tp->query_name()) + " opens up a glass jar and eats a pickle.\n");
            if(drinks == 0){
               write("There are no more pickles left. You drink up all the juice\n"+
                  "and hurl the jar into oblivion.\n");
               say(capitalize(tp->query_name()) + " finishes a jar of pickles, and drinks the juice left.\n");
               tp->add_weight(-3);
               tp->heal_self(5);
               destruct(this_object());
            }
            return 1;
            }
        }
   }
}

get() {
   return 1;
}

query_weight() {
   return 3;
}
