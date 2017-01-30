
#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "knucklebones" ||
           str == "bones" ||
           str == "bone" ||
           str == "knuckle" ||
           str == "bag" ||
           str == "knucklebone" ||
           str == "bag of knucklebones";
   }

short() {
   return "A bag of knucklebones";
}

query_save_flag()  { return 1; }
query_value() {
  if (!number)
    return 5;
  else
    return number*350;
}

long() {
   write("A bag of human knucklebones.\n"+
     "Perhaps you could pop a knucklebone.\n"+
    "You have another "+number+" knuckles.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 10;
}

pop()  {
if(number2 < 10)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
   write("You pop a knucklebone into your mouth.\n"+
     "The knucklebone is rather dry and crunchy.\n");
  say(tp+" pops one of the knucklebones and "+this_player()->query_pronoun()+" smirks wickedly.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 35);
 call_other(this_player(), "recalc_carry");
  if (!number) {
    full = 0;
  write("You pop the last knucklebone.\n"+
          "That was different..\n");
    say(call_other(this_player(), "query_name", 0) +
    " empties the bag of knucklebones.\n");
}
  return 1;
    }
if(number2 > 8)  {
  write("There are no more bones in the bag.\n");
    return 1;
}
}
init() {
   add_action("pop","pop");
}

get() {
    return 1;
}


query_weight() {
    return (number/3);
}

