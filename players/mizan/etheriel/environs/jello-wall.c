id(str) { return str == "wall" || str == "jello"; }
short() { return "A quivering wall of purple jello"; }
long() { write("Hmm. Yes, it is a wall of quivering purple jello.\n"+
	"The question is: Does it REALLY taste like grape?\n");
}
init() {
        add_action("touch","touch");
        add_action("eat","eat");
        add_action("dive","dive");
        add_action("think","think");
        }

lick(str) {
        if(!str) return 0;
        if(str=="jello") {
                write("You lick the wall of jello. Yummy! It does taste like grape!\n");
                say(capitalize(this_player()->query_name())+" licks the wall of jello.\n");
                return 1;
        }
}

eat(str) {
        if(!str) return 0;
        if(str=="jello") {
                write("You scoop off a chunk of the wall and devour it. Mmmmmmm.\n");
                say(capitalize(this_player()->query_name())+" scoops a handful of jello and eats it.\n");
                return 1;
        }
}

touch(str) {
        if(!str) return 0;
        if(str=="jello") {
                write("You touch the jello and watch it wiggle.\n");
                say(capitalize(this_player()->query_name())+" touches the jello. It wiggles.\n");
                return 1;
         }
}

dive(str) {
        if(!str) return 0;
        if(str=="jello") {
                write("You don't think that it would be a good idea..\n"+
"but you do it anyway, and arrive somewhere else..\n");
        this_player()->move_player("jello#players/mizan/etheriel/ROOMS/mizan.c");
        return 1;
        }
}

think(str) {
        if(!str) { write("Think hard!\n"); return 1; }
        if(str=="hard") {
             write("You ask yourself... How did I originally get into this place?\n");
                say(capitalize(this_player()->query_name())+" ponders the existence of jello in the universe.\n");
                return 1;
                }
        return 1;
        }
