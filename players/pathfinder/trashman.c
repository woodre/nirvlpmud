/* A Garbage collector
  This monster will roam around the mud, picking up objects that are:
  1. Light enough for the monster to pick up.
  2. Objects such as flyers or tablets or such that a wizard
     placed in the church to get more popularity.
  
  This monster will _NOT_ pick up objects that are:
  1. Corpses, dispensers, banks, clocks, trashcans, signs,
     computers, notices, boards, lists or monsters.
     
*/
 
inherit "obj/monster";
#define CAN "/players/pathfinder/trashcan.c"
 
reset(arg) 
{
  ::reset(arg);
  if(arg) return 0;
  set_name("garbageman");
  set_alias("garbage man");
  set_short("A garbageman");
  set_long(
   "You peer at the garbage man.  He stinks from picking up all the\n" +
   "garbage the people of nirvana, including you, have left about to\n" +
   "to be cleaned up.  He has various things on him.  Some might be\n" +
   "worth killing him for.\n");
  set_wc(16);
  set_ac(5);
  set_hp(100 + random(100));
  set_al(100);
  set_ep(50000);
  enable_commands();
  call_out("random_movement", 5);  /* make him try to move every 5 seconds */
}
 
/* 
  This is the function that is called to make the monster move randomly
  and also calls a function to see if there is anything to be
  picked up or excluded from being picked up
*/
 
random_movement() 
{
  int i, j, k;
  
/*
  Check to see if there is a trash can in the surrounding area to 
  trash all the items that are in the inventory 
*/
 
  if(present("trashcan", environment(this_object()))) {
    trash_all();
  }
 
/*
  Choose a random number from 0 to 10 and then move in the direction
  that is randomly chosen, some of which are not normally available
  unless trapped in a realm.
*/  
  
  i = random(11);
  if(i == 0) 
  {
    command("north");
  }
  else if(i == 1)
  {
    command("south");
  }
  else if(i == 2) 
  {
    command("east");
  }
  else if(i == 3)
  {
    command("west");
  }
  else if(i == 4)
  {
    command("northeast");
  }
  else if(i == 5)
  {
    command("northwest");
  }
  else if(i == 6) 
  {
    command("southeast");
  }
  else if(i == 7)
  {
   command("southwest");
  }
  else if(i == 8) 
  {
    command("up");
  }
  else if(i == 9)
  {
    command("down");
  }
  else if(i == 10)
  {
    command("leave");
  }
  
/* 
  Call the function to check to see if there is any thing to be picked up
  in the surrounding environment, if so then place it in the inventory
  of this monster for later trashing.
*/
 
  pick_up_things();
  
  call_out("random_movement", 5);
}
 
/*
  This is the function to trash all the objects in the inventory of
  this monster.  This is only necessary if there are objects in the
  inventory of this monster.
*/
 
trash_all()
{
  object ob, temp;
  string name;
  
  ob = first_inventory(this_object());
  while(ob)
  {
    temp = ob;
    ob = next_inventory(this_object());
    name = temp->query_short();
    say("You see the garbageman open the lid of the trashcan and throw\n");
    say(name + " into the trash.\n");
    destruct(temp);
  }
  return 1;
}
 
/*
  This function will check for all the objects in a room and put the objects
  which are not wished to be picked up into the monsters inventory so that
  they can be destructed
*/
 
pick_up_things()
{
  object ob, temp;
  
  ob = first_inventory(environment(this_object()));
  while(ob) 
  {
  /*
    Exclude those objects which have an id which is not one that is
    wanted to be picked up to be trashed.  Listed one on a line
    so that one might add/comment out one w/o major problems 
  */
    if(ob->is_living() || 
        ob->is_npc() ||
        ob->is_kid() ||
      ob->is_player() ||
       ob->query_name() == "computer" ||
       ob->id() == "computer" ||
       ob->query_name() == "notice" ||
       ob->id() == "notice" ||
       ob->query_name() == "list" ||
       ob->id() == "list" ||
       ob->query_name() == "trashcan" ||
       ob->id() == "trashcan" ||
       ob->query_name() == "sign" ||
       ob->id() == "sign" ||
       ob->query_name() == "bank" ||
       ob->id() == "bank" ||
       ob->query_name() == "corpse" ||
       ob->id() == "corpse" ||
       ob->query_name() == "castle" ||
       ob->id() == "castle" ||
       ob->query_name() == "board" ||
       ob->id() == "board")
    {
    /* do nothing because the item is excluded */
    }
    else
    {
      temp = ob;
      say("The garbageman carefully picks up a " + temp->short() + ".\n");
      move_object(temp, this_object());
    }
    ob = next_inventory(environment(this_object()));
  }
  return 1;
}
