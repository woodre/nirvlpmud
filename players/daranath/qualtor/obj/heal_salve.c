/* Taken from Saber's white wine with permission -Dar */

#define tp this_player()->query_name()
int full, number, number2;

id(str) {
    if (str == "salve" && full)
	return 1;
    return str == "tin";
}

short() {
    if (full)
    return "A tin of healing salve";
    return "An empty tin";
}

query_save_flag()  { return 1; }

query_value() {
    if (!full) return 5;
    return number*100;
}

long() {
   write("A small tin of an herbal sealing salve.\n"+
     "You may 'apply' another "+number+" applications.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 7;
    full = 1;
}

apply(str)
{
if (str == "salve" || str == "from tin")  {
    if (!full)
{
  write("The tin is empty.\n");
   return 1;
}
if(number > 0)  {
    if (!call_other(this_player(), "drink_soft", 14))
  return 0;
  write("You apply the healing salve to your wounds.\n");
   say(tp+" applies some healing salve to thier wounds.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
  return 1;
    }
else {
    full = 0;
     write("You fully empty the healing salve from the tin.\n"+
           "You wonder if you will need some more.\n");
    say(call_other(this_player(), "query_name", 0) +
    " empties the tin of healing salve.\n");
    return 1;
}
 }  }

init() {
    add_action("apply","apply");
}

get() { return 1; }
query_weight() { return 1; }
