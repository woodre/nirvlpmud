inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_short("A wireless balance meter");
   set_long("This is very small electronic device that is ruggedized and seems\n"+
            "to only have one purpose. It has a button on it simply marked \n"+
            "as 'balance'. This is something that obviously belonged to a member\n"+
            "of the Monsters' Guild.\n");
   set_name("meter");
   set_alias("balance");
   set_weight(1);
   set_save_flag(1);
   set_value(30);

   set_read("There is nothing really written on the balance meter.\n");
   set_smell("The device smells like goat cheese.\n");
   set_taste("The device tastes a lot like goat cheese!\n");
}


query_value() { return 130; }

init() 
{
    ::init();
	add_action("on_balance","balance");
}

on_balance() 
{
    int bal;

    bal = "players/mizan/mbv2/nexusDM"->query_balance();
    
    say(this_player()->query_name() + " glances quickly at a small wireless dongle-sized device.\n");
    write("You hold down the 'balance' button and the display reads: " + ((bal * 100) / 1000000) + "%.\n");

    return 1;
}
