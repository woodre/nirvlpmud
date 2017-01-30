#include "/players/francesco/univ/ansi.h"
id(str) { return str == "cigarettes" || str == "pack"; }
int counter;
reset() {counter=20;}

long() { write("A red and white pack of cigarettes. When you open it, you notice that\n"+
               "there are still "+counter+" cigarettes in it. Take one and enjoy to 'smoke' it.\n"+
               "Something is written on it with small characters:  'view' them.  \n"); }

short() { return HIW+"A pack of "+HIR+"cigarettes"+NORM; }

init() {
    add_action("smoke","smoke");
    add_action("view","view");
return 1;
}

smoke(arg) {
   if (arg=="cigarette") {
    if (!call_other(this_player(), "drink_alcohol", 1)){
       write("Cigarettes might be dangerous to your health,  "+call_other(this_player(),"query_name")+", The general surgeon said.\n");    
    return 1;}
    call_other(this_player(),"heal_self",2);
    counter--;
    tell_object(this_player(),"You take a drag off your cigarette.\n");
    say(call_other(this_player(),"query_name") + " takes a drag off "+this_player()->query_possessive()+" cigarette.\n");
    if (counter==0) { destruct(this_object()); return 1;}         
   return 1;}
  notify_fail("Smoke what?\n");    
 return 0;}   

view(str) {
  if(!str) {notify_fail("View what?\n"); return 0;}
   if(str == "characters") {
      write("According to the Surgeon General, smoking is dangerous to your health.\n");
      return 1;}
  notify_fail("View what?\n"); 
return 0;}


get() { return 1; }

query_weight() { return 1; }

query_value() { return (16*counter); }

drop() { return 0; }

query_save_flag() { return 1; } 

