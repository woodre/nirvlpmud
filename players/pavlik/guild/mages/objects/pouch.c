#include <ansi.h>

#define TP this_player()

#define ids ({"silver_needle","onyx_powder","heartstone","sulfur_powder",\
              "granite_powder","tespian orb","leather cord","gemstone",\
              "amber rod","platinum_mirror","spider","light feather",\
              "orb of souls"})

inherit "/obj/treasure";

reset(arg)
{
  if(arg) return;
  
  set_id("mage's component pouch");
  set_alias("component pouch");
  SetMultipleIds(({"pouch", "mage component pouch"}));
  set_short(HIM+"A mage's component pouch"+NORM);
  set_long("\
A large pocket which can hold a variety of spell components\n\
and trinkets.\n");
  set_weight(1);
  set_value(750);
}

init()
{
  add_action("cmd_pouch","pouch");
  add_action("cmd_unpouch","unpouch");
}

long()
{
  int lc, sn, op, hs, sp, gp, to, gem, ar, pm, spiders, os, lf;
  string *inv;
  int s;
  inv = all_inventory(this_object());
  s=sizeof(inv);
  while(s--)
  {
    if(inv[s]->id("silver_needle")) sn ++;
    if(inv[s]->id("onyx_powder")) op ++;
    if(inv[s]->id("heartstone")) hs ++;
    if(inv[s]->id("sulfur_powder")) sp ++;
    if(inv[s]->id("granite_powder")) gp ++;
    if(inv[s]->id("tespian orb")) to ++;
    if(inv[s]->id("leather cord")) lc ++;
    if(inv[s]->id("gemstone")) gem ++;
    if(inv[s]->id("amber rod")) ar ++;
    if(inv[s]->id("platinum_mirror")) pm ++;
    if(inv[s]->id("spider")) spiders ++;
    if(inv[s]->id("orb of souls")) os ++;
    if(inv[s]->id("light feather")) lf ++;
  }
  
  write("\n");
  
  write("Silver Needles:   "+sn+"\n");
  write("Onyx Powder:      "+op+"\n");
  write("Heartstones:      "+hs+"\n");
  write("Sulfur Powder:    "+sp+"\n");
  write("Granite Powder:   "+gp+"\n");
  write("Tespian Orbs:     "+to+"\n");
  write("Leather Cords:    "+lc+"\n");
  write("Gemstones:        "+gem+"\n");
  write("Amber Rods:       "+ar+"\n");
  write("Platinum Mirrors: "+pm+"\n");
  write("Spiders:          "+spiders+"\n");
  write("Orbs of Souls:    "+os+"\n");
  write("Light Feathers:   "+lf+"\n");
  
  write("\n");
  write("You can \"pouch\" or \"unpouch\" components.\n");
}
  

cmd_pouch(str)
{
  object obj;
  if(!str)
  {
    write("pouch what?\n");
    return 1;
  }
  if(!(obj=present(str, TP))){
    write("You don't have \""+str+"\"\n");
    return 1;
  }
  else
  {
    int s;
    int x;
    s = sizeof(ids);
    while(s--)
      if(obj->id(ids[s]))
        x = 1;
    if(!x)
    {
      write("That is not a valid component.\n");
      return 1;
    }
    TP->add_weight(-(obj->query_weight()));
    move_object(obj, this_object());
    write("You pouch \""+obj->short()+"\"\n");
    return 1;
  }
}

cmd_unpouch(str)
{
  object obj;
  if(!str)
  {
    write("unpouch what?\n");
    return 1;
  }
  
  if(!(obj = present(str, this_object()))){
    write("You don't have \""+str+"\" in the pouch.\n");
    return 1;
  }
  
  else {
    if(!TP->add_weight(obj->query_weight()))
    {
      write("You can't carry anymore.\n");
      return 1;
    }
    move_object(obj, TP);
    write("You unpouch \""+obj->short()+"\"\n");
    return 1;
  }
}

remove_object() {
  int i;
  object *inv;

  if( !environment() )
    return;

  inv = all_inventory(); 
  for( i=0; i < sizeof(inv); i++ )
    move_object( inv[i], environment() );
}
