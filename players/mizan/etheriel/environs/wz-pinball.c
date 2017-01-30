inherit "/players/mizan/core/object.c";

string lastnamer;
int a, x, pt, m;

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A Wacky Zacko pinball machine");
   set_long("This is a Wacky Zacko Pinball Machine. You can play\n"+
            "for the cost of 20 spell points. If you get a high score,\n"+
            "you have a chance of making more spell points back.\n"+
            "\n"+
            "Type 'play pinball' to play (Another KDY product).\n");

   set_name("machine");
   set_alias("pinball");

   set_read("There is graffiti and stickers plastered all over the machine.\n");
   set_smell("The machine smells a lot like an arcade. I wonder why!\n");
   set_taste("The machine tastes like sugary dirt.\n");

}

init() 
{ 
	add_action("on_play","play");
    ::init();

}

on_play(str) 
{
	if(!str) return 0;

    if(str="pinball") 
    {
	    if((this_player()->query_sp())<20) 
        {
            write("I'm sorry, you need 20 sp to play and you only have ["+
	        this_player()->query_sp()+"]sp\n");
            return 1; 
        }
	
        call_other(this_player(), "add_spell_point", -20);
	    x=(random(98));


    	m=(random(100)+(x*1000));

        if(x>88 && this_player()->query_real_name() != lastnamer) 
        {
	        write("DING DING DING!! JACKPOT!!! You kicked some ass!! ["+
        	(m+1000000)+"] points!!\n");
        	write("You are the Pinball Wizard!!\n");
	        
            say((this_player()->query_name())+" hit the jackpot!!! ["+
        	(m+1000000)+"] points!!!\n");
            this_player()->heal_self(1000);
            lastnamer=this_player()->query_real_name();
        	return 1;
	    }

        write("You load the machine with 20 sps...\n");
	    write("Ding! Boink! Bleep! Blam! Chung! Klang! Doink! Wibble!\n");
	    write("The last ball slips past you, and the game ends.\n");
	    write("You score was ["+m+"] points.\n");
	    say((this_player()->query_name())+" plays a game of pinball. Score ["+m+"] points.\n");
	    pt=x/3;
	    write("You made back ["+pt+"]sp\n");
	    call_other(this_player(), "add_spell_point", pt);
	    return 1;
    }
    return 0;
}
