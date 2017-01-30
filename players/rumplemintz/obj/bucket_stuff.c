/*
 bucket_stuff.c - put pain from a bucket on someone after they're hit with
                  a bucket for a while
*/

int duration_timer;
string bucket_color;

reset(arg) {
  if (arg) return;

  enable_commands();
  set_heart_beat(1);
}

extra_look() {
  return capitalize(environment(this_object())->query_name())+
         " is covered with "+bucket_color+" paint";
}

heart_beat() {
  duration_timer++;
  if (duration_timer==900) destruct(this_object());
}

start_bucket_stuff(str) {
  bucket_color = str;
}

drop() { return 1; }

id(str) { return str=="paint" || str=="bucket stuff" || str=="bucket_stuff"; }
