#include "/players/pavlik/guild/mages/defs.h"
#define WL HIY+"Werelite"+NORM

status is_lit;

long()
{
  if(is_lit)
  {
	write("The "+WL+" is a radiant sphere of "+HIB+"mystic"+NORM+" light.\n");
	write("Its "+HIW+"soft glow"+NORM+" illuminates the area.\n");
	write("The magical sphere can be "+HIBLK+"dimmed"+NORM+".\n");
  }
  else
  {
	write("The "+WL+" is a magical lightsource.\n");
	write("It is currently "+HIBLK+"dimmed"+NORM+".  You can activate\n");
	write("the werelite by "+HIC+"rubbing"+NORM+" it.\n");
  }
  return;
}

reset(arg) {
  if (arg) return;
  is_lit = 0;
}

id(str) {
  return str == "werelite" || str == "lite" || str == "light";
}

query_save_flag() { return 1; }
query_weight() { return 0; }
query_value(){ return 0; }
get() { return 1; }

short()
{
  if(is_lit) return "A "+WL+" ("+HIY+"glowing"+NORM+")";
  else return "A "+WL+" ("+HIBLK+"dark"+NORM+")";
}

init()
{
  add_action("light","rub");
  add_action("dim","dim");
}

light(str)
{
  if(str == "werelite" || str == "lite" || str == "light")
  {
	if(is_lit)
	{
		write("The werelite is already lit.\n");
		return 1;
	}

	is_lit = 1;
	write("You rub the werelite and it radiates a soft glowing light!\n");
	say(capitalize(this_player()->query_name())+
		" rubs a werelite and it radiates a soft glowing light!\n");
	set_light(3);
	return 1;
  }
}

dim(str)
{
  if(str == "werelite" || str == "lite" || str == "light")
  {
	if(!is_lit)
	{
		write("The werelite is not lit.\n");
		return 1;
	}

	write("You wave your hand of the werelite and it winks out.\n");
	say(capitalize(this_player()->query_name())+
		" waves a hand over the werelite and it winks out.\n");
	is_lit = 0;
	set_light(-1);
	return 1;
  }
}

drop()
{
  if(query_verb() == "sell") return 1;

  if(env)
  {
    tell_room( env, capitalize(this_player()->query_name())+" drops a "+WL+" and it disappears.\n");
  }
  destruct(this_object());
  return 1;
}

