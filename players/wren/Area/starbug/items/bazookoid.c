	/* Bazookoid */

#include <ansi.h>
inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("bazookoid");
set_alias("laser");
set_short("Bazookoid "+HIK+"mkII"+NORM+"");
set_long("This mining laser should be handled with the utmost care, \n"+
         "especially when using the heat-seeker option. Do not aim  \n"+
         "in face. This mk II version has removed the red dismantler\n"+
         "switch available on previous models, and is also capable  \n"+
         "of taking live or blank cartridges. The optional back-pack\n"+
         "has been withdrawn from sale.  \n");

set_type("gun");   /*sword,knife,club,axe,bow,polearm */
set_class(15);
set_weight(4);
set_value(1200);
set_hit_func(this_object());
}

weapon_hit(attacker) {
int W;
W = random(32);

if(W>=30)  {
    say(this_player()->query_name()+ " fires a devastating energy bolt into "+ this_player()->query_possessive()+" opponent.\n");
    write("You chamber an energy round and "+HIW+"BLAST"+NORM+" your opponent. \n");
    return 6;
          }

if(W<=3) {
    say("A pair of "+HIR+"heat"+NORM+" seeking shots chase the opponent for several feet before hammering them in the back.\n");
    write("A pair of "+HIR+"heat"+NORM+" seeking shots chase the opponent for several feet before hammering them in the back.\n");
    return 10;
         }

if(W>=10 && W<=14) {
    say("The bazookoid jams and "+ this_player()->query_name()+ "has to pause to fix it.\n");
    write("Your bazookoid jams and you are forced to pause and reset it.\n");
    return 0;
         }
return;
}
