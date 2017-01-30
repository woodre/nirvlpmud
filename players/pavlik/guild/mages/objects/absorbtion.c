#include "/players/pavlik/guild/mages/defs.h"

string stat;
string attrib;
int amount;
int expire;

reset(arg){
  if(arg || root()) return;
  stat = 0;
  amount = 0;
  expire = 0;
}

short(){ return; }
long(){ write("a mages absorb_obj.\n"); return; }
id(str){ return str == "absorbtion" || str == "absorb_obj"; }
get(){ return 0; }
drop(){ return 1; }

set_stat(str){ stat = str; }
query_stat(){ return stat; }

set_attrib(str){ attrib = str; }
query_attrib(){ return attrib; }

set_amount(i){ amount = i; }
query_amount(){ return amount; }

set_expire(i){ expire = i; }
query_expire(){ return expire; }


do_spell()
{
  string *stats;
  int i;

  if(!en || !present("mageobj", en) || !stat || !amount)
  {
	destruct(this_object());
	return 1;
  }

  if(attrib)
	present("mageobj", en)->add_guild_bonus(attrib, amount);

  if(stat != "ALL")
  {
	present("mageobj", en)->add_guild_bonus(stat, amount);
  }
  else
  {
	stats = SCHOOLS;
	i = sizeof(SCHOOLS);
	while(i--)
	{
		present("mageobj", en)->add_guild_bonus(stats[i], amount);
	}
  }

  call_out("end_spell", expire);
  return 1;
}


end_spell()
{
  string *stats;
  int i;

  if(!en || !present("mageobj", en))
  {
	destruct(this_object());
	return 1;
  }

  if(attrib)
	present("mageobj", en)->add_guild_bonus(attrib, -amount);

  if(stat != "ALL")
  {
	present("mageobj", en)->add_guild_bonus(stat, -amount);
  }
  else
  {
	stats = SCHOOLS;
	i = sizeof(stats);
	while(i--)
	{
		present("mageobj", en)->add_guild_bonus(stats[i], -amount);
	}
  }

  tell_object(en,
    SPELL_PROMPT+" Your "+HIC+"Absorbtion"+NORM+" wears off.\n" +
    SPELL_PROMPT+" You feel the sense of "+HIW+"heightened"+NORM+" awareness "+HIC+"fade"+NORM+" away.\n");

  present("mageobj", en)->remove_spell_object("absorb");
  destruct(this_object());

  return 1;
}

