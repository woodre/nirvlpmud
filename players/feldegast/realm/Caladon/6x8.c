/*
File: 6x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 10/18/01
Description:
  Barony of Caladon
  Coins can be hidden in the tree here.
*/
#include "defs.h"

inherit ROOM;

int coins;

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  x=6; y=8;
  set_light(1);

  short_desc=GRN+"Forest"+NORM;

  long_desc=
"  Gnarled old trees dot the foothills of the Caladonian countryside.\n\
A particularly gnarled and ugly dwarf tree sits at the top of a low\n\
hill.  To the west you can make out a road and some sort of marker.\n";

  items=({
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
    "tree", "A gnarled and ugly dwarf tree sits at the top of a low hill.  Its\n"+
            "complicated root system is filled with holes and crevices",
    "foothills", "The hills surrounding you are dotted with trees",
    "hills", "The surrounding hills are dotted with trees",
    "hill", "The surrounding hills are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "marker", "A short obelisk about waist-height sits beside the road",
    "holes", "dynamic",
    "hole", "dynamic",
    "crevices", "dynamic",
    "roots", "dynamic",
  });

  dest_dir=({
    PATH+"6x9.c","north",
    PATH+"5x8.c","west",
    PATH+"7x8.c","east",
    PATH+"6x7.c","south",
  });

  restore_object(PATH[1..strlen(PATH)] + "6x8");
  coins += random(200) - 100;
  if(coins < 0) coins = 0;
}

void long(string str)
{
  if(str == "holes" || str == "crevices" || str == "roots" || str == "hole")
  {
    write("You suspect that this would be a good place to hide coins and save\n"+
          "them for a rainy day.  There are already "+coins+" coins hidden there.\n"+
          "You can "+BOLD+"stash"+NORM+" coins or "+BOLD+"raid"+NORM+" coins.\n");
  }
  else ::long(str);
}

void init()
{
  ::init();
  add_action("cmd_stash", "stash");
  add_action("cmd_raid", "raid");
}

int cmd_stash(string str)
{
  int amt;
  if(!str)
  {
    notify_fail("Stash how many coins?\n");
    return 0;
  }

  amt = atoi(str);
  if(amt <= 0)
  {
    notify_fail("Stash how many coins?\n");
    return 0;
  }

  if((int)TP->query_money() < amt)
  {
    notify_fail("You don't have that many coins.\n");
    return 0;
  }

  TP->add_money(-amt);
  coins += amt;

  write("You stash "+amt+" coins in the tree.\n");

#ifdef LOGTREE
  write_file(LOG_PATH + "tree.log", ctime(time()) + " " + pad(TPN,20) + " +"+amt+"\n");
#endif
  save_object(PATH[1..strlen(PATH)] + "6x8");
  return 1;
}

int cmd_raid(string str)
{
  int amt;
  if(!str)
  {
    notify_fail("Raid how many coins?\n");
    return 0;
  }

  amt = atoi(str);
  if(amt <= 0)
  {
    notify_fail("Raid how many coins?\n");
    return 0;
  }

  if(amt > coins)
  {
    notify_fail("There aren't that many coins in the tree.\n");
    return 0;
  }

  if((int)TP->query_money() + amt > 80000)
  {
    write("You can't hold that many coins.\n");
    amt = 80000 - (int)TP->query_money();
  }

  TP->add_money(amt);
  coins -= amt;

  write("You raid "+amt+" coins from the tree.\n");

#ifdef LOGTREE
  write_file(LOG_PATH + "tree.log", ctime(time()) + " " + pad(TPN,20) + " -"+amt+"\n");
#endif
  save_object(PATH[1..strlen(PATH)] + "6x8");
  return 1;
}
  


