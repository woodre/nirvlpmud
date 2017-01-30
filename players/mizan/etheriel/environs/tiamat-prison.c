inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A HUGE crystal obelisk");
   set_long("This is a massive crystal obelisk, apparently some kind of plug\n"+
	        "to keep something VERY big from exiting... or entering this\n"+
	        "realm. Using your vast knowledge of geology, you deduce that\n"+
	        "a well placed shot to a certain part of the crystal with\n"+
	        "a stick big enough may completely shatter it.\n");

   set_name("crystal");
   set_alias("obelisk");

   set_read("There is nothing written on the obelisk.\n");
   set_smell("The obelisk smells a lot like burnt toast.\n");
   set_taste("The obelisk tates like nothing in particular and is cool to the touch.\n");

}



init() 
{
    ::init();
    add_action("lickme","smash");
    add_action("lickme","hit");
    add_action("lickme","shatter");
} 

lickme(str) 
{
    if(!str || str != "obelisk") return 0;

    if(!present("telephone pole", this_player()))
    {
        write("There is nothing on you that could possibly break this crystal.\n");
        return 1;
    }
    write("You take a big swing and smash away at the crystal.\n"+
    "Something inside it appears to be moving...\n\n"+
    "Suddenly, it explodes!\n\n"+
    "...and when you recover, you find yourself in a different place.\n");
    write("\n\n");

    say(this_player()->query_name() + " smashes the crystal obelisk with a telephone pole!\n\n");
    say("Bits of crystal and debris go flying all over the place!\n\n");
    this_player()->move_player("into a void#players/mizan/etheriel/ROOMS/tempest.c");
    move_object(clone_object("players/mizan/etheriel/environs/tiamat-portal.c"), environment(this_object()));
    command("poke tiamat", this_player());
    destruct(this_object());
    return 1;
}
