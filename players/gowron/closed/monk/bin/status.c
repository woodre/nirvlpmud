#include "../def.h"

main(str) {
	object ob;
	int p,i,ac,wc,hp,maxhp;
	string name;

	if (!str) {
	   write("usage status <what>\n");
	   return 1;
	}

	if (RANK < 2) {
           LOW_RANK;
	   return 1;
	}
	if (MYSP < 15) {
           NO_SP;
	   return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
	   write(str+" is not here.\n");
           return 1;
	}
	name = ob->query_name();
	wc = ob->query_wc();
	ac = ob->query_ac();
	maxhp = ob->query_mhp();
	hp = ob->query_hp();
	p = (hp*100/maxhp);
	write("Name: "+name+"\n");
	write("Location: "+environment(TP)->short()+"\n");

	write("Armor: ");
	if (ac < 3) 
           write("Poorly Armored");
	else
	if ((ac > 2) && (ac < 8)) 
           write("Average Protection");
	else
	if ((ac > 7) && (ac < 11))
	   write("Well Protected");
	else
	if ((ac > 10) && (ac < 20)) 
           write("Very Well Protected");
	else
	if (ac > 19)
	   write("You think you're really going to hit this guy?");
	else
           write("Incalculable");
	write("\n");

	write("Weapon: ");
	if (wc < 5) 
           write("This guy couldn't hit the broadside of a barn");
	else
	if ((wc > 4) && (wc < 15))
           write("He may cause you a few scratches, but nothing serious.");
	else
	if ((wc > 14) && (wc < 20))
           write("This monster could cause some moderate damage to you.");
	else
	if ((wc > 19) && (wc < 30))
	   write("This monster could cause you serious bodily harm.");
	else
	if (wc > 29)
           write("You're dead. :) ");
	else
	   write("Could hurt you, maybe it won't.. you never know.");
	write("\n");

	write("Full health: ");
	if (maxhp < 200)
           write("This monster won't last very long against you.");
	else
	if ((maxhp > 199) && (maxhp < 300))
           write("This monster will last a bit.");
	else
	if ((maxhp > 299) && (maxhp < 400))
           write("This monster will last a while.");
	if ((maxhp > 399) && (maxhp < 600))
           write("This monster will last a long time.");
	if (maxhp > 599) 
	   write("This monster could last a *really* long time.");
	else
	   write("Who knows.");
	write("\n");

	write("Current health: "+p+"\n");
	return 1;
}


