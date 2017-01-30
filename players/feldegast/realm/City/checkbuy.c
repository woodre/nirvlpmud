checked_buy(string file_name,int value,int weight) {
  object ob;
  if(this_player()->query_money()<value) {
    write("You don't have enough money.\n");
    return 0;
  }
  if(this_player()->query_weight()<weight) {
    write("That is too heavy for you.\n");
    return 0;
  }
  ob=clone_object(file_name);
  move_object(ob,this_player());
  this_player()->recalc_weight();
  return 1;
}

