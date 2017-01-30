inherit "/obj/treasure";
string owner;
reset(arg) {
  if(arg) return;
  owner = this_player()->query_real_name();
  set_short("Grimm's mass coding helper");
  set_long("This is a code helper made by Grimm.  It's function is \n"+
           "pretty much to help him port over his current code to a\n"+
           "new directory structure without having to edit every friggin\n"+
           "file manually.\n\nHelp commands will be detailed later.\n");
  set_id("coder");
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
}

heart_beat() {
  if(!find_living(owner)) {
    quit();
  }
  if(!environment(this_object())->query_interactive()) {
    gone_net_dead_damnit();
  }
}

init() {
  add_action("tree","tree");
}

tree(str) {
  string ln;
  int i;
  i=0;
  while(ln=read_file(str,i++)) {
    write("File: "+str+" found.\n");
    i++;
  }
  return 1;
}
