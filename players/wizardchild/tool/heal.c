heal(str) {
  int amt;
  if(!str || !sscanf(str, "%d", amt)) amt = 100000;
  write("You heal yourself.\n");
  this_player()->heal_self(amt);
  return 1;
}
