#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "knucklebones" ||
           str == "bones" ||
           str == "bone" ||
           str == "knuckle" ||
           str == "sack" ||
           str == "knucklebone" ||
           str == "sack of knucklebones";
   }

short() { return "A sack of knucklebones"; }
query_save_flag()  { return 1; }
query_value() {
  if (!number)
    return 5;
  else
    return number*250;
}

long() {
   write("A sack of human knucklebones.\n"+
     "Perhaps you could pop a knucklebone.\n"+
    "You have another "+number+" knuckles.\n");
}

reset(arg) {
    if (arg)
        return;
  number = 5;
}

pop()  {
if(number > 0)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
   write("You pop a knucklebone into your mouth.\n"+
     "The knucklebone is rather dry and crunchy.\n");
  say(tp+" pops one of the knucklebones and "+this_player()->query_pronoun()+" smirks wickedly.\n");
   number = number - 1;
 call_other(this_player(), "heal_self", 35);
 call_other(this_player(), "recalc_carry");
  if (!number) {
    full = 0;
  write("You pop the last knucklebone.\n"+
          "That was different..\n");
    say(call_other(this_player(), "query_name", 0) +
    " empties the sack of knucklebones.\n");
}
  return 1;
    }
 else {
  write("There are no more knucklebones to pop.\n");
  return 1; }
}

init() {
   add_action("pop","pop");
}
get() { return 1; }
query_weight() { return 1; }

