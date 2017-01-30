
#include "/obj/clean.c"

short()
{
      return "A yummy cookie";
}

query_value()
{
        return 0;
}

  query_weight() {   return 0; }
long()
{
     write("The cookie looks so good that seems to be calling for you to eat it.\n");
}

init() {
     add_action("eat", "eat");
}

id(str) {
    return str == "cookie" || str == "yummy cookie";
}

eat(str) {
    if (str && !id(str))
        return 0;
    if (!call_other(this_player(), "eat_food", 2))
        return 1;
 call_other(this_player(), "heal_self", random(7));
write("You eat the cookie and feel better.\n");
say(call_other(this_player(), "query_name") +
    " eats a cookie.\n");
  destruct(this_object());
    return 1;
}

get() {
      write("You nearly burn your hand picking up the hot cookie.\n");
    return 1;
}
