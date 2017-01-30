#include "/players/llew/closed/ansi.h"

inherit "obj/monster";

int pixie_price;

reset(moo) {
   ::reset(moo);
   if(moo) {
      return;
   }
   pixie_price=225+random(50);
   set_name("candyman");
   set_level(20);
   set_race("human");
   set_hp(750);
   set_wc(40);
   set_ac(20);
   set_al(1000);
   set_chat_chance(5);
   load_chat(short()+" smiles and says, \"Candy for sale!\"\n");
}

short() {
   string color;
   color=({RED,BLU,GRN,YEL,MAG,CYN,GRY,NORM});
   return "The "+color[random(8)]+"C"+NORM+color[random(8)]+NORM+"a"+NORM+color[random(8)]+"n"+NORM+color[random(8)]+"d"+NORM+color[random(8)]+"y"+NORM+color[random(8)]+"m"+NORM+color[random(8)]+"a"+NORM+color[random(8)]+"n"+NORM;
}

long() {
   write("The Candyman happily travels the paths on Nirvana\n");
   write("selling his candy to the sugar crazed masses.\n");
   write("His warm smile draws everyone to look at his sign:\n\n");
   write(RED+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("|                                      |\n");
   write("|                "+BOLD+"Candy"+NORM+RED+"                 |\n");
   write("|                                      |\n");
   write("|    "+HIB+"Pixie Sticks"+NORM+"..............."+BOLD+price("pixie")+NORM+RED+"    |\n");
   write("|                                      |\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"+NORM);
}

query_name() { return short(); }

price(candy) {
   switch(candy) {
      case "pixie":
         return pixie_price;
   }
}

init() {
   ::init();
   add_action("buy","buy");
}
