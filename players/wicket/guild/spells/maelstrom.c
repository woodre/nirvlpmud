#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object att, *ob, prevent;
	int h, s;
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_WATER() < 2){
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of this spell yet, young one!!.\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
		write(CYN+"Glyndwr"+NORM+" says: You are too drained to attempt this!!.\n");
		return 1;
	}
	
    s = sizeof(ob = all_inventory(environment(User)));
      
    while(h < s)
    {
	    if(att = (object)ob[h]->query_attack())
	    {
	    	ob[h]->stop_fight();
	    	att->stop_fight();
	    	ob[h]->stop_fight();
	    	att->stop_fight();
	    }
	    h++;
    }
    write("A "+BLU+"M"+NORM+HIK+"A"+NORM+BLU+"E"+NORM+HIK+"L"+NORM+BLU+"S"+NORM+HIK+"T"+NORM+BLU+"R"+NORM+HIK+"O"+NORM+BLU+"M "+NORM+" APPEARS IN THE ROOM, SWIRLING EVERYONE AND EVERYTHING AROUND!\n");
       write(HIK+"\n\n           OOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    write(HIK+"          OOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    write(HIK+"         OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    write(HIK+"        OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    write(HIK+"       OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                       \n"+NORM);
    write(HIK+"      OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                     \n"+NORM);
    write(HIK+"     OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                     \n"+NORM);
    write(HIK+"    OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    write(HIK+"   OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                  \n"+NORM);
    write(HIK+"  OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOOOO"+NORM+BLU+"XXXX                 \n"+NORM);
    write(HIK+"   OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                   \n"+NORM);
    write(HIK+"    OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    write(HIK+"     OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    write(HIK+"      OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                      \n"+NORM);
    write(HIK+"       OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                       \n"+NORM);
    write(HIK+"        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                                       \n"+NORM);
    write(HIK+"         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                                       \n"+NORM);
    say("\n\nThe "+BLU+"M"+NORM+HIK+"A"+NORM+BLU+"E"+NORM+HIK+"L"+NORM+BLU+"S"+NORM+HIK+"T"+NORM+BLU+"R"+NORM+HIK+"O"+NORM+BLU+"M "+NORM+"calms down and leaves the room quiet.\n"+NORM);
    say("A "+BLU+"M"+NORM+HIK+"A"+NORM+BLU+"E"+NORM+HIK+"L"+NORM+BLU+"S"+NORM+HIK+"T"+NORM+BLU+"R"+NORM+HIK+"O"+NORM+BLU+"M "+NORM+" APPEARS IN THE ROOM, SWIRLING EVERYONE AND EVERYTHING AROUND!\n");
    say(HIK+"\n\n           OOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    say(HIK+"          OOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    say(HIK+"         OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    say(HIK+"        OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                        \n"+NORM);
    say(HIK+"       OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                       \n"+NORM);
    say(HIK+"      OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                     \n"+NORM);
    say(HIK+"     OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                     \n"+NORM);
    say(HIK+"    OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    say(HIK+"   OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOO"+NORM+BLU+"XXXX                  \n"+NORM);
    say(HIK+"  OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXX"+NORM+HIK+"OOOOOO"+NORM+BLU+"XXXX                 \n"+NORM);
    say(HIK+"   OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                   \n"+NORM);
    say(HIK+"    OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    say(HIK+"     OOOO"+NORM+BLU+"XXXXX"+NORM+HIK+"OOOOOOOOOOOOOOOOOOOOOOOOOOOOO"+NORM+BLU+"XXXX                    \n"+NORM);
    say(HIK+"      OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                      \n"+NORM);
    say(HIK+"       OOOO"+NORM+BLU+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                       \n"+NORM);
    say(HIK+"        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                                       \n"+NORM);
    say(HIK+"         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                                       \n"+NORM);
    say("\n\nThe "+BLU+"M"+NORM+HIK+"A"+NORM+BLU+"E"+NORM+HIK+"L"+NORM+BLU+"S"+NORM+HIK+"T"+NORM+BLU+"R"+NORM+HIK+"O"+NORM+BLU+"M "+NORM+"calms down and leaves the room quiet.\n"+NORM);
    User->add_spell_point(-50);
    return 1;
}









