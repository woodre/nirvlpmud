#include "/players/pavlik/guild/mages/defs.h"
inherit "obj/weapon";

#define ED HIBLK+"Ethereal "+NORM+MAG+"Dagger"+NORM

int dmg;
int ttl;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_short(ED);
  set_long(
    "An "+ED+".\n"
  );
  set_name(ED);
  set_alias("ethereal dagger");
  set_type("dagger");
  set_class(8);
  set_weight(0);
  set_value(0);
  set_save_flag(1);
  message_hit = ({
    HIW+"impaled"+NORM, " on the "+ED,
    HIW+"carved"+NORM+" large chunks of flesh from", "",
    HIW+"sliced"+NORM+" the flesh from", "",
    HIW+"stabbed"+NORM+" the "+ED+" deep into", "",
    HIW+"pierced"+NORM+" the body of", " with the "+ED,
    HIW+"poked"+NORM, " with a quick jab of the "+MAG+"ethereal"+NORM+" blade",
    HIW+"nicked"+NORM, " with a quick swing of the "+MAG+"ethereal"+NORM+" blade",
  });
  dmg = 0;
}

init(){
  ::init();
  add_action("drop_object", "drop");
}

get(){ return 0; }
drop(){ return 1; }

set_dmg(i)
{
  if(i > 0)
  {
	dmg = i;
	set_params("other|mental", i, 0);
  }
}
query_dmg(){ return dmg; }

set_ttl(i)
{
  ttl = i;
  call_out("end_spell", i);
}

query_ttl(){ return ttl; }

end_spell()
{
  if(!environment())
  {
	destruct(this_object());
	return 1;
  }	

  tell_object(environment(), SPELL_PROMPT+" Your concentration wavers and the "+ED+" disappears.\n");

  if(wielded)
	tell_object(environment(), "\nYou are no longer wielding a weapon!\n\n");

  drop(1);
  destruct(this_object());
  return 1;
}


drop_object(str)
{
  if(id(str) || str == "all")
  {
	write("The "+ED+" disappears before it hits the ground.\n");
	drop(1);
	destruct(this_object());
	return 1;
  }
}

