object topcard;

reset(arg)
{
  if(arg) return;
  topcard = 0;
}

short()
{
  return "A pile of cards";
}

id(str)
{
  return "pile" == str;
}

long()
{
  if(topcard == 0)
  {
    write("The pile is empty!\n");
    return;
  }
  write("The top card is:\n");
  write(topcard->short()+"\n");
}

query_topcard()
{
  return topcard;
}

discard(card)
{
  move_object(card,this_object());
  topcard = card;
}

cleanup()
{
  array a;
  int i;
  a = all_inventory(this_object());
  for(i=sizeof(a)-1; i>=0; i--) destruct(a[i]);
}

get() { return 1; }
drop() { return 1; }
