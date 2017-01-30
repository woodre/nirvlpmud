/*
10/07/05 - Earwax - Added ability to 'read sign' instead of just look
*/

#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
  if(!present("olga")) move_object(clone_object("/players/saber/closed/bards/olga.c"),this_object());
  if(!arg){
    set_light(1);
    short_desc="Black Chamber";
  long_desc= "\n    You stand in the Black Chamber.\n\n"+
             "    A single sign floats here.\n\n";

items=({
 "chamber","A dark black chamber with a sign"});

  dest_dir=({
           });
  }   }

/* Changed from item desc to action to allow 'read' - Earwax 10/7/05 */
status do_read_sign(string arg) {
  if (arg != "sign" && arg != "at sign")
    return 0;

  write("The sign reads:\n"+
   "You may say one of the following words of travel.\n"+
   "\n"+
   "     Advance\n"+
   "     Arena\n"+
/*
	"     Bigelow\n"+
*/
   "     Chamber\n"+
   "     Church\n"+
   "     Crystal\n"+
   "     Disco\n"+
   "     Empire\n"+
   "     Hotel\n"+
   "     Lockers\n"+
   "     Market\n"+
  "\n"+
   "     Newbie\n"+
  "\n"+
   "     Orin\n"+
   "     Post\n"+
   "     Pub\n"+
   /*
   "     Qualtor\n"+
    */
   "     Ruins\n"+
   "     Rift\n"+
   "     Robomech\n"+
   "     Shop\n"+
/* "     Shrine\n"+ */
   "     Templar Castle\n"+
   "     Tower\n"+
   "     Victoria\n"+
   "     Warp\n");
  return 1;
}

init(){
 ::init();
  add_action("do_read_sign", "read"); /* Earwax 10/07/05 */
  add_action("do_read_sign", "look"); /* Earwax 10/07/05 */
  add_action("search","search");
   add_action("advance","advance");
   add_action("arena","arena");
/*
	add_action("bigelow","bigelow");
*/
   add_action("church","church");
   add_action("crystal","crystal");
   add_action("disco","disco");
   add_action("empire","empire");
   add_action("hotel","hotel");
   add_action("lockers","lockers");
   add_action("market","market");
   add_action("orin","orin");
   add_action("post","post");
   add_action("pub","pub");
   add_action("ruins","ruins");
   add_action("rift","rift");
   add_action("robomech","robomech");
   add_action("shop","shop");
  add_action("shrine","shrine");
   add_action("templar","templar");
   add_action("tower","tower");
   add_action("victoria","victoria");
   add_action("warp","warp");
   add_action("chamber","chamber");
   add_action("newbie","newbie");
/*
  add_action("qualtor","qualtor");
*/
}

search() {
write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

advance()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the advance guild#"+"/room/adv_guild.c");
  return 1;        }

arena()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the arena#"+"/players/saber/ryllian/arena.c");
  return 1;      }
bigelow() {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the town of Bigelow#"+"/players/pain/NEW/square.c");
return 1;	}

church()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the church#"+"/room/church");
  return 1;        }
crystal()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("into the crystal#"+"/players/arrina/newbie/newbie1a.c");
  return 1;        }

disco()   {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the disco#"+"/players/trix/castle/disco/in1.c");
  return 1;        }

empire()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("into the Empire#"+"/players/mythos/aroom/path1.c");
  return 1;        }

hotel()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the hotel#"+"/players/boltar/hotel/hotel.c");
  return 1;     }

lockers()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the lockers#"+"/players/catwoman/tl.c");
  return 1;     }

market()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Market Square#"+"/players/saber/ryllian/ms5.c");
  return 1;        }

orin()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to Orin's Inn#"+"/players/guilds/bards/orin/orin1.c");
  return 1;     }


newbie() {
  if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Newbie Lockers#players/mythos/locker.c");
return 1; }
post()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the post office#"+"/room/post.c");
  return 1;     }

pub()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the main pub#"+"/room/pub2.c");
  return 1;     }

rift()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the rift in space and time#"+"/players/saber/ryllian/rift.c");
  return 1;        }

robomech()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Robomech arena#"+"/players/dune/closed/pavilion/rooms/entryway.c");
  return 1;        }

ruins()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the ruins#"+"/room/ruin.c");
  return 1;    }

shop()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the shop#"+"/room/shop.c");
  return 1;     }

shrine() {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Shrine#/players/feldegast/shrine.c");
return 1; }

templar()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Templar Castle#"+"/room/south/sshore1.c");
  return 1;     }

tower()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Dark Tower#"+"/players/saber/tower/tower1.c");
  return 1;     }

victoria()  {
if(check()) { write("Amoril blocks your way.\n"); return 1; }
if(this_player()->query_gender() != "female")  {
  write("You can't enter this portal...\n");
  return 1;
        }
this_player()->move_player("into Victoria's Secret Room#"+"/players/saber/closed/fem/fems.c");
  return 1;        }

chamber() { 
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Chamber of Realms#players/mythos/entrance.c");
return 1; }

warp() { 
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to the Warp#players/eurale/RMS/warp.c");
return 1; }

realm()  { return "NT"; }

check() {
  if(present("hunters_servant")) return 1;
  else return 0;
}

qualtor() { 
if(check()) { write("Amoril blocks your way.\n"); return 1; }
this_player()->move_player("to Qualtor#players/daranath/qualtor/wayin2.c");
return 1; }
