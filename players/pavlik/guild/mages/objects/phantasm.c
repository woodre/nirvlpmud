#include "/players/pavlik/guild/mages/defs.h"

#define TARGET capitalize(target->query_name())
#define MAX_REPS	12

object target;
object owner;
int acid_count;
int damage;

reset(arg){
  if(arg) return;
  target = 0;
  owner = 0;
  acid_count = 0;
  damage = 0;
  set_heart_beat(1);
}

short(){ return; }
long(){ write("a mages phantasmagoria.\n"); return; }
id(str){ return str == "phantasm" || str == "phantasmagoria"; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_target(ob){ target = ob; }
query_target(){ return target; }

set_damage(i){ damage = i; }
query_damage(){ return damage; }


heart_beat()
{
  if(!environment() || !target || environment() != target)
	return destruct(this_object());

  if(!environment(target))
	return destruct(this_object());

  acid_count++;

  if(!owner || owner->query_attack() != target)
	acid_count = MAX_REPS;

  if(damage <= 1)
	acid_count = MAX_REPS;

  if(acid_count >= MAX_REPS)
  {
	tell_room(environment(target),
	  "The last of the "+HIK+"Phantasms"+NORM+" haunt "+TARGET+".\n");
	destruct(this_object());
	return 1;
  }
  else
  {
    string msg;
    string omsg;
    switch(random(6))
    {
      case 0:
      msg = "\
You are swept up into a "+HIB+"whirling vortex"+NORM+" of ghoulish figures and\n\
"+HIK+"ghostly visages"+NORM+". You are scared out of your "+HIM+"mind"+NORM+"!\n";
      omsg = "\
Your victim is sucked up into a "+HIB+"whirling vortex"+NORM+" of "+HIK+"ghoulish visages"+NORM+"\n\
and appears frightened beyond imagination...\n";
      break;
      case 1:
      msg = "\
The world around you shifts and you find yourself falling into a pit\n\
of "+HIR+"molten lava"+NORM+"! You cannot help but be frightened beyond belief!\n";
      omsg = "\
"+TARGET+" hallucinates that they are falling into a large pit\n\
of "+HIR+"lava"+NORM+"! You laugh in spite of their ill fortune!\n";
      break;
      case 2:
      msg = "\
You are "+BLU+"frozen in fear"+NORM+" as your worst fear flashes before your eyes!\n";
      omsg = "\
"+TARGET+" is "+BLU+"frozen in fear"+NORM+" by an image of their worst fear now\n\
come true! You laugh maniacally.\n";
      break;
      case 3:
      msg = "\
Thoughts of "+HIK+"death"+NORM+" creep into your mind, and you see an image of your\n\
self dead infront of you. You scream in "+HIK+"Terror"+NORM+"!\n";
      omsg = "\
Your victim "+HIK+"SCREAMS IN TERROR"+NORM+" as they mumble something about themself\n\
being "+HIK+"dead"+NORM+". You can't help but smile.\n";
      break;
      case 4:
      msg = "\
You are terrified as a "+HIW+"ghostly arm"+NORM+" pops out of your chest and grabs\n\
your face. Your screams are muffled by the "+HIW+"ghostly hand"+NORM+" on your mouth.\n";
      omsg = "\
A "+HIW+"ghostly arm"+NORM+" pops out of "+TARGET+"'s chest and clamps onto\n"+
TARGET+"'s face. Their screams are muffled by your illusion...\n";
      break;
      case 5:
      msg = "\
A ghoulish figure appears riding on a "+HIK+"black"+NORM+" horse. His head is that\n\
of a skull, and stares at you with "+RED+"red eyes"+NORM+" sunken deep inside.\n\
He charges and you are caught in terror as his image passes right\n\
through you.\n";
      omsg = "\
"+TARGET+" is confronted by a ghoulish "+HIW+"skeleton"+NORM+" on a "+HIK+"black horse"+NORM+".\n\
They are caught in fear as the rider charges them and disappears...\n";
      break;
    }

	tell_object(target, msg);
	tell_object(owner, omsg);
	
	target->do_damage(({damage}), ({"other|evil"}));
	damage = damage * 3 / 4;
  }
  return 1;
}

