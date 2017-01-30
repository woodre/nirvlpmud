#include "/players/mythos/closed/guild/def.h"

id(str) {return str == "demon_pact";}
int stopper;

get() { return 0;}
drop() { return 1;}
query_stopper() { return stopper; }

reset(arg) {
  if(arg) return;
  stopper = 0;
  call_out("one",90);
}

one() {
  stopper = 1;
  tell_object(ep,"\nThe ground shakes! The air darkens!\n");
  call_out("two",15);
return 1;}

two() {
  tell_object(ep,"Thunder booms and the ground before you splits!\n");
  tell_object(ep,HIB+
    "\nDark smoke erupts from the ground and slowly solidifies!\n\n"+NORM);
call_out("three",6);
return 1;}

three() {
  tell_object(ep,"A man stands before you when the smoke clears.\n"+
                 "He wears a blood red business suit and carries a small briefcase.\n"+
                 "He smiles- a chilling smile- red beady eyes gleam from behind\n"+
                 "his small glasses.\n");
  call_out("four",6);
return 1;}

four() {
  tell_object(ep,"He glances at you and in a business like tone speaks:\n"+
                 "   'So, you wish to make a pact with us.  Before\n"+
                 "    I go on and take down your proposal, let me\n"+
                 "    introduce you to the corporation.'\n"+
                 "He snaps his fingers and an image flashes before you.\n");
  call_out("five",6);
return 1;}

five() {
  tell_object(ep,"A face made from flames stares back at you.  It smiles\n"+
                 "and in a deep voice it intones:\n"+
                 "    >Welcome to H.E.L.L. Inc.\n"+
                 "    >We are in the trade business.  You ask \n"+
                 "    >and we produce.  But at a price.\n");
  tell_object(ep,"The face laughs maniacally.\n"+
                 "    >Like all things, there is a price.\n"+
                 "    >We at H.E.L.L. Inc. wish to give you \n"+
                 "    >a good bargain.  You name the price and\n"+
                 "    >the gift and our sales representative will\n"+
                 "    >get back to you as soon as possible.\n"+
                 "The image vanishes and the salesman smiles...\n"+
                 "He takes out a business notebook and pen and asks\n"+
                 "    'Gift: \n");
  input_to("six");
return 1;}

six(str) {
  if(!str) { write("Gift: \n"); input_to("six"); return 1;}
  write_file("/players/mythos/closed/guild/prop/g/"+epn,ctime(time())+" GIFT  "+str+"\n");
  tell_object(ep,"The man nods and jots it down.\n"+
                 "He asks, 'Price: ");
  input_to("seven");
return 1;}

seven(str) {
  if(!str) { write("Price: \n"); input_to("seven"); return 1;}
  write_file("/players/mythos/closed/guild/prop/g/"+epn,ctime(time())+" Price  "+str+"\n");
  tell_object(ep,"The man nods and jots it down.\n"+
                 "He asks, 'Is that final? <y/n> ");
  input_to("eight");
return 1;} 

eight(str) {
  if(str == "y") {
     tell_object(ep,"The man nods and tells you:\n"+
                    "   'Okay.  Then we will get back to you as soon as\n"+
                    "    the appropriate commitee takes a look at your propasal.\n"+
                    "    If you wish to clearify anything mail 'mythos'\n"+
                    "    And have a fun day.'\n"+
                    "He laughs and vanishes.\n");
     return 1;}
  if(str == "n") {
     rm("/players/mythos/closed/guild/prop/g/"+epn);
     tell_object(ep,"The man tears out a piece of paper and asks you again:\n"+
                    "   'Gift:  ");
     input_to("six");
  return 1;} 
  write("<y/n>  ");
  input_to("eight");
return 1;}
                 
