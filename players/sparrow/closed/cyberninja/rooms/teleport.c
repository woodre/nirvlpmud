inherit "/players/dune/closed/guild/rooms/room";
#include "std.h"
#include "../DEFS.h"
#define TEL  call_other(this_player(), "move_player"



reset(arg)
{
  set_light (1);
  if(!arg) {
    short_desc=FUNKYNAME+" Room of Dark Paths";
    long_desc=
"     You are in the "+FUNKYNAME+" Room of Dark Paths.\n"+
"From here you may reach many dark corners of Nirvana.\n"+
"Type 'list' to list the places you may go.\n";

    items=({
    });

    dest_dir=({
    ALTLOGIN,"down",
    });
  }
}

init()
{
  if(this_player()->query_guild_name() == "cyberninja") {
  add_action("where",    "list");
  add_action("post",     "post");
  add_action("lockers",  "lockers");
  add_action("rat",      "rat");
  add_action("waste",    "waste");
  add_action("hotel",    "hotel");
  add_action("robomech", "robomech");
  add_action("fiend",    "fiend");
  add_action("dryant",   "dryant");
  add_action("nbar",     "nbar");
  }
   ::init();
}


int where()
{
  write("You may travel to the following places.\n");
  write(
" _________________________________________\n"+
" General Locations:\n"+
"   post     \n"+
"   lockers  \n"+
"            \n"+
" Taverns, Healing:\n"+
"   rat (The Drowning Rat)\n"+
"            \n"+
" PK Areas:  \n"+
"   waste    \n"+
"   robomech \n"+
"   fiend     \n"+
"   dryant\n"+
"   nbar\n"+
"            \n"+
" _________________________________________\n");
  return 1;
}


advance()  { TEL,"advance #room/adv_guild.c");                 return 1; }
post()     { TEL,"post    #room/post");                        return 1; }
shop()     { TEL,"shop    #room/shop.c");                      return 1; }
lockers()  { TEL,"lockers #players/catwoman/tl.c");            return 1; }
church()   { TEL,"church  #room/church.c");                    return 1; }
rat()      { TEL,"pub1    #players/snow/ROOMS/bar.c");         return 1; }
pub2()     { TEL,"pub2    #room/pub2.c");                      return 1; }
pub3()     { TEL,"pub3    #players/trix/castle/disco/bar.c");  return 1; }
waste()    { TEL,"waste   #players/dragnar/WasteLands/rooms/entrance.c"); return 1; }
hotel()    { TEL,"hotel   #players/boltar/hotel/hotel.c");     return 1; }
robomech() { TEL,"robomech#players/dune/closed/pavilion/rooms/entryway.c"); return 1;}
warp()     { TEL,"warp    #players/eurale/closed/warp.c");     return 1; }
rift()     { TEL,"rift    #players/saber/ryllian/rift.c");     return 1; }
dryant()    { TEL,"dryant  #players/wocket/graveyard/gr1.c");   return 1;}
fiend()   { TEL,"fiendsville   #players/eurale/Fiend/mm1.c"); return 1; }
nbar()    { TEL,"nudie bar #players/unsane/closed/extra/titti.c"); return 1; }
