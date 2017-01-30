id(str){return str == "rose";}
short() { return "A sweet rose"; }
get(){ return 1; }
long() {write("A rose only for the one I love the most.\n"+
"Glimmering, and trembling, trembling and unfolding, a breaking\n"+
"light, an opening rose, it spreads in endless succession to\n"+
"itself, breaking in full crimson and unfolding, and fading to\n"+
"palest rose, leaf by leaf and wave of light by wave of light,\n"+
"flooding all the heavens with its soft flushes, every flush\n"+
"deeper than other.\n");}
 
init() {
add_action("smell","smell");
}
smell(str) {

    say(this_player()->query_name()+" smells the everlasting rose...\n");
    write("You smell the delicate yet beautiful rose. The\n"+
           "aroma overwhelms you and dazes for a split sec...\n");
	return 1;
        }
            
