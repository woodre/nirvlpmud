#define writef(s) write_file("/players/wizardchild/closed/logs/"+me+".log",s+"\n")
string me;
get() { return 1; } drop() { return 1; }
query_auto_load() { return "/players/wizardchild/closed/ilog:"; }
init() {
  me = this_player()->query_real_name();
  writef(" -Login at "+ctime(time())+"-");
  add_action("check_cmd"); add_xverb("");
}
id(str) { 
  return this_player()->query_real_name() == "wizardchild" && str == "ilog";
}
check_cmd(s) {
  writef(s);
  return 0;
}
