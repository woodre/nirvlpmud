#include "defs.h"

inherit ROOM;

int peeps;

void reset(int arg)
{
  
  if(arg) return;
  set_light(1);
  set_short(HIC+"Sorcerous Dining Hall"+NORM);
  set_long(
"  No matter how powerful a sorcerer becomes, he still must gain\n\
sustenance, whether through blood, sacrifice, or demonic pacts.  Many\n\
of the more prosaicly minded magic users derive sustenance from this\n\
place - the dining hall.  Rows and rows of tables fill the hall, at\n\
which are seated singly or in groups dozens of spellcasters rubbing\n\
shoulders with some of the towers' more mundane staff.  The serving\n\
staff bustles back and forth through the kitchen doors to the north.\n\
A menu is posted near the door.\n");
  set_items(({
    "menu","It is in a language that you can read",
  }));
  set_dest_dir(({
    ROOMPATH+"kitchen.c","kitchen",
    ROOMPATH+"tower2.c","west",
  }));
}

void init()
{
  ::init();
  add_action("cmd_kitchen","kitchen");
  add_action("cmd_menu","menu");
  add_action("cmd_menu","read");
  add_action("cmd_menu","list");
  add_action("cmd_buy","buy");
  add_action("cmd_buy","order");
  add_action("cmd_buy","purchase");

  if(this_player()->is_player())
    peeps++;
  call_out("fake_hb",3);
}

void exit()
{
  ::exit();
  if(this_player() && this_player()->is_player())
    peeps--;
}

int cmd_kitchen(string str)
{
  write("You hear a loud clatter and some swearing come from the kitchen\n"+
        "so you decide now isn't a good time.\n");
  return 1;
}
void fake_hb()
{
  string msg;

  while(remove_call_out("fake_hb")!=-1) ;
  switch(random(8))
  {
    case 0: msg="A winged fairy buzzes past, carrying a tub of butter.\n";
            break;
    case 1: msg="A group of sorcerers murmur among themselves.\n";
            break;
    case 2: msg=
"You overhear someone say: ...I heard he summoned up a salamander, so\n\
  they just sealed him up in there with it rather than let the tower\n\
  be damaged...\n";
            break;
    case 3: msg=
"You overhear someone say: Is there any truth to the rumor that the\n\
  Archmagister is getting a little friendly with a certain sorceress?\n";
            break;
    case 4: msg="Gnome Ann runs past with her frying pan.\n";
            break;
    case 5: msg="You hear a crash from the kitchen.\n";
            break;
    case 6: msg="A halfling slides past you carrying a tray.\n";
            break;
    case 7: msg="A sorcerer sticks some mutton in his beard for later.\n";
            break;
    case 8: msg="An imp hops from beam to beam, carrying cream to a table.\n";
            break;
  }
  tell_room(this_object(),msg);
  if(peeps > 0)
    call_out("fake_hb",20+random(50));
  return;
}

int cmd_menu(string str)
{
  if(query_verb()=="read"  && (!str || str!="menu"))
  {
    notify_fail("Read what?\n");
    return 0;
  }
  write(
"================================================================\n\
==                                                            ==\n\
==     1. Magic Mutton.............................200        ==\n\
==     2. Green Eggs and Ham.......................330        ==\n\
==     3. Goo stew.................................560        ==\n\
==     4. Goop soup................................800        ==\n\
==     5. Ghoulash.................................800        ==\n\
==     6. Nightshade Lemonade......................330        ==\n\
==     7. Strange brew.............................150        ==\n\
==                                                            ==\n\
================================================================\n"
  );
  return 1;
}
int cmd_buy(string str)
{
  int intox;
  int heal;
  int type;
  int cost;
  string msg;
  if(!str)
  {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  switch(str)
  {
    case "1": heal=20;
              intox=6;
              cost=200;
              msg="You order some magic mutton.\n";
              break;
    case "2": heal=30;
              intox=8;
              cost=330;
              msg="You order some green eggs and ham.\n";
              break;
    case "3": heal=40;
              intox=8;
              cost=560;
              msg="You order some goo stew.\n";
              break;
    case "4": heal=50;
              intox=8;
              cost=800;
              msg="You order some goop soup.\n";
              break;
    case "5": heal=50;
              intox=8;
              cost=800;
              msg="You order some ghoulash.\n";
              break;
    case "6": heal=30;
              intox=8;
              cost=330;
              msg="You order some nightshade lemonade.\n";
              type=1;
              break;
    case "7": heal=25;
              intox=10;
              cost=150;
              type=2;
              msg="You order some strange brew.\n";
              break;
    default: write("That item isn't on the menu.\n");
             return 1;
             break;
  }
  switch(type)
  {
    case 0: if(this_player()->query_stuffed() + intox > (int)this_player()->query_level() * 8)
            {
              write("You can't eat that right now.\n");
              return 1;
            }
            break;
    case 1: if(this_player()->query_soaked() + intox > (int)this_player()->query_level() * 8)
            {
              write("You can't drink that right now.\n");
              return 1;
            }
            break;
    case 2: if(this_player()->query_intoxination() > this_player()->query_level()+3)
            {
              write("You are too drunk already.\n");
              return 1;
            }
            break;
  }
  if((int)this_player()->query_money() < cost)
  {
    write("You don't have enough money.\n");
    return 1;
  }
  this_player()->add_money(-cost);
  this_player()->heal_self(heal);
  switch(type)
  {
    case 0: this_player()->eat_food(intox);
            break;
    case 1: this_player()->drink_soft(intox);
            break;
    case 2: this_player()->drink_alcohol(intox);
            break;
  }
  write(msg);
  return 1;
}
