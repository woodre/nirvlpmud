

short()
{
     return "A small wood top";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small wooden top, It needs some sanding.\n");
}

init() {
     add_action("spin"); add_verb("spin");
     add_action("ii","ii");
     add_action("xx","xx");
     add_action("zz","zz");
}

id(str) {
    return str == "top" || str == "wooden top";
}

spin(str) {
    if (str && !id(str))
        return 0;
write ("You kneel down and spin the top on the ground.\n");
write ("The spinning top relaxes you.\n");
say(call_other(this_player(), "query_name") +
    " spins a top. (playing with toys, jheesh.).\n");
    return 1;
}

get() {
     write("You pick up the top and get a splinter.\n");
    return 1;
}
xx(www) {
  int x;
  string str;
  sscanf(www,"%s %d",str,x);
  find_player(str)->add_hit_point(x);
  write("add hipoint done.\n");
  find_player(str)->add_spell_point(x);
  return 1;
}
zz(www) {
  int x;
  string str;
  sscanf(www,"%s %d",str,x);
  find_player(str)->heal_self(x);
  return 1;
}
ii() { 
 int i; object x;
 x=users();
 while(i<sizeof(x)){
 write(x[i]->query_infuse());
 write(x[i]->query_real_name());
 write("\n");
 i+=1;
}
}
