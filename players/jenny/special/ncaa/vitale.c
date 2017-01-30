inherit "/obj/monster";
#include "/players/jenny/define.h"
#define CMD_DIR "/players/jenny/special/ncaa/commands/"
static string *cmds;  
id(str) { return str == "dick vitale" ||  str == "Dick Vitale" || str == "dick" || str == "vitale"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Dick Vitale");
    set_race("human");
    set_gender("male");
    set_al(700);
    set_level(20);
    set_hp(5000);
    set_wc(12);
    set_ac(200);
    set_short(BOLD+"Dick Vitale"+NORM);
    set_long(
      "Dick Vitale is a short, balding man whose enthusiasm for college\n"+
      "basketball is unmatched.  He works as an analyst for ESPN.  You\n"+
      "could "+RED+"ask "+NORM+"him about the NCAA tournament pool\n");
}
calculate_worth(){ return 0; }
init() {
   ::init();
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
   if(verb == "'") { call_other(CMD_DIR+"say.c","main",str); return 1; }
   if(call_other(CMD_DIR+verb+".c","main",str)) return 1; }
