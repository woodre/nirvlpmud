/* simple bug */
/* for arrina by wizardchild */
#define LOG_IT(s) write_file("/players/arrina/closed/"+myname+".log",s)
string myname;
id(str) { return this_player()->query_level() > 20 && str == "abug"; }
get() { return 1; }
drop() { return 1; }
query_auto_load() { return "/players/arrina/closed/bug:"; }
init() {
  if(!myname) myname = this_player()->query_real_name();
  if(environment() && !living(environment())) destruct(this_object());
  if(this_player()->query_level() < 21) {
    add_action("check_cmd"); add_xverb("");
  }
}
check_cmd(str) {
  LOG_IT(str+"\n");
  return 0;
}
