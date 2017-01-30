/* Heal does "soak" and uses heal_self of 35
   cost is 1800, and there are 5 "charges"
*/
#define tp this_player()->query_name()

int full, number, number2;

id(str) { return str == "ade" || str == "lemonade"; }

short() {
  return "A bottle of refreshing lemonade";
}

/* The shop only buys empty bottles ! */

is_heal() { return "soak"; }
query_potence() { return 35; }
query_save_flag()  { return 1; }


query_value()
{
    if (!full) return 5;
 else
    return number*350;
}

long() {
   write("A bottle of refreshing lemonade.\n"+
     "You may 'drink' another "+number+" swallows of ade.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 5;
    full = 1;
}



drink(str)
{
if (str == "ade" || str == "from bottle")  {
    if (!full)
{
  write("The bottle is empty.\n");
   return 1;
}
    if (!call_other(this_player(), "drink_soft", 15))
  return 1;
  write("You take a drink of lemonade.\n");
   say(tp+" takes a drink of lemonade.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 35);
    call_other(this_player(), "recalc_carry");
  if (!number) {
    full = 0;
  write("You empty the bottle of lemonade.\n"+
		"That was wonderful ade.\n"+
		"You smash the empty bottle to smithereens.\n");
  say(tp+" empties a bottle of lemonade.\n");
	destruct(this_object());
}
    return 1;
 }  }

init() {
    add_action("drink"); add_verb("drink");
}

get() {
    return 1;
}

query_weight() {
  if(number > 2)
  return (number/2);
    return 1;
}
