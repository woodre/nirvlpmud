
#define tp this_player()->query_name()
int full, number, number2;

id(str) {
    if (str == "wine" && full)
	return 1;
    return str == "bottle";
}

short() {
    if (full)
    return "A tall bottle of white wine";
    return "An empty bottle";
}

/* The shop only buys empty bottles ! */

query_save_flag()  { return 1; }


query_value()
{
    if (!full) return 5;
    return 500;
}

long() {
   write("A tall bottle of white wine.\n"+
     "You may 'sip' another "+number+" sips.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 10;
    full = 1;
}

sip(str)
{
if (str == "wine" || str == "from bottle")  {
    if (!full)
{
  write("The bottle is empty.\n");
   return 1;
}
if(number2 < 10)  {
    if (!call_other(this_player(), "drink_alcohol", 14))
  return 0;
  write("You take a sip of strong white wine.\n");
   say(tp+" takes a sip of strong white wine.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
  return 1;
    }
if(number2 > 8)  {
    full = 0;
     write("You finish off the bottle of wine.\n"+
          "That was quite good.\n");
    say(call_other(this_player(), "query_name", 0) +
    " finishes off a bottle of wine.\n");
    return 1;
}
 }  }

init() {
    add_action("sip"); add_verb("sip");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
