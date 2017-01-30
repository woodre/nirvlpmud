int toast,price;

id(str) { return str == "chickens" || str == "bag"; }

reset(arg) {
  if(arg) return;
  toast=1296;
  price = toast * 23;
}

short() { return "A bag of frozen chickens [" + toast + "]"; }

long() {
write("This is a bag of frozen chickens. Hmm.\n");
  write("There are [" + toast + "] chickens left.\n");
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

get() { return 1; }

query_weight() { return 5; }

