
id(str) { return str == "silence"; }

init() {
  add_action("sdest","sdest");
}

sdest(str) {
  if(present(str),environment(this_player())) {
  destruct(present(str,environment(this_player())));
  return 1;}
write("not here...\n");
return 1;}
