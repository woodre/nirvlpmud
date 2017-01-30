/*
// cmd_hook.c
//
// This file catches any call to a daemonized command, and calls the
// daemon.
// Added by Shadowhawk in the tradition of TMI.
// eval cost dropped some by Verte,
// added multi-directory support [/bin/ is getting way too big]

Conversion to using get_dir and member array by Illarion
update and reload the object if commands are added or removed

*/

string *bin_wiz;
string *closed_bin;
string *bin_play;
string *bin_soul;

void reset() {
  bin_wiz=get_dir("/bin/wiz/_*.c");
  closed_bin=get_dir("/closed/bin/_*.c");
  bin_play=get_dir("/bin/play/_*.c");
  bin_soul=get_dir("/bin/soul/_*.c");
}

int
cmd_hook(string str) {
  string command, arg, cmd_ob_file;
  int   level;

  if (!str || str == "")
    return 0;
 /* dot dot bug */
  if(strlen(str) >= 2 && (str[0..1] == ".."))
    return 0;
  /* end dot dot bug */
  if (sscanf(str, "%s %s", command, arg) != 2)
    command = str;
    level = (int)this_player()->query_level();
    cmd_ob_file="_"+command+".c";
    if(level >= 21 && member_array(cmd_ob_file,bin_wiz) > -1)
      return (int)call_other("/bin/wiz/_" + command, "cmd_" + command ,arg);
    if(level >= 1000 && member_array(cmd_ob_file,closed_bin) > -1)
      return (int)call_other("/closed/bin/_" + command, "cmd_" + command, arg);
    if(member_array(cmd_ob_file,bin_play) > -1)
      return (int)call_other("/bin/play/_" + command, "cmd_" + command, arg);
    if(member_array(cmd_ob_file,bin_soul) > -1)
      return (int)call_other("/bin/soul/_" + command, "cmd_" + command, arg);
    return 0;
  /*  
    if(level >= 21)
    {
      cmd_ob_file = "/bin/wiz/_" + command;
      if(file_size(cmd_ob_file + ".c") > 0)
        return (int)call_other(cmd_ob_file, "cmd_" + command, arg);
    }
    if(level >= 1000)
    {
      cmd_ob_file = "/closed/bin/_" + command;
      if(file_size(cmd_ob_file + ".c") > 0)
        return (int)call_other(cmd_ob_file, "cmd_" + command, arg);
    }   
  
    cmd_ob_file = "/bin/play/_" + command;
    if (file_size(cmd_ob_file + ".c") > 0)
      return (int)call_other(cmd_ob_file, "cmd_" + command, arg);

    cmd_ob_file = "/bin/soul/_" + command;

    if (file_size(cmd_ob_file + ".c") > 0)
      return (int)call_other(cmd_ob_file, "cmd_" + command, arg);

    else
      return 0;
      */
}
