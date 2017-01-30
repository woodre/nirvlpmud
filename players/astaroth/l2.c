#include        "std.h"
 
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
ONE_EXIT("players/astaroth/workroom", "out",
         "Astaroth's protected Workroom",
         "This is Astaroth's protected Workroom.\n"+
         "He can specify anyone he doesn't want to get in.\n"+
         "These people tend to be either nuicances or just higher level people\n"+
         "who may like to remain invisible when they enter.\n",
         1)
 
 
extra_init() {
  object intrude;
  string who;
 
    who = call_other(this_player(), "query_real_name");
   if ((who != "astaroth") && (who != "chevren")) {
       write("This room is protected by a wizard forcefield.\n");
       write("Just to let Astaroth know you want in, you knock politely.\n");
       move_object(this_player(),"players/astaroth/entrance");
       intrude = find_player("astaroth");
       if (intrude) tell_object(intrude, who +" knocked.\n");
    }
}
