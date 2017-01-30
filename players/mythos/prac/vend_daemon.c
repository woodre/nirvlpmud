inherit "/obj/clean";
int bags;

void reset(int x)
{
  if(x) return;
  set_no_clean(1);
  bags=random(6);
}

int query_bags()
{
  return bags;
}

void buy_bag()
{
  bags --;
}
