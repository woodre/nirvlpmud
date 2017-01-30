#include "/players/francesco/univ/ansi.h"
id(str) { return str == "pill"; }
int counter;
reset() {counter=3;}

long() { write("A red pill, must be something like dehydrated drink.\n"+
               "You can eat it for healing purposes\n"); }

short() { return HIR+"A red pill "+counter+NORM; }

init() {
    add_action("eat","eat");
    add_action("trade","trade");
    return 1;
}

eat(arg) {
      if (present(arg)==this_object()) /*if (arg=="red pill") */
   {
    if( this_player()->query_soaked() + 8 < this_player()->query_level()*8)
        { 
         call_other(this_player(), "drink_soft", 8);
         call_other(this_player(), "heal_self",19);
         counter--;
         say(call_other(this_player(),"query_name") + " eats one third of a red pill.\n");
         write("You eat one third of a red pill.\n");
         if (counter==0) { destruct(this_object());return 1;}         
         return 1;
        }
   notify_fail("Be careful, "+call_other(this_player(),"query_name")+", you used too many heals in the last minutes.\n");    
   return 0;
  }   
return 0;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return (50*counter); }

drop() { return 0; }
query_save_flag() { return 1; } 
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="pill"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 450 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(450));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}


