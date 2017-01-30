inherit "/players/mizan/core/object.c";


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   

   set_get(1);


   set_short("The Wand of Anthrax");
   set_name("wand");
   set_long("This is a small glass wand with a questionable ooze contained\n"+
	        "within it. A label on the wand reads: \n"+
        	"'Break me to infect a widespread area of living things!'\n"+
	        "You are not too sure what that means.\n");

   set_weight(1);
   set_value(2600);
   set_save_flag(1);

   /* we only want 4 of these items in the game at any time */
   set_limited_issue(1);
   set_limited_issue_count(4);

   set_read("The wand has the inscription 'Made in Idaho' printed on it.\n");
   set_smell("The wand smells like mothballs.\n");
   set_taste("The wand taste a lot like licorice...\n");

}

init()
{
    add_action("on_break", "break"); 
    ::init();
}

on_break(arg)
{
    object tp;
    tp = this_player();

    if(!arg || arg != "wand") return 0;
    
    area_attack();
    tp->add_weight(-1);
    
    return 1;
}

area_attack() 
{
    object room,ob2,oc2;
    object ob,TP;

    TP=this_player();
    room=environment(TP);
    ob=first_inventory(room);

    write("You break the wand in half, and a viral scourge is released!\n");
    say((TP->query_name())+" breaks the Wand of Anthrax in half.\n");
    say((TP->query_name())+" ducks and just misses the microscopic scourge!'\n");
    
    while(ob) 
    {
        object oc;
        oc=ob;
        ob=next_inventory(ob);
        if(living(oc)) 
        {
            if(oc->query_npc() !=1) 
            {
                say((oc->query_name())+" seems to be immune to the disease.\n");
                write("You notice "+(oc->query_name())+" seems to be immune to the disease.\n");
            }
    
            if(oc->query_npc() == 1) 
            {
                write("You watch as "+(oc->query_name())+" is zonked by a hundred million screaming microbes.\n");
                say("A hundred million screaming microbes infect"+(oc->query_name())+"!\n");
                oc->hit_player(30+random(10));

                if(oc && !oc->query_attack()) 
                    oc->attack_object(TP); 
            }
        }
    }

    destruct(this_object());
    return 1;
}
