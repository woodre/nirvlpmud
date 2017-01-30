object x;

id(str) { return (str == "induct_obj"); }

init()
{
  add_action("whk", "whk");
}

load_func(y)
{
  x=y;
  command("whk", environment());
}

whk() {
  x->receive_func(environment());
  destruct(this_object());
  return 1;
}
