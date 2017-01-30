inherit "/obj/money";

void reset(status arg) {
  if(arg) return;
  
  money=4000+random(300)+random(300)+random(300);
}

status get() {
  write("Your greedy, grasping hands pass right through the coins.\n");
  say(this_player()->query_name()+" tries to get a pile of coins, but fails.\n");
  return 0;
}
