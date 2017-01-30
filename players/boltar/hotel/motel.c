#define MAX_GUESTS 40
#define ROOM_COST 500
string guests;
int full,done;
object box;
int is_done,guest_no,guest_count;
id(str) { return str == "motel"; }
init() {
      add_action("west","west");
      add_action("register","register");
      add_action("check_out", "checkout");
      add_action("north","north");
      add_action("look","look");
      add_action("look","l");
      add_action("look","examine");
      add_action("look","move");
      add_action("sit","sit");
}
reset() {
  object book;
  int i;
  if(!done) {
       set_light(1);
guests = allocate(105);
box = allocate(105);
    i = 0;
  }
     if(!present("book")) {
        book = clone_object("players/boltar/hotel/mbook.c");
        move_object(book, this_object());
       }
         }
short() {return "The One Night Stand Motel";}
long() {
write("You see the run down decore of a cheap motel, ahead of you is a long\n"+
  "desk where you can register for a room. The sign above states that rooms\n"+
  "cost 500 coins and are rented until the next reboot.\n");
 write("There is an opening north to the rooms and the exit to the west.\n");
 write("The lost and found is located at the hotel up the street.\n");
}
 west() {
 call_other(this_player(), "move_player", "west#room/southroad1.c");
   return 1;
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
       write ("Sorry, but the motel is booked solid.\n");
       return 1;
     }
    call_other(this_player(), "add_money", -ROOM_COST);
    if (full == 0)
    guest_count += 1;
    guests[guest_count] = call_other(this_player(), "query_real_name", 0);
     box[guest_count] = clone_object("players/boltar/hotel/motel_room");
     move_object(box[guest_count], "players/boltar/lv2/unfin.c");
    write("It costs you " +ROOM_COST+" gold coins.\n");
   write("You scribe your name into the book.\n");
   write("You are now a guest at the One Night stand Motel\n");
    write("\n");
    nme = call_other(this_player(), "query_name", 0);
    say(nme + " is now a guest of the motel.");
    say("\n");
    call_other(box[guest_count], "set_owner", guests[guest_count]);
       done = 0;
   if (full == 1) guest_count = MAX_GUESTS;
      done = 1;
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at chair" || str == "in chair"){
    write("A very nice looking chair.\n");
   return 1;
  }
return 0;
}
sit(str) {
   if (str !="on chair")
     return 0;
   write("You sit.\n");
  return 1;
  }
list_guests(){
  int x;
  write("Motel Guest List\n");
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
 call_other("players/boltar/sx.c", "rmm", "/players/boltar/hotel/room/q"+call_other(this_player(), "query_real_name") + ".o"+yy);
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
