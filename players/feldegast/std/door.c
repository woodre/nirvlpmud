/*
Generic door
File: door.c
Author: Feldegast@Nirvana
Description:
  A generic door that can be synched to another door in a different
room.  Supports opening and closing, locks and keys, lockpicking, and
traps.
*/

mixed destination;
object synched;
string *ids;
string open_desc;
string close_desc;
string exit; /* Cardinal direction such as north,west,east,south,up,down */

int open;
int locked;
int trapped;

string key; /* The id of the object that will unlock this. */

/* Difficulty of picking lock, 1 being easiest, 100 being impossible */
int difficulty; 

int trap_dmg;
string trap_msg;
int trap_chance;

void reset(int arg)
{
  if(arg) return;
  ids=({ "door" });
}

void init()
{
  add_action("cmd_enter","enter");
  add_action("cmd_open","open");
  add_action("cmd_close","close");
  add_action("cmd_unlock","unlock");
  add_action("cmd_lock","lock");
  if(exit) add_action("cmd_enter",exit);
}

void long()
{
  if(open)
    write(open_desc);
  else
    write(close_desc);

  if(open)
    write("It is open.\n");
  else
    if(locked)
      write("It is locked.\n");
    else 
      write("It is closed.\n");
}

int id(string str)
{
  int i,size;
  size=sizeof(ids);
  for(i=0; i < size; i++)
    if(str==ids[i])
      return 1;
  return 0;
}

void add_id(string arg) { ids+=({ arg }); }
void set_open_desc(string arg) { open_desc=arg; }
void set_close_desc(string arg) { close_desc=arg; }
void set_exit(string arg) { exit=arg; }
void set_synched(object ob) { synched=ob; }

void set_open(int arg)
{
  open=arg;
}

void set_locked(int arg)
{
  locked=arg;
}

void set_key(string str) { key=str; }
void set_trapped(int arg){ trapped=arg; }
void set_difficulty(int arg) { difficulty=arg; }
void set_trap_msg(string arg) { trap_msg=arg; }
void set_trap_dmg(int arg) { trap_dmg=arg; }

void set_destination(mixed arg) { destination=arg; }

object set_partner(mixed ob,mixed env) {
  if(stringp(ob)) {
    if(stringp(env)) {
      call_other(env,"???");
      env=find_object(env);
    }
    synched=present(ob,env);
  }
  else
    synched=ob;
  return synched;
}

int query_door() { return 1; }
int get() { return 0; }
string query_key() { return key; }
string query_open_desc() { return open_desc; }
string query_close_desc() { return close_desc; }
string query_exit() { return exit; }
object query_synched() { return synched; }
int query_open() { return open; }
int query_locked() { return locked; }
int query_trapped() { return trapped; }
int query_difficulty() { return difficulty; }
string query_trap_msg() { return trap_msg; }
int query_trap_dmg() { return trap_dmg; }
mixed query_destination() { return destination; }

int synch()
{
  if(synched)
  {
    synched->set_open(open);
    synched->set_locked(locked);
    return 1;
  }
  else
    return 0;
}

int cmd_open(string str)
{
  if(!str || !id(str))
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(open)
  {
    notify_fail("It is already open.\n");
    return 0;
  }
  if(locked)
  {
    notify_fail("It is locked.\n");
    return 0;
  }
  open=1;
  synch();
  write("You open the "+str+".\n");
  say((string)this_player()->query_name()+" opens the "+str+".\n");
  return 1;
}  

int cmd_close(string str)
{
  if(!str || !id(str))
  {
    notify_fail("Close what?\n");
    return 0;
  }
  if(!open)
  {
    notify_fail("It is already closed.\n");
    return 0;
  }
  if(locked)
  {
    notify_fail("It is locked.\n");
    return 0;
  }
  open=0;
  synch();
  write("You close the "+str+".\n");
  say((string)this_player()->query_name()+" closes the "+str+".\n");
  return 1;
}  

int cmd_enter(string str)
{
  
  if(query_verb()=="enter" && (!str || !id(str)))
  {
    notify_fail("Enter what?\n");
    return 0;
  } else str=ids[0];

  if(!open)
  {
    write("It's closed.\n");
    return 1;
  }
  say((string)this_player()->query_name()+" enters the "+str+".\n");
  move_object(this_player(),destination);
  command("look",this_player());
  say((string)this_player()->query_name()+" enters through the "+str+".\n");
  return 1;
}

int cmd_lock(string str)
{
  if(!str || !id(str))
  {
    notify_fail("Lock what?\n");
    return 0;
  }
  if(locked)
  {
    notify_fail("It is not unlocked.\n");
    return 0;
  }
  if(!present(key,this_player()))
  {
    notify_fail("You do not possess the key.\n");
    return 0;
  }

  locked=1;
  synch();
  write("You lock the "+str+".\n");
  say((string)this_player()->query_name()+" locks the "+str+".\n");
  return 1;
}

int cmd_unlock(string str)
{
  if(!str || !id(str))
  {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(!locked)
  {
    notify_fail("It is already unlocked.\n");
    return 0;
  }
  if(!present(key,this_player()))
  {
    notify_fail("You do not possess the key.\n");
    return 0;
  }
  locked=0;
  synch();
  write("You unlock the "+str+".\n");
  say((string)this_player()->query_name()+" unlocks the "+str+".\n");
  return 1;
}

