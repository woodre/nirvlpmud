#define tp this_player()->query_name()
int full, number, number2;

id(str) {
    if (str == "salsa" && full)
	return 1;
    return str == "jar";
}

short() {
    if (full)
    return "A jar of special salsa";
    return "An empty jar";
}

query_save_flag()  { return 1; }

query_value() {
    if (!full) return 5;
    return number*0;
}

long() {
  write("A jar of Daranath's special salsa. The ingredients have\n"+
        "been a secret for centuries untold. If you wish, you\n"+
        "could <taste> the salsa to see if its any good.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 2;
    full = 1;
}

taste(str) {
if (!str) {
  write("Taste what???\n");
return 1; 
}
if (str == "salsa" || str == "from jar")  {
    if (!full)
{
  write("The jar of salsa is empty.\n");
   return 1;
}
if(number > 0)  {
    if (!call_other(this_player(), "drink_soft", 5))
  return 0;
  write("You take the jar and dip into the special salsa within.\n"+
        "The salsa is extremly spicy and it warms your body all over.\n"+
       "Daranath must really know what he is doing.\n\n");
  write("You feel the need to share this wonderful salsa with\n"+
        "someone else, perhaps someone special.\n");
  say(tp+" takes a taste of Daranath's special salsa.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 30);
  return 1;
    }
else {
    full = 0;
    write("You fully empty the special salsa from the jar.\n"+
          "An empty feeling comes over your body and you begin\n"+
          "to wonder where you could possibly get some more.\n");
    say(call_other(this_player(), "query_name", 0) +
    " empties the jar of Daranath's Special Salsa.\n");
    return 1;
}
 }  }

init() {
    add_action("taste","taste");
}

get() { return 1; }
query_weight() { return 1; }
