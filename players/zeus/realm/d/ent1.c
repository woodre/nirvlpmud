inherit "room/room";	/*  ent1.c  */
int teleport;

reset(arg){
	if(arg) return;

 teleport = 0;  if(random(2)) teleport = 1;

 short_desc="The bottom of the staircase";
 long_desc=
"You now stand at the bottom of the dark stairway, which leads back\n"+
"up into the darkness.  The hallway continues to the north, towards\n"+
"a softly glowing red light.  Their are cobwebs lining the corners of\n"+
"the hallway.  The room is quite cold.\n";
 set_light(0);
 items=({
  "staircase",
"The staircase leads back up through the tower.  It is constructed\n"+
"out of pale looking flat stones",
  "stones",
"The walls and the staircase are made of these pale stones",
  "light",
"To the north a glowing red light is visible.  It is pulsing softly",
  "cobwebs",
"There are some frail looking cobwebs in the corners of the wallway,\n"+
"each of which is coated in dust.  They have been there for ages",
 });
 dest_dir=({
	  "/players/zeus/realm/d/vortex.c", "north",
	  "/players/zeus/realm/d/ent2.c", "up",
 });
}

exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){ if(teleport) return "NT"; }
okay_follow() { return 1; }
