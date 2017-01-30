inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

object gold;
reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("wasp");
	set_alt_name("shinshi_wasp");
	set_race("wasp");
	set_alias("bee");
	set_short("A large "+HIY+"w"+HIK+"a"+HIY+"s"+HIK+"p"+NORM);
	set_long("\
		The wasp is approximately fourteen and a half millimeters.\n\
		Its head, thorax, and abdomen are black and yellow or white.\n\
		The body is fairly stout and its wings are smokey.\n");
	gold = clone_object("obj/money");
	gold->set_money(2000+random(5000));
	move_object(gold, this_object());
	set_level(20);
	set_hp(500 + random(100));
	set_ac(17 + random(8));
	set_wc(30 + random(10));
	set_al(-7000);
	set_chat_chance(1);
	load_chat(query_name()+" buzzes around your head.\n");
	add_spell("sting","#MN# "+HIK+"stings "+NORM+" you.\n",
			  "#MN# "+HIY+"stings "+NORM+"you.\n",
			  15,75,"other|physical");
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