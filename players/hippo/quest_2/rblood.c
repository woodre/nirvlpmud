inherit "room/room";
reset(arg){
set_light(0);
short_desc="Female blood";
long_desc="You're just swimming around in the blood. There might \n"+
   "be things in the blood somewhere you could use. \n"+
   "I'm not sure, though.";
dest_dir=
({
   "/players/hippo/quest_2/ut_blood.c","east",
   "/players/hippo/quest_2/rstock3.c","diffuse",
   "/players/quest_2/rovarium.c","eggs",
});
}
