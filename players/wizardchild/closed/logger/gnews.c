short() { return "A Logger's guild newspaper"; }
id(str) { 
  return str == "paper" || str == "newspaper" || str == "guild newspaper"; 
}
long()  {
  if(!present("logger pack", this_player())) return 0;
  cat("/players/wizardchild/closed/logger/WELCOME");
  return 1;
}
get() { return 1; }
init() {
  if(present("logger pack", this_player()))
  add_action("read", "read");
}
read(str) {
  return (id(str) ? long() : 0);
}
