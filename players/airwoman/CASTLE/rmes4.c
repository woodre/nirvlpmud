inherit "room/room";
object joyboy, money;

reset(arg){
    if (!present("joyboy")){
       joyboy = clone_object("players/airwoman/MONSTER/joyboy");
	move_object(joyboy, this_object());
       money = clone_object ("obj/money");
       money->set_money(1276);
	move_object(money, joyboy);
    }

    if(!arg){
         set_light(1);
         short_desc = "The Loved One by Evelyn Waugh";
	long_desc =
	"Here appears to be Whispering Glades....\n"+
	"You see replicas of famous 18th century buildings around you.\n"+
        "This is where our loved ones can dwell in peace.\n"+
	"A place where we've always wanted to live in...\n";

	dest_dir=({"players/airwoman/CASTLE/rmes3", "north"});
}
}
