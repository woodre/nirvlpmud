
/*
 * SPARRING HALL (7/3/94)
 */

#define SPARRM "/players/molasar/sparring/sp_rm"
#define LIST "/players/molasar/sparring/list"
#define DENY this_player()->query_level() < 100

reset(arg) {
   if(!arg)
     set_light(1);
}

id(str) { return str == "armaments" || str == "mural"; }

init() {
   add_action("list","list");
   add_action("northwest","northwest");
   add_action("south","south");
   add_action("up","up");
   add_action("top_ten_list","top10");  
   add_action("help","help");
   add_action("rules","rules");
   /* RESTRICTED COMMANDS */   
   add_action("remove","remove");
   add_action("add","add");
   add_action("setwin","setwin");
   add_action("setlose","setlose");
   add_action("get_top10","gettop10");
}

northwest() {
   this_player()->move_player("the Sparring Hall"+
       "#players/molasar/rowan/e_twn_sq");
   return 1;
}

south() {
   if(SPARRM->query_locked()) {
     write("The sparring room is locked.\n");
     return 1;
   }
   this_player()->move_player("through the iron doors into the "+
       "Sparring Arena#players/molasar/sparring/sp_rm");
   return 1;
}

up() { 
   this_player()->move_player("up the marble staircase to the viewing "+
       "balcony#players/molasar/sparring/balcony");
   return 1;
}

short() { return "Sparring hall"; }

long(str) {
   if(str == "armaments") {
     write("Numerous swords, battle axes, shields, and other armors\n");
     write("are securely fastened to the walls.\n");
     return 1;
   }
   if(str == "mural") {
     write("Two knights stand facing each other, swords drawn.\n");
     write("The first knight is encased in gleaming platemail, the\n");
     write("second in armor as dark as night. In the background is\n");
     write("a sea and across the sea is an island with a dark tower\n");
     write("which seems to watch the two combatants closely.\n");
     return 1;
   }
   write("You are in the sparring hall.\n");
   write("Armaments of all kinds decorate the walls. A huge mural of a\n");
   write("battle between two knights covers the entire western wall.\n");
   write("Enormous marble pillars line the stairway which lead up to the\n");
   write("balcony where people may view any sparring matches in progress.\n");
   write("Here you may look at the scoring list to see all of the\n");
   write("participants records.  A top ten list is also available which\n");
   write("is updated at every reset.\n");
   write("Sparring Room:\t\t");
   if(SPARRM->query_locked())
     write("OCCUPIED\n");
   else
     write("[available]\n");
   write("Commands: list, top10, help, rules\n");
   if(this_player()->query_level() > 99) {
     write("WIZ COMMANDS:  remove, add, setwin, setlose, gettop10\n");
     write("               These are for manipulating the data file!\n");
     write("               Do not use without VERY GOOD reason.\n");
   }
   write("    There are three obvious exits: northwest, south, and up\n");
}

list() {
   LIST->show_players();
   return 1;
}

top_ten_list() {
   LIST->top_ten_list();
   return 1;
}

rules() {
   cat("/players/molasar/sparring/RULES");
   return 1;
}

help() {
   cat("/players/molasar/sparring/HELP");
   return 1;
}

remove(who) {
   if(DENY)
     return;
   LIST->remove_player(who);
   return 1;
}

add(who) {
   if(DENY)
     return;
   LIST->set_player(who);
   return 1;
}

setwin(str) {
   if(DENY)
     return;
   LIST->win(str);
   return 1;
}

setlose(str) {
   if(DENY)
     return;
   LIST->lose(str);
   return 1;
}

get_top10() {
   if(DENY)
     return;
   LIST->get_top_ten_list();
   return 1;
}
