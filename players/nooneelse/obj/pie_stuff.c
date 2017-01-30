/*
 pie_stuff.c - put remains of a pie on someone after they're hit with a pie
               for a while
*/

string pie_type;

reset(arg) {
  if (arg) return;

  call_out("trash_this", 600);
}

extra_look() {
  return capitalize(environment(this_object())->query_name())+
         "'s face is covered with the remains of a sticky "+pie_type+" pie";
}

trash_this() { destruct(this_object()); }

start_pie_stuff(str) {
  pie_type = str;
}

drop() { return 1; }

id(str) { return str=="pie stuff" || str=="pie_stuff"; }
