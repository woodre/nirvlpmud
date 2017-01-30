/*
File: storage.c
Author: Feldegast @ nirvana.mudservices.com
Date: 5/30/01
Description:
  A common locker room for healers to use, with 12 slots.
*/

#include "def.h"

#define SAVE_FILE "players/feldegast/healers/rooms/storage"

#define SLOTS 12

inherit ROOM;

int next_available();
void clear_slot(int p);
object get_item(int f);

string *ob_file;
string *ob_arg;


void reset(int arg)
{
  if(arg) return;
  set_light(1);
  set_no_teleport(1);
  short_desc = AREANAME;
  long_desc=
"  This is a small, but well-organized storage room.  A row of\n\
cabinets are to the left and right of the door, and mahogany shelves\n\
ascend the walls.  A sign is prominently placed on the wall opposite\n\
the door.\n\
Commands: list, withdraw, deposit\n";
  items=({
    "room", "reflexive", 
    "cabinets", "The cabinets are spacious, and well-maintained",
    "door", "A simple wooden door leads out",
    "shelves", "The shelves are made out of mahogany",
    "sign", "The sign has neat lettering on it that you can "+BOLD+"read"+NORM,
  });
  dest_dir = ({
    ROOMPATH + "workshop", "south",
  });
  ob_file = allocate(SLOTS);
  ob_arg = allocate(SLOTS);
  restore_object(SAVE_FILE);
}

void init()
{
  ::init();
  add_action("cmd_read", "read");
  if(present(GUILD_ID, TP))
  {
    add_action("cmd_withdraw", "withdraw");
    add_action("cmd_deposit", "deposit");
    add_action("cmd_list", "list");
  }
}

int cmd_read(string str)
{
  if(str=="sign")
  {
    write(
      "\tThis is a public storage facility.  You may leave items\n"+
      "\there for other players to use, or you may take an item if\n"+
      "\tyou are in need of it.  Please do not abuse the generosity\n"+
      "\tof others.\n"+
      "\t\t\t-Feldegast\n"
    );
    say(TPN+" reads a sign.\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}

int cmd_deposit(string str)
{
  object ob;
  string junk;
  int slotnum;

  if(!str) 
  {
    notify_fail("Deposit what?\n");
    return 0;
  }

  slotnum = next_available();
  if(slotnum == -1)
  {
    write("The storage room is full.\n");
    return 1;
  }

  ob = present(str, this_player());
  if(!ob || !((int)ob->short()))
  {
    notify_fail("You do not possess a "+str+".\n");
    return 0;
  }

  if((int)ob->query_save_flag() && (int)ob->query_save_flag() != 3)
  {
    write("You cannot save that item here.\n");
    return 1;
  }

  /* Get the file name. */
  if(sscanf(file_name(ob), "%s#%s", ob_file[slotnum], junk) != 2)
    ob_file[slotnum] = file_name(ob);

  /* Cannot save generic items. */
  if(member_array(ob_file[slotnum],
    ({ "obj/weapon",
       "obj/armor",
       "obj/armour",
       "obj/container",
       "obj/generic_heal",
       "obj/treasure" })) != -1)
  {
    write("You cannot save that item here.\n");
    ob_file[slotnum] = 0;
    return 1;
  }

  if((int)ob->drop())
  {
    write("You cannot drop that item.\n");
    ob_file[slotnum] = 0;
    return 1;
  }

  /* Get various locker specific values */
  ob_arg[slotnum] = (string)ob->locker_arg();
  ob_arg[slotnum] += "$" + (int)ob->query_hits();
  ob_arg[slotnum] += "$" + (int)ob->query_misses();

  /* Get rid of the item. */
  TP->add_weight(-((int)ob->query_weight()));
  move_object(ob, this_object());

  write("You store: "+(string)ob->short()+".\n");
  say(TPN+" stores: "+(string)ob->short()+".\n");

  destruct(ob);

  save_object(SAVE_FILE);


  return 1;
}

int cmd_withdraw(string str)
{
  object ob;
  int slotnum;
  int i;
  slotnum = atoi(str);
  if(slotnum < 1 || slotnum > SLOTS)
  {
    write("There is no item in that slot.\n");
    return 1;
  }
  /* 1-12 to 0-11 */
  slotnum--;

  /* Handles cloning and initialization. */
  ob = get_item(slotnum);
  if(!ob) return 1;

  if( !((int)TP->add_weight( (int)ob->query_weight() )) )
  {
    write("It is too heavy for you to carry.\n");
    destruct(ob);
    return 1;
  }

  /* Move everything down one slot so there're no empty spaces. */
  for(i = slotnum; i < sizeof(ob_file)-1; i++)
  {
    ob_file [i] = ob_file [i+1];
    ob_arg  [i] = ob_arg  [i+1]; 
  }

  clear_slot(SLOTS-1);

  move_object(ob, TP);
  write("You withdraw a "+(string)ob->short()+".\n");
  say(TPN+" withdraws a "+(string)ob->short()+".\n");
  return 1;
}
  
int cmd_list(string str)
{
  int i;
  object current;
  write("The storage room contains the following items:\n");
  for(i = 0; i < SLOTS; i++)
  {
    if(ob_file[i])
      current = get_item(i);
    if(current)
      write(pad((i+1)+". ", 4)+(string)current->short()+"\n");
    else
      write((i+1)+".\n");
    destruct(current);
  }
  return 1;
}



int next_available()
{
  int i, size;
  size = sizeof(ob_file);
  for(i = 0; i < size; i++)
    if(!ob_file[i]) return i;
  return -1;
}

void clear_slot(int p)
{
  ob_file[p] = 0;
  ob_arg[p] = 0;
}

mixed get_item(int foo)
{
  object ob;
  string args;
  int hits;
  int misses;

  int err;

  if(err = catch( ob = clone_object(ob_file[foo]) ) )
  {
    write("An error has occured with that item.  It has been logged and removed from storage.\n");
    write_file(DEBUG_FILE, ctime(time())+" Storage Error: ["+TPN+"] "+ob_file[foo]+" ("+ob_arg[foo]+")\n");
    clear_slot(foo);
    return 0;
  }

  if(sscanf(ob_arg[foo], "%s$%d$%d", args, hits, misses) != 3)
  {
    write("An error has occured with that item.  It has been logged and removed from storage.\n");
    write_file(DEBUG_FILE, ctime(time())+" Storage Error: ["+TPN+"] "+ob_file[foo]+" ("+ob_arg[foo]+")\n");
    clear_slot(foo);
    return 0;
  }

  ob->locker_init(args);
  ob->set_hits(hits);
  ob->set_misses(misses);
  
  return ob;
}
      
