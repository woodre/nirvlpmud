
#include "std.h"

reset(arg){
     if(!arg){
     set_light(0);
     extra_reset();
}
}

object dwarf, sword;
int i;

extra_reset(){
i = 0;
if(!present("dwarf")){
while(i < 8) {
i += 1;
     dwarf = clone_object("obj/monster");
     dwarf->set_name("druegar");
     dwarf->set_alias("dwarf");
      dwarf->set_short(0);
     call_other(dwarf, "set_long",
       "Druegar dwarves are cavern-dwelling relatives of their mountain\n"+
       "loving surface relatives.  They are rather more powerful than the\n"+
       "usual dwarf, and have enhanced abilities.  Rumor has it that they\n"+
       "are quite evil and can turn invisible.\n");
     dwarf->set_level(10);
     dwarf->set_hp(150);
     dwarf->set_ac(8);
     dwarf->set_al(-100);
     dwarf->set_aggressive(1);
     sword = clone_object("obj/weapon");
     sword->set_name("short sword");
     sword->set_alias("sword");
     sword->set_short("A short sword");
     sword->set_class(8);
     sword->set_value(400);
          sword->set_weight(2);
     move_object(sword, dwarf);
     move_object(dwarf, this_object());
     dwarf->init_command("wield sword");
     }
}
}

init(){
     add_action("west","west");
}

west(){
     if(present("dwarf")){
       write("You are surrounded by Druegar dwarves!\n");
     return 1;
     }
     call_other(this_player(), "move_player",
       "west#players/deathmonger/UNDERDARK/tunnel6b");
     return 1;
}

short(){  return "An ambush"; }
long(){
     write("All you see is an empty room....but wait!\n");
}

