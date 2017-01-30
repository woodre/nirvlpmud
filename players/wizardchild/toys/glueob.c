drop() { return 1; }
get() { return 1; }
/* glueob.c */
id(str) { return str == "glueob"; }
reset(arg) { if(arg) destruct(this_object()); }
extra_look() {
  return environment(this_object())->query_name()+" has a big gob of glue in their hair!";
}
