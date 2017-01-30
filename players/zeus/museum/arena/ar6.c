inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/museum/arena/file.h"

object ctob;

reset(arg){
 if(arg) return;

  if(!present("Invisible_catch_tell_Object"), this_object())
  {
    ctob = clone_object("/players/zeus/museum/OBJ/ctobj.c");
    ctob->set_location("E ");
    move_object(ctob, this_object());
  }

	short_desc = HIW+"Museum Arena"+NORM;
	long_desc =
"You are in the east side of the arena.  To the east is a clear wall\n"+
"which gives you an excellent view of outer space.  The ceiling and floor\n"+
"are also perfectly clear.  A soft light is coming from the ceiling.\n"+
"To leave type 'exit arena'.\n";
	items=({
		"walls",
"The walls are all perfectly clear, made of a material unknown to you.\n"+
"You are able to see the stars through them",
		"ceiling",
"The celing is perfectly clear, eminating a soft light.  It is made of\n"+
"at material which is unknown to you",
		"floor",
"The floor is perfectly clear, allowing you to see straight through it",
		"stars",
"There are many distant stars visible through the walls, ceiling and\n"+
"floor of the arena.  They are very beautiful",
	});
	set_light(1);
	dest_dir=({
		"/players/zeus/museum/arena/ar3.c", "north",
		"/players/zeus/museum/arena/ar9.c", "south",
		"/players/zeus/museum/arena/ar8.c", "southwest",
		"/players/zeus/museum/arena/ar5.c", "west",
		"/players/zeus/museum/arena/ar2.c", "northwest",
	});
}

void init(){
	::init();
	if(find_call_out("display_health") == -1) 
	  call_out("display_health", 1);
	if((string)TP->query_guild_name() != "polymorph")
		TP->set_fight_area();
	add_action("exit_cmd", "exit");
}

exit(){    if(TP) TP->clear_fight_area();  }
realm(){   return "NT";   }

display_health()
{
  object play, mmob;
  object *inv;
  int php, mmhp;
  int nlength;
  int s, t;
  inv = all_inventory(this_object());
  s = sizeof(inv);
  for (t = 0; t < s; t++)
  {
  	if(inv[t]->query_z_museum_mob())
  	{
  	  mmob = inv[t];
  	  break;
  	}
  }
  for (t = 0; t < s; t++)
  {
  	if(inv[t]->is_player())
  	{
  	  play = inv[t];
  	  break;
  	}
  }
  if(!mmob && !play)
  {
    remove_call_out("display_health");
    return;
  }
  if(play)
    php = (play->query_hp() * 100) / play->query_mhp();   
  if(mmob)
    mmhp = (mmob->query_hp() * 100) / mmob->query_mhp();      
  if(play && mmob)
  {
  	nlength = strlen((string)play->query_real_name()) + 2;
  	tell_room("/players/zeus/museum/stands",
      HIY+"E "+HIW+"]  "+NORM+
      pad(capitalize((string)play->query_real_name()),nlength)+
      pad(php+"%",4)+HIW+"   ["+HIY+"VS"+HIW+"]   "+NORM);
  	nlength = strlen((string)mmob->query_name()) + 2;      
    tell_room("/players/zeus/museum/stands",
      pad(mmob->query_name(),nlength)+
      pad(mmhp+"%",4)+"\n"+NORM);
  }
  else if(play)
  {
  	nlength = strlen((string)play->query_real_name()) + 2;
  	tell_room("/players/zeus/museum/stands",
      HIY+"E "+HIW+"]  "+NORM+
      pad(capitalize((string)play->query_real_name()),nlength)+
      pad(php+"%",4)+"\n"+NORM);
  }           
  else if(mmob)
  {
  	nlength = strlen((string)mmob->query_name()) + 2;
  	tell_room("/players/zeus/museum/stands",
      HIY+"E "+HIW+"]  "+NORM+
      pad(capitalize((string)mmob->query_name()),nlength)+
      pad(mmhp+"%",4)+"\n"+NORM);
  } 
  call_out("display_health", 2);
  return;
}