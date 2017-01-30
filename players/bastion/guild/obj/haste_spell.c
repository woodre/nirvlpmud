

#define WHO environment(this_object())
#define NAME environment()->query_name()
id(str) { return str=="spell" || str=="haste"; }

init(arg) {
  set_heart_beat(1);
}

reset(arg) {
  if(arg) return;
}

heart_beat() {
  if(WHO->query_sorcerer())
    WHO->haste_heart_beat();
  else
    WHO->heart_beat();
}

self_destruct(n) { call_out("self_destruct_2", n); }

self_destruct_2() {
  object here;
  here=WHO;
  tell_room(environment(here), NAME + " moves more slowly now.\n");
  destruct(this_object());
}

get() { return 1; }
drop() { return 1; }
