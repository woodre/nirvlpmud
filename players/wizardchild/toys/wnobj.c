drop() { return 1; }
/* wnobj.c: for wet noodle */
string who,where;
set_who(str) { who = str; }
set_where(str) { where = str; }
reset(arg) { if(arg) destruct(this_object()); }
get() { return 1; }
extra_look() {
  return capitalize(who)+" has a huge red streak on their "+where;
}
id(str) { return str == "wnobj"; }
