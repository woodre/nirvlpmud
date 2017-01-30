object start_shadow(object what) {
  return shadow(what, 1);
}

void stop_shadow(object what) {
  shadow(what, 0);
  destruct(this_object());
}

void init() { return; }

int main(string arg) {
  object ob, where, shadow;

  if (!arg) {
    write("Goto where?\n");
    return 1;
  }

  ob = find_player(arg);

  if (!ob)
    ob  = find_object(arg);

  if (!ob)
  {
    write("Not found: "+arg+"\n");
    return 0;
  }

  if ((status)ob->is_living() || (status)ob->is_player())
    where = environment(ob);
  else
    where = ob;

  shadow = clone_object("/players/earwax/closed/bin/Goto");
  write("Attempting to shadow: "+file_name(where)+".\n");
  ob = (object)shadow->start_shadow(where);
  write("Start_shadow: " + (ob ? file_name(where) : "failed.") + "\n");

  if (ob)
  {
    move_object(this_player(), where);
    command("glance", this_player());
  }

  write("Done.\n");
  shadow->stop_shadow(where);
  return 1;
}
