/* This is Snow's pain pills */

inherit "/obj/clean.c";
inherit "/obj/treasure.c";
#include <ansi.h>
int charges;
id(str) { return str == "lifesavers" || str == "lifesaver"; } 

reset(arg) {
        if (!arg) charges = 3;
        set_short("A bag of "+HIR+"L"+HIY+"i"+HIG+"f"+HIB+"e"+HIM+"s"+HIC+"a"+HIW+"v"+HIR+"e"+HIY+"r"+HIG+"s"+NORM);
  set_no_clean();
}
 
long() {
        write(
     "This is a small bag of Lifesavers that is usually consumed\n"+
     "to gain an extra burst of energy. Perhaps you could 'eat' one.\n"+
     "There are "+RED+charges+NORM+" lifesavers left.\n");
}
query_value() { return 0; }
 
init() {
    add_action("heal"); add_verb("eat");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "lifesavers" || arg == "lifesaver") {

int amount;
amount = (random(this_player()->query_mhp() - this_player()->query_hp()) + this_player()->query_attrib("sta"));
  charges--;
  this_player()->heal_self(amount); 
        write(
"You open the bag of Lifesavers and take a one out of the bag.\n"+
"You pop it into your mouth and feel a little better.\n"+
"There are "+RED+charges+NORM+" lifesavers left.\n");
        say(
this_player()->query_name()+" opens a bag of lifesavers and pops one into "+possessive(this_player())+" mouth.\n");
command("mon",this_player());

if(charges < 1){
  write("You finish off the bag of Lifesavers and throw the bag away.\n");

     destruct(this_object()); this_player()->recalc_carry();

                }
return 1;
                }
        }
get() {
    return 1;
}
 
query_charges(){ return charges; }
query_weight() { return 1; }
 
query_save_flag() { return 1; }

is_heal() { return "no-tox"; }