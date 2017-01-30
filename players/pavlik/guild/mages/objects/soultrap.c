#include "/players/pavlik/guild/mages/defs.h"

#define SJ		YEL+"Soul "+NORM+CYN+"Jar"+NORM
#define AS		RED+"Angry "+NORM+YEL+"Souls"+NORM
#define MAX_VALUE	50

int soul_value;		/* how many points have been stored */
int soul_count;		/* iteration counter */
int thrown;		/* if the object is "active" or not */
int msg;		/* tracker for room msgs */
string owner;		/* who created the jar */
object target;		/* our "victim" */

reset(arg) {
  if(arg) return;
  soul_value = 0;
  soul_count = 0;
  thrown = 0;
  target = 0;
  msg = random(4);
  owner = "anonymous";
  set_heart_beat(0);
}

short()
{
  string meter;
  int i, x;

  if(thrown) return;

  meter = CYN+"["+NORM+MAG;
  x = soul_value / 10;
  for(i=1; i<=(MAX_VALUE/10); i++)
  {
	if(x)
	{
		meter = meter + "*";
		x--;
	}
	else
		meter = meter + " ";
  }
  meter = meter + CYN+"]"+NORM;

  return "a "+SJ+" "+meter;
}

long()
{
  if(!thrown)
  {
	write(
	  short()+"\n" +
	  "A glass jar with the captured souls of "+capitalize(owner)+"'s defeated foes.\n" +
	  "You realize that this jar could be a valuable weapon if thrown at an opponent.\n");
	if(soul_value >= MAX_VALUE) write("The jar is full.\n");
	else if(soul_value >= (MAX_VALUE * 3)/4) write("The jar is mostly full.\n");
	else if(soul_value >= MAX_VALUE/2) write("The jar is half full.\n");
	else if(soul_value >= MAX_VALUE/4) write("The jar is somewhat full.\n");
	else write("The jar is nearly empty.\n");
  }

  return;
}

drop()
{
  if(thrown) return 1;
  if(query_verb() == "sell") return 1;

  if(tp && env)
  {
	tell_room(env,
	  "The "+SJ+" falls to the ground and "+HIR+"shatters"+NORM+"!\n" +
	  "The freed "+YEL+"souls"+NORM+" depart with haste.\n");
  }
  destruct(this_object());
  return 1;
}

get()
{
  if(thrown) return 0;
  else return 1;
}

add_soul_value(i)
{
  soul_value += i;
  if(soul_value > MAX_VALUE) soul_value = MAX_VALUE;
}

query_soul_value(){ return soul_value; }

set_target(ob){ target = ob; }
query_target(){ return target; }

set_owner(str){ owner = str; }
query_owner(){ return owner; }

id(str)
{
  if(thrown) return str == "thrown_jar" || str == "thrown_soul_jar";
  else return str == "jar" || str == "soul jar" || str == "soul_jar" || str == "mage_soul_jar";
}

init()
{
  add_action("throw_jar", "throw");
}

throw_jar(str)
{
  object obj;
  string tmp, target;

  if( sscanf(str, "%s at %s", tmp, target) == 2 ) {
    obj = present(target, env );
  }

  if( id(str) && en && en->query_attack() ) {
    obj = en->query_attack();
    tmp = str;
  }

  if(str && obj && id(tmp))
  {
    if(!obj) return 0;
    if(!living(obj)) {
	notify_fail("That would be a waste of time.\n");
	return 0;
    }
    if(!obj->is_npc()) {
	notify_fail("You can't throw the "+SJ+" at a player.\n");
	return 0;
    }
    if(soul_value < 10) {
	notify_fail("There are not enough souls in the jar yet.\n");
	return 0;
    }

        write(
	  SPELL_PROMPT+" You hurl the "+SJ+" at "+IT+".\n" +
	  "The glass "+CYN+"jar"+NORM+" hits the ground at "+IT+"'s feet and "+RED+"shatters"+NORM+".\n");
	say(
	  ME+" hurls a "+SJ+" at "+IT+".\n" +
	  "The glass "+CYN+"jar"+NORM+" hits the ground at "+IT+"'s feet and "+RED+"shatters"+NORM+".\n");
	tell_room(env,
	  "The "+RED+"Angry "+NORM+YEL+"Souls"+NORM+" of "+capitalize(owner)+"'s defeated enemies rise from " +
	  "a "+HIBLK+"swirling "+HIW+"mist"+NORM+" and "+MAG+"attack"+NORM+" "+IT+"!\n");

	if(tp->query_attack() != obj)
		tp->attack_object(obj);

	set_target(obj);
	move_object(this_object(), obj);
	set_heart_beat(1);
	thrown = 1;
	return 1;
  }
}


heart_beat()
{
  int dmg;

  if(!target || !environment() || environment() != target || !environment(target))
  {
	destruct(this_object());
	return 1;
  }

  if(!thrown)
  {
	set_heart_beat(0);
	return 1;
  }

  if(soul_count >= 3)
  {
	tell_room(environment(target),
	  "The "+AS+" "+HIW+"DEPART"+NORM+" in search of "+MAG+"final rest"+NORM+".\n");
	destruct(this_object());
	return 1;
  }

  if(msg == 0)
	tell_room(environment(target),
	  "The "+AS+" of "+capitalize(owner)+"'s defeated foes "+HIM+"POUND"+NORM+" "+
	  capitalize(target->query_name())+" with "+HIBLK+"incorporeal"+NORM+" fists.\n");
  else if(msg == 1)
	tell_room(environment(target),
	capitalize(target->query_name())+" is "+HIY+"~terrorized~"+NORM+" by the "+AS+
	" of "+capitalize(owner)+"'s defeated enemies.\n");
  else if(msg == 2)
	tell_room(environment(target),
	"The "+AS+" of "+capitalize(owner)+"'s defeated opponents "+HIR+"STAB"+NORM+
	" "+HIBLK+"invisible weapons"+NORM+" into "+capitalize(target->query_name())+"'s body!\n");
  else if(msg == 3)
	tell_room(environment(target),
	"The "+AS+" of "+capitalize(owner)+"'s defeated foes "+HIY+"FEED"+NORM+
	" on "+capitalize(target->query_name())+"'s life-force.\n");

  msg++;
  if(msg > 3) msg = 0;

  dmg = (soul_value / 3) + random(soul_value);
  target->do_damage( ({dmg}), ({"other|evil"}) );

  soul_count++;
  return 1;

}

query_save_flag() { return 1; }
