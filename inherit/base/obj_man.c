string *ob_files;
object *ob_list;

string * query_object_list( ){ return ob_files; }

void set_object_list(mixed *arg) {
  int i, j;

  ob_files = ({ });
  for (i = 0; i < sizeof(arg); i++) {
    if (stringp(arg[i]))
      ob_files += ({ arg[i] });
    if (intp(arg[i]))
      if (i >= 1)
        for (j = 0; j < arg[i] - 1; j++)
          ob_files += ({ arg[i-1] });
  }
}

void reset_objects() {
  int i;
  object ob;

  if (!ob_files) return;
  if (!ob_list) ob_list = allocate(sizeof(ob_files));
  for (i = 0; i < sizeof(ob_files); i++) {
    if (!ob_list[i]) {
      ob = clone_object(ob_files[i]);
      ob_list[i] = ob;
      move_object(ob_list[i], this_object());
    }
  }
}

