int toast,price;

id(str) { return str == "spuckballs" || str == "tube"; }

reset(arg) {
  if(arg) return;
  toast=144;
  price = toast * 23;
}

short() { return "A Super Extendo tube of Spuckballs [" + toast + "]"; }

long() {
write("You hold a very long, large, soft, and squishy cylinder filled with\n"+
      "equally squishy but very dense colored balls. You are not quite sure\n"+
      "what you could do with them. This cylinder is much, much longer than\n"+
      "the length of the ones you are used to seeing.\n");
  write("There are [" + toast + "] spuckballs left.\n");
}

lose_ammo(i) {
  if(i) toast = toast - i;
  else toast=toast-1;
  return toast;
}

query_ammo() {
  return toast;
}

query_save_flag() {return 1;}

query_value() { return price; }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("use"); add_verb("eat");
#else
  add_action("use", "eat");
#endif
}

use(arg) {
  object tp;
  tp = this_player();
    if(!arg || arg != "spuckball"){
    return 0;
  } else {
    if(!tp->eat_food(3)){
    return 1;
  } else {
    if(arg == "spuckball"){
      toast=toast - 1;
      write("You gobble up a Spuckball. You feel like you just ate a water balloon.\n"+
      "There are ["+toast+"] spuckballs left.\n");
      say(capitalize(tp->query_name()) + " eats a Spuckball.\n");
        if(toast == 0){
          destruct(this_object());
          write("You finish off the tube and chuck it away.\n");
          tp->add_weight(-1);
        }
      return 1;
      }
    }
  }
}

get() { return 1; }

query_weight() { return 1; }

