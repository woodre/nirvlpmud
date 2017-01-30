/* Emoter.c
   An emoter designed for use with the Cyberninja guild
   By gowron
   Last Modified 31 Mar 1997
*/

id(str) {
  return str == "emoter";
}

short() {
  return "Cyberninja Emoter";
}

long() {
   write("An emoter for cyberninjas. Type 'hemote' for more info.\n");
}

get() { 
  return 1;
}

drop() {
  return 1;
}

init() {
   string *dir,cmd;
   int i;
   add_action("test_cmds", "clist");
   dir = get_dir("/players/gowron/cyber/cmds/*.c");
    while (i < sizeof(dir)) {
       sscanf(dir[i], "%s.c", cmd);
       add_action("cmd_hook", cmd);
       i++;
    }
}
query_weight() {
  return 0;
}



