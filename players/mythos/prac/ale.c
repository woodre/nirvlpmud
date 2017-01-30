#define tp this_player()->query_name()

int full, number, number2;

id(str) {
    if (str == "ale" && full)
        return 1;
    return str == "bottle";
}

short() {
    if (full)
    return "A bottle of strong ale";
    return "An empty bottle";
}

/* The shop only buys empty bottles ! */

query_save_flag()  { return 1; }


query_value()
{
    if (!full) return 5;
 else
    return number*350;
}

long() {
   write("A bottle of strong ale.\n"+
     "You may 'drink' another "+number+" swallows.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 10;
    full = 1;
}



drink(str)
{
if (str == "ale" || str == "from bottle")  {
    if (!full)
{
  write("The bottle is empty.\n");
   return 1;
}
if(number2 < 10)  {
    if (!call_other(this_player(), "drink_alcohol", 15))
  return 0;
  write("You take a drink of ale.\n");
   say(tp+" takes a drink of ale.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 35);
    call_other(this_player(), "recalc_carry");
  return 1;
    }
if(number2 > 8)  {
    full = 0;
  write("You empty the bottle of ale.\n"+
          "That was wonderful ale.\n");
    say(call_other(this_player(), "query_name", 0) +
    " empties a bottle of ale.\n");
    return 1;
}
 }  }

init() {
    add_action("drink", "drink");
}

get() {
    return 1;
}

query_weight() {
  return (number/3);
    return 1;
}
