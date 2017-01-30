#include "/players/pavlik/guild/mages/defs.h"

#define EN capitalize(environment()->query_name())

int ac_amount;
int expire;

reset(arg){
  if(arg) return;
  ac_amount = 0;
  expire = 0;
}

short(){ return; }
long(){ write("stone_skin.\n"); }
id(str){ return str == "stone_skin"; }
get(){ return 0; }
drop(){ return 1; }

set_ac_amount(i){ ac_amount = i; }
query_ac_amount(){ return ac_amount; }

set_expire(i){ expire = i; }
query_expire(){ return expire; }


do_spell()
{
  en->RegisterArmor(this_object(), ({"physical", ac_amount, 0, 0}));
  call_out("remove_skin", expire);
  return 1;
}


remove_skin()
{
  if(en)
  {
	en->RemoveArmor(this_object());

	if(present("mageobj", en))
		present("mageobj", en)->remove_spell_object("stoneskin");

	tell_object(en,
	  SPELL_PROMPT+" Your "+HIW+"Stone "+NORM+CYN+"Skin"+NORM+" spell wears off.\n" +
	  "You feel your flesh "+HIY+"soften"+NORM+" and "+HIW+"return to normal"+NORM+" as the spell fades.\n");
	tell_room(environment(en),
	  EN+"'s "+HIW+"Stone "+NORM+CYN+"Skin "+NORM+" spell wears off.\n",
	 ({en}));
  }
  destruct(this_object());
  return 1;
}


remove_object()
{
  if(en)
	en->RemoveArmor(this_object());
}


extra_look()
{
  if(en == tp)
	return "You are protected by "+HIW+"Stone "+NORM+CYN+"Skin"+NORM;
  else
	return EN+" is protected by a "+HIW+"Stone "+NORM+CYN+"Skin"+NORM;
}


