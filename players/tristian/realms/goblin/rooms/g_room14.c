#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";
int cloned_mob;


reset(arg) {
  if(arg) return;

set_light(1);

custom_exits = 1;

short_desc = "Goblin Encampment [n,e,s,w]";

long_desc =
    " The forest has started to encroach into this area of the camp, small\n"+
    "trees grow up amongst the knee high grasses. The grass moves slightly with\n"+
    "the breeze, but every now and then the grass seems to move on its own accord.\n"+
    "Brids can be heard farther out in the forest. The picket line is barely visble\n"+
    "to the north, making it impossible to leave into the forest in that direction.\n"+
    "    There are four obvious exits: east, west, northeast and northwest\n";

items = ({

    "line",
        "A low fence of sticks, twigs and small logs that prevents\n"+
        "going out into the forest, but more importantly prevents\n"+
        "intruders from coming in that way",
    "picket",
        "A low fence of sticks, twigs and small logs that prevents\n"+
        "going out into the forest, but more importantly prevents\n"+
        "intruders from coming in that way",
    "pines", 
        "Evergreen pines well over 100' tall",
    "forest",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
    "trees",
        "Small pines, no more than 10 feet in height", 
    "clearing",
        "An open area of the woods, mostly beaten down grass and dirt",
    "grass",
        "Waist high grass, looking closer you see beaten down trails\n"+
        "that look like something or someone has recently been through here",
    "trails",
        "Beaten down grass, you see some goblins crawling around on their\n"+
        "bellies, perhaps you can 'run' away from them",

});

}

    init()   {
        ::init();
            add_action("east","east");
            add_action("west","west");
            add_action("northeast","northeast");
            add_action("northwest","northwest");
            add_action("run","run");
            add_action("Smell","smell");
            add_action("Search","search");
            add_action("Listen","listen");
}

    east()   {

       if(!cloned_mob)   {

           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());


               write("As you try to leave some sappers jump up out of the grass blocking your exit.\n\n");
                   say("As "+TPN+" tries to leave some sappers jump up out\n"+
                       "of the grass and block the exit.\n");
               command("look",this_player());

       cloned_mob = 1;

       return 1;
}
       
          if(present("goblin_sapper"))    {
              write("As you try to leave the sappers block you from leaving.\n");
                  say("As "+TPN+" the sappers block them from leaving.\n");
     
       return 1;
}

              move_object(this_player(),RMS+"g_room15.c");
                  command("look",this_player());
        
       return 1;
}

    west() {

       if(!cloned_mob){

           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());

               write("As you try to leave some sappers jump up out of the grass blocking your exit.\n\n");
                   say("As "+TPN+" tries to leave some sappers jump up out\n"+
                       "of the grass and block the exit.\n");
               command("look",this_player());

       cloned_mob = 1;

       return 1;
}
       
          if(present("goblin_sapper")) {
              write("As you try to leave the sappers block you from leaving.\n");
                  say("As "+TPN+" the sappers block them from leaving.\n");
     
       return 1;
}

              move_object(this_player(),RMS+"g_room16.c");
                  command("look",this_player());
        
       return 1;
}

    northeast() {

       if(!cloned_mob){

           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());

               write("As you try to leave some sappers jump up out of the grass blocking your exit.\n\n");
                   say("As "+TPN+" tries to leave some sappers jump up out\n"+
                       "of the grass and block the exit.\n");
               command("look",this_player());

       cloned_mob = 1;

       return 1;
}
       
          if(present("goblin_sapper")) {
              write("As you try to leave the sappers block you from leaving.\n");
                  say("As "+TPN+" the sappers block them from leaving.\n");
     
       return 1;
}

              move_object(this_player(),RMS+"g_room13.c");
                  command("look",this_player());
        
       return 1;
}

    northwest() {

       if(!cloned_mob){

           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());
           move_object(
               clone_object(NPC+"goblin_sapper.c"),
                   this_object());

               write("As you try to leave some sappers jump up out of the grass blocking your exit.\n\n");
                   say("As "+TPN+" tries to leave some sappers jump up out\n"+
                       "of the grass and block the exit.\n");
               command("look",this_player());

       cloned_mob = 1;

       return 1;
}
       
          if(present("goblin_sapper")) {
              write("As you try to leave the sappers block you from leaving.\n");
                  say("As "+TPN+" the sappers block them from leaving.\n");
     
       return 1;
}

              move_object(this_player(),RMS+"g_room12.c");
                  command("look",this_player());
        
       return 1;
}


    run(str) {
        if(!str) {
            write("Run in which direction?\n");
        return 1;
}

    if(str == "east" || str == "e") {
        write("You run away from the sappers to the east.\n");
        say (TPN+" runs from the sappers to the east.\n");
    move_object(this_player(),RMS+"g_room15.c");
    command("look",this_player()); 
        return 1; 
}

    if(str == "west" || str == "w") {
        write("You run away from the sappers to the west.\n");
        say (TPN+" runs from the sappers to the west.\n");
    move_object(this_player(),RMS+"g_room16.c");
    command("look",this_player()); 
        return 1; 
}

    if(str == "northeast" || str == "ne") {
        write("You run away from the sappers to the northeast.\n");
        say (TPN+" runs from the sappers to the northeast.\n");
    move_object(this_player(),RMS+"g_room13.c");
    command("look",this_player()); 
        return 1; 
}

    if(str == "northwest" || str == "nw") {
        write("You run away from the sappers to the northwest.\n");
        say (TPN+" runs from the sappers to the northwest.\n");
    move_object(this_player(),RMS+"g_room12.c");
    command("look",this_player()); 
        return 1; 
}

    write("Run in which direction?\n");
        return 1;

}

  Smell(str) {
        if(!str || str == "air") {
            write("The smells of wood smoke and dirty goblins wafts through the air.\n");
    return 1;
}
    return 1;
}

  Search() {
        write("You search reveals goblins laying in ambush in the long grasses. Perhaps you can\n"+
              "'run' away from them in any direction.\n");
    return 1;
}

  Listen() {
        write("The general din of the goblin camp, and off further into the forest,\n"+
              "the sounds of birds chirping float on the afternoon breeze.\n");
    return 1;
}


    short() {
        return "Goblin Encampment [e,w,ne,nw]";
    }
