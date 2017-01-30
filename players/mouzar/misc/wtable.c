int now;
id(str) {return str == "table";}
short() {return "A Huge Table";}
long() {write("You are looking at a Huge table with with some goodies on it.\n"+
	      "On the left side you see rows of beer in frosted mugs.  On the\n"+
	      "right side you see crystal wine glasses filled with fine red\n"+
	      "wine.  In the middle there is a HUGE 5 layer wedding cake. The\n"+
	      "cake has white frosting on it with different colored flowers and\n"+
	      "stuff on it.  There is a glass statue of a couple on top of it. As\n"+
	      "you look at the table a servant sees you and says just type\n"+
	      "out what you want.  If you want some wine just type 'wine'\n"+
	      "and so on.\n");return;}
get() {return 0;}
init () {
        add_action("beer","beer");
	add_action("wine","wine");
	add_action("cake","cake");
	add_action("cakenow","cakenow");
}
cakenow() {
	write("You make the first cut into the cake.\n");
        say(this_player()->query_name()+" makes the first cut into the cake.\n");
        now = 69;
        return 1;
}
       
beer() {
        move_object(clone_object("/players/mouzar/misc/wbeer.c"),this_player());
        write("You are served a cold beer.\n");
        return 1;
}
wine() {
        move_object(clone_object("/players/mouzar/misc/wwine.c"),this_player());
        write("You are served some red wine.\n");
        return 1;
}
cake() {
        if(now == 69) {
          move_object(clone_object("/players/mouzar/misc/wslice.c"),this_player());
          write("You are served a slice of cake.\n");
          return 1;
        } else {
          write("You must wait till the first cut is made!\n");
          return 1;
        }
}
