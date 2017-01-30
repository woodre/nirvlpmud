
#include "std.h"

reset(arg){
     if(!arg){
     set_light(1);
     extra_reset();
     }
}

object baphomet;
extra_reset(){
     if(!present("baphomet")){
     baphomet = clone_object("players/deathmonger/MONSTERS/baphomet");
     move_object(baphomet, this_object());
     }
}

init(){
     if(present("blessing", this_player())){
       scare();
     }
     add_action("east","east");
     add_action("west","west");
}

west(){
     if(present("baphomet")){
       write("Baphomet stands in your way and pushes you back.\n");
       write("Baphomet says: Not so fast, mortal...<cackle>\n");
       return 1;
     }
     call_other(this_player(), "move_player",
       "west#players/deathmonger/UNDERDARK/gate1");
     return 1;
}

east(){
     call_other(this_player(), "move_player",
       "east#players/deathmonger/UNDERDARK/maze/maze16");
     return 1;
}

scare(){
     object head;
     write("Baphomet immediately sees that you carry a powerful blessing,\n");
     write("and decides to flee rather than face your power.\n");
     write("Baphomet says: You may have me beaten this time, but I'll be back!\n");
     write("Baphomet drops an adamantite head.\n");
     write("Baphomet throws his head back and cackles with glee.\n");
     write("Baphomet shifts back to the Abyssal Dimension.\n");
     destruct(baphomet);
     head = clone_object("players/deathmonger/QUEST/head");
     move_object(head, this_object());
     return 1;
}

short(){ return "Baphomet's Lair"; }

long(){
     write("You have entered a horrible lair of some sort, which fortunately\n");
     write("is not the lair of a wild minotaur.  It is strewn with bones,\n");
     write("and there is a cold chill in the air that makes you shiver.  Before\n");
     write("you stands Baphomet, Lord of the Minotaurs, who is no less than\n");
     write("a god of the Abyss.  He's ignoring you right now because a \n");
     write("mortal such as yourself couldn't possibly hurt him.  His glowing\n");
     write("red eyes and leather skin strike fear down your spine.\n");
     write("There are two obvious exits: west and east.\n");
}
