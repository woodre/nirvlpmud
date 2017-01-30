#define TP this_player()
inherit "room/room";

reset(arg){


if(!present("terminal")) {
   move_object(clone_object("/players/snow/closed/cyber/boards/guildboard.c"),
   this_object());
   }


/* Comment out when no elections are being held
if(!present("ballot box")) {
   move_object(clone_object
   ("/players/dune/closed/guild/ballot_box.c"),
   this_object());
   }
*/

 if(!arg){
 set_light(1);
 short_desc="CyberNinja Main Guild Hall";
 long_desc=
"     The Grand Hall of the CyberNinja lies before you.\n"+
"Columns of raging fire stand along the sides of the black\n"+
"marble floor.  Gigantic red statues of past ninja warriors\n"+
"cast their flickering shadows upon the high white walls.\n"+
"The Hall is circular in shape, with the ceiling tapering to\n"+
"a glass dome overhead.\n";

items=({
 "fire", "The blazing fire shoots from the top of the columns",
 "columns","Several large marble columns encircle the center of the room",
 "floor","The black marble floor shines with a polished surface",
 "statues","The statues stand over 20 feet high, near each column",
 "ceiling","The ceiling opens up into a glass viewing window",
 "dome","The glass dome gives you a clear view of the sky outside",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway1.c","north",
 "/players/snow/closed/cyber/rooms/entrance.c","east",
/* "/players/snow/closed/cyber/rooms/bar.c","south", */
 "/players/snow/closed/cyber/rooms/hallway2.c","west",
 "/players/snow/closed/cyber/rooms/meeting.c","down",
 "/players/snow/closed/cyber/rooms/teleport.c","up",
      });
  }   }

init() {
  ::init();
  call_out("move_me", 0, TP);
}

move_me(object ob) {
  if(!present("either implants", ob) &&
     ob->query_guild_name() != "cyberninja") {
  tell_object(ob, "------------>\n");
  tell_object(ob,"You have infiltrated Netropolis without authorization.\n");
  tell_object(ob, "------------>\n");
  if(ob->is_pet() && creator(ob) != "snow" && creator(ob) != "mythos" &&
     creator(ob) != "sandman")
    destruct(ob);
  if(ob->is_player() && ob->query_level() < 20)
    zap_object(ob);
  return 1;
  }
  return 1;
}


realm() { return "NT"; }
feel() { return "no"; }