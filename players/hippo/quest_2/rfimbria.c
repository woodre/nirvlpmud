inherit "room/room";
reset(arg){
set_light(0);
short_desc="The right fimbria";
long_desc="Hmm.. you never seen things as complex as these twisting,\n"+
"strange bundle of strings. They twirl around as if they want to\n"+
grep something and lead it in here.";
dest_dir= ({
   "/players/hippo/quest_2/rtuba3.c","north",
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
