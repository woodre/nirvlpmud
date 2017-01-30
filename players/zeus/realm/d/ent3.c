inherit "room/room";	/*  ent3.c  */
int teleport;

reset(arg){
	if(arg) return;

 teleport = 0;  if(random(2)) teleport = 1;

 short_desc="A dark stairway";
 long_desc=
"This is a hidden stairway leading down through the tower.  By the\n"+
"way things look, you would guess that it hasn't been used in ages.\n"+
"There are numerous cobwebs in the corners of the room, and there are\n"+
"two torches on the walls which don't look like they've been lit since\n"+
"they were placed there.  The room is rather cold.\n";
 set_light(0);
 items=({
  "cobwebs",
"The dusty cobwebs make the room feel as though it is long forgotten.\n"+
"They are very frail looking, clinging to the walls of the room",
  "torches",
"The small black torches which are mounted on the wall look as if it\n"+
"has been literally decades since they were last lit",
  "walls",
"The walls are very dusty, made of a very pale looking stone",
 });
 dest_dir=({
	  "/players/zeus/realm/d/ent4.c", "up",
	  "/players/zeus/realm/d/ent2.c", "down",
 });
}

exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){ if(teleport) return "NT"; }
okay_follow() { return 1; }
