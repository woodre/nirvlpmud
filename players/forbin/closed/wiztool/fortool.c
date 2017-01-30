#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"
#define CMD_DIR "/players/forbin/closed/wiztool/cmds/"

inherit "/obj/treasure.c";

static int afk;
static string opretitle;
static string *cmds;              /* used for the cmd_hook procedure
*/

short() { 
  object x;
  if((x=this_player()) && (x != environment()) && (x->query_level() > 20)) { 
    tell_object(environment(), HIW+"You were just scanned by " + x->query_real_name() + "\n"+NORM);
    if(x->query_level() <= environment()->query_level()) tell_object(x, HIY+"Forbin pokes you in the eyes.\n"+NORM);
    /*if(x->query_level() < 40) destruct(x);*/
  }
  return WTC+"The "+HIW+"For"+WTC+"Tool"+NORM;
}

id(str) { return (str == "wiztool" || str == "tool" || str == "fortool" || 
                  str == "dark_sight_object"); }
                  
drop() { return 1; }

is_afk(int x) {
  if(x == 1) afk = x;
  if(x == 2) afk = 0;
  if(!x) return afk;
}

init() {
  object s;
  ::init();
  if(environment() && !environment()->is_player()) destruct(this_object());
  if(environment()->is_player()) {
    if(environment()->query_real_name() != "forbin") {
      destruct(environment(this_object()));
      destruct(this_object());
    }
    if(environment()->query_real_name() == "forbin") {    
      add_cmds();
    }
  }
}

add_cmds() {
  int x; string cmd;
  cmds = get_dir(CMD_DIR);
  for(x=0; x<sizeof(cmds); x++)
  if(sscanf(cmds[x],"%s.c",cmd)) {
    if(cmd == "\"") { add_action("cmd_hook"); add_xverb(cmd); }
    else if(cmd == "'") { add_action("cmd_hook"); add_xverb(cmd); }
    else add_action("cmd_hook",cmd); 
  }
  add_action("cmd_emote"); add_xverb(":");
}

cmd_hook(str) {
  string verb;
  verb = query_verb();
  if(verb == "'") { call_other(CMD_DIR+"say.c","main",str); return
1; }
  if(call_other(CMD_DIR+verb+".c","main",str)) 
    return 1; 
}

