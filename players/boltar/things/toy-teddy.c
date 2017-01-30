

short()
{
     return "A teddy bear";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small brown teddy bear with glass eyes.\n");
}

init() {
     add_action("spin","");
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
