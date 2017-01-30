inherit "room/room";	/*  ent4.c  */
int teleport;

reset(arg){
	if(arg) return;

 teleport = 0;  if(random(2)) teleport = 1;

 short_desc="A dark stairway";
 long_desc=
"This is a very dark stairway in the tower.  It seems as though it\n"+
"has not been used in a very long time, for there are many cobwebs\n"+
"in the corners of the room.  There are a few torches on the walls\n"+
"which have not been lit in untold ages.  It leads further down\n"+
"into the darkness, or back up into the room above.\n";
 set_light(0);
 items=({
  "cobwebs",
"In the corners of the narrow room there are very old cobwebs.  There\n"+
"are no spiders in sight, so who knows how long the cobwebs have been\n"+
"up there",
  "torches",
"There are two torches hanging from the walls of the narrow staircase.\n"+
"Each one doesn't look as though it has been lit in an eternity",
  "walls",
"The dusty walls are covered in cobwebs",
 });
 dest_dir=({
	  "/players/zeus/realm/taus/tower7.c", "up",
	  "/players/zeus/realm/d/ent3.c", "down",
 });
}

exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){ if(teleport) return "NT"; }
okay_follow() { return 1; }
