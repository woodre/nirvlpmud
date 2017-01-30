#include "/obj/ansi.h"

#define en		environment(this_object())
#define EN		capitalize(environment(this_object())->query_name())
#define NF		GRN+"noxious"+NORM+" "+YEL+"fumes"+NORM
#define MAX_MSG_NUM	3

int do_damage;
int msg_num;

reset(arg)
{
  if(arg) return;
  do_damage = 0;
  msg_num = random(4);
  set_heart_beat(1);
  return;
}

short() { return; }
long() { return; }
query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }

id(str)
{
  if(!en || !environment(en))
	return str == "cloudkill_obj";

  if(!present("cloudkill", environment(en)))
	return str == "cloudkill_obj";
  else
	return str == "no_combat" || str == "no_msg_hit" ||
	  str == "no_weapon_attack" || str == "cloudkill_obj";
}

set_do_damage(i){ do_damage = i; }
query_do_damage(){ return do_damage; }

heart_beat()
{
  object env;
  int msg;

  if(!en || !living(en))
	return destruct(this_object());

  if(!(env = environment(en)))
	return destruct(this_object());

  if(!present("cloudkill", env))
	return destruct(this_object());

  if(msg == 0)
	tell_room(env, EN+" "+YEL+"falls"+NORM+" to the ground and "+HIG+"pukes"+NORM+".\n");
  else if(msg == 1)
	tell_room(env, EN+" "+GRN+"chokes"+NORM+" and "+HIBLK+"gags"+NORM+" on the "+NF+".\n");
  else if(msg == 2)
	tell_room(env, EN+" succumbs to a helpless "+GRN+"fit"+NORM+" of "+YEL+"coughing"+NORM+".\n");
  else if(msg == 3)
	tell_room(env, EN+" is "+MAG+"overcome"+NORM+" with a "+YEL+"wave"+NORM+" of "+GRN+"nausea"+NORM+".\n");

  msg_num++;
  if(msg_num > MAX_MSG_NUM)
	msg_num = 0;

}

