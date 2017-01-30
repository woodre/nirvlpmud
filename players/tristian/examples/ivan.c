#include "/obj/living.h"
#include "/players/dakeyras/define.h"
inherit "/obj/monster.c";

reset(arg) {
   
  ::reset(arg);
    if (arg) return;

    set_name("ivan");

    set_level(18);

    set_short("Ivan, the barkeep");

    set_long(
"  Ivan is a massive man, standing about seven feet tall.  He is well muscled\n"+
"and appears more than able to quell any bar fights.  His size makes him\n"+
"appear a bear of a man, but his smile makes him appear more like a great\n"+
"teddy bear.  He smiles at you, waiting for you to order.\n");
    
}

init() {
::init();

add_action("enter","enter");}

query_name() { return "ivan"; }


id(str) {
  return str == "bartender" || str == "barkeep" || str == "ivan";
}
second_life() {
write("Ivan dies, crashing onto the ground behind the bar.  At the site\n"+
"the barmaid screams and locks herself inside the kitchen.\n");
destruct(this_object());
   return 1;
}

search(arg) {
if(arg != "door") return 0;
write("Ivan stops you with a firm hand.\n"+
"Ivan says, 'Sorry, employees only.'\n");
return 1; }
