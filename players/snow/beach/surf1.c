inherit "room/room";
 
reset(arg){
 
if(!present("killer whale 2"))  {
move_object(clone_object("/players/snow/MONSTERS/killer_whale"),this_object());  }
if(!present("arctic seal 2")) {
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object()); }
 
 if(!arg){
 
 set_light(1);
  short_desc="In the surf";
 long_desc=
"You stand in the ice-cold surf of an arctic beach.\n"+
"The sun shines brightly above while the cold water surges about\n"+
"your feet. There appears to be something beneath the murky water\n"+
"a little farther out.\n";
 
items=({
 "sun", "The sun is bright but doesn't seem to warm you much",
 "rocks","Jagged rocks beaten by the surf",
  "something","You would have to dive under the water to see it clearer",
  "water","You see something under the water but you would have to dive down to see it clearer",
 "surf","Waves crash upon the shore",
  });
 
  dest_dir=({
  "/players/snow/beach/beach1","beach",
  "/players/snow/beach/surf2","north",
});
  }   }
 
init() {
  ::init();
  add_action("dive_under","dive");
}

dive_under() {
  if(this_player()->query_level() < 15) {
    write("You cannot swim down far enough yet.\n"); return 1; }
  say(this_player()->query_name()+" dives into the cold surf!\n");
  write("You dive into the cold surf!\n");
  write("\n\tYOU ARE SUCKED UNDER!\n\n");
  move_object(this_player(), "/players/snow/water/hall");
  write("You find yourself in a strange place...\n");
  command("look", this_player());
  return 1; }
