short()
{
  return "A deck of cards";
}

id(str)
{
  return "deck" == str;
}

topCard()
{
  return first_inventory(this_object());
}

reset(arg)
{
  int i;
  object o;
  if(arg) return;
  for(i=0;i<52;i++)
  {
    o = clone_object("/players/sado/toys/card.c");
    o->set_card(i);
    move_object(o,this_object());
  }
}

shuffle()
{
  array old;
  int i,j,k,n;
  old = all_inventory(this_object());
  n = sizeof(old);
  for(i=0;i<n;i++) move_object(old[i],"/room/void");
  i=0; j=n/2;
  while((i < n/2) && (j < n))
  {
    if(random(2) == 0) move_object(old[i++],this_object());
    else move_object(old[j++],this_object());
  }
  while(i < n/2) move_object(old[i++],this_object());
  while(j < n) move_object(old[j++],this_object());
}

query_deck()
{
  object o;
  for(o = first_inventory(this_object()); o; o = next_inventory(o))
  {
    write(o->short()+"\n");
  }
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
