#define TP   this_player()
#define CO   call_other
#define MV   "move_player"
#define TEL  CO(TP, MV
#define R1   return 1
#include "std.h"

inherit "room/room";

reset(arg) {
  set_light (1);
  if(!arg) {
 short_desc="CyberNinja Matter Transfer Room";
 long_desc=
  "     You are in the CyberNinja Matter Transfer Room.\n"+
  "From here you may reach all corners of Nirvana.\n"+
  "Type 'list' to list the places you may go.\n";

items=({
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/guildhall.c","down",
      });
} }

init() {
   add_action("where","list");
   add_action("church","church");
   add_action("post","post");
   add_action("mailroom","mailroom");
   add_action("shop","shop");
   add_action("lockers","lockers");
   add_action("advance","advance");
   add_action("rat","rat");
   add_action("pub2","pub2");
   add_action("pub3","pub3");
   add_action("waste","waste");
   add_action("hotel","hotel");
   add_action("robomech","robomech");
   add_action("warp","warp");
   add_action("rift","rift");
   ::init();
  if(!present("either implants",TP)) {
    tell_object(TP, "------------>\n");
    tell_object(TP, "You have infiltrated Netropolis without authorization.\n");
    tell_object(TP, "------------>\n");
    if(TP->is_player()) move_object(TP, "/room/church.c");
  }
}

where() {
  write("You may teleport to the following places.\n");
  write(
" _________________________________________\n"+
" General Locations:\n"+
"   church\n"+
"   post\n"+
"   mailroom\n"+
"   shop\n"+
"   lockers\n"+
"   advance\n"+
"   hotel\n"+
"   rift\n"+
" \n"+
" Taverns/Healing:\n"+
"   rat\n"+
"   pub2\n"+
"   pub3\n"+
" \n"+
" PK Areas:\n"+
"   Waste\n"+
"   Robomech\n"+
"   Warp\n"+
" \n"+
" _________________________________________\n");
return 1;}

advance(){TEL, "advance#room/adv_guild.c"); R1;}
post() { TEL, "post#room/post"); R1; }
/*
mailroom(){TEL, "mailroom#players/snow/closed/cyber/rooms/mailroom"); R1; }
*/
mailroom() { write("This is temporarily closed for repairs.\n"); R1; }
shop(){TEL, "shop#room/shop.c"); R1;}
lockers() {TEL, "lockers#players/catwoman/tl.c"); R1;}
church() {TEL, "church#room/church.c"); R1;}
 rat() {TEL, "to 'The Drowned Rat'#players/snow/ROOMS/bar.c"); R1;}
pub2() {TEL, "pub2#room/pub2.c"); R1;}
pub3() {TEL, "pub3#players/trix/castle/disco/bar.c"); R1;}
waste() {TEL, "waste#players/dragnar/WasteLands/rooms/entrance.c"); R1;}
hotel() {TEL, "hotel#players/boltar/hotel/hotel.c"); R1;}
robomech() {TEL, "robomech#players/dune/closed/pavilion/rooms/entryway.c"); R1;}
warp() {TEL, "warp#players/eurale/closed/warp.c"); R1; }
rift() {TEL, "rift#players/saber/ryllian/rift.c"); R1; }

feel() { return "no"; }
