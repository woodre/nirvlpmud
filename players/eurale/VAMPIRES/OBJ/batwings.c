#define TP   this_player()
#include "/players/eurale/closed/ansi.h"

  string c1, c2, c3, c4, c5;
  string cmds;
  int n, v;
  
short() { return BOLD+"leathery bat wings"+NORM; }
long() { write(
  "These powerful, leathery bat wings can fly you rapidly across\n"+
  "the mud. You just vf (vamp fly) the direction you want to go\n"+
  "seperated by commas. You may only fly 5 rooms max, however.\n"+
  "To get rid of your bat wings, just "+BOLD+"molt_wings"+NORM+
  "\n"+
  "   "+HIR+"Usage: vf dir1,dir2,dir3,dir4,dir5"+NORM+"\n");
}

id(str) { return str == "batwings" || str == "wings"; }
get() { return 0; }
drop() { return 1; }
query_auto_load() {
  return "/players/eurale/VAMPIRES/OBJ/batwings.c:"; }

init() { 
if(environment(this_object())->query_guild_name() != "vampire") {
  destruct(this_object());
  return 1;}

  add_action("do_cmds","vf"); 
  add_action("trash_wings","molt_wings");}

do_cmds(string str) {
  c1 = c2 = c3 = c4 = c5 = "";
  if(!str) {write("Usage: vf <dir1,dir2,etc.>\n"); return 1;}
  if(sscanf(str, "%s,%s,%s,%s,%s", c1, c2, c3, c4, c5) == 5) {
    cmds = ({c1,c2,c3,c4,c5});
    check_speed();
    return 1;}
  if(sscanf(str, "%s,%s,%s,%s", c1, c2, c3, c4) == 4) {
    cmds = ({c1,c2,c3,c4});
    check_speed();
    return 1;}
  if(sscanf(str, "%s,%s,%s", c1, c2, c3) == 3) {
    cmds = ({c1,c2,c3});
    check_speed();
    return 1;}
  if(sscanf(str, "%s,%s", c1, c2) == 2) {
    cmds = ({c1,c2});
    check_speed();
    return 1;}
  if(sscanf(str, "%s", c1) == 1) {
    cmds = ({c1});
    check_speed();
    return 1;}
return 1;}

check_speed() {
if(cmds)
if(sizeof(cmds) > 0)
  for(v=0; v<sizeof(cmds); v++) {
  if((cmds[v]) != "n" && (cmds[v]) != "e" && (cmds[v]) != "s" && (cmds[v]) != "w" &&
       (cmds[v]) != "u" && (cmds[v]) != "d" && (cmds[v]) != "ne" && (cmds[v]) != "nw" &&
       (cmds[v]) != "se" && (cmds[v]) != "sw" && (cmds[v]) != "") {
    write("You spread out your bat wings and glide to a stop...\n");
       return 1;}
    command(cmds[v],TP);
    }
	write("You spread out your "+BOLD+"bat wings"+
              NORM+" and flutter to a stop.\n");
  return 1;
}

trash_wings() {
  write("You begin to molt.... your leather wings fall off...\n"+
        "and as they hit the ground, they turn to powdery dust\n"+
        "and disappear into the earth.\n");
  destruct(this_object());
  return 1;}
