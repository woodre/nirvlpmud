
#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "fungus treats" ||
           str == "treats" ||
           str == "growth" ||
           str == "fungus treat" ||
           str == "growth of fungus treats";
   }

short() {
   return "A growth of fungal treats";
}

query_save_flag()  { return 1; }
query_value() {
  if (!number)
    return 5;
  else
    return number*350;
}

long() {
   write("A growth of fungal sugar treats.\n"+
     "Perhaps you could eat a treat.\n"+
    "You have another "+number+" treats.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 5;
}

eat()  {
if(number2 < 5)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
   write("You reach down and eat a treat from the growth.\n"+
     "The treat is soft and sweety.\n");
  say(tp+" eats one of the treats and "+this_player()->query_pronoun()+" grins smuggly.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
 call_other(this_player(), "recalc_carry");
  if (!number) {
    full = 0;
  write("You eat the last fungus treat.\n"+
          "That was different..\n");
    say(call_other(this_player(), "query_name", 0) +
    " eats the last treat off the growth.\n");
}
  return 1;
    }
if(number2 > 5)  {
  write("There are no more treats on the growth.\n");
    return 1;
}
}
init() {
   add_action("eat","eat");
}

get() {
    return 1;
}


query_weight() {
  if(number > 2) return (number/3);
  else return 1; }

