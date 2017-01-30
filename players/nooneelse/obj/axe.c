/*
  axe.c - mostly for cutting down trees :)
*/

inherit "obj/weapon";

init() {
  ::init();

  add_action("chop", "chop");
}

chop(str) {
  object tree_obj;
  string str1, str2, str3;
  if (!str || str != "tree") return;
  tree_obj=present("tree", environment(this_player()));
  if (!tree_obj) {
    write("There is no tree here!\n");
    return 1;
  }
  str1=file_name(tree_obj);
  if (sscanf(str1, "%s/merlyn/closed/guild/tree#%s", str2, str3) != 2) {
    write("Sorry, this axe only works on mage's trees.\n");
    return 1;
  }
  destruct(tree_obj);
  write("You take a mighty swing at the tree and it topples.\n");
  say(this_player()->query_name()+
      " takes a mighty swing at the tree and it topples.\n", this_player());
  return 1;
}

reset(arg) {
  ::reset(arg);

  set_name("axe");
  set_class(13);
  set_weight(2);
  set_value(600);
  set_short("A woodsman's axe");
  set_long(
    "It is a strong axe, that looks like it'd work better for chopping trees\n"+
    "than fighting.\n");
}
