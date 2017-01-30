inherit "/room/room";

reset(arg) {
  if(!present("board",this_object()))
    move_object(clone_object("/players/grimm/closed/obj/badge_stuff/iboard"),this_object());
  if(!present("sign",this_object()))
    move_object(clone_object("/players/grimm/closed/obj/badge_stuff/isign"),this_object());
  if(arg) return;
  short_desc="Dopple Info Room";
  long_desc=
"This is the Doppleganger's information room.  Examine the board and sign\n"+
"to get some information on the new additions to the guild.\n";
  dest_dir=({ "/players/grimm/closed/obj/badge_stuff/guild_pr","east" });
  set_light(1);
}
