#include "../def.h"

#define FRUIT "/players/feldegast/healers/obj/enchanted_fruit.c"
#define STORE "players/feldegast/healers/obj/great_tree"

int fruit,energy;

short() 
{
  return "Tree of Giving";
}

id(str) 
{
  return str=="tree" || str=="tree of giving";
}

long() 
{

  write("Long, powerful branches spread out from the trunk of this enchanted\n"+
        "fruit tree.  Magical, golden fruit grave its limbs.\n");

  if(present(GUILD_ID,TP))
    write("You feel that you can imbue the tree with some of your own\n"+
          "strength to make it grow more fruit.\n");

  write("There are "+fruit+" ripe fruit left.\n");

  if(TP->query_level()>20)
    write(BOLD+"Wiz: There are "+(energy/40)+" unripe fruit left.\n"+NORM);
  save_object(STORE);
}

get() { return 0; }
drop() { return 1; }

reset(arg) 
{
  energy+=5;

  if(arg) return;

  restore_object(STORE);

  if(energy > 40 && fruit < 10)
    fruit+=(energy/=40);

}

init() 
{
  add_action("cmd_pick","pick");
  add_action("cmd_imbue","imbue");
}

cmd_pick(str) 
{
  notify_fail("Pick what?\n");

  if(!str) return 0;

  if(str!="fruit" && str!="fruit from tree") return 0;

  if(!fruit) 
  {
    write("There are no more fruit to pick.\n");
    return 1;
  }

  write("You pluck a ripe magical fruit from the tree.\n");
  say(TPN+" plucks a fruit from the tree.\n");

  TP->add_weight(1);
  move_object(clone_object(FRUIT),TP);
  fruit--;
  save_object(STORE);

  return 1;

}

cmd_imbue(str) 
{
  int x;

  if(!present(GUILD_ID,TP)) return 0;

  notify_fail("Usage: imbue #\n");

  if(!str) return 0;

  sscanf(str,"%d",x);

  if(x<0) 
  {
    write("You attempt to steal energy from the tree of giving, but fail\n"+
          "utterly.\n");
    say(TPN+" attempts to steal energy from the tree of giving.\n");
    return 1;
  }

  if(TP->query_sp()<x) 
  {
    write("You don't have that much energy.\n");
    return 1;
  }

  write("You place both hands upon the trunk of the tree and imbue it\n"+
        "with the strength to grow more magical fruit.\n");
  say(TPN+" places both of "+TP->query_possessive()+" hands upon the trunk of the tree\n"+
      "and seems to glow with a golden light.\n");
  energy+=x;
  save_object(STORE);
  return 1;
}
