inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

object gold;
reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("mosquito");
	set_alt_name("shinshi_mosquito");
	set_race("insect");
	set_alias("bug");
	set_short("A tiny mosquito"+NORM);
	set_long("\
		The mosquito is about one-fifth of an inch long, with a\n\
		slightly shorter spread of its narrow wings. Its body,\n\
		like that of other insects, consists of a head, thorax, and\n\
		abdomen. The round head has a long tubular mouth part and\n\
		antennae. The mosquitos slender legs are attached to the\n\
		triangular thorax. The abdomen is long and narrow.\n");
	gold = clone_object("obj/money");
	gold->set_money(2000+random(5000));
	move_object(gold, this_object());
	set_level(20);
	set_hp(500 + random(100));
	set_ac(17 + random(8));
	set_wc(30 + random(10));
	set_al(-7000);
	add_spell("bite","#MN# sucks some "+HIR+"blood"+NORM+"from you.\n",
			  "#MN# "+HIR+"sucks "+NORM+"blood from you.\n",
			  30,75,"other|physical");
}


heart_beat()
{
  object tun;
  ::heart_beat();
  if(!environment()) return;
  
  tun = present("tunnel");
  
  if(tun)
  {
	  destruct(tun);
	  tell_room(environment(this_object()), "You have died. You must 'exit' and get to the church.\n");
  }
}