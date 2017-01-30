#define MAX_GUESTS 100
#define vac 0
#define ROOM_COST 18000
#include "/players/jaraxle/ansi.h"
inherit "room/room";
string guests;
int full,done;
object box;
int is_done,guest_no,guest_count;
id(str) { return str == "TemplarStorage"; }

init() {
      add_action("west"); add_verb("west");
      add_action("down"); add_verb("down");
      add_action("setguest","setguest");
      add_action("register"); add_verb("register");
      add_action("check_out", "checkout");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
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
    restore_object("players/boltar/templar/private");
     if(!present("book")) {
        book = clone_object("players/boltar/templar/book.c");
        move_object(book, this_object());
       }
    i = 1;
    while (i <= guest_count) {
         lastvisit[i]=book->query_visit(i);
         if(lastvisit[i]) {
             cl=time() - lastvisit[i];
             if(vac != 1)
              if(cl > 2592000) {
                 guests[i] = "vacant";
                 save_object("players/boltar/templar/private");
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
short() { return HIW+"Inner Chambers ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+" [w,d]"; }
long() {
write("  The room is fairly plain, with a small table pushed back against the\n"+
      "southern wall. A large vase filled with beautiful flowers from the\n"+
      "garden stands upon the table. There is a thick, aged book set out and\n"+
      "open on the table, with a pen beside it. A softly glowing portal hums\n"+
   "quietly, just in front of the northern wall.\n"+
    "    There are two obvious exits: west and down\n");
}
down() {
    call_other(this_player(), "move_player", "down#players/jaraxle/templar/rooms/mage_room.c");
      return 1;
  }

west() {
   call_other(this_player(), "move_player", "west#players/jaraxle/templar/rooms/adv_inner.c");
     return 1;
 }
 north() {
  int x,f;
  string jj;
  x=0;
 f = 0;
  jj=this_player()->query_real_name();
  while (x <= guest_count) {
     if(guests[x] == jj){
         guest_no = x;
         f = 1;
         x = guest_count;
        }
     x += 1;
    }
if (!f) {
  write("You bounce off the portal.\n");
  write("Katarin says: You aren't a guest, please register.\n");
  return 1;
 }
  say(call_other(this_player(), "query_name",0) + " enters the portal.\n");
  call_other("players/boltar/templar/book.c","set_date",guest_no);
       if(!box[guest_no])
          {
         box[guest_no] = clone_object("players/boltar/templar/room.c");
         move_object(box[guest_no],"players/boltar/lv1/unfin.c");
         call_other(box[guest_no], "set_owner", guests[guest_no]);
           }
 move_object(this_player(), box[guest_no]);
  call_other(box[guest_no], "long");
  return 1;
}
register(str) {
string jj,nme;
  int x,f;
  x=0;
 f = 0;
  jj=this_player()->query_real_name();
  if(this_player()->query_guild_name() != "Knights Templar") {
   write("Katarin says: You cannot register here.\n");
   return 1;
 }
  while (x <= guest_count) {
     if (guests[x]==jj){
         f = 1;
         x = guest_count;
        }
     x += 1;
    }
    if(f == 1) {
      write("Katarin says: You already have a room.\n");
      return 1;
    }
    if (call_other(this_player(), "query_money", 0) < ROOM_COST) {
         write("Katarin says: You don't have enough money!\n");
          return 1;
      }
    if (guest_count >= MAX_GUESTS ) {
       full = 1;
       guest_count = find_empty();
       if (guest_count == 0)
            guest_count = MAX_GUESTS + 1;
      }
   if (guest_count > MAX_GUESTS) {
       write ("Katarin says: Sorry, but the Templar rooms are booked.\n");
       return 1;
     }
    call_other(this_player(), "add_money", -ROOM_COST);
    if (full == 0)
    guest_count += 1;
    guests[guest_count] = call_other(this_player(), "query_real_name", 0);
     box[guest_count] = clone_object("players/boltar/templar/room");
     move_object(box[guest_count], "players/boltar/lv1/unfin.c");
    write("Katarin takes "+ROOM_COST+" gold coins from you.\n");
   write("You scribe your name into the book.\n");
   write("You now have your own private room in the Templar Castle.\n");
    nme = call_other(this_player(), "query_name", 0);
    say(nme + " now has a room.");
    say("\n");
    call_other(box[guest_count], "set_owner", guests[guest_count]);
       done = 0;
   if (full == 1) guest_count = MAX_GUESTS;
   save_object("players/boltar/templar/private");
      done = 1;
   write("Katarin shows you to your room.\n");
    write("\n");
   command("north",this_player());
  return 1;
}
sit(str) {
   string stra;
   if (str !="on chair" && str !="on sofa" && str !="on table")
     return 0;
   write("You sit.\n");
   sscanf(str,"on %s",stra);
   tell_room(this_object(),this_player()->query_name()+" sits on a "+stra+".\n");
  return 1;
  }
list_guests(arg){
  int x;
  write("Room List:\n");
 x=1;
while (x <= guest_count && x <= MAX_GUESTS) {
  if(call_other(this_player(), "query_level",0) > 200)
    write(box[x]);
    write (" " + x + " -- ");
    if(arg == 1) log_file ("BOOK", " " + x + " -- ");
 write(guests[x] + "        \t"+call_other("players/boltar/templar/book.c","date",x)+"\n");
 if (arg==1) log_file("BOOK", guests[x] + "        \t"+call_other("players/boltar/templar/book.c","date",x)+"\n");
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
 call_other("players/boltar/things/sx.c", "rmm", "/players/boltar/templar/room/"+call_other(this_player(), "query_real_name") + ".o");
          yy = 0;
          while(yy < 10) {
 call_other("players/boltar/sx.c", "rmm", "/players/boltar/templar/room/q"+call_other(this_player(), "query_real_name") + ".o"+yy);
          yy += 1;
          }
*/
         x = MAX_GUESTS;
        }
     x += 1;
    }
  write ("Katarin checks you out of your room.\n");
  save_object("players/boltar/templar/private");
  return 1;
  }
look(str) {
   if (!str) {
   return 0;
  }
if (str == "at book") {
  write("A thick book, aged and yellowed. You may"+GRN+" read"+NORM+" it.\n");
  return 1;
  }
 if (str == "at sofa") {
  write("A large, black leather sofa.\n");
   return 1;
  }
  if(str == "at table" || str == "at tables") {
   write("A large, highly polished rectangular table, with equally beautiful chairs.\n");
  return 1;
    }
   if(str== "at chair" || str=="at chairs") {
    write("Beautiful, hand crafted wood chairs with a green fabric cusions.\n");
   return 1;
    }
return 0;
}
setguest(str) {
  int blah;
  string bbb;
  if(this_player()->query_level() < 10000) return 0;
  if(sscanf(str,"%d %s",blah,bbb) == 2) {
  guests[blah] = bbb;
  save_object("players/boltar/templar/private");
  write("Please Update the Hotel now\n");
  return 1;
  }
return 0;
}
query_dest_dir() { return ({ "/players/jaraxle/templar/rooms/adv_inner.c","west" }); }
