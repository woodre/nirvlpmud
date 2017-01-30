id(str) {return str == "sign"; }
reset(arg) {if(arg) return; }
long() { write("\n"+
	"This is a map to Town Central, since many of you don't know where\n"+
	"it is located.  You can find a shop, bar, and pretty much anything you\n"+
	"need on you journies.\n"+
	"__________________________________________________________________\n"+
	"|                                                                |\n"+
	"|         *--Cloud                                               |\n"+
	"|         -                                                      |\n"+
        "|         *                                - means go up         |\n"+
	"|         -                                                      |\n"+
	"|         *              When you get to the cloud, type ride.   |\n"+
	"|         |              Then explore all ya want, more to come. |\n"+
	"|         *                                                      |\n"+
	"|         |                                                      |\n"+
        "|         *                                                      |\n"+
        "|         |                                                      |\n"+
        "|         *                                                      |\n"+
        "|         |                                                      |\n"+
	"|         *                                                      |\n"+
	"|         |                                                      |\n"+
	"|         *            Church                                    |\n"+
	"|         |               |                                      |\n"+
	"|         *---*---*---*---*                                      |\n"+
	"|                                                                |\n"+
	"------------------------------------------------------------------\n"+
	"Good luck, and I hope ya like it.               --Rump            \n");
	}
short() { return "A sign"; }
get() {
	write("It is too heavy to pick up.\n");
	return 0;
	}
