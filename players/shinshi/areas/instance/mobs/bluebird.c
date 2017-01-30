inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

object gold;
reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("bluebird");
	set_alt_name("shinshi_bird");
	set_race("bird");
	set_alias("bird");
	set_short("A large "+HIB+"bluebird"+NORM);
	set_long("\
		This bluebird measures six and a half inches in\n\
		length. He has bright blue feathers, a reddish\n\
		breast, and a white underbelly. The sight of him\n\
		is usually a sign that winter is on the way out.\n");
	gold = clone_object("obj/money");
	gold->set_money(2000+random(5000));
	move_object(gold, this_object());
	set_level(20);
	set_hp(500 + random(100));
	set_ac(17 + random(8));
	set_wc(30 + random(10));
	set_al(-7000);
	set_chat_chance(1);
	load_chat(query_name()+" tweets.\n");
	add_spell("peck","#MN# "+HIY+"pecks "+NORM+" your head.\n",
			  "#MN# "+HIY+"pecks "+NORM+"your head.\n",
			  25,75,"other|physical");
	add_spell("claw","#MN# digs its claws into your shoulder.\n",
			  "#MN# digs its claws into your shoulder.\n",
			  10,150,"other|physical");
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