#define tp   this_player()

  string c1, c2, c3, c4, c5;
  string cmds;
  int n, v;
  
short() { return "A Speedster"; }
long() { 
  write("This is a speedster.  Usage: speed <cmd1,cmd2,etc.>\n");
  write("Or another way of usage: coast <cmd1,cmd2,etc>.\n");
  write("Maximum of 5 different commands.  Type <speed_list> for\n"+
        "allowable commands.\n"+
        "<To get rid of this type trash_speed>\n\n"+
        "                                               - Mythos\n");
  }
id(str) { return str == "speedster" || str == "speed"; }
get() { return 0; }
drop() { return 1; }
init() { 
  if(tp->query_guild_name() == "shardak" || tp->query_guild_name() == "rangers") {
  tp->add_money(1000);
  tell_object(tp,"I'm sorry but your guild is unable to use this.\n"+
                 "You have been compensated with 1000 coins.\n");
  destruct(this_object());
  tp->save_me();
  return 1;}
  add_action("do_cmds","speed"); 
  add_action("do_cmds","coast");
  add_action("speed_list","speed_list");
  add_action("trash_speed","trash_speed");}

do_cmds(string str) {
  c1 = c2 = c3 = c4 = c5 = "";
  if(!str) {write("Usage: speed <cmd1,cmd2,etc.>\n"); return 1;}
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
       write("The action "+cmds[v]+" may not be done. Speed commands aborted.\n");
       return 1;}
    command(cmds[v],tp);
    }
    write("Speed done.\n");
  return 1;
}

speed_list() {
  write("Commands Available:\n"+
        "n  e  s  w  u  d  ne  nw  se  sw\n");
return 1;}

trash_speed() { write("You have trashed the speedster.\n");
    destruct(this_object());
    return 1;}
