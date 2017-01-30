/* verte 6.5.01 - changed the full heal to actually heal.
    changed the hit_player to other|lightning */
#define tp this_player()->query_name()
inherit "room/room";
string heal_count;
int i;
reset(int arg){
if(!present("saber_lich")) {
move_object(clone_object("/players/saber/monsters/stormlich.c"),this_object()); }
if(!present("storm")) {
move_object(clone_object("/players/saber/effects/storm.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Center of the Storm";
long_desc=
 "You have entered into the center of the raging storm.  As you enter the\n"+
 "wind lashes at your body and pulls you into the air.  Flying amidst the\n"+
 "chaos, you notice that the storm seems to be radiating from one central\n"+
 "point.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "throne","The Throne of the storm Lich.  Only the master of the storm\n"+
   "may safely 'sit' upon it",
 "storm","A storm of colossal proportion rages about you",
 "center","There is a large throne floating in the middle of the storm",
 "point","There is a large throne floating in the middle of the strom",
 "wind","The wind is howling with the force of a banshee",
 "ground","There is no ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20+12.c","out",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("sit","sit");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str)  {
object ob;
if(!str)  {
  write("Sit on what?\n");
  say(tp+" looks around for a place to sit.\n");
  return 1;
     }
if(str == "throne") {
if(present("saber_lich")){
 write("The Storm Lich blocks your path to the throne.\n"+
    "Storm Lich whispers: Thou shalt not sit there while my bones still move...\n");
  say(tp+" flies towards the throne.\n"+
   "The Strom Lich materializes in front of "+tp+" in a burst of lightning\n"+
  "Storm Lich whispers: Thou shalt not sit there while my bones still move...\n");
   return 1;
     }
if(!present("staff of power", this_player())) {
ob = this_player();
 write("You must be master of the storm to sit on this throne.\n");
 write("You are struck by a bolt of lightning.\n");
ob->hit_player(30 + random(35), "other|lightning"); /* by verte */
 return 1;
     }
write("You sit upon the throne of the Storm King.\n");
if(heal_count < 1) {
write("You are fully healed.\n");
this_player()->heal_self(1000);
heal_count = heal_count + 1;
  return 1;
     }
  return 1;
   }
write("Sit on what?\n");
 return 1;
   }
