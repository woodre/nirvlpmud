#include "/players/pestilence/define.h"
#include "/obj/user/dt_stamp.h"
#define CMD_DIR "/players/katya/cmds/"
#define TPQ this_player()->query_real_name()

inherit "/obj/treasure";
static int afk;
static string opretitle;
static string *cmds;              /* used for the cmd_hook procedure */

short() 
{
  return ""+HIW+"Katya's"+NORM+WHT+" fluffy pillow "+HIM+" (cuddly)"+NORM+""; }



id(str) { return str == "wiztool" || str == "tool" || str == "pillow"; }

drop() { return 1; }

is_afk(int x)
  {
  if(x == 1) afk = x;
  if(x == 2) afk = 0;
  if(!x) return afk;
  }

init() 
  {
  object s;
  ::init();
  add_cmds();

  }


add_cmds() 
  {
   int x; string cmd;
   cmds = get_dir(CMD_DIR);
   for(x=0;x<sizeof(cmds);x++)
   if(sscanf(cmds[x],"%s.c",cmd)) 
     {
     if(cmd == "\"") 
       { 
       add_action("cmd_hook"); add_xverb(cmd); 
       }
     else if(cmd == "'") 
       { 
       add_action("cmd_hook"); add_xverb(cmd); 
       }
     else add_action("cmd_hook",cmd); 
     }
   add_action("cmd_emote"); add_xverb(":");
  }

cmd_hook(str) 
  {
  string verb;
  verb = query_verb();
  /* sloppy communication bug fix */
  if(verb == "'") 
    { 
    call_other(CMD_DIR+"say.c","main",str); 
      return 1; 
    }
  if(call_other(CMD_DIR+verb+".c","main",str)) 
    return 1; 
  }

cmd_emote(str)
  {
  if(!str) return;
  write("You "+str+"\n");
  TP->remote_say(capitalize(TPRN)+" "+str+"\n");
    return 1;
  }
