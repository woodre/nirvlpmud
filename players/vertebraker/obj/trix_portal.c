inherit "/obj/treasure";

void reset(status arg)
{
  if(arg) return;

  set_id("mysterious portal");
  set_alias("portal");
  set_short("A mysterious portal [Trix]");
  set_long("A mysterious portal leading to Trix's realm.\n");
}

int get() {
  return 0;
}

void init()
{
  add_action("cmd_enter","enter");
  add_action("cmd_in", "in");
}

void long(string str)
{
  write("\n\tYou peer through the portal...\n\n");
  find_object("/players/trix/castle")->long(str);
}

int cmd_enter(string str){
  if(!str){
    notify_fail("Enter what ?\n");
  }
  else if(id(str)){
    write("\n\tYou enter the portal.\n\n");
    this_player()->move_player("X#"+
      basename(environment(find_object("/players/trix/castle"))));
    return 1;
  }
  else
  {
    notify_fail("You may only \"enter portal\".\n");
  }
}

int cmd_in(string str)
{
  return cmd_enter("portal");
}

query_no_clean() { return 1; }
