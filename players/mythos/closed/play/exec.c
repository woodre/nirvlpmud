#define tp   this_player()

  string c1, c2, c3, c4, c5;
  string cmds;
  int n, v;
id(str) { return str == "exec"; }
short() { }
long() { 
  write("This is a speedster.  Usage: exe <cmd1,cmd2,etc.>\n");
  write("Maximum of 5 different commands.  Type <speed_list> for\n"+
        "allowable commands.\n"+
        "<To get rid of this type trash_speed>\n\n"+
        "                                               - Mythos\n");
  }

get() { return 0; }
query_prevent_shadow() { return 1; } 
drop() { return 1; }
init() { 
  add_action("do_cmds","exe"); 
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
    for(v=0; v<sizeof(cmds); v++) {
    command(cmds[v],tp);
    }
    write("exec done.\n");
  return 1;
}


trash_speed() { write("You have trashed the speedster.\n");
    destruct(this_object());
    return 1;}
