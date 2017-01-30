short() { return "The object of mass spamming"; }
string filename;
id(str) { return str == "spam" || str == "object"; }
get() { return 1; }
drop() { return 1; }
init() {
  if(!living(environment())) destruct(this_object());
  call_out("spammage",3);
}
set_filename(str) { filename = str; }
spammage() {
  remove_call_out("spammage");
  if(!filename) {
    call_out("spammage",3);
    return ;
  }
  tell_object(environment(),read_file(filename));
  call_out("spammage",3);
}
