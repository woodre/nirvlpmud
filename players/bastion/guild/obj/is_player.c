
string name;

is_player(str) {
  name=0;
  str=lower_case(str);
  restore_object("players/" + str);
  if(name)
    return 1;
}
