inherit "/obj/monster";
#include "/players/jareel/define.h"
int number;
string mobname;
reset(arg)
{
	number = random(3);
	::reset(arg);
	if (arg) return;
	set_race("newtling");
      set_alt_name("newt");
	set_al(102);
	set_ac(8);
	set_wc(14);
	set_hp(150);
	set_level(10);
	add_money(350+random(100));
	
	if(number == 0) {mobname = "A timid newtling"+NORM;}
	if(number == 1) {mobname = "A happy newtling"+NORM;}
	if(number == 2) {mobname = "An excited newtling"+NORM;}
	
	
	set_name(mobname);
	set_short(mobname);
	set_long(
	  "This small reptilian creature is humanoid in nature but has the head \n"+
	  "of a newt.  The newtlings skin is a composed of a light green scale.\n"+
	  "The newtlings claws look pretty sharp, they could gouge your eyes out.\n");
}
