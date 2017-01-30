
/*
 * ROWAN STABLE (4/17/94)
 */

#include "/room/clean.c"

#define STABLE "/players/sandman/paladin/stable"
#define HELPDIR "/players/molasar/rowan/helpdir/"
#define SPEAK(x) write("The stablehand says: "+x);
#define COST 1000

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object hand;
   if(!present("stablehand")) {
     hand = clone_object("/obj/monster");
     hand->set_name("stablehand");
     hand->set_alias("hand");
     hand->set_level(2);
     hand->set_hp(60);
     hand->set_al(22);
     hand->set_wc(5);
     hand->set_ac(1);
     hand->set_short("The stablehand");
     hand->set_long("A middle-aged stablehand dressed in overalls.\n");
     move_object(hand, this_object());
   }
}

id(str) { return str == "sign"; }

short() { return "A stable  [s]"; }

long(str) {
   if(str == "sign") {
     write("\n"+
           "   ------------------------------------- \n"+
           "  |                                     |\n"+
           "  | Here you can purchase a horse to    |\n"+
           "  | ride or aid in carrying items.      |\n"+
           "  |                                     |\n"+
           "  | Cost is "+COST+" gold pieces            |\n"+
           "  |                                     |\n"+
           "  | Command: buy <horse>                |\n"+
           "  |                                     |\n"+
           "  | Type 'horse' for more information.  |\n"+
           "  |                                     |\n"+
           "   ------------------------------------- \n\n");
     return 1;
   }
   write("This is a large horse stable.  Stalls line the walls to the\n"+
         "north and south.  A large sign is hung on the western wall.\n"+
         "   There is one obvious exit:  south\n");
}

init() {
   add_action("south","south");
   add_action("buy","buy");
   add_action("read","read");
   add_action("horse","horse");
}

south() {
   this_player()->move_player("south#players/molasar/rowan/road3");
   return 1;
}

horse() {
   cat(HELPDIR+"H_HELP");
   return 1;
}

read(str) {
   if(str == "sign") {
     this_player()->look("at sign");
     return 1;
   }
}

buy(str) {
   object guild, horse, pack;
   string owner;

   if(!str) {
     write("You may buy horses here.\n");
     return 1;
   }
   if(!present("stablehand")) {
     write("The stablehand is not here at the moment.  Come back later.\n");
     return 1;
   }
   if(str == "horse") { 
/* Added by Snow 11/99 */ SPEAK("I'm sorry I cannot sell horses anymore.\n"); return 1;
     if(this_player()->query_money() < COST) {
       SPEAK("You do not have enough money.\n");
       return 1;
     }
     this_player()->add_money(-COST);
     owner = this_player()->query_real_name();
     horse = clone_object("players/molasar/rowan/obj/horse");
     horse->set_owner(owner);
     pack = clone_object("players/sandman/paladin/obj/pack");
     move_object(pack, horse);
     transfer(horse, this_object());
     say("The stablehand leads a black horse out to "
                                               +capitalize(owner)+".\n");
     write("You purchase a horse.\n");
     return 1;
   }
   return;
}

