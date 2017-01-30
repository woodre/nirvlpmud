#include "def.h"
#define SLOTS 5

string owner_name;
string *ob_file;
string *ob_arg;

int next_available();
void clear_slot(int p);
object get_item(int f);

void set_owner_name(string str) {
  owner_name=str;
  restore_object(STORAGEPATH+owner_name);
}

string short() {
  return CYN+capitalize(owner_name)+"'s room"+NORM;
}

void long() {
  write(
"  This is a simple cell in the east wing of the Healer hall.\n"+
"In the middle of the room is a narrow bed with a cotton blanket\n"+
"on it.  A brown throw rug is in the middle of the floor.  A\n"+
"large chest of drawers is in the corner next to the window.\n"
  );
  if((string)TP->query_real_name()==owner_name)
    write("Commands: list, withdraw, deposit\n");
  write("\tThere is one obvious exit: west\n");
}

void reset(int arg) {
  if(arg) return;
  set_light(1);
  ob_file = allocate(SLOTS);
  ob_arg = allocate(SLOTS);
}

void init() {
  add_action("cmd_out","west");
  if((string)TP->query_real_name()==owner_name) {
    add_action("cmd_list","list");
    add_action("cmd_deposit","deposit");
    add_action("cmd_withdraw","withdraw");
  }
}

int cmd_out() {
  TP->move_player("west#"+ROOMPATH+"east_hall");
  return 1;
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
    write("Your chest is full.\n");
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

  save_object(STORAGEPATH+owner_name);


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
  save_object(STORAGEPATH+owner_name);
  return 1;
}
  
int cmd_list(string str)
{
  int i;
  object current;
  write("Your storage chest contains the following items:\n");
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
 
