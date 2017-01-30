#include "/room/clean.c"
#include "/players/fred/closed/bloodfist/defs.h"
#define SIZE 40

reset(arg){
  set_no_clean(1);
}

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

short(){
  if(this_player() && this_player()->query_guild_name() == "bloodfist")
    return "An open treasure chest";
  else
    return "A locked treasure chest";
}

long(){
  if(this_player() && this_player()->query_guild_name() == "bloodfist")
    write(
  "This is a very large treasure chest, propped open near some equipment\n"+
  "that is lying on the ground.  Anyone could put something into it or\n"+
  "take something out of it.  chest_help for more info.\n");
  else
    write("This is a plain looking chest.\n");
}

id(str){ return str == "chest" || str == "treasure" || str == "treasure chest"
|| str == "fred_bf_Tchest"; }

void init(){
  add_action("help",    "chest_help");
  add_action("help",    "chelp");
  add_action("list",    "chest_list");
  add_action("list",    "clist");
  add_action("gett",    "chest_withdraw");
  add_action("gett",    "cwithdraw");
  add_action("gett",    "chest_get");
  add_action("gett",    "cget");
  add_action("gett",    "chest_take");
  add_action("gett",    "ctake");
  add_action("deposit", "chest_deposit");
  add_action("deposit", "cdeposit");
  add_action("deposit", "chest_put");
  add_action("deposit", "cput");
}

status help()
{
  write("You read the plaque on the side of the chest:\n"+
"  List:     chest_list, clist\n"+
"  Withdraw: chest_withdraw, cwithdraw, chest_get, cget, chest_take, ctake\n"+
"  Deposit:  chest_deposit, cdeposit, chest_put, cput\n\n"+
"You may use name, number or all.  Deposits are added to the end and there\n"+
"can be up to "+SIZE+" things in the chest at once.  Withdraws will cause\n"+
"all numbers below that item to shift up one space.\n");
  return 1;
}

status deposit(string str)
{
  int a, sa;
  object *myinv, it;
  string t;
  if((string)this_player()->query_guild_name() != "bloodfist") return 0;
  if(sizeof(all_inventory(this_object())) > SIZE)   /* only SIZE items max */
    return (notify_fail("The chest is full.\n"), 0);
  if(str == "all")
  {
    myinv = all_inventory(this_player());
    sa = sizeof(myinv);
    write("You put your things in the treasure chest.\n");
    for(a = 0; a < sa; a++)
    {
      if((t = (string)myinv[a]->short()))
      {
        write("  "+colour_pad(t, 55)+" ... ");
        if(!myinv[a]->drop() && myinv[a]->query_value() > 0)
        {
          write("okay\n");
          move_object(myinv[a], this_object());
        }
        else
          write("\n");
      }
    }
    say(this_player()->query_name()+
      " puts some items in the treasure chest.\n");
    write("\n");
    this_player()->recalc_carry();
    return 1;
  }
  else if(!(it = present(str, this_player())))
    return (notify_fail("What do you want to deposit?\n"), 0);

  if(!it->drop() && it->query_value() > 0)
  {
    write("You put your "+it->short()+" in the treasure chest.\n");
    move_object(it, this_object());
  }
  else
    return (notify_fail("You can not deposit that.\n"), 0);
  return 1;
}

status gett(string str)
{
  object it, *myinv;
  int a, b, sa;
  string t;
  if((string)this_player()->query_guild_name() != "bloodfist") return 0;
  myinv = all_inventory(this_object());
  sa = sizeof(myinv);
  if(!sa)
    return (notify_fail("There is nothing in the chest.\n"), 0);
  if(str == "all")
  {
    write("You take as much as you can from the treasure chest.\n");
    for(a = 0; a < sa; a++)
    {
      it = myinv[a];
      t = (string)it->short();
      write("  "+colour_pad(t,55)+" ... ");
      if(!this_player()->add_weight(it->query_weight()))
        return (notify_fail("too heavy\n"), 0);
      else
        write("okay\n");
      say(this_player()->query_name()+" takes "+it->short()+
        " from the treasure chest.\n");
      move_object(it, this_player());
    }
    this_player()->recalc_carry();
    write("\n");
    return 1;
  }
  if(!(it = present(str, this_object())))
  {
    if(sscanf(str, "%d", b))
      if((b > 0) && ((b-1) < sa))
        it = myinv[(b-1)];
  }
  if(!it)
    return (notify_fail("What do you want to get from the chest?\n"), 0);
  if(!this_player()->add_weight(it->query_weight()))
    return (notify_fail("You can not carry that.\n"), 0);
  move_object(it, this_player());
  write("You take "+it->short()+" from the treasure chest.\n");
  say(this_player()->query_name()+" takes "+it->short()+
    " from the treasure chest.\n");
  return 1;
}

status list()
{
  int a, sa;
  object *myinv;
  myinv = all_inventory(this_object());
  sa = sizeof(myinv);
  if((string)this_player()->query_guild_name() != "bloodfist") return 0;
  if(!sa)
    return (notify_fail("There is nothing in the chest.\n"), 0);
  write("Treasure chest contents:\n");
  say(this_player()->query_name()+" searches through the treasure chest.\n");
  for(a = 0; a < sa; a++)
    write(" "+(a+1)+". "+myinv[a]->short()+"\n");
  write("\n");
  return 1;
}

