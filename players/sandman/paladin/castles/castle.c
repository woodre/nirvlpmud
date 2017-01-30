
/*
 * Generic castle (4/18/94)
 */

#define CPATH "players/sandman/paladin/castles/"
#define NAME this_player()->query_real_name()
#define CME capitalize(this_player()->query_name())
#define LOCKER "/players/sandman/paladin/locker/locker"

string owner;
string long_desc;
string outer_desc;
string grounds_desc;
int locked;

set_owner(o) { owner = o; }

reset(arg) {
   if(arg)
     return;
   restore_object(CPATH+owner);
}

id(str) { return str == "castle"; }

short() { return "The Castle of "+capitalize(owner); }

long(str) {
   if(str == "castle") {
     if(environment(this_player()) == this_object()) {
       write("That is not here.\n");
       return 1;
     }
     if(!outer_desc) 
       write("The Castle of "+capitalize(owner)+".\n");
     else
       write(outer_desc);
     return 1;
   }
   if(!long_desc)
     write("The Castle of "+capitalize(owner)+".\n");  
   else
     write(long_desc);
   if(locked)
     write("The castle is locked.\n");
   else
     write("The castle is unlocked.\n");
   if(NAME == owner)
     write("Type [castle_help] for a list of commands.\n");
   write("     There is one obvious exit: leave\n");
}

init() {
   add_action("leave","leave");
   add_action("enter","enter");
   add_action("lock","lock");
   add_action("unlock","unlock");
   add_action("set_long","longdesc");
   add_action("set_outer","outerdesc");
   add_action("grounds_desc","groundsdesc");
   add_action("store","store");
   add_action("retrieve","retrieve");
   add_action("list","list");
   add_action("shop","shop");
   add_action("palguild","palguild");
   add_action("church","church");
   add_action("guild","guild");
   add_action("cmdroom","cmdroom");
   add_action("castle_help","castle_help");
}

shop() {
   this_player()->move_player("through a portal#room/shop");
   return 1;
}

palguild() {
   this_player()->move_player("through a portal"+
                      "#players/sandman/paladin/adv_guild");
   return 1;
}

church() {
   this_player()->move_player("through a portal#room/church");
   return 1;
}

guild() {
   this_player()->move_player("through a portal#room/guild");
   return 1;
}

cmdroom() {
   this_player()->move_player("through a portal#"+
                      "players/sandman/paladin/cmd_room");
   return 1;
}

castle_help() {
   cat("/players/sandman/paladin/castles/CHELP");
   return 1;
}

store(str) {
  if(NAME != owner) 
    return;
  LOCKER->store(str); 
  return 1;
}

retrieve() {
  if(NAME != owner) 
    return;
  LOCKER->retrieve(); 
  return 1;
}

list() {
   if(NAME != owner)
     return;
   LOCKER->list();
   return 1;
}

lock() {
  if(NAME != owner) 
    return;
  if(locked) {
    write("Your castle is already locked.\n");
    return 1;
  }
  locked = 1;
  write("Your castle is now locked.\n");
  return 1;
}

unlock() {
  if(NAME != owner) 
    return;
  if(!locked) {
    write("Your castle is not locked.\n");
    return 1;
  }
  locked = 0;
  write("Your castle is now unlocked.\n");
  return 1;
}

leave() {
   if(environment(this_player()) == environment(this_object()))
     return;
   tell_room(environment(this_object()), CME+" arrives.\n");
   move_object(this_player(), environment(this_object()));
   tell_room(this_object(), CME+" leaves the castle.\n");
   this_player()->look();
   return 1;
}

enter() {
   if(environment(this_player()) == this_object())
      return;
   if(locked && NAME != owner) {
     write("The castle is locked.\n");
     return 1;
   }
   tell_room(this_object(), CME+" arrives.\n");
   move_object(this_player(), this_object());
   tell_room(environment(this_object()), CME+" enters the castle.\n");
   this_player()->look();
   return 1;
}

set_long() {
   if(NAME != owner) 
     return;
   input_to("get_long");
   write("Give long description, to end type '**'.\n");
   write("]");
   long_desc = "";
   return 1;
}

get_long(str) {
  if(str == "**") {
    save_object(CPATH+owner);
    write("Ok.\n");
    return 1;
  }
  long_desc = long_desc+str+"\n";
  write("]");
  input_to("get_long");
}

set_outer() {
   if(NAME != owner) 
     return;
   input_to("get_outer");
   write("Give outer long description, to end type '**'.\n");
   write("]");
   outer_desc = "";
   return 1;
}

get_outer(str) {
   if(str == "**") {
     save_object(CPATH+owner);
     write("Ok.\n");
     return 1;
   }
   outer_desc = outer_desc+str+"\n";
   write("]");
   input_to("get_outer");
}

grounds_desc() {
   if(NAME != owner) 
     return;
   input_to("grounds_long");
   write("Give grounds description, to end type '**'.\n");
   write("]");
   grounds_desc = "";
   return 1;
}

grounds_long(str) {
  if(str == "**") {
    save_object(CPATH+owner);
    write("Ok.\n");
    return 1;
  }
  grounds_desc = grounds_desc+str+"\n";
  write("]");
  input_to("grounds_long");
}

query_grounds_desc() { return grounds_desc; }

