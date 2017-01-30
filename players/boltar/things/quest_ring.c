

short()
{
     return "A small ring";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small, cheaply made ring.\n");
    write("It has some sort of dial and markings on it.\n");
    write("Some writing in the band reads as follows:\n");
    write("I need to be worn by the one who isn't one or whole.\n");
 }

init() {
     add_action("wear", "wear");
}

id(str) {
    return str == "ring" || str == "ringxxxt" || str == "small ring";
}

wear(str) {
    if (str && !id(str))
        return 0;
  call_other(this_player(), "add_hit_point", -13);
  tell_object(this_player(), "You get a shock from the ring and can't wear it.\n");
    return 1;
}

get() {
    write("The ring is so cheaply made that it nearly breaks when you pick it up.\n");
    return 1;
}
