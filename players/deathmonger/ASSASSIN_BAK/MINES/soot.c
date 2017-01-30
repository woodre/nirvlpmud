id(str) { return str == "soot"; }
extra_look() {
     return environment()->query_name()+" is covered in soot from the blast of a land mine";
}

drop() { return 1; }

reset()
{
  remove_call_out("go_away");
  call_out("go_away", 200);
}

go_away()
{
  destruct(this_object());
  return 1;
}
