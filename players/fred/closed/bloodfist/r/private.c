#include "/room/clean.c"
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
string custom_desc, owner;
static string new_desc;      /* temp var used in changing long desc */
static int guard_out;        /* if a player is invited */
static object guard, chest;  /* room guard and chest */

reset(arg){

  if(!present("f_bf_gem_tc", this_object()))
  {
    chest = clone_object("/players/fred/closed/bloodfist/obj/gem_chest.c");
    move_object(chest, this_object());
  }

  if(arg) return;

  set_light(1);
  set_no_clean(1);
  custom_desc = "";
  new_desc = "";
  owner = this_player()->query_real_name();
  restore_object(ROOM+this_player()->query_real_name());
}

short(){ 
  if(owner)
    return capitalize(owner)+"'s room within the encampment";
  else
    return "A room within the encampment";
}

long(){
  if(custom_desc != "")
    write(custom_desc);
  else
    write(
"This is a private room within the encampment.  It has been dug out of\n"+
"the side of the mountain and is very cozy.  This is your personal room\n"+
"that others can not enter unless you want them to.  You may do with it\n"+
"as you see fit.\n");
write("    There is one obvious exit: west\n");
}

void init(){
  add_action("new_desc", "new_desc");
  add_action("save_room", "save_room");
  add_action("invite", "invite");
  add_action("remove", "remove");
  add_action("west", "west");
  add_action("clear_desc","clear_desc");
  if(!present("f_bf_gem_tc", this_object()))
  {
    chest = clone_object("/players/fred/closed/bloodfist/obj/gem_chest.c");
    move_object(chest, this_object());
  }
}

string query_owner(){ return owner; }
int query_bf_priv_room(){ return 1; }

status new_desc()
{
  write("Use ** to end the description and use ~q to cancel.\n"+
    "> ");
  input_to("next_line");
  return 1;
}

status clear_desc(string str)
{
  custom_desc = "";
  new_desc = 0;
  new_desc = "";
  save_object(ROOM+owner);
  write("You clear your room description.\n");
  return 1;
}

status next_line(string str)
{
  if(str == "**")
  {
    custom_desc = new_desc;
    save_object(ROOM+owner);
    write("You finish making changes to your room.\n");
    return 1;
  }
  else if(str == "~q")
  { 
    new_desc = 0;
    write("You decide not to make changes to your room.\n");
    return 1;
  }
  new_desc += str;
  new_desc += "\n";
  write("> ");
  input_to("next_line");
  return 1;
}

status save_room()
{
  write("Saving room information...\n");
  save_object(ROOM+this_player()->query_real_name());
  return 1;
}

void guard_return(object here)
{
  if(!here) return;
  if(!guard_out) return;
  if(!present(owner, here) && find_player(owner))
    tell_object(here, "The invitation was not accepted in time.\n");
  else if(!present(owner, here)){}
  else if(!guard)
    tell_room(here, "Something happened to the guard.\n");
  else {
    tell_room(environment(guard),
      "\nA guard says, \"Alright, well... I'm heading back.\"\n\n"+
      "A guard leaves...\n");
    tell_room(here, "The invitation was not accepted in time.\n");
    move_object(guard, "/room/void.c");
    guard->dest();
  }
  guard_out = 0;
}

void accepted(){ 
  guard_out = 0;  
  move_object(previous_object(), "/room/void.c"); 
}

void declined(string name)
{
  if(present(owner, this_object()))
    tell_room(this_object(), "The invitation was declined by "+name+".\n");
  else if(!present(owner, this_object()) && find_player(owner))
    tell_object(this_object(), "The invitation was declined by "+name+".\n");
  else if(!present(owner, this_object())){}
  guard_out = 0;
  move_object(previous_object(), "/room/void.c");
}

status invite(string name)
{
  int cost;
  object who, loc;
  string g;
  if(!name)
    return (notify_fail("Who do you want to invite?\n"), 0);
  if((string)this_player()->query_real_name() != owner) return 0;
  if(!(who = find_player(name)))
    return (notify_fail("That person is not online to invite.\n"), 0);
  if(!(loc = environment(who)))
    return(notify_fail(capitalize(name)+" does not have an environment.\n"),0);
  if(environment(this_player()) == loc)
    return (notify_fail(capitalize(name)+" is already here.\n"), 0);
  if(guard_out)
    return (notify_fail("The guard is already out for you.\n"), 0);
  if(sscanf(file_name(environment(who)), "players/fred/closed/bloodfist%s", g))
    cost = 0;
  else {
    cost = 50;
    if((string)loc->realm() == "NT" || loc->query_property("no_teleport"))
      return (notify_fail(capitalize(name)+" is in a non-teleport area.\n"),0);
  }
  if((int)this_player()->query_sp() < cost)
    return (notify_fail("You do not have the sp to invite someone.\n"), 0);

  guard = clone_object("/players/fred/closed/bloodfist/NPC/room_guard.c");
  move_object(guard, loc); 
  guard->invite(who, this_object());
  write("You invite "+who->query_name()+" into the room.\n");
  tell_room(loc, "\nA guard arrives...\n"+
    "\nA guard says, \""+who->query_name()+", I have an invitation from "+
    this_player()->query_name()+".\"\n"+
    "              \"Would you like to be escorted to "+this_player()->POS+
    " room?\"\n");
  tell_object(who, "                       'accept' or 'decline'\n");

  guard_out = 1;
  call_out("guard_return", 20, this_object());
  return 1;
}

status remove(string str)
{
  object who;
  if(!(who = present(str, this_object())))
  {
    notify_fail("That person is not here to remove.\n");
    return 0;
  }
  if(!living(who))
  {
    notify_fail("You can not have "+str+" removed.\n");
    return 0;
  }
  write("You summon a guard into the room.\n");
  tell_room(this_object(),
    this_player()->query_name()+" summons a guard into the room.\n",
    ({ this_player() }));
  tell_room(this_object(),
    "A guard blindfolds "+capitalize(str)+" and escorts "+who->OBJ+
    " to the village church.\n", ({ who }));
  tell_object(who,
    "A guard blindfolds you and escorts you to the village church.\n");
  tell_room("/room/church.c", 
    "A guard escorts "+who->query_name()+" into the room.\n");
  who->move_player("west#/room/church.c");
  tell_room("/room/church.c", "A guard leaves south.\n");
  return 1;
}

status west()
{
  if((string)this_player()->query_guild_name() != "bloodfist")
  {
    write("A guard escorts you to the church.\n");
    this_player()->move_player("west#/room/church.c");
    return 1;
  }
  this_player()->move_player("west#/players/fred/closed/bloodfist/r/hall.c");
  return 1;
}

