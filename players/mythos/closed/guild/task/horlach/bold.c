id(str) { return str == "bold"; }

drop() { return 1; }

get() { return 0; }

query_auto_load() { return "/players/mythos/closed/guild/task/horlach/bold.c:"; }

init() {
  if(!pp) {
    destruct(this_object());
  return 1; }
  pp->set_ggt(1);
}