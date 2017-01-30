/* 08/13/06 Earwax: Daemonized this */
int cmd_cashmoney(string str)
{
  object cash;
  int money;
  int cash2;

  if(!str || !sscanf(str,"%d",cash2)==1) {
    write("Usage: money <number of coins>\n");
    return 1;
  }
  money = (int)this_player()->query_money();
  if(money < cash2) {
    write("You don't have that much!\n");
    return 1;
  }
  if(cash2 < 1) {
    write("Use a positive number of coins!\n");
    return 1;
  }
  if(cash2 > 10000) {
    write("You may not convert more than 10,000 coins at a time.\n");
    return 1;
  }
  if(!((int)this_player()->add_weight(cash2/900))) {
    write("You cannot carry that much more weight in your inventory.\n");
    return 1;
  }
  cash = clone_object("/obj/money");
  this_player()->add_money(-cash2);
  cash->set_money(cash2);
  move_object(cash,this_player());
  write("You move "+cash2+" coins into your inventory.\n");
  say((string)this_player()->query_name()+" moves some money around.\n");
  return 1;
}
