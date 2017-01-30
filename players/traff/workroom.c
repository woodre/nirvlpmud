#include "std.h"
#include "/players/traff/closed/ansi.h"
 int shield, notin;
 reset(arg) {
 if(arg) return;
 shield = 1;
 set_light(1);
 }
 
init() {
  add_action("on","on");
  add_action("board","board");
  add_action("kesu","kesu");
  add_action("out","out");
  add_action("pguild","pguild");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("rift","rift");
  add_action("portal","portal");
  add_action("post","post");
  add_action("ndest","destruct",4);
  
if(!present("pool")) {
move_object(clone_object("/players/saber/closed/bards/pool.c"),this_object());}

if(this_player()->query_real_name() != "traff" && shield == 1) {
write(NORM+"\n\tA bright "+BOLD+YEL+"YELLOW "+NORM+"glow surrounds you and dissolves your body.\n\n"+NORM);
  if (notin == 1) {
  write("Thank you for stopping by, friend, but I am currently busy.\n");
  write("\tPlease stop by again.\n");}
  this_player()->move_player("off the shields#room/church");
   tell_object(this_player(),"\n\tYour body reforms in a solid state.\n\n");}
 }
 
static on() {
   write("\t\tThe "+BOLD+YEL+"Aura "+NORM+"protects.\n");
  shield = 1;
   return 1;}
   
static kesu() {
   if (call_other(this_player(), "query_real_name", 0) != "traff") {
   write("Try as you might, you cannot muster the magical forces required.\n");
    return 1;}
   shield = 0;
   notin = 0;
   write("\t\tThe "+BOLD+YEL+"Aura "+NORM+"fades away...\n");
   return 1;
   }
   
out() {
   shield = 1;
   notin = 1;
   write(BOLD+YEL+"\t\tAura "+NORM+"on, Message on.\n");
   return 1;}

 short() { return BLU+"Delnoch Pass"+NORM;}
 
long() {
 write(""+
"You are standing in the midst of that most famous of places,\n"+
"\t\tSOME OTHER PLACE!\n"+
"This is the hang out of the notorious Wizard Traff.  Although\n"+
"the room is well lit, details are hard to make out.  Along one\n"+
"wall you see several computers, printers, disks, and other\n"+
"related items.  Another wall is entirely covered with bookshelves.\n"+
"The rest of the room is fuzzy, but you get the distinct feeling\n"+
"that if you looked hard enough you might find almost\n"+
"anything you could imagine here.\n\n"+
 "You may exit: church, post, portal, pguild, hotel, shop.\n");}

ndest(str) {
  if(str=="traff") {
  tell_object(find_player("traff"),BOLD+"The dest field flashes.\n"+
             "Attempt to dest by "+this_player()->query_real_name()+"\n"+NORM);
  return 1;}}
  
pguild() {
  call_other(this_player(), "move_player", "pguild#players/sandman/paladin/adv_guild");
   return 1;   }
   
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;}
  
portal() {
call_other(this_player(), "move_player", "portal#players/saber/ryllian/portal.c");
 return 1;}
 
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;}

post(){
   call_other(this_player(), "move_player","post#room/post");
   return 1;}
   
  
shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;}

board() {
  call_other(this_player(),"move_player","board#room/adv_inner.c");
  return 1;}


  
