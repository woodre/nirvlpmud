inherit "obj/treasure";
query_auto_load(){return "/players/rumplemintz/wiz/nin.c:";}
reset(arg) {
	if(arg) return;
        name = "A tatoo of 'NIN'";
}
extra_look() {
	return ("\n"+
	"I still recall the taste, of your tears\n"+
	"Echoing your voice just like, the ringing in my ears\n"+
	"My favorite dreams of you still wash ashore\n"+
	"Scraping through my head 'til I don't wanna sleep, anymore\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I'm down to just one thing, and I'm starting to scare myself\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I just want something, I just want something, I can never have\n"+
	"\n"+
	"You always were the one, to show me how\n"+
	"Back then I couldn't do the things, that I can do now\n"+
	"This thing is slowly taking me apart\n"+
	"Gray would be the color, If I had a heart, come on tell me\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I'm down to just one thing, and I'm starting to scare myself\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I just want something, I just want something, I can never have\n"+
	"\n"+
	"In this world, it seems like such a shame\n"+
	"Though it all looks different now, I know it's still the same\n"+
	"Everywhere I look, you're all I see\n"+
	"Just a fading, fucking reminder of, who I used to be, come on tell me\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I'm down to just one thing, and I'm starting to scare myself\n"+
	"\n"+
	"You make this all, go away, You make this all, go away\n"+
	"I just want something, I just want something, I can never have.\n"+
	"\n"+
	"I just want something, I can never have.\n"+
	"\n"+
	"-----Trent Reznor\n");
}

id(str) { return (str == "nin" || str == "NIN"); }
short() { return name; }
long() {
	write("This is just an object that types out a song when people look at me.\n");
}
get() { return 1; }
query_value() { return (0); }
query_weight() { return (0); }
drop() { return 1; }
