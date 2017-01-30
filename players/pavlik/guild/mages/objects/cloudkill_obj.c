#include "/obj/ansi.h"

#define en		environment(this_object())
#define EN		capitalize(environment(this_object())->query_name())
#define NF		GRN+"noxious"+NORM+" "+YEL+"fumes"+NORM

object owner;
int do_damage;
int poisoned;
int msg_num;
string *msgs;
string *player_msgs;

reset(arg)
{
  if(arg) return;
  do_damage = 0;
  owner = 0;
  poisoned = 0;
  set_heart_beat(1);
  player_msgs = ({
	"'s face turns "+YEL+"sickly "+GRN+"green"+NORM+".\n",
	" breaks into a "+BLU+"cold"+NORM+" sweat.\n",
	" stops breathing to "+MAG+"avoid"+NORM+" the "+NF+".\n",
  });
  msgs = ({
	" "+YEL+"falls"+NORM+" to the ground and "+HIG+"pukes"+NORM+".\n",
	" "+GRN+"chokes"+NORM+" and "+HIBLK+"gags"+NORM+" on the "+NF+".\n",
	" succumbs to a helpless "+GRN+"fit"+NORM+" of "+YEL+"coughing"+NORM+".\n",
	" is "+MAG+"overcome"+NORM+" with a "+YEL+"wave"+NORM+" of "+GRN+"nausea"+NORM+".\n",
	" "+GRN+"gags"+NORM+" on the "+NF+".\n"
  });
  msg_num = random(sizeof(msgs)-1);
}

short() { return; }
long() { return; }
query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }
do_no_attack_message(ob){ return 1; }

id(str)
{
  if(!en || !environment(en))
	return str == "cloudkill_obj";

  /*
   * dont affect combat of players ...
   * unless the player is in combat with owner
   */
  if(en->is_player() && (owner && owner->query_attack() != en))
	return str == "cloudkill_obj";

  if(!present("cloudkill", environment(en)))
	return str == "cloudkill_obj";
  else
	return str == "no_combat" || str == "no_msg_hit" ||
	  str == "no_weapon_attack" || str == "cloudkill_obj";
}

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_do_damage(i){ do_damage = i; }
query_do_damage(){ return do_damage; }

set_poisoned(i){ poisoned = i; }
query_poisoned(){ return poisoned; }

heart_beat()
{
  object env;
  int i;

  if(!en || !living(en))
	return destruct(this_object());

  if(!(env = environment(en)))
	return destruct(this_object());

  if(!present("cloudkill", env))
	return destruct(this_object());

  /* no damage or messages in the first round */
  if(!poisoned)
	return;

  if(en->is_player() && (owner && owner->query_attack() != en))
  {
	i = random(sizeof(player_msgs)-1);
	tell_room(env, EN + player_msgs[i]);
  }
  else
  {
	tell_room(env, EN + msgs[msg_num]);
  }

  msg_num++;
  if(msg_num >= sizeof(msgs))
	msg_num = 0;

}

