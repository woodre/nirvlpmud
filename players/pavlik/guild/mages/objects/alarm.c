#include "/players/pavlik/guild/mages/defs.h"

string owner;

reset(arg){
  if(arg) return;
  owner = "Noone";
}

id(str) {
  return str == "alarm_obj" || str == "runes" || str == "glyph" ||
  str == owner+"'s alarm" || str == "markings"; 
}

short(){
  if(present("mageobj", tp))
	return CYN+capitalize(owner)+"'s Alarm glyph"+NORM;
  else
	return "A "+MAG+"magic glyph"+NORM+" inscribed in the ground";
}

long(){
  if(present("mageobj", this_player())) 
	write(CYN+capitalize(owner)+"'s Alarm glyph.\n"+NORM);
  write(
   "A "+HIY+"magic"+NORM+" glyph has been inscribed on the ground here.\n" +
   "The intricate pattern "+MAG+"swirls"+NORM+" and "+YEL+"twists"+NORM+" endlessly.\n");
  return;
}

drop(){ return 1; }
get(){ return; }

set_owner(str){ owner = str; }
query_owner(){ return owner; }

init()
{
  if(!find_player(owner))
  {
	destruct(this_object());
	return 1;
  }
  if(this_player()->query_name())
  {
	if(this_player()->query_real_name() != owner)
		tell_object(find_player(owner),
			HIC+"<Alarm>"+NORM+": "+capitalize(this_player()->query_name())+
			" has entered the room.\n");
  }
}

