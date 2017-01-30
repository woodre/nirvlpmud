#include "/players/feldegast/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if (!arg){
    set_light(1);
    short_desc = "Temple Arena";
       long_desc = 
        "This is the center of the Arena, but it is inhabited by a large\n" +
        "red dragon.  He was sent by Benju Matsutomo to protect the\n" +
        "altar from good.  You probably cannot destroy him, and he will\n" +
        "more than likely destroy you!\n\n";
    dest_dir = 
        ({
        "players/paulasx/temple/temple_south", "south",
        "players/paulasx/temple/temple_north", "north",
        "players/paulasx/temple/temple_west", "west",
        "players/paulasx/temple/temple_east", "east",
        });
    items = 
        ({
        "treasures", "The usual things a dragon collects over a lifetime",
        });
  }
  if(!present("dragon", this_object())){
    object dragon,chainmail;
    dragon=clone_object("obj/monster");
    call_other(dragon,"set_name","dragon");
    call_other(dragon,"set_level",20);
    call_other(dragon,"set_hp",700); 
    call_other(dragon,"set_wc",35); 
    call_other(dragon,"set_ac",17); 
    call_other(dragon,"set_al",-200);
    call_other(dragon,"set_short","A large ferocious "+RED+"red dragon"+NORM);
    call_other(dragon,"set_long",
               "A huge dragon. His name is Aru and is rumoured to be the last.\n"+
               "of his kind. When you see him you really hope so. He looks like\n" +
               "he usually eat folks like you whole, and that his intent is to\n"+
               "prove it to you rather soon. He gives you a gaze that could\n"+
               "melt stone.  Fumes come out of his nostrils in a way that\n"+
               "makes you feel that this dragon is sure of himself. He has NO\n" +
               "thoughts about losing a battle. His scars make you realize why.\n"+
               "The feeling his gaze inflicts in you gives you an insight in the\n"+
               "term \"premonition\".\n");
   call_other(dragon,"set_alias","Jkannei");
    call_other(dragon,"set_spell_mess1","The dragon breathes fire!");

    call_other(dragon,"set_spell_mess2","The dragon breathes fire at you!");
    call_other(dragon,"set_chance",30);
    call_other(dragon,"set_spell_chance",60); 
                call_other(dragon,"set_spell_dam",23);
    
    chainmail=clone_object("/players/paulasx/armor/chainmail.c");
    /*
    call_other(chainmail,"set_name","chainmail");
    call_other(chainmail,"set_short",CYN+"Mithril Chainmail"+NORM);
    call_other(chainmail,"set_long",
               "This suit of chainmail is of such superior manufacture that it\n"+
               "is simultaneously protective and quite light.\n");
    call_other(chainmail,"set_alias","mithril chainmail");
    call_other(chainmail,"set_value",3000);
   call_other(chainmail,"set_weight", 2);
    call_other(chainmail,"set_ac",4);
    call_other(chainmail,"set_type","armor");
    */
     call_other(dragon,"add_money",random(3000));
    move_object(chainmail,dragon);
    move_object(dragon,this_object());
  }
}

query_light() {
    return 1;
}

/* additions to force a fight before continuing north  */
init() {
  ::init();
  add_action("north","north");
}

north() {
if(present("dragon")) {
  write("The dragon blocks your way!\n");
  return 1; }
else {
  this_player()->move_player("north#players/paulasx/temple/temple_north.c");
  return 1; }
}
