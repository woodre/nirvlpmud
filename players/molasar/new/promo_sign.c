
/*
 * SIGN FOR PROMO DATA
 */

#define MAIN "/players/molasar/promo"


reset(arg) {
   if(!arg)
     move_object(this_object(), "room/adv_inner");
}

id(str) { return str == "sign" || str == "promo_sign"; }

get() {
   write("It is fastened securely to the wall.\n");
   return 0;
}

short() { return "A large sign covers the wall"; }

long() {
   write("}-=-=-=-=-=-{ Nirvana Castle and Guild Guide }-=-=-=-=-=-{\n");
   write("}         Here you may recieve information about         {\n");
   write("}         all wizards with open castles or guilds.       {\n"); 
   write("}-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-={\n");
   write("COMMANDS: castles, castles <wizard>, guilds, guilds <wizard>\n");
   if(this_player()->query_level() > 20) {
     write("WIZ COMMANDS: add <castle/guild>, remove <castle/guild>\n");
   }
}

init() {
   add_action("castles","castles");
   add_action("guilds","guilds");
   if(this_player() && this_player()->query_level() > 20) {
     add_action("add","add");
     add_action("remove","remove");
   }
}

castles(str) {
   MAIN->show_castles(str);
   return 1;
}

guilds(str) {
   MAIN->show_guilds(str);
   return 1;
}

add(str) {
   MAIN->add(str);
   return 1;
}

remove(str) {
   MAIN->remove(str);
   return 1;
}

