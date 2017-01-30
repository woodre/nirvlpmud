id(str) { return str == "ball" || str == "money"; }
 
short() {
  return "A money ball";
  }
  
long() {
  write("Its a money ball.  You paid 10,000 coins for it as an investment.\n");
  write("It will give you back 5000 coins now that you have it.  Just\n");
  write("'unwad ball' to get the money back.\n");
  }
  
query_save_flag() { return 1; }
query_weight() { return 1;}
drop() { return 0; }
get() { return 1; }
 
init() {
  add_action("money_back", "unwad");
  }
  
money_back(str) {
  object tp;
  tp=this_player();
  if((!str) || (str != "ball")) {
    write("Unwad what?\n");
    return 1;
    }
  tell_object(tp,"You unwad the ball of money and stick it into your pocket.\n");
  tell_room(environment(this_player()),capitalize(tp->query_name())+" unwads a ball of money and sticks it in their pocket.\n");
  tp->add_money(5000);
  destruct(this_object());
  return 1;
}
