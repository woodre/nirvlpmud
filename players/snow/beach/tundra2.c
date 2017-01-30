inherit "room/room";

int found;
 
reset(arg){
 
if(!present("arctic wolf 3"))  {
move_object(clone_object("/players/snow/MONSTERS/arctic_wolf"),this_object());
move_object(clone_object("/players/snow/MONSTERS/arctic_wolf"),this_object());
move_object(clone_object("/players/snow/MONSTERS/arctic_wolf"),this_object());  }
if(!present("beach bear")) {
move_object(clone_object("/players/snow/MONSTERS/beach_bear"),this_object()); }
 
  found = 0;
 if(!arg){
 
 set_light(1);
  short_desc="Coastal tundra";
 long_desc=
"Rolling, wild, windswept hills define this bleak area. The arctic tundra\n"+
"appears to be a harsh land. The hardened loam is scuffed up underfoot here.\n";
 
items=({
 "sun", "The sun is bright but doesn't seem to warm you much",
 "hills","Wind whips through the small crests and valleys of these mounds of earth",
 "wind","A fierce wind blowing toward the beach",
"loam","The soil looks like it has been recently turned for some reason",
  });
 
  dest_dir=({
  "/players/snow/beach/beach2","west",
  "/players/snow/beach/tundra1","south",
});
  }   }

init() {
  ::init();
  add_action("search","search");
  add_action("dig","dig");
}

search() {
  if(present("bear")) {
    present("bear")->attack_object(this_player());
    return 1; }
  if(found) { write("You search and find nothing.\n"); return 1; }
  write("You search about and see a faint glow coming from the disturbed earth.\n");
  return 1; }

dig() {
  if(present("bear")) {
    present("bear")->attack_object(this_player());
    return 1; }
  if(found) {
    write("You dig around and find nothing.\n");
    return 1; }
  if(!found) {
    write("You dig down into the hardened loam...\n"+
          "\n\tYou find a glowing knife!\n");
    move_object(clone_object("/players/snow/WEAPONS/glowknife.c"), this_object());
    found = 1;
    write_file("/players/snow/closed/q/knife", ctime(time())+
      " "+this_player()->query_real_name()+" found the glowknife.\n");
    return 1; }
}
