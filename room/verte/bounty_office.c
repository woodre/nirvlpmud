#include <ansi.h>
#include <security.h>

#define B_SAVE "room/verte/data/bounty_office"
#define MIN_BOUNTY 10000

inherit "/room/room";

string *b_names;
int    *b_coins;
static mixed  *remembered;

void refresh_remembered();

int force_set(string name, int arg) {
  int i;
  if (!b_names || !b_coins) return 0;
  i = member_array(name, b_names);
  if (i < 0) {
    write("Add them to the list first by posting mininum bounty.\n");
    return 0;
  }
  b_coins[i] = arg;
  save_object(B_SAVE);
  return b_coins[i];
}

void reset(int x) {
  if(x) return;
  set_light(1);
  if(!restore_object(B_SAVE)) {
    b_names = ({ });
    b_coins = ({ });
    set_short("The village bounty office");
    set_long("\
This is the village bounty office. It is a newer-looking room,\n\
with white walls and a dark brown floor. Numerous wanted\n\
posters line the walls. On the north wall, iron bars separate\n\
you from the cashier. There is a sign hanging from the bars.\n");
    set_dest_dir(({
      "room/police", "south"
    }));
    set_items(({
      "posters", "\
Numerous scoundrels and scallywags decorate the walls.\n\
You've never seen such a collection of ugly mugs.\n\
Type 'bounties' to list all bounties",
      "walls", "\
White-washed walls with slightly gilded trim, they were\n\
made from solid brick, a masterpiece of craftsmanship",
      "floor", "\
A dark brown, hardy wooden floor. The boards easily hold\n\
your weight atop them",
      "wall", "\
The only pertinent wall is the north wall",
      "north wall", "\
The north wall separates you from the cashier by a heavy set of\n\
iron bars",
      "cashier", "\
The cashier stands ready to tender payment if you are collecting\n\
a bounty or process money for a bounty post",
      "iron bars", "\
Iron clad bars separate you and the cashier",
      "bars", "\
Iron clad bars separate you and the cashier",
      "sign", "\n\
The sign reads:\n\n\
 \"post\" at least a "+MIN_BOUNTY+" coin bounty on someone's head.\n\
 \"bounties\" to list all bounties\n\
 \"collect\" a bounty on someone you've slain.\n\n\
Note: Bounties may only be collected on the SAME day\n\
      you have commited the murder, i.e. Thursday.\n\
      NOT 24 HOURS",
   }));
  }
  refresh_remembered();
}
  
void refresh_remembered()
{
  int x, y;
  remembered = ({ });
  y = sizeof(b_names);
  for(x = 0; x < y; x ++)
  {
    remembered += ({ b_coins[x], b_names[x] });
  }
}

void save_me()
{
  save_object(B_SAVE);
}

void init()
{
  ::init();
/*
  if(this_player() && present(this_player(),this_object()) &&
     query_ip_number(this_player()) != "68.45.152.184") {
    move_object(this_player(), "/room/vill_green");
    return;
  }
*/
  add_action("cmd_post", "post");
  add_action("cmd_collect", "collect");
  add_action("cmd_bounties", "bounties");
}

int query_index(string nm)
{
  return member_array(nm, b_names);
}

int sort_me(int a, int b)
{
  return (b > a);
}

void order_arrays()
{ 
  int x, y, i, j, found;
  int *pos;
  
  
  b_coins = sort_array(b_coins, "sort_me", this_object());
  b_names = allocate(sizeof(b_coins));
  
  y = sizeof(b_coins);
  
  pos = ({ });
  
  for(x = 0; x < y; x ++)
  {
    found = 0;
    i = member_array(b_coins[x], remembered);
    while(!found)
    {
      j = member_array(i, pos);
      if(j == -1)
      {
        pos += ({ i });
        found = 1;
      }
      else
      {
        i += 2;
      }
    }
    if(intp(remembered[i+1])) { i+=1; }
    b_names[x] = remembered[i+1];
  }
}

