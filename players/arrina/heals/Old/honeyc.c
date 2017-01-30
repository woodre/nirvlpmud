/* Heal does "stuff" and uses heal_self of 35
   cost is 1800, and there are 5 "charges"
*/

#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "comb" || str == "honeycomb";  }

short() {
   return "A Honeycomb";
}

is_heal() { return "stuff"; }
query_potence() { return 35; }
query_save_flag()  { return 1; }
query_value() {
  if (!number)
    return 5;
  else
    return number*350;
}

long() {
   write("A sweet honeycomb.\n"+
    "You probably could 'sweeten' yourself.\n"+
    "You have another "+number+" bites.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 5;
}

sweeten()  {
if(number2 < 5)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 1;
  write("You take a bite of sweet honeycomb.\n"+
    "The honey drips from your lips and you feel better.\n");
  say(tp+" takes a bite of the honeycomb and "+this_player()->query_pronoun()+" feels better.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 35);
 call_other(this_player(), "recalc_carry");
  if (!number) {
    full = 0;
  write("You empty the honeycomb.\n"+
		"That was wonderful...  You shove the\n"+
		"wax in your mouth, chew it up and..\n"+
		"GULP.. you swallow it.\n");
  say(tp+" finishes off a honeycomb.\n");
    destruct(this_object());
}
  return 1;
    }
if(number2 > 8)  {
  write("There are no more bites in the honeycomb.\n");
    return 1;
}
}
init() {
   add_action("sweeten"); add_verb("sweeten");
}

get() {
    return 1;
}

query_weight() {
  if(number > 2)
  return (number/2);
    return 1;
}

