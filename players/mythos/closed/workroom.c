#include "/players/mythos/closed/ansi.h"
 int shield, notin, anch, care;
int stick;
 string short_desc;
 reset(arg) {
 if(arg) return;
 anch = 0;
 care = 0;
stick = 0;
 short_desc = BOLD+"Circle of Darkness"+NORM;
 shield = 1;
 set_light(1);
 }
query_prevent_shadow() { return 1; } 
 
init() {
  add_action("on","on");
  add_action("anchor","anchor");
  add_action("chamber","chamber");
  add_action("board","board");
add_action("lock","lock");
  add_action("unlock","unlock");
  add_action("kesu","kesu");
  add_action("out","out");
  add_action("caring","caring");
  add_action("bards","bards");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("rift","rift");
  add_action("portal","portal");
  add_action("test","test");
  add_action("post","post");
  add_action("ndest","destruct",4);
  add_action("mailread","mr");
  add_action("set_short","wshort");
  add_action("forest","forest");
  
if(!present("tonpi")) {
move_object(clone_object("/players/mythos/prac/tonpi.c"),this_object());}


if(this_player()->query_real_name() == "mythos")
if(!present("setter")) {
/*
move_object(clone_object("/players/mythos/closed/play/setter5.c"),this_object());
*/
}

if(this_player()->query_real_name() != "mythos" && 
  this_player()->query_real_name() != "braxana" &&
   this_player()->query_real_name() != "tonpi" && shield == 1) {
write(RED+"\n\tA Celestial Dragon appears and TOSSES you away- FAR AWAY.\n\n"+NORM);
  if (notin == 1) {
  write("Mythos is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");}
  this_player()->move_player("off the shields#room/church");}
 }
 
static lock() {
   if(this_player()->query_real_name() != "mythos") return 0;
  stick = 1;
  write("Lock Down.\n");
return 1; }

static unlock() {
  if(this_player()->query_real_name() != "mythos") {
  return 0; }
  stick = 0;
write("Unlocked.\n"); return 1; }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;}
   
static kesu() {
   if (call_other(this_player(), "query_real_name", 0) != "mythos") {
   write("You cannot do that....Aren't you worried at what Mythos may say?\n");
    return 1;}
   shield = 0;
   notin = 0;
   write("shields deactivated.\n");
   return 1;
   }
   

exit() { if(stick) tell_object(find_player("meshitsukai"),"moo lock\n"); }
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;}

set_short(str) {
  if(this_player()->query_real_name() != "mythos" &&
  this_player()->query_real_name() != "braxana") return 1;
   short_desc = str; }
 short() { return short_desc;}
 
long() {
   if(this_player()->query_level() < 80)
   if(environment(this_player()) != this_object()) {  write("BLAH!\n"); destruct(this_player()); return 1; }
 write(""+
 "Here within these walls, peace dwells.  The Tatami floor is\n" +
 "slightly raised, except for an area nearest to the glowing\n" +
 "portal behind you- here you may remove your shoes and wdon\n" +
 "the slippers that are set before you.  On the far west wall\n" +
 "in the center, there is a Japanese Sumie painting depicting\n" +
 "the Great Mountain Fuji.  In the north east corner there is a  \n" +
 "paper door closet- within are Futons to be taken out when sleep\n" +
 "calls.  In the center of the room is a low wood table- the\n" +
 "Zabutons are stacked in the south east corner. In the north\n" +
 " west corner is a small Tansu.  The room is lit by the light\n" +
 "from the Portal.\n" +
 "Be Welcome, be comfortable.\n"+
"You may exit church, post, portal, bards, hotel, shop, chamber.\n");}

ndest(str) {
  if(str=="mythos") {
  tell_object(find_player("mythos"),BOLD+"The dest field flashes.\n"+
             "Attempt to dest by "+this_player()->query_real_name()+"\n"+NORM);
  return 1;}}
  
bards() {
  call_other(this_player(), "move_player", "bards#players/saber/closed/bards/bardrooms/teleport.c");
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
   
chamber(){
   call_other(this_player(), "move_player", "chamber#players/mythos/enterance.c");
  return 1;}
  
shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;}

mailread(){
   move_object(clone_object("/players/mythos/closed/play/mr.c"),this_player());
    write("Mail, sir.\n");
return 1;}

test() {
  call_other(this_player(),"move_player","test#players/mythos/prac/test.c");
return 1;}

board() {
  call_other(this_player(),"move_player","board#room/adv_inner.c");
  return 1;}

hall() {
  call_other(this_player(),"move_player","hall#players/mythos/closed/guild/hall.c");
  return 1;}

forest() {
  call_other(this_player(),"move_player","forest#players/mythos/aroom/forest/pathway4.c");
  return 1;} 

anchor() {
if(this_player()->query_real_name() != "mythos") return 0;
if(!anch) { anch = 1; write("Anchored!\n"); settled(); return 1;}
else { anch = 0; write("Anchor off.\n"); remove_call_out("settled"); return 1;}
return 1;}

settled() {
object obs;
int h,kj;
  if(!find_player("mythos") && anch) { anch = 0; return 1; }
  if(!anch) return 1;
  if(environment(find_player("mythos")) != this_object()) {
    move_object(find_player("mythos"),this_object());
    tell_object(find_player("mythos"),"WORKROOM\n");
    if(care) { 
    obs = deep_inventory(find_player("mythos"));
    kj = 0;
    for(h=0;h<sizeof(obs);h++) {
    tell_object(find_player("mythos"),obs[h]);
    tell_object(find_player("mythos"),"  ");
    kj = kj + 1;
    if(kj > 2) { kj = 0; tell_object(find_player("mythos"),"\n"); }
    }
    find_player("mythos")->destruct_inventory();
    move_object(clone_object("/players/mythos/closed/play/blade.c"),
      find_player("mythos"));
    }
  }
call_out("settled",3);
return 1;}


caring() {
  if(this_player()->query_real_name() != "mythos") return 0;
  if(!care) { care = 1; write("Inventory safety_destruct set.\n"); }
  else { care = 0; write("Inventory safety off.\n"); }
return 1;}
