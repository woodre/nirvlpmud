
#define tp this_player()->query_name()
int full, number, number2;

id(str)
 { return str == "bread" || str == "loaf";  }

short() {
   return "A loaf of bread";
}

query_save_flag()  { return 1; }
query_value()
{
    return 250;
}

long() {
    write("A loaf of bread.\n"+
     "You think you could 'eat' the bread.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 5;
}

feedme(str)  {
if(!str) {
  write("Eat what?\n");
   return 1;   }
  if(str == "bread" || str == "loaf")  {
if(number2 < 5)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
  write("You eat part of the loaf.\n"+
    "Your body feels nourished.\n");
   say(tp+" eats part of a loaf of bread.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
 write("You have "+number+" of bites left.\n");
    }
if(number2 > 4)  {
  write("You finish off the loaf of bread.\n");
  destruct(this_object());
}
 return 1;
}
}

init() {
    add_action("feedme"); add_verb("eat");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
