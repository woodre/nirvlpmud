#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Deep within the tower of Sorcere";
  long_desc=
  "Blackened walls close all about this small chamber, deep within\n"+
  "the fabled tower of Sorcere. Dark red viens of a foreign metal run\n"+
  "throughout the stone, bringing a sense of life to the obsidian\n"+
  "walls. An erie red light glows softly from the floor, carved in\n"+
  "the shape of a large series of triangles all about.\n";

items=({
  "wall", "The black stone of the walls is set with a dark red\n"+
          "ruby veins running all throughout them\n",
  "light", "The erie light eminates from the pattern on the floor",
  "pattern", "The pattern on the floor is of interlocking triangles\n"+
             "and ancient writing all about",
  "stone", "The stone of the walls is very rare and valuable",
 });

  dest_dir=({
  "/players/daranath/underdark/sorcere2.c","south",
           });
  }
}

init(){
 ::init();
  add_action("search","search");
  add_action("study","study");
}

search() {
write("You find nothing about the dark city.\n");
say (tpn +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
realm() { return "NT"; }

study(str) {
  if(str == "magic_missile") {
  present("guild_ob",tp)->add_perc(0,5);
  tp->add_exp(-1000);
  write("You gain in the knowledge of the spell.\n");
  return 1; }

  if(str == "shield") {
  present("guild_ob",tp)->add_perc(1,5);
  tp->add_exp(-1000);
  write("You gain i nthe knowledge of the spell.\n");
  return 1; }

  if(str == "spidercraft") {
  present("guild_ob",tp)->add_perc(2,5);
  tp->add_exp(-1000);
  write("You gain in the knowledge of the spell.\n");
  return 1; }

  write("There is no such spell available to you.\n");
  return 1; }
