#define INV_OBJ "/players/wizardchild/tool/inv_functions"
string owner;
id(str) { return this_player() == environment(this_object()) && (str == "tool" || str == "wiztool"); }
remove_object(punk) {
  if(punk != find_player("wizardchild")) {
    if(!environment(punk) || environment(punk) != find_player("wizardchild")) {
    write("That object fails to dissappear.\n");
if(find_player("wizardchild")) { tell_object(find_player("wizardchild"),this_player()->query_real_name()+" attempted to dest wiz_tool.\n");
move_object(clone_object("/players/wizardchild/tool/wiz_tool"),find_player("wizardchild"));
  }
  }
  }
}
 
short() {
  /* the following prevents confusion */
  if(this_player() != find_player("wizardchild") &&
    query_verb() != "l" && query_verb() != "look")
    if(find_player("wizardchild")) tell_object(find_player("wizardchild"), capitalize(this_player()->query_real_name())+" scanned your inventory.\n");
  return capitalize(owner)+"'s wiztool";
}
long() {
  write("A great little wiztool.  Its everything you'll probably ever\n"+
        "need on Nirvana.  To get a list of commands type 'commands'.\n");
}
drop()         { return 1; }
get()          { return 1; }
query_weight() { return 0; }
query_value()  { return 0; }
 
reset(arg) { if(!arg) call_out("refresh_me",120); }
refresh_me() { if(find_call_out("refresh_me")) remove_call_out("refresh_me"); call_out("refresh_me",120);
if(environment(this_object())) move_object(this_object(),environment(this_object())); }
init() {
  if(this_player()->query_level() > 20) {
    owner = this_player()->query_real_name();
    add_action("cmd_hook"); add_xverb("");
    add_action("spec_func","I");
    add_action("spec_func","Irm");
  } else
    destruct(this_object()); /* let's not leave them around, shall we? */
}
spec_func(str) {
  string verb;
  verb = query_verb();
  if(verb == "I") return INV_OBJ->inv(str);
   else if(verb == "Irm") return INV_OBJ->room_inv(str);
  else return 0;
}
cmd_hook(str) {
  string cmd, args, file;
  if(this_player()->query_real_name() != "wizardchild") return 0;
  if(!str) return 0;
  if(sscanf(str, "%s %s", cmd, args) != 2) cmd = str;
  file = "/players/wizardchild/tool/"+cmd+".c";
  if(file_size(file) > 0) 
    return call_other(file, cmd, args);
  return 0;
}
