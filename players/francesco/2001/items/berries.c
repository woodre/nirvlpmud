#include "/players/francesco/univ/ansi.h"
id(str) { return str == "berries"; }
int counter;
reset() {counter=3;}

long() { write("Even though coming from a desolated land, these berries\n"+
               "can still give some relief to your thirsthy and hungry.\n"); }

short() { return HIR+"Some berries "+counter+NORM; }

init() {
    add_action("eat","eat");
    add_action("trade","trade");
    return 1;
}

eat(arg) {
   if (arg=="berries") 
   {
    if(   this_player()->query_stuffed() + 5 < this_player()->query_level()*8
       && this_player()->query_soaked() + 5 < this_player()->query_level()*8)
        { 
         call_other(this_player(), "eat_food", 5);
         call_other(this_player(), "drink_soft", 5);
         call_other(this_player(), "heal_self",23);
         counter--;
         say(call_other(this_player(),"query_name") + " eats one third of the berries.\n");
         write("You eat one third of the berries.\n");
         if (counter==0) { destruct(this_object());return 1;}         
         return 1;
        }
   notify_fail("Be careful, "+call_other(this_player(),"query_name")+", you used too many heals in the last minutes.\n");    
   return 0;
  }   
return 0;
}

trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="berries"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 550 coins for these "+(str)+".\n");
      call_other(this_player(),"add_money",(550));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return (100*counter); }

drop() { return 0; }

query_save_flag() { return 1; } 

