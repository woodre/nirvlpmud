/*originally coded by boltar adapted to fit the needs for the honeymoon suites */
#include "/players/dreamspeakr/closed/ansi.h"
#define MAX_GUESTS 40
#define ROOM_COST 1000
string guests;
int full,done;
object box;
int is_done,guest_no,guest_count;
id(str) { return str == "lodge" || str == "desk"; }
init() {
    add_action("register", "register");
      add_action("check_out", "checkout");
    add_action("north", "north");
      add_action("list_guests", "list_guests");
}
reset() {
  int i;
  if(!done) {
       set_light(1);
guests = allocate(105);
box = allocate(105);
    i = 0;
  }
}
short() {return "Registration desk for "+HIR+"The Honeymoon Heaven Lodge"+NORM;}
long() {
write("A large marble counter lines the wall, behind it is small cubicals \n"+
      "filled with keys.  A small sign above the counter states that rooms\n"+
      "can be rented for the small sum of 1000 coins and are rented until \n"+
      "the next reboot for those who have recently married.  To rent a room\n"+
      "type '"+HIR+"register"+NORM+"'.\n");
 write("There is an opening north to the rooms.\n");
}
 north() {
  int x,f;
  string jj;
  x=0;
 f = 0;
  jj=this_player()->query_real_name();
  while (x <= guest_count) {
      if(guests[x]==jj){
         guest_no = x;
         f = 1;
         x = guest_count;
        }
     x += 1;
    }
if (!f) {
  write("You bounce off the portal.\n");
  write("A voice says: You are not a guest, please register.\n");
  return 1;
 }
  say(call_other(this_player(), "query_name",0) + " enters the portal.\n");
 move_object(this_player(), box[guest_no]);
  call_other(box[guest_no], "long");
  return 1;
}
register(str) {
string nme,jj;
  int x,f;
  x=0;
 f = 0;
  jj=this_player()->query_real_name();
  if( !present("wedding ring", this_player())){
     write("Your not even married!  This is a honeymoon lodge!\n");
     return 1;
  }
  if( (int)present("wedding ring", this_player())->query_married() != 2 ){
     write("You're not a newlywed!\n");
     return 1;
  }
  while (x <= guest_count) {
      if(guests[x]==jj){
         f = 1;
         x = guest_count;
        }
     x += 1;
    }
    if(f == 1) {
      write("You already have a room.\n");
      return 1;
    }
    if (call_other(this_player(), "query_money", 0) < ROOM_COST) {
         write("You don't have enough money!\n");
          return 1;
      }
    if (guest_count >= MAX_GUESTS ) {
       full = 1;
       guest_count = find_empty();
       if (guest_count == 0)
            guest_count = MAX_GUESTS + 1;
      }
   if (guest_count > MAX_GUESTS) {
       write ("Sorry, but the lodge is booked solid.\n");
       return 1;
     }
    call_other(this_player(), "add_money", -ROOM_COST);
    if (full == 0)
    guest_count += 1;
    guests[guest_count] = call_other(this_player(), "query_real_name", 0);
     box[guest_count] = clone_object("players/dreamspeakr/WEDDING/motel_room.c");
     move_object(box[guest_count], "players/dreamspeakr/WEDDING/unfin.c");
    write("It costs you " +ROOM_COST+" gold coins.\n");
   write("Congratulations on your recent marriage!\n");
   write("You are now a guest at the Honeymoon Heaven Lodge\n");
    write("\n");
    nme = call_other(this_player(), "query_name", 0);
    say(nme + " is now a guest of the lodge.");
    say("\n");
    call_other(box[guest_count], "set_owner", guests[guest_count]);
       done = 0;
   if (full == 1) guest_count = MAX_GUESTS;
      done = 1;
  return 1;
}

list_guests(){
  int x;
  write("Honeymoon Heaven Guest List\n");
 x=1;
while (x <= guest_count && x <= MAX_GUESTS) {
  if(call_other(this_player(), "query_level",0) > 200)
    write(box[x]);
    write (" " + x + " -- ");
    write(guests[x] + "\n");
    x +=1;
   }
 return 1;
   }
find_empty() {
  int empty_rm,x;
  x=1;
  while (x <= MAX_GUESTS + 1) {
     if (guests[x] == "vacant") {
         empty_rm = x;
         x = MAX_GUESTS + 1;
        }
     x += 1;
    }
   return empty_rm;
  }
check_out() {
  int yy,empty_rm,x;
  x=1;
  while (x <= MAX_GUESTS) {
     if (guests[x] == call_other(this_player(), "query_real_name",0))
     {
         guests[x] = "vacant";
/*
          yy = 0;
          while(yy < 10) {
 call_other("players/dreamspeakr/WEDDING/HONEYMOON/sx.c", "rmm", "/players/dreamspeakr/WEDDING/HONEYMOON/q"+call_other(this_player(), "query_real_name") + ".o"+yy);
          yy += 1;
          }
*/
         x = MAX_GUESTS;
        }
     x += 1;
    }
  write ("You have been checked out of your room.\n");
  return 1;
  }
query_vac() { 
    if(full) return 0;
    return 1;
   }
