#define MAX_GUESTS 52
#define vac 0
#define ROOM_COST 30000
string guests;
int full,done;
object box;
int is_done,guest_no,guest_count;
id(str) { return str == "hotel"; }
init() {
      add_action("west"); add_verb("west");
      add_action("register"); add_verb("register");
      add_action("check_out", "checkout");
      add_action("north"); add_verb("north");
      add_action("look"); add_verb("look");
      add_action("look"); add_verb("l");
      add_action("look"); add_verb("examine");
      add_action("look"); add_verb("move");
      add_action("sit","sit");
}
reset() {
  object book;
  int i,cl,lastvisit;
  if(!done) {
       set_light(1);
guests = allocate(105);
box = allocate(105);
lastvisit=allocate(105);
    restore_object("players/boltar/hotel/hotel");
     if(!present("book")) {
        book = clone_object("players/boltar/hotel/book.c");
        move_object(book, this_object());
       }
    i = 0;
    while (i <= guest_count) {
         lastvisit[i]=book->query_visit(i);
         if(lastvisit[i]) {
             cl=time() - lastvisit[i];
             if(vac != 1)
              if(cl > 2592000) {
                 guests[i] = "vacant";
                 save_object("players/boltar/hotel/hotel");
              }
                  }
         if (guests[i] != "vacant")
          {
         }
         i += 1;
    }
    done = 1;
  }
         }
short() { return"The Hotel of space in and time.."; }
long() {
  write("You are in what looks like a hotel lobby, however no one is here.\n");
  write("There is a counter on along the far wall and chairs, sofas, and tables\n");
  write("scattered thoughout this large highly decrative room.\n");
  write("There is a portal to the north and a street exit to the west.\n");
  write("\n\n");
  write("You hear an automated voice, you cant seem to tell were it's coming\n");
  write("from.\n 'Welcome to the Hotel Time and Space.'\n 'if you wish to register the book will tell you how.'\n");
}
 west() {
 call_other(this_player(), "move_player", "west#room/northroad2.c");
   return 1;
}
 north() {
  int x,f;
  x=0;
 f = 0;
  while (x <= guest_count) {
     if (guests[x] == call_other(this_player(), "query_real_name", 0)){
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
  call_other("players/boltar/hotel/book.c","set_date",guest_no);
         box[guest_no] = clone_object("players/boltar/hotel/room.c");
         move_object(box[guest_no],"players/boltar/lv1/unfin.c");
         call_other(box[guest_no], "set_owner", guests[guest_no]);
     if(call_other("players/boltar/hotel/book.c","query_days_gone",guest_no)) {
    write("You have been gone "+call_other("players/boltar/hotel/book.c","query_days_gone",guest_no) +" days.\n");
    write("You owe "+call_other("players/boltar/hotel/book.c","query_bill",guest_no)+ " coins, please pay.\n");
    return 1;
    }
 move_object(this_player(), box[guest_no]);
  call_other(box[guest_no], "long");
  return 1;
}
register(str) {
string nme;
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
       write ("Sorry, but the hotel is booked solid.\n");
       return 1;
     }
    call_other(this_player(), "add_money", -ROOM_COST);
    if (full == 0)
    guest_count += 1;
    guests[guest_count] = call_other(this_player(), "query_real_name", 0);
     box[guest_count] = clone_object("players/boltar/hotel/room");
     move_object(box[guest_count], "players/boltar/lv1/unfin.c");
    write("It costs you " +ROOM_COST+" gold coins.\n");
   write("You scribe your name into the book.\n");
   write("You are now a guest at the Hotel of Time and Space\n");
    write("\n");
    nme = call_other(this_player(), "query_name", 0);
    say(nme + " is now a guest of the hotel.");
    say("\n");
    call_other(box[guest_count], "set_owner", guests[guest_count]);
       done = 0;
   if (full == 1) guest_count = MAX_GUESTS;
   save_object("players/boltar/hotel/hotel");
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
list_guests(arg){
  int x;
  write("Hotel Guest List\n");
 x=1;
while (x <= guest_count && x <= MAX_GUESTS) {
  if(call_other(this_player(), "query_level",0) > 200)
    write(box[x]);
    write (" " + x + " -- ");
    if(arg == 1) log_file ("BOOK", " " + x + " -- ");
 write(guests[x] + "        \t"+call_other("players/boltar/hotel/book.c","date",x)+"\n");
 if (arg==1) log_file("BOOK", guests[x] + "        \t"+call_other("players/boltar/hotel/book.c","date",x)+"\n");
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
  if(this_player()->is_kid()) return 0;
  while (x <= MAX_GUESTS) {
     if (guests[x] == call_other(this_player(), "query_real_name",0))
     {
         guests[x] = "vacant";
         log_file("HOTEL", this_player()->query_real_name() + " checked out\n");
/*
 call_other("players/boltar/things/sx.c", "rmm", "/players/boltar/hotel/room/"+call_other(this_player(), "query_real_name") + ".o");
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
  save_object("players/boltar/hotel/hotel");
  return 1;
  }
pay(arg) {
