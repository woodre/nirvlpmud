varargs
void tell_text(object ob, string str, object *exclude)
{
  object *inv;
  int x, y;

  if(!str) str="";
  if(!exclude) exclude=({});

  inv = all_inventory(ob);
  y = sizeof(inv);

  for(x=0;x<y;x++)
  {
    if(living(inv[x]))
      if(member_array(inv[x], exclude) == -1)
        tell_object(inv[x], str);
  }
}
