#define ME capitalize(this_player()->query_name())
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(0);
short_desc="Staircase";
long_desc=
"You are in a darkened stairwell.\n"+
"A set of stairs spirals downwards from here.\n"+
"A foul odor creeps up from below.\n";

dest_dir=({
});

   }
}

init(){
 ::init();
  add_action("pull_stone","pull");
  add_action("push_stone","push");
  add_action("down_stairs","down");
}

push_stone(){
  write("You try to push the stone, but it won't budge.\n");
  return 1;
}

pull_stone(){
  write("You work your fingers around the loose stone and pull\n"+
  "it out towards you.  There is a familiar 'click' and 'whoosh'\n"+
  "and you find yourself back in Myla's shop.\n");
  say("There is a 'click and 'whoosh' and "+ME+" is gone.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/lil_shop");
  say("There is a 'click' and a 'whoosh' and "+ME+" suddenly appears.\n");
  return 1;
}

down_stairs(){
  write("You go down the stairs.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/blood_bank");
  command("look", this_player());
  return 1;
}

