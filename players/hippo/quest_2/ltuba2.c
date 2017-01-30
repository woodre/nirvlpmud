inherit "room/room";
reset(arg){
set_light(0);
short_desc="The tuba uterina sinistra";
long_desc="You are in a small round hallway with flexible soft walls.\n"+
"From the way they are built, you have the idea that this tube\n"+
"might have an important function.\n";
dest_dir= ({
   "/players/hippo/quest_2/ltuba3.c","west",
   "/players/hippo/quest_2/ltuba1.c","east",
});
}

init() {
    ::init();
    add_action("look");
}

look(str) {
	if(sscanf(str,"%s %s",str1,str)<2) return 0;
	if(str1<>"at") return 0;
	if(str=="walls"||str=="wall") {
		write("The walls are very soft and flexible. This makes you think \n"+
		"that even very fragile things like eggs could be kept or\n"+
		"transportated in here.\n");
		return 1;
	}
	return 0;
}
