 /* A Garbage collector
  This monster will roam around the mud, picking up objects that are:
  1. Light enough for the monster to pick up.
  2. Objects such as flyers or tablets or such that a wizard
     placed in the church to get more popularity.
  
  This monster will _NOT_ pick up objects that are:
  1. Corpses, dispensers, banks, clocks, trashcans, signs,
     computers, notices, boards, lists or monsters.
     
 */
 
inherit "/obj/monster";
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
  set_level(8);
  set_wc(16);
  set_ac(5);
  set_hp(100 + random(100));
  set_al(100);
  set_ep(50000);
  enable_commands();
/* call_out("random_movement", 5); */
}
 
 /* 
  This is the function that is called to make the monster move randomly
  and also calls a function to see if there is anything to be
  picked up or excluded from being picked up
 */
 
random_movement() 
{
  int i, j, k;
  string dir;
  if (!environment()) return 1;
/*
  while(remove_call_out("random_movement") != -1);
  call_out("random_movement",5); 
*/
  
 /*
  Check to see if there is a trash can in the surrounding area to 
  trash all the items that are in the inventory 
 */
 
  if(environment(this_object()))
  if(present("trashcan", environment(this_object()))) {
    trash_all();
  }
 
 /*
  Choose a random number from 0 to 10 and then move in the direction
  that is randomly chosen, some of which are not normally available
  unless trapped in a realm.
 */  
  
  i = random(7);
  if(i == 0) 
  {
    dir = "north";
  }
  else if(i == 1)
  {
    dir = "south";
  }
  else if(i == 2) 
  {
    dir = "east";
  }
  else if(i == 3)
  {
    dir = "west";
  }
  else if(i == 4)
  {
    dir = "up";
  }
  else if(i == 5)
  {
    dir = "down";
  }
  else if(i == 6)
  {
    dir = "leave";
  }
  
  init_command(dir);
 
 /* 
  Call the function to check to see if there is any thing to be picked up
  in the surrounding environment, if so then place it in the inventory
  of this monster for later trashing.
 */
 
  pick_up_things();
 
  /*
  call_out("random_movement", 5);
  */
  return 1;
}
 
 /*
  This is the function to trash all the objects in the inventory of
  this monster.  This is only necessary if there are objects in the
  inventory of this monster.
 */
 
trash_all()
{
  object items;
  string name;
  int i;
  
  items = all_inventory(this_object());
  for(i = 0; i < sizeof(items); i++)
  {
    name = items[i]->short();
    say("You see the garbageman open the lid of the trashcan and throw\n");
    say(name + " into the trash.\n");
    destruct(items[i]);
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
  object ob, eto;
  int i;

/* hmm.  i don't think we need this, just changed it from !this_object()
    tho :)  [5.23.01] Vertebraker */
  if(this_object())
  eto = environment(this_object());  
  if(!eto) return 1;

  ob = first_inventory(eto);
  
  while(ob)
  {
  /*
    Exclude those objects which have an id which is not one that is
    wanted to be picked up to be trashed.  Listed one on a line
    so that one might add/comment out one w/o major problems 
  */
  
    if(!living(ob) && 
       ob != present("computer", eto) &&
       ob != present("notice", eto) &&
       ob != present("list", eto) &&
       ob != present("trashcan", eto) &&
       ob != present("sign", eto) &&
       ob != present("bank", eto) &&
       ob != present("corpse", eto) &&
       ob != present("board", eto) &&
       ob != present("dispenser", eto) &&
       ob != present("castle", eto) &&
       ob != present("tree",eto) &&
       ob != present("santa",eto) &&
       ob != present("lights",eto) &&
       ob != present("amulet",eto) &&
       ob != present("statue", eto) &&
      !ob->query_auto_load() &&
       ob->get() &&
       !ob->is_castle())
    {
      say("The garbage man carefully picks up a " + ob->short() + ".\n");
      move_object(ob, this_object());

      ob = next_inventory(eto);
    }
    else
    {
      ob = next_inventory(ob);
    }
  }
  return 1;
}

heart_beat()
{
  if(random(2)) random_movement();
}
