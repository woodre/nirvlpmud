inherit "room/room";
reset(arg){
set_light(0);
short_desc="Female blood";
long_desc="You're just swimming around in the blood. There might \n"+
   "be things in the blood somewhere you could use. \n"+
   "I'm not sure, though.";
dest_dir=
({
  "/players/hippo/quest_2/uterus.c","diffuse",
   "/players/hippo/quest_2/glom.c","glomerulus",
   "/players/hippo/quest_2/lblood.c","east",
   "/players/hippo/quest_2/rblood.c","west",
});
}
