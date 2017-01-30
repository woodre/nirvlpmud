id(str) { return str == "here"; }

drop() { return 1; }

init() {
  if(this_player()) if(this_player()->query_level() < 21) { destruct(this_object()); return 1; }
  add_action("ed_here","edhere");
  add_action("update_here","updatehere");
}

ed_here() {
  string moo;
  string one,two;
  moo = object_name(environment(this_player()));
  if(sscanf(moo,"%s#%s",one,two) == 2) moo = one;
  command("ed /"+moo+".c",this_player());
return 1; }

update_here() {
  string moo;
  string one,two;
  moo = object_name(environment(this_player()));
  if(sscanf(moo,"%s#%s",one,two) == 2) moo = one;
  command("update /"+moo+".c",this_player());
  command("goto /"+moo+".c",this_player());
return 1; }