#include "/players/feldegast/closed/shortcut.h"
#include "/players/feldegast/closed/ansi.h"


int charges;

init() {
  add_action("eat", "eat");
}

id(str) {
  return  str == "banana";
}

short(){
  return HIY+"A banana"+NORM;
}

long() {
  write("A yellow banana.\n");
}

get(){
  return 1;
}

eat(str) {
  if (!str || !id(str))
    return 0;
  if (!TP->eat_food(14)) return 1;
  TP->heal_self(15);
  write("You peel the banana and eat it in one bite.\n"
  );
  say(TPN+" eats a banana.\n");
  destruct(this_object());
  return 1;
}

query_value() {
   return 150;
}

query_weight() {
   return 1;
}
