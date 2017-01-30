inherit "room/room";	/*  ent2.c  */
int teleport;

reset(arg){
	if(arg) return;

 teleport = 0;  if(random(2)) teleport = 1;

 short_desc="A dark stairway";
 long_desc=
"This narrow staircase leads down through the darkness.  The walls\n"+
"of the room are made of cold lifeless stone.  There are numerous\n"+
"cobwebs in the corners of the room.  There are also two torches\n"+
"mounted on the walls of the stairway.  There seems to be some\n"+
"light visible at the bottom of the staircase below you.\n";
 set_light(0);
 items=({
  "stone",
"The stones making up the walls are solid, having been in place\n"+
"for many centuries.  They are quite pale and flat",
  "cobwebs",
"The dusty cobwebs are clinging to the walls of the staircase.  They\n"+
"look as though they've been there for years",
  "light",
"It's hard to see, but there seems to be a faint light coming from\n"+
"the bottom of the staircase",
  "torches",
"The two torches mounted on the walls of the staircase looks as though\n"+
"they've been there for ages.  They are both covered in dust and cobwebs",
  "walls",
"The walls are made of a pale stone",
 });
 dest_dir=({
	  "/players/zeus/realm/d/ent3.c", "up",
	  "/players/zeus/realm/d/ent1.c", "down",
 });
}

exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){ if(teleport) return "NT"; }
okay_follow() { return 1; }
