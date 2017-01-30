int main(string str){
  int coins;
  if(!str || !sscanf(str,"%d",coins) || coins <= 0){
    write("Donate how many coins ?\n");
    return 1;
  }
  if((int)this_player()->query_money() < coins){
    write("You don't have "+HIY+coins+NORM+" coins.\n");
    return 1;
  }
  else {
    object stack;
    write("You donate "+HIY+gc+NORM+" gold coins"
         +" to the Gods.\n");
    stack = clone_object("/obj/money");
    stack->set_money(coins);
    stack->short();
    tell_room(environment(this_player()),
      (string)this_player()->query_name()+" tosses "
      +lower_case((string)stack->query_descr())
      +" into the air.\nIt disappears.\n", ({this_player()}));
    destruct(stack);
  }
  this_player()->add_money(-coins);
  previous_object()->add_donation(coins);
  return 1;
}