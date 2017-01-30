#include "std.h"
#include "/players/mythos/closed/guild/def.h"
int shield;
init() {
if(!present("zzzb")) { 
  move_object(clone_object("/players/mythos/closed/guild/zzzb.c"),this_object()); }
  if(pp) { pp->set_defence(0);}
  add_action("chamber","chamber");
  add_action("library","library");
  add_action("forbidden","forbidden");
  add_action("desert","desert");
  add_action("slib","library_annex");
  add_action("tokyo","tokyo");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("portal","portal");
  add_action("assembly","assembly");
  add_action("lockers","lockers");
  add_action("daycare","daycare");
  add_action("post","post");
  add_action("shrine","shrine");
  add_action("invite","invite");
  add_action("advance","advance");
  if(pp) { move_object(clone_object("/players/mythos/closed/guild/rob.c"),tp); }
}

reset(arg) {
if(!present("guildboard")) {
  move_object(clone_object("/players/mythos/closed/guild/board.c"),this_object());
  }
  if(arg) return;
  set_light(1); } 

 realm() { return "NT"; }
 short() { return "The Initiates' Quarters";}
 
long() {
 write(""+
"Here is the Initiate Quarters.\n"+
"You may exit: assembly, chamber, church, hotel, library, library_annex,\n"+
"              lockers, portal, post, shop, shrine, tokyo, daycare, advance.\n"+
"              forbidden, desert\n");}
  
slib() {
if(!present(fear,tp)) {  write("You may not go that way.\n"); return 1;}
  call_other(this_player(), "move_player", "slib#players/mythos/closed/guild/seclib.c");
   return 1;   }
   
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;}
  
portal() {
tp->add_spell_point(-40);
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

library() {
  call_other(this_player(),"move_player","library#players/mythos/lroom/hall.c");
return 1;}

assembly() {
  if(!present(fear,tp)) {  write("You may not go that way.\n"); return 1;}
  call_other(this_player(),"move_player","hall#players/mythos/closed/guild/assembly.c");
  return 1;}
  
shrine() {
    call_other(this_player(),"move_player","shrine#players/mythos/aroom/shrinear3.c");
return 1;}

lockers() { 
  call_other(this_player(),"move_player","lockers#players/catwoman/tl.c");
return 1;}

tokyo() {
  call_other(this_player(),"move_player","tokyo#players/mythos/mroom/narita.c");
return 1;}


desert() { 
   call_other(this_player(), "move_player","desert#players/mythos/droom/desert.c");
   return 1;}

invite(str) {
string name;
object ob, invit;
  if(!str) { write("Who do you wish to invite?\n"); return 1;}
  name = str;
  ob = find_player(name);
  if(!(environment(ob)->realm() == "NT")) {
  if(present("black_orb",ob)) { command("drop black_orb",ob);}
  invit = clone_object("/players/mythos/closed/guild/invite.c");
  invit->set_ask(tpn);
  move_object(invit,ob);
  write("You invite "+str+"\n");
  return 1;}
  write("That person is either not here or not in a teleportable place!\n");
return 1;}

daycare() {
  this_player()->move_player("daycare#players/boltar/sprooms/daycare.c");
return 1;}

advance() {
  this_player()->move_player("advance#room/adv_guild.c");
return 1;}

forbidden() { 
  this_player()->move_player("forbidden#players/mythos/closed/guild/forest/rooms/hunter.c");
return 1;}
