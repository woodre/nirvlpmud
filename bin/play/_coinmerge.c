/* Added by Fred [1.28.11] player idea */

int cmd_coinmerge()
{
  object obj, obj2;
  object gold;
  int amount, total;

  amount = 0;
  total = 0;

  obj = first_inventory(this_player());

  while(obj)
  {
    obj2 = next_inventory(obj);    
    if(obj->is_money())
      {
        amount = (int)obj->query_goldamt();
        total += amount;
   
        destruct(obj);
      }
    obj = obj2;
  }

  if(this_player()->query_money() < 80000)
  {
    int amt, amt2;
    amt = (int)this_player()->query_money();
    amt2 = 80000 - amt;
    if(amt2 > total)
      amt2 = total;
    this_player()->add_money(amt2);
    total = total - amt2;
  }
 
  if( total > 0 ) {
    gold = clone_object("/obj/money.c");
    gold->set_money(total);
    move_object(gold, this_player());
  }

  write("You merge the stacks of coins in your inventory.\n");
  return 1;
} 