int cmd_post(string str)
{
  string x;
  int    money;
  
  if((int)this_player()->query_level() >= 21 &&
     (int)this_player()->query_level() < ELDER)
  {
    write("Wizards may no longer post bounties.\n");
    return 1;
  }
  
  if(!str || sscanf(str, "%s %d", x, money) < 2) {
    write("Usage: 'post <scoundrel> <money>'\n");
    return 1;
  }
  
  if(!valid_active_player(x)) {
    write("There isn't any such active player named \""+x+"\"\n");
    return 1;
  }
  if(valid_wizard(x)) {
    write("Don't be stupid. Immortals would never pay out.\n"+
          "Because they never die.\n");
    return 1;
  }
  if(money < MIN_BOUNTY) {
    write("You must post at least "+MIN_BOUNTY+" coins.\n");
    return 1;
  }
  if((int)this_player()->query_money() < money)
  {
    write("You don't have that much money.\n");
    return 1;
  }
  else
  {
    int i, total;
    this_player()->add_money(-money);
    
    i = query_index(x);
    if(i > -1)
      total = b_coins[i];
    else
    {
      b_names += ({ x });
      b_coins += ({ 0 });
      i = query_index(x);
    }
      
    write("You post a "+HIG+money+NORM+" bounty on "+
      capitalize(x)+"'s head.\n");
    say((string)this_player()->query_name()
    +" pays the cashier.\n");
    
    if(total) {
      write("That brings the total bounty to "+HIG+(total+money)+NORM+".\n");
    }
    
    log_file("BOUNTIES", 
      capitalize((string)this_player()->query_real_name())+
      " posted "+money+" on "+capitalize(x)+".\n");
    b_coins[i] += money;
    refresh_remembered();
    order_arrays();
    save_me();
    return 1;
  }
}

int cmd_collect(string str)
{
  if(!str) {
    write("Collect the bounty on whose head?\n");
    return 1;
  }
  
  if(!this_player()->is_player()) return 0;
  
  else
  {
    int i, x, y, ok;
    string ct, rf, *exp;
    
    i = query_index(str);
    if(i == -1)
    {
      write(capitalize(str)
       +"'s head does not have a bounty on it.\n");
      return 1;
    }
    
    ct = ctime()[0..9];
    
    rf = read_file("/log/PK");
    exp = explode(rf, "\n");
    y = sizeof(exp);
    
    for(x = 0; x < y && !ok; x ++)
    {
      if(text_contains(exp[x],ct) && 
         text_contains(exp[x], ctime()[20..23]+" "+str+" "))
      {
        if(text_contains(exp[x],"killed by "+
          (string)this_player()->query_real_name()+"."))
        {
          ok = 1;
        }
      }
    }
    
    if(!ok)
    {
      write("You CANNOT collect a bounty you have not earned...\n");
      return 1;
    }
    
    else
    {
      object bag, geld;
      int    cm, amt;
      amt = 0;
      bag = clone_object("/obj/bag");
      cm = b_coins[i];
      while(cm)
      {
        geld = clone_object("/obj/money");
        if(cm > 80000)
        {
          cm -= 80000;
          amt = 80000;
        }
        else
        {
          amt = cm;
          cm = 0;
        }
        geld->set_money(amt);
        move_object(geld, bag);
      }
      move_object(bag, this_player());
    }
    
    write("Congratulations!\n");
    write("The cashier tosses a bag to you.\n");
    say("The cashier tosses a bag to "+
      (string)this_player()->query_name()+".\n");
    
    log_file("BOUNTIES", (string)this_player()->query_real_name()
      +" COLLECTED "+b_coins[i]+" from "+str+"'s HEAD!\n");
    emit_channel("junk", "(junk) "+(string)this_player()->query_name()
      +" just collected the bounty of "+b_coins[i]+" on "+capitalize(str)+"!\n");
    
    b_coins = a_delete(i, b_coins);
    b_names = a_delete(i, b_names);
    refresh_remembered();
    order_arrays();
    save_me();
    
    return 1;
  }
}

#define BAR RED+pad("",69,'-')+NORM+"\n"

int cmd_bounties()
{
  int x, y, thugs, total;
  write("\n");
  write(BAR);
  write("\t\t       NIRVANA'S MOST WANTED\n");
  write(BAR);
  
  total = 0;
  
  y = sizeof(b_names);
  
  for(x = 0; x < y; x ++)
  {
    write("\t\t     "+(x+1)+": "+capitalize(pad(b_names[x],15))+b_coins[x]+"\n");
    total += b_coins[x];
  }
  
  write(BAR);
  write("\t\t      Total Bounties: "+y+"\n");        
  write("\t\t    Total Bounty Rewards: "+total+"\n");
  write(BAR);
  write("\n");
  return 1;
}
