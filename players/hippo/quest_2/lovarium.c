inherit "room/room";
reset(arg){
set_light(0);
short_desc="Left ovarium";
long_desc="Not yet done.\n";
dest_dir=
({
   "/players/hippo/quest_2/lfimbria.c","jump",
});
}

init() {
    ::init();
    add_action("look");
}

look(str) {
	if(sscanf(str,"%s %s",str1,str)<2) return 0;
	if(str1<>"at") return 0;
	write("Not yet done.\n");
	return 1;
}
