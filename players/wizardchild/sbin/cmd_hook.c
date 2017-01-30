short() { return "A large hook"; }
long()  { write("Just try a few commands...\n"); return 1; }
id(str) { return str=="hook" || str == "cmd_hook"; }
get()   { return 1; }
init()  {
  add_action("cmd_hook"); add_xverb("");
}
cmd_hook(str) {
  string command, arg;
  string cmd_ob_file;
  if(!str || str == "")
    return 0;
  if(sscanf(str, "%s %s", command, arg) != 2)
    command = str;
  cmd_ob_file = "/players/wizardchild/sbin/_" + command;
  if (file_size(cmd_ob_file + ".c") > 0)
    return (int)call_other(cmd_ob_file, "cmd_" + command, arg);
  else
    return 0;
}
