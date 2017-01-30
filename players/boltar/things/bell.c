#include "/obj/clean.c"


short()
{
     return "A small gold colored bell";
}

query_value()
{
        return 3;
}

  query_weight() {   return 0; }
long()
{
   write("Every time a bell rings.....an angle gets his wings.\n");
}

init() {
     add_action("ring","ring");
}

id(str) {
    return str == "bell" || str == "small bell";
}

ring(str) {
    if (str && !id(str))
        return 0;
write("You ring the bell.\n");
say(call_other(this_player(), "query_name") +
     "rings a bell.\n");
    return 1;
}

get() {
     write("The bell seems very light.\n");
    return 1;
}
