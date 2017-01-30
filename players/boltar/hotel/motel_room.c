#define NUMBER_OF_ITEMS 6
 int inv_no,done,shield, notin;
 string filename,long_dsc,owner_name;
int lighton;
init() {
     if (!done) {
   owner_name="nobody";
     done = 1;
    }
  add_action("on","lock");
  add_action("invite","invite");
  add_action("off","unlock");
  add_action("south","south");
  add_action("clear_long","clear");
  add_action("light_switch","switch");
#ifndef __LDMUD__
  add_action("add_to_long"); add_xverb("@");
#else
  add_action("add_to_long", "@", 3);
#endif
  if(this_player()->query_real_name() != owner_name && shield == 1) {
    write(capitalize(owner_name) + " has the room locked.\n");
    write("You are transported to the lobby.\n");
  this_player()->move_player("after tring to enter the room#players/boltar/hotel/motel");
 }
 }
static on() {
   shield = 1;
   write("Room locked.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != owner_name) {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   write("The room is unlocked.\n");
   return 1;
   }

 short() {
   return capitalize(owner_name) + "'s motel room";
  }
 long() {
    if (!long_dsc)
   {
   write("You are in " + capitalize(owner_name) +"'s motel room.\n");
   write ("Use 'clear' to clear room description.\n");
   write ("Use '@desc' to add a line to room description.\n");
   write ("There is a light switch on the wall near the door.\n");
   }
    if(long_dsc) write (long_dsc);
   if (shield == 1) write ("The door is locked to others.\n");
   if (shield == 0 ) write ("The door is unlocked.\n");
 write("The only exit is south.\n");
  }
south() {
  call_other(this_player(), "move_player", "south#players/boltar/hotel/motel.c");
  return 1;
}
set_owner(str){
  set_light( 1);
    owner_name = str;
    done = 1;
        return 1;
   }
add_to_long(str){
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
     return 0;
     }
if (!long_dsc) long_dsc = "";
  long_dsc = long_dsc + str;
  long_dsc = format(long_dsc, 78);
  return 1;
}
clear_long(){
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
     return 0;
     }
   long_dsc = "";
   return 1;
   }
invite(str) {
object guest;
    guest=find_player(str);
  if(!guest)
   {
   write(str+" is not currently logged in.\n");
   return 1;
   }
  if(file_name(environment(guest)) != "players/boltar/hotel/motel")
    {
   write(str+" is not in the lobby.\n");
   return 1;
   }
  if (shield == 1)
   {
    write("You must unlock the door first.\n");
    return 1;
   }
  move_object(guest,this_object());
   write(str+" has been allowed to enter.\n");
   tell_object(guest, " you are pushed into the portal by some unseen force.\n");
   write(str + " arrives.\n");
   return 1;
}
light_switch() {
 write("You flip the switch.\n");
 say(this_player()->query_name()+" reaches for the light switch\n");
 if(lighton) {
  move_object(this_object(), "/players/boltar/hotel/holddark");
   call_other("players/boltar/hotel/holddark","lights",-1*set_light(0));
   set_light(-1);
   lighton = 0;
   say("The lights go out.\n");
   if(this_player()->query_level() > 200)  write("lights at "+set_light(0)+"\n");
   write("The lights go out.\n");
 }
 else {
    move_object(this_object(), "/players/boltar/hotel/holdlight");
   call_other("players/boltar/hotel/holdlight","lights",-1*set_light(0));
   set_light(1);
   lighton = 1;
   say("The lights come on.\n");
    if(this_player()->query_level() > 200)  write("lights at "+set_light(0)+"\n");
   write("The lights come on.\n");
 }
 return 1;
}
