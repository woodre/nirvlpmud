inherit "room/room";

#define TP this_player()
#define TPN TP->query_name()

int smashes;

reset(arg){
 
  while( !present("ice demon 4") ) {
move_object(clone_object("/players/snow/MONSTERS/ice_demon.c"),this_object());
  }
 
 if(!arg){
 
 set_light(1);
  short_desc="In the tundra";
 long_desc=
 "You have come to a dead end. A huge glacier lies to every direction but\n\
south.The icy wind screams by your ears as you continue to wander\n\
through the tundra. The terrain seems a bit more slick here and you see\n\
patches of blue ice showing through the snow. Evidently, this is a\n\
favored haunt of the legendary ice demons.\n";
 
items=({
 "ice", "Patches of ice, rather hard. Some patches look thin enough to smash.",
 "tundra","A seemingly bleak and heartless plain of snow and ice",
            });
 
  dest_dir=({
  "/players/snow/ROOMS/tundra/tundra5.c","south",
      });
smashes = 0;
  }   }
 
 
init()  {
 ::init();
  add_action("smash_ice","smash"); 
         }
 
smash_ice(string str) {
  int i;
  if(!str || (str != "ice" && str != "the ice") ) {
    notify_fail("Smash what?\n"); return 0;
  }
 if(smashes > 2) {
    write("You smash the blue ice!\n...but nothing happens.\n");
    say(TPN+" smashes the blue ice!\n...but nothing happens.\n");
return 1;
  }
  write("You viciously smash the ice! Hordes of demons erupt forth!\n\n");
    say(TPN+" viciously smashes the blue ice! Demons erupt forth!\n\n");
  for(i=0; i < 4; i++) {
move_object(clone_object("/players/snow/MONSTERS/ice_demon.c"),this_object());
  }
  smashes++;
return 1;
}
