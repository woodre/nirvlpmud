
#include "std.h"


#undef EXTRA_RESET
#undef EXTRA_INIT
#define EXTRA_RESET extra_reset();
#define EXTRA_INIT extra_init();
object mayor, mycon;
object mushroom, friend;
object dude;
extra_reset(){
     if(!present("myconid")){
       mycon = clone_object("players/deathmonger/UNDERDARK/mycon/myconid");
       mycon->set_short("Captain of the Myconid Guard");
       mycon->set_name("captain");
       move_object(mycon, this_object());
     }
     if(!present("mayor")){
       mayor = clone_object("players/deathmonger/MONSTERS/mycoking");
       move_object(mayor, this_object());
     }
}

extra_init(){
     add_action("give", "give");
     dude = this_player();
}

query_dude(){ return dude; }

give(str){
     if(str == "mushroom to mayor"){
     if(!present("mushroom", this_player())){
         write("You don't have any mushroom.\n");
         return 1;
       }
       write("You give the mushroom to mayor.\n");
       write("The mayor smiles and gives you his symbol of friendship.\n");
       mushroom = present("mushroom", this_player());
       destruct(mushroom);
       friend = clone_object("players/deathmonger/QUEST/friend");
       move_object(friend, this_player());
       return 1;
       }
}
ONE_EXIT("players/deathmonger/UNDERDARK/mycon/mycon3","west",
         "Myconid mayor's hut",
         "You are in the hut of the mayor of this myconid village.\n"+
         "The owner wants to know what you want.\n", 1)
