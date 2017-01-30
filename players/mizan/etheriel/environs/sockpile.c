inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A gigantic pile of socks");
   set_long("This is a terrifyingly large pile of dirty socks.\n"+
            "Whose were they? Why are they here? Ahhh. the mysteries of life.\n");

   set_name("pile");
   set_alias("socks");

   set_read("Upon examining the socks closer you realize they are all LEFT socks\n"+
            "There also appears to be a hole that you can 'squeeze' into.\nFascinating.\n");

   set_smell("The smell is excruciatingly horrifying.\n");
   set_taste("The taste must be quite satisfying and gamey if you are a dog.\n");
}


init()
{
    ::init();

    add_action("on_squeeze","squeeze");
}

on_squeeze()
{
    write("You squeeze into the pile and emerge elsewhere!\n");
    say(this_player()->query_name() + " squeezes into the sock pile.\n");
    this_player()->move_player("into the sockpile#players/mizan/etheriel/subrealms/sockworld/entrance.c");
    write_file("/players/mizan/logs/SUBREALM_SOCKWORLD", (this_player()->query_real_name() + " has found the sockpile on " + ctime() + "\n"));   

    return 1;
}