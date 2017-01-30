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

/*
/*
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
*/

/*
  if ((status)ob->is_living() || (status)ob->is_player())
    where = environment(ob);
  else
    where = ob;
*/

  ob = environment(this_player());
  where = ob;

  shadow = clone_object("/players/earwax/closed/bin/getout");
  write("Attempting to shadow: "+file_name(where)+".\n");
  ob = (object)shadow->start_shadow(where);
  write("Start_shadow: " + (ob ? file_name(where) : "failed.") + "\n");
  write("attempting destruct on you:\n");
/*
  efun::destruct(this_player());
*/

  if (ob)
  {
    move_object(this_player(), "/players/earwax/workroom");
    command("glance", this_player());
  }

  write("Done.\n");
/*
*/
  shadow->stop_shadow(where);
  return 1;
}

/*
void exit() { move_object(this_player(), "/room/void"); }
*/
void exit() { write("Exit shadow triggered.\n"); }
