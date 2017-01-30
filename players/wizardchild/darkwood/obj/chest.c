/* chest.c: chest of trinkets */
#define ROOT_DIR "players/wizardchild/darkwood/"
short() { return "A small chest"; }
long() {
  object ob;
  write("This appears to be some sort of treasure chest in which the last owner of it\n");
  write("stored his junk. There is probably something of interest to you in it.\n");
  ob = first_inventory(this_object());
  write("    The chest "+(ob?"contains:":"appears to be empty.")+"\n");
  while(ob) {
    if(ob->short())
      write(ob->short()+".\n");
    ob = next_inventory(ob);
  }
  return 1;
}
reset(arg) {
  object ob;
  if(arg)
    return ;
  ob = clone_object("obj/money");
  ob->set_money(600+random(600));
  move_object(ob, this_object());
  move_object(clone_object(ROOT_DIR+"obj/rock"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/torch"), this_object());
  if(random(100) < 35)
    move_object(clone_object(ROOT_DIR+"obj/bones"), this_object());
}
id(str) { return str == "chest" || str == "small chest"; }
get() { return 1; }
static inv_query(flag) {
  object ob;
  int i;
  i = 2;
  ob = first_inventory(this_object());
  while(ob) {
    i += (flag ? ob->query_weight() : ob->query_value());
    ob = next_inventory(ob);
  }
  return i;
}
query_weight() { return inv_query(1); }
query_value()  { return inv_query(0); }
init() {
  add_action("get_item", "get");
  add_action("get_item", "take");
}
get_item(str) {
  string jnk1;
  object ob, nob;
  if(!sscanf(str, "%s from chest", jnk1)) return 0;
  if(jnk1 == "all") {
    ob = first_inventory(this_object());
    while(ob) {
      if(environment(this_object()) != this_player()) {
        if(!this_player()->add_weight(ob->query_weight())) {
          write("You cannot carry any more.\n");
          return 1;
        } 
      }
      if(ob->short()) write(ob->short()+": taken.\n");
      nob = next_inventory(ob);
      if(!ob->get())
        move_object(ob, this_player());
      ob = nob;
    }
    return 1;
  }
  ob = present(jnk1, this_object());
  if(!ob) {
    write("There is no "+jnk1+" inside the chest.\n");
    return 1;
  }
  if(!living(environment(this_object())) && !this_player()->add_weight(ob->query_weight()))
    write("You cannot carry any more.\n");
  else {
    move_object(ob, this_player());
    write("You take "+jnk1+" from the chest.\n");
    say(this_player()->query_name()+" takes something from the chest.\n");
  }
  return 1;
}
