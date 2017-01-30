#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Training room";
  long_desc=
  "The training room for the mages.\n";

items=({
 });

  dest_dir=({
  "/players/daranath/workroom.c","home",
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
