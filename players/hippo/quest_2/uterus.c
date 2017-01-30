inherit "room/room";
int blood;
reset(arg){
	blood=0;
	set_light(0);
	short_desc="The uterus";
   long_desc="As you look around, you see dark red, irregular walls\n"+
	"with large, fast wiggling tubes that grab your attention.\n"+
	"The continuous motion of the weak, wet walls and the sparse\n"+
	"light that enters this place through a large gap at the south,\n"+
	"give it a scary look. The place seems big enough to give room\n"+
	"to a small hippo baby.\n"+
	"One large exit, from where the light enters, is located in the\n"+  
	"south corner of this triangular shaped place. There are two \n"+
  "dark, small, identical holes in the east and west corners.\n";
/*
	addition();
*/
	dest_dir= ({
	   "/players/hippo/quest_2/ltuba1.c","west",
	   "/players/hippo/quest_2/rtuba1.c","east",
	   "/players/hippo/quest_2/vagina.c","south",
	});
	move_object(clone_object("/players/hippo/quest_2/c/cell22.c"),this_object());
	move_object(clone_object("/players/hippo/quest_2/c/cellx.c"),this_object());
}

init() {
    ::init();
   add_action("look_no","look");
   add_action("diffuse","diffuse");
}

look_no(str) {
   string str1;
   if(!str) return 0;
	if(sscanf(str,"%s %s",str1,str)<2) return 0;
	if(str1!="at") return 0;
	if(str=="walls"||str=="wall"||str=="muscle") {
		format("As you approach the wall closer and touch it, it strongly deforms\n"+
		"at that specific place. The walls are wet and there run some sort\n"+
		"of bundles over it. Then you recognize the tissue as muscle, and\n"+
		"realize that it's all around. If the muscle would become active\n"+
		"with you inside, the only way out were back to the vagina.\n");
		return 1;
	}
	if(str=="gap"||str=="large gap") {
		format("A large gap that you looks very familiar to you. Vage memories\n"+
		"take you to a long time back, to the time before your birth. The\n"+
		"harder you try to remember, the more you realize that you have\n"+
		"been looking at this gap for month, and finally entered it to\n"+ 
		"escape fomr something. However, you just cannot remember all\n"+
		"the details.\n"+
		"Maybe you could enter it to find out?\n");
		return 1;
	}
	if(str=="tubes") {
		blood=1;
		format("There are two types of tubes around. One type looks weaker, with a\n"+
		"blue shining over it. The others are stronger and red and pulsate\n"+
		"with a steady frequency of 60 to 70 beats per minute. Furthermore\n"+
		"there are a bunch of smaller tubes around.\n"+
		"Obviously, these tubes are arterial and venous vessels, together\n"+
		"providing the tissue with oxigen and other metabolites. To see\n"+
		"what's inside these vessels, you could diffuse into it.\n");
		return 1;
	}
	return 0;
}

addition() {
	if(blood) write("You could also diffuse into the blood.\n");
	return 1;
}

diffuse() {
	if(blood) {
		write("You suddenly diffuse into the blood.\n");
		move_object(this_player(),"/players/hippo/quest_2/ut_blood.c");
		return 1;
	}
	else { return 0; }
}

