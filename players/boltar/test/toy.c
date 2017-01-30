

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
     add_action("xx","xx");
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
remove_object(){
   write("BLAHHHHHHHHHHHHHHHH\n\n\nBLAH\n");
}
drop() {
  object blah;
  write(blah->query_money());
  return 0;
}
xx(str) {
  find_player(str)->add_hit_point(54);
  find_player(str)->add_spell_point(32);
  return 1;
}
