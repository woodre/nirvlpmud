#define ETO environment(this_object())
int ac_times;


id(str) { return str == "enrage_check"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  ac_times = 0;
call_out("enrage_return",150);
}

add_ac_times(arg) { ac_times = ac_times + arg; }
query_ac_times() { return ac_times; }

enrage_return() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You may enrage again.\n");
    destruct(this_object());
    return 1; }
  }
}
