inherit "/players/feldegast/std/room.c";

string *item;
string *file;
int *value;
int *inventory;
int *weight;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return; /* by verte, uhhh, big bug ;) */
  item=({ });
  file=({ });
  value=({ });
  inventory=({ });
  weight=({ });
}

void add_item(string it, string f, int v, int in, int w)
{
  item+=({ it });
  file+=({ f });
  value+=({ v });
  inventory+=({ in });
  weight+=({ w });
}

int invalid_purchase(string arg)
{
  int index;
  index=member_array(arg,item);
  if(index==-1)
    if(sscanf(arg,"%d",index)==1)
    {
      if(index > sizeof(item) || index < 1)
        return 1;
      index--;
    }
    else
      return 1;
  if((int)this_player()->query_money() < value[index])
    return 2;
  if(inventory[index] <= 0)
    return 3;
  if(!((int)this_player()->add_weight(weight[index])))
    return 4;
}

string purchase(string arg)
{
  object ob;
  int index;
  index=member_array(arg,item);
  if(index==-1)
  {
    sscanf(arg,"%d",index);
    index--;
  }
  inventory[index]--;
  this_player()->add_money(-value[index]);
  ob=clone_object(file[index]);
  move_object(ob,this_player());
  return (string)ob->short();
}

int list(string arg)
{
  int i;
  write("   Item                          Quantity            Price\n");
  write("-------------------------------------------------------------\n");
  for(i=0; i < sizeof(item); i++)
  {
    write(pad((i+1)+". ",3));
    write(pad(item[i],30));
    write(pad(inventory[i],20));
    write(pad(value[i],10));
    write("\n");
  }
  return 1;
}
