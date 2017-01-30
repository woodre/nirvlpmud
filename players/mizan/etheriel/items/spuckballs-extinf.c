int toast,price;

id(str) { return str == "spuckballs" || str == "coil"; }

reset(arg) {
  if(arg) return;
  toast=30000;
  price = toast * 23;
}

short() { return "A Spuckball coil [" + toast + "]"; }

long() {
write("You hold a very long, large, soft, and squishy tube filled with\n"+
      "equally squishy but very dense colored balls. You are not quite sure\n"+
      "what you could do with them. This thing is very heavy,\n"+
      "about the weight of a small car.\n");
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

query_value() { return 0; }

init() {
#if 0 /* Rumplemintz */
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
          write("You finish off the coil and chuck it away.\n");
          tp->add_weight(-5);
        }
      return 1;
      }
    }
  }
}

get() { return 1; }

query_weight() { return 5; }

