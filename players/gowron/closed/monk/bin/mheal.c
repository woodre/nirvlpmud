#include "../def.h"

main(arg) {
	object ob;
	string msg,str;
	int num;

	sscanf(arg, "%s %d", str, num);

	ob = present(str, environment(TP));
	if ((!str) || (!num)) {
           write("Usage mheal <player> <amt>\n");
	   return 1;
	}
	if (!ob) {
	   write(str+" is not here.\n");
	   return 1;
	}
	if (MYSP < num) {
           write("You do not have enough spell points.\n");
	   return 1;
	}
	ob->add_hit_point(num);
	TP->add_spell_point(-num);
	msg = CME+" concocts a foul smelling brew and shoves it down "+
	      str+"'s throat.  "+str+" chokes, wheezes, coughs "+
	      "and sputters and then looks better.\n";
	msg = format(msg, 75);
	write(msg);
	say(msg);
	return 1;
}
	
	
