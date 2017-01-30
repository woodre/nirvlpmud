/*
 doodad.c
*/

inherit "obj/treasure";

string scd_who, directory, str2;

init() {
  add_action("drop_doodad",   "drop");
  add_action("drop_doodad",   "quit");
  add_action("set_directory", "set");
  add_action("ls_directory",  "sls");
  add_action("cd_directory",  "scd");
  add_action("scd_log",       "dlog");
  add_action("pwd",           "pwd");
  add_action("vampire_board", "vboard", 3);
}

set_directory(str) {
  if (!str) {
    write("Use: set <directory>\n");
    return 1;
  }
  if (str=="me") str="nooneelse";
  directory="/players/"+str;
  scd_who=str;
  write("Directory now set to "+directory+"\n");
  return 1;
}

ls_directory(str) {
  if (str)
    str2=directory+"/"+str;
  else
    str2=directory;
  command("ls "+str2, this_player());
  return 1;
}

cd_directory(str) {
  if (str)
    str2=directory+"/"+str;
  else
    str2=directory;
  command("cd "+str2, this_player());
  return 1;
}

scd_log(str) {
  if (!scd_who) return;
  write(capitalize(scd_who)+"'s error logs:\n");
  write("=====> Error log:\n");
  command("cat /log/"+scd_who, this_player());
  write("\n=====> Bug/Idea/Typo log:\n");
  command("cat /log/"+scd_who+".rep", this_player());
  return 1;
}

pwd() {
  write("pwd:  "+directory+"\n");
  return 1;
}

vampire_board() {
  command("goto /players/nooneelse/black/guild_training", this_player());
  command("look at board", this_player());
  return 1;
}

reset(arg) {
     if (arg) return;

     set_short("A doodad");
     set_long(
       "An extremely cheap doodad.\n"+
       "    set     - set it to a default directory (ex: set nooneelse)\n"+
       "    sls     - do an 'ls' at the default directory\n"+
       "    scd     - 'cd' to default directory\n"+
       "    scd obj - 'cd' to obj subdirectory in default directory\n"+
       "    dlog    - see the set player's log files\n"+
       "    pwd     - see current path\n"+
       "    vboard  - go to the vampire's board to read it\n");
     set_value(0);
     set_weight(0);
     directory="/players/nooneelse";
}
drop_doodad(str) {
  if (!str || !id(str)) return;
  write("The doodad flashes, then disappears.\n");
  destruct(this_object());
  return 1;
}

id(str) { return (str=="doodad"); }

