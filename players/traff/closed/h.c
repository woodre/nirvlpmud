
#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "honeycomb" || str == "honeycomb";  }

short() {
   return "A Honeycomb";
}

query_save_flag()  { return 1; }
query_value()
{
    return 500;
}

long() {
   write("An sweet honeycomb.\n"+
    "You probably could 'eat honey'.\n"+
    "You have another "+number+" bites.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 10;
}

eat_honey()  {
if(number2 < 10)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
  write("You take a bit of sweet honeycomb.\n"+
    "The honey drips from your lips and you feel better.\n");
  say(tp+" takes a bite of the honeycomb and "+this_player()->query_pronoun()+" feels better.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
  return 1;
    }
if(number2 > 8)  {
  write("There are no more bites in the honeycomb.\n");
    return 1;
}
}
init() {
   add_action("eat_honey","eat_honey");
}

get() {
    return 1;
}


query_weight() {
    return 1;
}

