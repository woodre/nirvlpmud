query_ok(ob) {
  if(!ob->is_player()) return 1;
  return (present("logger pack",ob) || !ob->is_player() || ob->query_level() > 20);
}
