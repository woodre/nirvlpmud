short()
{
  return "A hand of cards";
}

id(str)
{
  return "hand" == str;
}

long()
{
  array a;
  int i;
  write("You're holding:\n");
  a = all_inventory(this_object());
  for(i=sizeof(a)-1; i>=0; i--) write(i + ": " + a[i]->short()+"\n");
}

cleanup()
{
  array a;
  int i;
  a = all_inventory(this_object());
  for(i=sizeof(a)-1; i>=0; i--) destruct(a[i]);
}

getCard(c)
{
  return all_inventory(this_object())[c];
}

get() { return 1; }
drop() { return 1; }
