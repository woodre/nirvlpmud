id(str) { return str == "tester"; }

short() { return "A tester"; }

long() { write("A tester.\n"); return 1; }

query_weight() { return 0; }

init() {
  add_action("find_creator", "findc");
}

find_creator(str) {
  object who, what;
  string per, item, create;

  if(!str) { return; }
  if(!sscanf(str,"%s %s", per, item) == 2) return;

  who = find_player(per);
  if(!who) { who = find_living(per); }
  if(!who) { return; }
  what = present(item, who);
  if(!what) return;

  if(creator(what)) {
    create = creator(what);
  }

  write("The Creator of " + capitalize(per) + "'s " + " " + item +
        " is " + capitalize(create) + ".\n");
  return 1;
}
