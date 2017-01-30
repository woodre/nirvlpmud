int toast,price;

id(str) { return str == "rawtoast" || str == "toast" || str == "bag"; }

reset(arg) {
  if(arg) return;
  toast=12;
  price = toast * 180;
}

short() { return "A bag of raw toast [" + toast + "]"; }

long() {
  write("The contents of this bag are soft, white, and fluffy. The bag\n"+
	"itself is made of a see-through material, soft and crumply.\n"+	
	"covered with polka dots, the logo 'Wonder' is emblazoned on it.\n");
  write("There are [" + toast + "] slices of raw toast left.\n");
}

lose_ammo() {
  toast=toast-1;
  return toast;
}

query_ammo() {
  return toast;
}

query_save_flag() {return 1;}

query_value() { return price; }

init() {
add_action("use", "eat");
}

use(arg) {
  object tp;
  tp = this_player();
    if(!arg || arg != "toast"){
    return 0;
  } else {
    if(!tp->eat_food(10)){
    return 1;
  } else {
    if(arg == "toast"){
      toast=toast - 1;
      write("You eat up a slice of raw toast. Mmmmm. It kind of tastes like bread.\n"+
      "There are ["+toast+"] slices left.\n");
      say(capitalize(tp->query_name()) + " digs into a plastic bag and devours some (eew) raw toast.\n");
        if(toast == 0){
          destruct(this_object());
          write("You finish off the bag, blow it up, and pop it with a loud BOOM!\n");
          tp->add_weight(-1);
        }
      return 1;
      }
    }
  }
}

get() { return 1; }

query_weight() { return 1; }


