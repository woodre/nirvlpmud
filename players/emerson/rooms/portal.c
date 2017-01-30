#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Black Chamber";
long_desc=
 "\n    You stand in the Black Chamber.\n\n"+
 "    A single sign floats here.\n\n";

items=({
 "chamber","A dark black chamber with a sign",
 "sign","The sign reads:\n"+
   "You may say one of the following words of travel.\n"+
   "\n"+
   "     Advance\n"+
   "     Arena\n"+
   "     Church\n"+
   "     Disco\n"+
   "     Hotel\n"+
   "     Lockers\n"+
   "     Market\n"+
   "     Orin\n"+
   "     Post\n"+
   "     Pub\n"+
   "     Ruins\n"+
   "     Rift\n"+
   "     Shop\n"+
   "     Tower\n"+
   " ",
 });

  dest_dir=({
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("advance","advance");
   add_action("arena","arena");
   add_action("church","church");
   add_action("disco","disco");
   add_action("hotel","hotel");
   add_action("lockers","lockers");
   add_action("market","market");
   add_action("orin","orin");
   add_action("post","post");
   add_action("pub","pub");
   add_action("ruins","ruins");
   add_action("rift","rift");
   add_action("shop","shop");
   add_action("tower","tower");
}

search() {
write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

advance()  {
this_player()->move_player("to the advance guild#"+"/room/adv_guild.c");
  return 1;        }

arena()  {
this_player()->move_player("to the arena#"+"/players/saber/ryllian/arena.c");
  return 1;      }

church()  {
this_player()->move_player("to the church#"+"/room/church");
  return 1;        }

disco()   {
this_player()->move_player("to the disco#"+"/players/trix/castle/disco/in1.c");
  return 1;        }

hotel()  {
this_player()->move_player("to the hotel#"+"/players/boltar/hotel/hotel.c");
  return 1;     }

lockers()  {
this_player()->move_player("to the lockers#"+"/players/catwoman/tl.c");
  return 1;     }

market()  {
this_player()->move_player("to the Market Square#"+"/players/saber/ryllian/ms5.c");
  return 1;        }

orin()  {
this_player()->move_player("to Orin's Inn#"+"/players/saber/ryllian/orin1.c");
  return 1;     }

post()  {
this_player()->move_player("to the post office#"+"/room/post.c");
  return 1;     }

pub()  {
this_player()->move_player("to the main pub#"+"/room/pub2.c");
  return 1;     }

rift()  {
this_player()->move_player("to the rift in space and time#"+"/players/saber/ryllian/rift.c");
  return 1;        }

ruins()  {
this_player()->move_player("to the ruins#"+"/room/ruin.c");
  return 1;    }

shop()  {
this_player()->move_player("to the shop#"+"/room/shop.c");
  return 1;     }

tower()  {
this_player()->move_player("to the Dark Tower#"+"/players/saber/tower/tower1.c");
  return 1;     }

realm()  { return "NT"; }
