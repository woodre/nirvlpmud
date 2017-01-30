#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Staircase";
  long_desc=
	"You are on the Staircase of Mages.  This huge sweeping staircase spirals\n"+
	"upwards into the tower.  The steps here are adorned with strange runes\n"+
	"and markings that glow with a mystical power.  Members of the Mages guild\n"+
	"rush by, no doubt working on some important task.  There is a small silver door\n"+
	"crafted into the south wall.  It's polished surface is covered with more\n"+
	"swirling inscriptions.\n";

  dest_dir=({
	"/players/pavlik/guild/mages/rooms/main.c", "down",
	"/players/pavlik/guild/mages/room/join_room", "south",
	"/players/pavlik/guild/mages/room/guild_room", "up",
  });

  call_out("ran_messages", 10);

}

query_mguild(){ return "Stairs"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("up","up");
}


up()
{
  if(this_player()->query_guild_name() != "mage")
  {
	write(
	  "You try to walk up the stairs, but the inscribed runes flare brightly\n"+
	  "and you are forced to step back.\n"+
	  "... You notice a small door in the south wall.\n");
	return 1;
  }
  write("You ascend into the Tower of Mages.\n");
  say(capitalize(this_player()->query_name())+" ascends into the Tower of Mages.\n");

  /*
   * TEMPORARY
   */
  if(present("mageobj_NEW", this_player()))
	move_object(this_player(), "players/pavlik/guild/mages/room/guild_room");
  else
	move_object(this_player(), "players/pavlik/guild/mages/rooms/guild_room");

  say(capitalize(this_player()->query_name())+" ascends into the Tower of Mages.\n");
  command("look", this_player());
  return 1;
}

ran_messages(){
 int x;
x = random(10);
if(x == 0){
tell_room(this_object(),
"A group of Wizards walk down the stairs into the Main Hall.\n"+
"Activity stops as people pay silent respect to the Warlocks.\n");
   }
if(x == 1){
tell_room(this_object(),
"A large ball of what looks like yarn rolls past you down the steps.\n"+
"A bunch of wizards runs down the stairs chasing the ball.\n");
   }
if(x == 2){
tell_room(this_object(),
"A wheezing mage stops to catch his breath.  The mage swears profusely,\n"+
"then continues his journey up into the tower.\n");
   }
if(x == 3){
tell_room(this_object(),
"You here some muttering as Boltar climbs the steps:\n"+
"I put an elevator in the Church, why couldn't he put one in his "+
"stupid Tower?\n");
   }
if(x == 4){
tell_room(this_object(),
"An Arch-Mage flies gracefully up the staircase.\n");
   }
if(x == 5){
tell_room(this_object(),
"A small man in white robes enters the door in the south wall.\n");
   }
if(x == 6){
tell_room(this_object(),
"A new Mage-Apprentice begins his first journey up into the Tower.\n");
   }
if(x == 7){
tell_room(this_object(),
"A Mage carrying a large stack of papers enters the south door.\n");
   }
if(x == 8){
tell_room(this_object(),
"Vertebraker hurries past you up the stairs.\n");
   }
call_out("ran_messages", 25);
return 1;
}
