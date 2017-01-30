#define tp this_player()->query_name()
inherit "room/room";
string elemental_count;
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain High";
long_desc=
 "You stand just below the mountain peak.  Above you a terrible storm rages,\n"+
 "unleashing ominous sounding thunder and occasional flashes of nerve racking\n"+
 "lightning.  To the east is the traditional resting place of He Who Must Wait.\n"+
 "Ice lies around you, and the storm waits above.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "path","A small animal path leading to the south",
 "cliff","You stand at the base of a large cliff",
 "mountain","The peak of the mountain looms above you",
 "peak","The peak of the mountain looms above you",
 "storm","A storm of colossal proportion rages above you",
 "ice","The trail is covered with ice",
 "lightning","Lightning blazes forth from the heart of the storm.\n"+
    "It almost looks like you could reach out and 'grab' some",
 "thunder","Ominous sounding thunder rages in the heart of the storm",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+12.c","up",
 "/players/saber/tower/tower20+8.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("grab","grab");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

grab(str)  {
 if(!str) {
   write("Grab what?\n");
          }
if(str == "lightning") {
if(elemental_count < 1) {
 write("You reach out and grab a passing bolt of lightning!\n"+
   "The lightning squirms out of your hand and grows in size...\n"+
   "You have summoned a LIGHTNING elemental.\n\n");
 say(tp+" reaches out and grabs a passing bolt of lightning!\n"+
   tp+" has summoned a LIGHTNING elemental!\n\n");
move_object(clone_object("/players/saber/monsters/lightning.c"),this_object());
elemental_count = elemental_count + 1;
   return 1;
   }
write("The lightning has already been grabbed.\n");
  return 1;
}
write("That is not here to grab.\n");
 return 1;
}
