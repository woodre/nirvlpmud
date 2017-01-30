inherit "room/room";
 
reset(arg){

  if(!present("knight"))
    move_object(clone_object("/players/snow/cam/mon/red"), this_object()); 

 if(!arg){

 set_light(1);
  short_desc="Above the clouds...";
 long_desc=
 "You have ascended above the clouds.. The sun shines brilliantly upon you.\n\
The small plateau you have reached is about halfway up the mountain.\n\
There is a cave entrance here and it seems to have been heavily travelled\n\
into recently. Strangely, there do not seem to be any tracks leading out\n\
of the cave. As you look up you realize you are nearing the ice fortress\n\
but the true peak of the mountain lies far above even that height..\n";
 
items=({
 "cave", "As you look into the cave, you can sense some sort of powerful \n" + 
             "animal presence",
 "tracks","These are tracks made by many sorts of animals, including humans",
 "fortress","The huge ice fortress looms above you, light reflecting brilliantly \n" +
                "off its myriad reflecting surfaces",
 "peak","The mountain summit shines in the sun",
 "clouds","The cloud cover hides the ground from your sight",
 "sun","The sun, free of clouds at last, shines down upon you",
 });
 
  dest_dir=({
  "/players/snow/ROOMS/fort_gate.c","up",
  "/players/snow/ROOMS/path2.c","down",
  "/players/snow/ROOMS/cave1.c","cave",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("enter_cave","enter cave");}
 
enter_cave() {
call_other(this_player(),"move_player","enter_cave#players/snow/ROOMS/cave.c");
say(this_player()->query_name()+" enters the dark lair\n");
if((this_player()->query_level()) < 6)  {
  write("Snow tells you: Moving further into this cave for you is surely death.\n");
return 1;  }
  }
 
