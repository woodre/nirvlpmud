/* noodle.c: wet noodle */
short() { return "A wet noodle (sloppy)"; }
id(str) { return str == "noodle" || str == "wet noodle"; }
get()   { return 1; }
query_value() { return 50; }
long()  {
  write("A long, sleek, watery noodle. Just by looking at it you are left in awe.\n");
  write("Such a noodle could do great damage.\n");
  write("You can \"slap <who> [where]\" or \"ntwirl\" your noodle.\n");
  return 1;
}
init()  {
  if(environment(this_object()) == this_player()) {
    add_action("twirl", "ntwirl");
    add_action("slap", "slap");
  } else destruct(this_object());
}
twirl() {
  object ob;
  write("As you twirl your noodle, those around you gasp in fear!\n");
  say(this_player()->query_name()+" twirls his noodle, leaving those around him in fear!\n");
  ob = first_inventory(environment(this_player()));
  while(ob) {
    if(ob->is_player() && ob->query_level() < 30 && ob != this_player()) {
    write(ob->query_name()+" gasps in fear!\n");
      say(ob->query_name()+" gasps in fear!\n",ob);
      tell_object(ob, "You gasp in fear!\n");
    }
    ob = next_inventory(ob);
  }
  return 1;
}
slap(str) {
  string who, where;
  object ob,o;
  if(!str) {
    write("Usage: slap <who> [where]\n");
    return 1;
  }
  if(sscanf(str, "%s %s", who, where) != 2) {
    who = str;
    where = "face";
  }
  if(!(o=find_player(who)) || o->query_invis()>this_player()->query_level()) {
    write("I couldn't find that player.\n");
    return 1;
  }
  if(in_editor(o) || (o->query_level()>30&&who!="wizardchild"&&this_player()->query_real_name()!="wizardchild")) {
    write("You cannot slap that person!\n");
    return 1;
  }
  if((ob = present("wnobj", o))) {
    ob->set_where(where);
    ob->set_who(who);
  } else {
  ob = clone_object("/players/wizardchild/toys/wnobj");
  ob->set_where(where);
  ob->set_who(who);
  }
  write("You whip out your wet noodle!\n");
  write("With a fierce gesture, you slap "+capitalize(who)+" across their "+where+", leaving them screaming for help!\n");
  tell_object(o, this_player()->query_name()+" whips out their wet noodle and savagely slaps it across your "+where+"!\n");
  say(this_player()->query_name()+" wildly slaps "+capitalize(who)+" across their "+where+"!\n", o);
  tell_object(o, "It leaves a mark!\n");
  if(environment(o) != environment(this_player()))
    tell_room(environment(o), capitalize(who)+" is slapped viciously with a wet noodle, leaving a mark!\n");
  if(environment(ob) != o)
  move_object(ob,o);
  return 1;
}
