#include "std.h"
object man; 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
    object  treasure;
 
    if(!present("man")) {
        man = clone_object("obj/monster");
        call_other(man, "set_name", "wizened man");
        call_other(man, "set_level", 19);
        call_other(man, "set_hp", 800);
        call_other(man, "set_ac", 12);
        call_other(man, "set_alias", "man");
        call_other(man, "set_al", 0);
        call_other(man, "set_wc", 9);
        call_other(man, "set_aggressive", 0);
        call_other(man, "set_chat_chance",10); 
        call_other(man, "load_chat",
             "Remember, just 'say I want to kill' then the name, my son.\n");
        call_other(man, "set_chance", 90);
        call_other(man, "set_spell_mess1", "The wizened man looks pissed.");
        call_other(man, "set_spell_mess2",
                  "The wizened man says 'take that!!!'");
        call_other(man, "set_spell_dam", 40);

       call_other(man, "set_object", this_object());
        call_other(man, "set_function", "want_to");
        call_other(man, "set_type", "says:");
        call_other(man, "set_match", " ");

       treasure = clone_object("obj/treasure");
        call_other(treasure, "set_id", "periapt");
        call_other(treasure, "set_alias", "periapt");
        call_other(treasure, "set_short", "a jewelled periapt");
        call_other(treasure, "set_weight", 1);
        call_other(treasure, "set_value", 4000);
        transfer(treasure, man);
        move_object(man, this_object());
        }
}

	
   TWO_EXIT ("players/kyle/cast/entrance5", "north",
             "players/kyle/cast/entrance7", "south",
           "Sage's place",
           "  You have come to a small grassy area.  In the midst is an\n"+
           "old man tilling the soil.  He sees you and beckons you forward.\n"+
           "After you approach, he whispers into your ear....\n"+
           "\n"+            
           "  'Well, now, it is nice to see you.  You are looking well.\n"+
           "And yet... Something is troubling you, isn't it...?\n"+
           "No, the world is not a nice place.  But I can help you, relieve\n"+
           "your tensions for at least a little while.'  He peers into your eyes.\n"+
           "'There is somebody troubling you, is there not?  Somebody you would\n"+
           "like to rip apart into bloody little pieces.  No, don't deny it.\n"+
           "Deep down inside, everyone knows someone that they would like to see\n"+
           "burn in hell.  Do not be afraid of repressing such desire here, \n"+
           "adventurous one.  Simply 'say I want to kill' followed by they name\n"+
           "of he or she who has earned your hatred, and walk south.  You will\n"+
           "not be... disappointed....'\n"+
           "Oh.  No capital letters, young one.  Got it?\n\n"+
           "The wizened man laughs.  'Well?'\n" ,1)      

want_to(str) {
    string a, b, c;
    object monstt, guy,treasure;
    int lev,amcl,hitp;

    if (!sscanf(str, "%s says: %s\n", c, b) == 2)
	return;


    str = b;
    monstt = clone_object("obj/monster");
        call_other(monstt, "set_name", b);
        lev = (call_other(find_living(lower_case(c)), "query_level"));
        amcl = (call_other(find_living(lower_case(c)), "query_alignment"));
        call_other(monstt, "set_level", lev-1);
        call_other(monstt, "set_hp", 70+10*lev);
        call_other(monstt, "set_al", -amcl);
        call_other(monstt, "set_race", "enemy");
        call_other(monstt, "set_short", "Before you, you see "+b);
        call_other(monstt, "set_ac", lev/2 + 2);
        call_other(monstt, "set_wc", lev+4);
        call_other(monstt, "set_aggressive", 0);
        call_other(monstt, "set_can_kill", 1);
        treasure = clone_object("obj/treasure");
        call_other(treasure, "set_id", "an ornately carved something or other");
        call_other(treasure, "set_alias", "something");
        call_other(treasure, "set_short", "an ornately carved something or other");
        call_other(treasure, "set_weight", 2);

        call_other(treasure, "set_value", 1000-50*(20-lev));
        move_object(treasure, monstt);

        
   



        move_object(monstt, "players/kyle/cast/entrance7.c");
	      
}
