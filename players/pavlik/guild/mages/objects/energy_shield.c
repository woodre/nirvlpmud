#include "/players/pavlik/guild/mages/defs.h"
#define NAME capitalize((string)environment()->query_name())

int hits;		/* how many times the shield has been hit */
int max_hits;		/* max amount of hits the shield can take */
int shield_amount;	/* resistance amount */
string color;

void reset(int x)		{ if(x) return; }
int get()			{ return 0; }
int drop()			{ return 1; }
int id(string str)		{ return (str=="energy_shield_obj"); }
void set_max_hits(int i)	{ max_hits = i; }
int query_max_hits()		{ return max_hits; }
void set_hits(int i)		{ hits = i; }
int query_hits()		{ return hits; }
void set_shield_amount(int i)	{ shield_amount = i; }
int query_shield_amount()	{ return shield_amount; }

void start()
{
  if(!max_hits) max_hits = 10;
  if(!shield_amount) shield_amount = 5;
  environment()->RegisterArmor(this_object(), ({"physical",0,shield_amount,"do_special"}));
  this_object()->pick_color();
  call_out("tell_em", 40 + random(40));
}

void long()
{
  if(tp->query_level() < WIZLEVEL) return;
  write(color+"Mage Energy Shield\n"+NORM);
  write(CYN+"--------------------------\n"+NORM);
  write("Max Hits Allowed : " + max_hits + "\n");
  write("      Hits Taken : " + hits + "\n");
  write("    Protection % : " + shield_amount + "\n");
  write(CYN+"--------------------------\n"+NORM);
  return;
}

void pick_color()
{
  switch(random(6))
  {
    case 0: color=HIB; break;
    case 1: color=HIC; break;
    case 2: color=HIR; break;
    case 3: color=HIG; break;
    case 4: color=HIM; break;
    case 5: color=HIY; break;
  }
}

void tell_em()
{
  object room;
  tell_object(environment(), "Your "+color+"Energy Shield"+NORM+" shifts spectrum.\n");
  pick_color();
}
  

int do_special(object owner)
{
  object room;
  if(!environment()) return 0;
  room = environment(environment());

  tell_object(environment(), "The "+color+"Energy Shield"+NORM+" flashes!\n");
  if(room)
  {
	tell_room(room,
	  "The "+color+"Energy Shield"+NORM+" surrounding "+NAME+" flashes!\n",
	  ({environment()}));
  }
  if(hits++ > max_hits)
  {
	tell_object(environment(),
	  SPELL_PROMPT+CYN+" Your "+NORM+color+"Energy Shield"+NORM+CYN+" fizzles and "+NORM+HIY+"blinks out!\n"+NORM);
	if(room)
		tell_room(room,
		  "The "+color+"Energy Shield"+NORM+" surrounding "+NAME+" fizzles and blinks out.\n",
		  ({environment()}));
	destruct(this_object());
  }
}

void extra_look()
{
  if(!environment()) return;
  else if(environment()==this_player())
  {
	write("You are protected by an "+color+"Energy Shield"+NORM);
	if(tp->query_level() > WIZLEVEL)
		write(" (Hits: "+hits+"/"+max_hits+"  Prot%: "+shield_amount+")");
	else
		write(".\n");
  }
  else
	write(NAME+" is protected by an "+color+"Energy Shield"+NORM+".\n");
}

void remove_object()
{
  if(environment())
  {
	object room;
	tell_object(environment(), SPELL_PROMPT+color+" Your Energy Shield disappears.\n"+NORM);
	if(room=environment(environment()))
	{
		tell_room(room,
		 color+"The Energy Shield surrounding "+NAME+" disappears.\n"+NORM,
		 ({environment()}));
	}
	if(present("mageobj", environment()))
		present("mageobj", environment())->remove_spell_object("eshield");
  }
}

