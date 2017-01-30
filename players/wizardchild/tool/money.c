money(str) {
  int amt;
  if(!str || !sscanf(str, "%d", amt)) amt = 80000;
  write("You give yourself "+amt+" coins.\n");
  this_player()->add_money(amt);
  return 1;
}
