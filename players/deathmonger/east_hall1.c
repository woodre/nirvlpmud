
#include "std.h"


object rabbit;
reset(arg){
    if(!arg){
    set_light(1);
    extra_reset();
    }
}

extra_reset(){
     if(!rabbit){
     rabbit = clone_object("obj/monster");
     rabbit->set_name("black rabbit");
     rabbit->set_alias("rabbit");
     rabbit->set_short("El-ahrairah, the Black Rabbit");
     call_other(rabbit, "set_long",
     "El-ahrairah, the Black Rabbit, is the famous rabbit folk hero of\n"+
     "Watership Down. He is here to stop high level players from killing\n"+
     "his flock. If you're a newbie, then you may pass freely. However,\n"+
     "if you are higher than level 8, El-hrairah will challenge you.\n"+
     "Be forewarned, high-level players. (If you have read Watership Down,\n"+
     "then you recognize El-hrairah, if not, you are an ignorant fool.)\n");
     rabbit->set_level(18);
     rabbit->set_wc(40);
     rabbit->set_ac(16);
     rabbit->set_hp(1000);
     rabbit->set_chance(80);
     rabbit->set_spell_dam(20);
     rabbit->set_spell_mess1("El-hrairah summons forth his lapine power upon you head!\n");
     rabbit->set_spell_mess2("El-hrairah calls upon his lapine fury!\n");
     move_object(rabbit, this_object());
     }
}

init(){
     add_action("north","north");
     add_action("west","west");
}

north(){
     if(rabbit && this_player()->query_level() > 8){

     rabbit->attack_object(this_player());
     write("El-hrairah, the Black Rabbit, leaps upon you!\n");
     return 1;
     }
     this_player()->move_player("north#players/deathmonger/CASTLE/rabbit_room");
     return 1;
}

west(){
     this_player()->move_player("west#players/deathmonger/hall1");
     return 1;
}

short(){ return "Entrance the Rabbit Land"; }
long(){
write("There stands before you a lone rabbit. It is clear that this is\n");
write("no ordinary rabbit. You can see rabbits grazing on a hill to the\n");
write("north.\n");
write("There are two obvious exits: west and north\n");
}
