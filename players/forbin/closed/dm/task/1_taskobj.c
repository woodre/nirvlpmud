#include "../defs.h"
#include "/players/forbin/closed/dm/inherits/color_string.h"

object play, gob;
int gl;
int finished, digging, buried;
object stone;

id(string str) { return (str == "forbin_dm_taskobj" || str == "fdmto39487598302"); }

void reset(int x)
{
  if(x) return;
  finished = 0;
  digging = 0;
  buried = 1;
}

init()
{
	if(this_player())
	{
  	if(play)
  	  return;
    if((gob = present("forbin_dm_object", this_player())))
    {
    	gl = (int)gob->query_guild_level();
    	if(gl < 1)
  	  { 
    		play = this_player();
    		tell_object(play,
  	  	  "\n\tThe ground trembles slightly below your feet...\n"+
  		    "\tSomething calls from within the muddy earth...\n\n");
        add_action("cmd_dig", "dig");
        call_out("called_call", 10+random(20));
      }
    }
  }
}

void called_call()
{
	if(!buried)
	  return;
	if(!play)
	  return;
	if(!random(20))
	  tell_object(play,
	    "Something whispers to you: \"Dig for me.\"\n");
	else if(!random(3))
	  tell_object(play,
  	  "\n\tThe ground trembles slightly below your feet...\n"+
  		"\tSomething calls from within the muddy earth...\n\n");
  else
    tell_object(play,
  	  "\n\tSomething calls from within the muddy earth...\n\n");
  call_out("called_call", 20+random(20));
}

status cmd_dig()
{
	if(!digging && buried)
	{
	  tell_room(environment(this_object()),
	    (string)play->QN+" begins to dig furiously in the mud.\n", ({ play }) );
	  tell_object(play,
	    "You begin to dig furiously in the mud.\n");		
		digging = 1;
  	call_out("called_dig", 3);
	  call_out("called_dig", 7);
	  call_out("called_dug", 10);
	  return 1;
	}
}

void called_dig()
{
	if(play && present(play, environment(this_object())))
	{
	  tell_room(environment(this_object()),
	    (string)play->QN+" digs furiously in the mud.\n", ({ play }) );
	  tell_object(play,
	    "You dig furiously in the mud.\n");
  }
  else 
  {
		buried = 0;
		finished = 1;
		digging = 0;  	
  }	    
}

void called_dug()
{
	if(play && present(play, environment(this_object())))
	{
		tell_room(environment(this_object()),
		  (string)play->QN+" finds a large oval stone.\n", ({ play }) );
		tell_object(play,
		  "About three feet down into the mud and muck of the swamp floor\n"+
		  "you find a large oval stone...\n"+
		  "The voice echoing inside your head ceases...\n"+
		  "The stone, black as the darkest night shimmers with a living\n"+
		  "quality, giving you a sense of uneasiness.\n");
		stone = clone_object(TASKS+"1_blackstone.c");
		stone->set_who(play);
	  move_object(stone, environment(this_object()));
		buried = 0;
		finished = 1;
		digging = 0;
		destruct(this_object());
	}
	else
	{
		buried = 1;
		finished = 0;
		digging = 0;
	}		
}
