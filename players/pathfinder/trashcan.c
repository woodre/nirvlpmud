/* A Trashcan */
/* This is a object which can remove an object from a player and */
/* destroy it, removing it from the game, and lessening the impact */
/* of lag on the mud. */
/* This will check to see if the object can be dropped or not and */
/* if it unable to be dropped will let the player know */
 
#define TP this_player()
#define CAP capitalize
 
int items_trashed;  /* keeps a count of the number of items trashed */
 
id(str) 
{ 
  return str == "trashcan" ||
         str == "garbage_can" ||
         str == "trash" ||
         str == "wastebasket" ||
         str == "shredder";
}
 
short() 
{
  return "A Trashcan";
}
 
long() 
{
  write("This is a trashcan.  It is about 3 feet tall and is cylindrical\n"+
        "in shape.  It looks like it is fairly sturdy.\n"+
        "You can put things that you have no need to use in here, along\n"+
        "with items that are useless.\n"+
        "Place on its lid is a sticker -- 'Keep Nirvana Clean!'\n" +
        "And help keep lag down!  Dispose of unused items!\n" +
        "To throw an item into the trashcan, type 'trash <item>'\n");
  return 1;
}
 
reset(arg)
{
  if(arg) return;
  items_trashed = 0;        /* sets to 0 the number of items trashed */
}
 
init() 
{
  add_action("trash_item", "trash");
  add_action("count_items", "count_trash");
}
 
/* displays the number of items that people have trashed so */
/* far during this reboot */
 
count_items() 
{
  write("The Number of Items trashed so far this reboot is: "+
        items_trashed+".\n");
  return 1;
}
 
/* destroy the item the player would like to get rid of */
 
trash_item(str)
{
  object item;
  if(!str)
  {
    write("What would you like to trash?\n");
    say(CAP(TP->query_name())+" tries to throw something away but fails.\n");
    return 1;
  }
 
/* check to see if the player has the item they want to get rid of */ 
 
  if(!present(str, TP))
  {
    write("You don't have a "+str+".\n");
    return 1;
  }
  
/* player has the item they want to get rid of */
 
  item = present(str, TP);
  
/* check to see if the player can drop the item they want to */
/* get rid of */
 
   if(item->drop() ||
  !item->short() ||
  !item->get() ||
   living(item) ||
  !item->query_weight())
  {
    write("You cannot trash that!\n");
    return 1;
  }
  
/* Ok, they can get rid of the item they want to get rid of */
/* move the object off the player and then destroy the object */
 
/* moves the object to a room made JUST for holding objects that fail */
/* to be dested */
 
  move_object(item, "/room/void");
  if(item->short())
  write("Ok, you trash a "+item->short()+".\n");
  say(CAP(TP->query_name())+" throws something away.\n");
  destruct(item);
  items_trashed++;
  return 1;
}

