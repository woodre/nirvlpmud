
#define tp this_player()->query_name()
int full, number, number2, price;

id(str)
 { return str == "taco" || str == "taco";  }

/*  dumb but new */
is_heal(){ return "stuff";}
query_potence(){ return 32;}
short() {
   return "A soft taco";
}

query_save_flag()  { return 1; }
query_value()
{
    return price;
}

long() {
write("A soft taco made with grade 'D' hamburger, lettuce, tomatoes,\n"+
"and some shredded cheese wrapped in a soft flour tortilla shell.\n"+
     "You think you could 'eat' the taco.\n");
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
  if(str == "taco" || str == "taco")  {
if(number2 < 5)  {
    if (!call_other(this_player(), "eat_food", 7))
  return 0;
  write("You eat part of the taco.\n"+
    "Your body feels nourished.\n");
   say(tp+" eats part of a soft taco.\n");
  number2 = number2 + 1;
  number = number - 1;
price = number * 400;
 call_other(this_player(), "heal_self", 32);
 write("You have "+number+" of bites left.\n");
    }
if(number2 > 4)  {
  write("You finish off the soft taco.\n");
  destruct(this_object());
}
 return 1;
}
}

init() {
    add_action("feedme", "eat");
}

get() {
    return 1;
}

query_weight() {
    return 3;
}
