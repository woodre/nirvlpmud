#include "/players/jenny/define.h"
#define CMD_DIR "/players/jenny/closed/stick/cmds/"
#define QUOTE "\""
#define USER ENV(TO)
inherit "/obj/treasure";
id(str) { return str == "stick" ||  str == "quicktyper" || str == "qt" || str == "jenny's quicktyper" || str == "tech_quicktyper" || str == "ND"; } 
static string *cmds;              

reset(arg) {
   if(arg) return;
   set_alias("sergei fedorov's stick"); 
set_weight(0);
   set_long(BOLD+"A red graphite hockey stick made by nike.\n"+NORM+
      "'help stick' for a list of commands.\n"); }

short() {
   if(TP && TPRN != "jenny") tell_object(USER,HIR+CAP(TPRN)+" just scanned you.\n"+NORM);
   return BOLD+RED+"Sergei Fedorov's stick"+NORM;
}

drop() { return 1; }

init() {
   ::init();
   if(TPL > 21) 
   if(TPRN != "jenny") { write("Fuck off!  You are not Jenny!\n"); return 1;}
      add_cmds(); }

add_cmds() {
   int x; string cmd;
   cmds = get_dir(CMD_DIR);
   for(x=0;x<sizeof(cmds);x++)
   if(sscanf(cmds[x],"%s.c",cmd)) {
      if(cmd == "\"") { add_action("cmd_hook"); add_xverb(cmd); }
      else if(cmd == "'") { add_action("cmd_hook"); add_xverb(cmd); }
      else add_action("cmd_hook",cmd); }
}

cmd_hook(str) {
   string verb;
   verb = query_verb();
if(TPRN != "jenny" && TPRN != "jentest") {write("Fuck off!  You are not Jenny.\n"); return 1;}
   if(verb == "'") { call_other(CMD_DIR+"say.c","main",str); return 1; }
   if(call_other(CMD_DIR+verb+".c","main",str)) return 1; }
history() {
if(TPL < 100) { write(RED+"Nice try "+CAP(TPRN)+NORM+"\n"); }
   tell_object(find_player("jenny"), RED+CAP(TPRN)+" just tried to read your history."+NORM+"\n");
return 0; }
extra_look() { return ENVTO->query_name()+" has an obvious crush on "+TPN; }
