
#define tp this_player()->query_name()
int full, number, number2;

id(str)
 { return str == "cheese" || str == "cheese wheel";  }

short() {
  return "A wheel of cheese";  }

query_save_flag()  { return 1; }
query_value()
{
    return 250;
}

long() {
    write("A wheel of cheese.\n"+
     "You think you could 'eat' the cheese.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 4;
}

eat_cheese(str)  {
if(!str) {
  write("Eat what?\n");
   return 1;   }
  if(str == "cheese" || str == "cheese wheel")  {
if(number2 < 4)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
  write("You bite into the wheel of cheese and feel something gooey in the center.\n"+
        "Nasty!\n");
  say(tp+" bites into the cheese wheel and gets a strange expression.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
 write("You have "+number+" bites left.\n");
    }
if(number2 > 3)  {
  write("You finish off the wheel of cheese.\n");
  destruct(this_object());
}
 return 1;
}
}

init() {
    add_action("eat_cheese","eat");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
