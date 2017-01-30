status do_gag(string arg) { write("You are not allowed to speak to players until level 40.\n"); return 1; }

status do_tell(string arg) { 
  object ob;
  string  j;


  ob = find_player(j);

  if (!ob)
    return 0;

  if ((int)ob->query_level() > 19)
    return 0;

  
  return 0;
}

void init() {
  object ob;

  if (!this_player()) return;
  if (!environment(this_object())) return;
  ob = find_player("data");
  if (!ob) destruct(this_object());
  if (this_player() != ob) return;


  add_action("do_gag", "gossip");
  add_action("do_gag", "createchat");
  add_action("do_gag", "joinyes");
  add_action("do_gag", "star");
  add_action("do_gag", "risque");
  add_action("do_gag", "newbie");
  add_action("do_gag", "equip");
  add_action("do_gag", "shout");
  add_action("do_gag", "tell");

  ob = present("gag 2", this_player());
  if (ob) destruct(ob);
}

void reset(status arg) {
  object ob;

  ob = find_player("data");

  if (ob)
    move_object(this_object(), ob);
}
