#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
object arm;
id(str) { return str=="linus_angel_mob" || str=="dog" || str=="hellhound"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Hellhound");
 set_short("A large hound chained to the crypt");
 set_long(
 "  The hound fixes his "+HIR+"eyes"+NORM+" on you.  He lets out a throaty growl\n"+
 "through barred teeth, from which tendrils of saliva hang and drop\n"+
 "to the ground.  Coarse black hair covers his muscular frame, and\n"+
 "is saturated in sweat.  Razor sharp claws protrude from his large\n"+
 "feet, and are stained red with blood.  He wears a black spiked\n"+
 "collar, which is connected by a heavy chain to an iron ring in the\n"+
 "crypt doorway.\n");
 arm = CO("/players/linus/Plains/obj/collar.c");
             MO(arm, TO);
             command("wear collar",TO);
 set_level(15);
 set_wc(30);
 set_chat_chance(10);
 load_chat("The hound lets out a deep throaty growl...\n");
 load_chat("The hound paces back and forth...\n");
 load_chat("The hound lifts his hind leg and "+HIY+"pisses"+NORM+" on a grave marker.\n");
 load_chat("The heavy chain drags across the ground as the hound paces...\n");
 set_a_chat_chance(10);
 load_a_chat("The hound lets out a yelp as you strike him.\n");
 load_a_chat("The hound snarls and lunges for your throat.\n"); 
 set_chance(10);
 set_spell_dam(20+random(40));
 set_spell_mess1("The hound\n      "+RED+" / / /  C L A W S  / / /"+NORM+"\n                        his attacker leaving deep wounds.\n");
 set_spell_mess2("The hound\n      "+RED+" / / /  C L A W S  / / /"+NORM+"\n                        you leaving deep wounds.\n");
}
init() {
::init();
add_action("bad_doggie","open");
add_action("bad_doggie","enter");
}
bad_doggie(arg) {
 if(!arg) { write("What?\n"); return 1; }
 if(arg == "door" || arg == "crypt") {
 write("As you reach for the door, the hound growls and\n"+
       "takes a swipe at you with his large paw.\n");
 say("As "+TPN+" reaches for the door, the hound growls and\n"+
     "takes a swipe at "+TPO+" with his large paw.\n", ({TP}));
 return 1;
}
else { write("What?\n"); return 1; }
}
