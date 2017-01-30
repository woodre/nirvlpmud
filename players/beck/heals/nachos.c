
#define tp this_player()->query_name()
int full, number, number2, price;

id(str)
 { return str == "nachos" || str == "nachos";  }

/* more base code hack and slash */
is_heal(){ return "stuff";}
query_potence(){ return 24;}
short() {
   return "Some Nachos from Taco Bell";
}

query_save_flag()  { return 1; }
query_value()
{
    return price;
}

long() {
write("Some corn tortilla chips covered with orange cheese.\n"+
"They look very tasty.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
  number = 2;
price = number * 100;
}

feedme(str)  {
if(!str) {
  write("Eat what?\n");
   return 1;   }
  if(str == "nachos" || str == "nachos")  {
if(number2 < 2)  {
    if (!call_other(this_player(), "eat_food", 5))
  return 0;
  write("You eat half of the nachos.\n"+
    "Your body feels nourished.\n");
   say(tp+" eats half of some nachos.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 24);
 write("You have "+number+" servings left.\n");
    }
if(number2 > 1)  {
  write("You finish off the nachos.\n");
  destruct(this_object());
}
 return 1;
}
}

init() {
    add_action("feedme","eat");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
