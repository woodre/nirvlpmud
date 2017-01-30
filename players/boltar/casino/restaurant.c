
#include "room.h"
#define FOODS 1000
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s)\
 write("The Waitress says: "+s+"\n")

int cm,mm,rmm,af,bf,cf,df;
string last_eater;

#undef EXTRA_RESET
#define EXTRA_RESET\
  cm=FOODS*4;\
  mm=FOODS*2;\
  rmm=FOODS;\
  af=FOODS;\
  bf=FOODS;\
  cf=FOODS;\
  df=FOODS;\
  if(arg) return;\
  items=({"menu"," ","goblet"," ","plate"," ","station"," ","doorway"," ",\
          "door"," ","sign", " ","draperies"," ","curtains"," ",\
          "ceiling"," ","floor", " ","carpet"," ","sconces"," ",\
          "sconce"," ","flames", " ","flame"," ","wall"," ","walls"," ",\
          "table"," ","tables", " ","tablecloth"," ","candelabra"," ",\
          "candelabras"," ","napkin", " ","silverware"," ","crystal"," ",\
          "goblets"," ","waitress"," ",\
  });

TWO_EXIT("players/boltar/casino/hall1e1","west",
         "players/boltar/casino/bar","north",
"Casa de Nirvana Restaurant",
        "Fashionably dim lighting and soft music welcome patrons\n"+
        "to the Casa de Nirvana Restaurant.  The maitre d' station\n"+
        "appears to be abandoned, but sports a carefully lettered\n"+
        "sign inviting guests to choose a table to their liking, \n"+
        "and reassuring them that a waitress will be with them \n"+
        "shortly.  Heavy scarlet draperies of rich velvet line the\n"+
        "walls from nearly ceiling to floor, parted at even intervals\n"+
        "by large brass wall sconces dully reflecting the dancing\n"+
        "flames of the candles held securely in their grip. Deep,\n"+
        "plush carpet, decorated with subtle floral patterns in \n"+
        "shades of scarlet, black, and cream, covers the floor.  \n"+
        "Petite round tables are scattered throughout the room, \n"+
        "each just far enough from the others to create the illusion\n"+
        "of privacy.  Each table is decorated with a crisp cream\n"+
        "colored linen tablecloth, a twinkling candelabra, two linen\n"+
        "napkins folded into something reminiscent of origami surrounded\n"+
        "by an imposing array of shiny silverware, two crystal goblets,\n"+
        "and a gold-embossed, leather-bound 'Menu'.  An engraved\n"+
        "brass plate near the east door reads, 'Lobby'.  A discrete\n"+
        "door to the north leads to the restaurant's bar.\n",1)

init() {
 add_action("buy","buy");
 add_action("buy","order");
 ::init();
}

long(str) {
  if(str=="plate")
    write("A sizeable brass sign, polished to a mirror sheen, hangs near the\n"+
        "doorway to the east.  It is engraved with the word 'L O B B Y'.\n");
  if(str=="station")
   write("A discrete podium of darkest mahogany stands abandoned near\n"+
        "the door to the lobby.  A small hand-lettered sign invites\n"+
        "patrons to please seat themselves.\n");
  if(str=="doorway")
   write("The large door to the east is inset with thick frosted glass that \n"+
        "blurs the view of the room beyond.  A brass plate near the doorway\n"+
        "reads 'L O B B Y'.\n");
  if(str=="door")
   write("The large door to the east is inset with thick frosted glass that \n"+
        "blurs the view of the room beyond.  A brass plate near the doorway\n"+
        "reads 'L O B B Y'.\n");
  if(str=="sign")
   write("A small hand-lettered sign on linen paper invites patrons to\n"+
        "please seat themselves, and assures patrons that a waitress \n"+
        "will assist them shortly.\n");
  if(str=="draperies")
   write("Heavy velvet draperies of rich, dark scarlet line the walls \n"+
        "of the restaurant, each set pulled back to form a graceful arc\n"+
        "that exposes the warm cream color of the wall behind them.\n");
  if(str=="curtains")
   write("Heavy velvet draperies of rich, dark scarlet line the walls \n"+
        "of the restaurant, each set pulled back to form a graceful arc\n"+
        "that exposes the warm cream color of the wall behind them.\n");
  if(str=="ceiling")
    write("The vaulted ceiling is barely discernable\n"+
        "overhead in the dim light of the room.\n");
  if(str=="floor")
   write("The floor is wholly covered by subtle floral patterns in\n"+
        "scarlet, black, and cream running through the ankle-deep carpet.\n");
  if(str=="carpet")
   write("Ankle-deep carpet decorated with subtle floral patterns in\n"+
        "scarlet, black, and cream covers the floor.\n");
  if(str=="sconces")
   write("Dozens of sturdy brass sconces hang along the walls, each\n"+
        "supporting the flickering, dancing flame of a tall tapered candle.\n");
  if(str=="sconce")
   write("Upon close inspection, the dull brass of the sconce appears\n"+
        "to be expertly polished, and the tall taper in its center \n"+
        "sports a bright, merry flame that flings dancing shadows \n"+
        "across the wall behind it.\n");
  if(str=="flames")
   write("Bright points of light twinkle and dance from the tops\n"+
        "of the candelabras and wall sconces, casting endless\n"+
        "patterns of shadows across the room.\n");
  if(str=="flame")
   write("The bright point of light twinkles and dances with\n"+
        "each stray breeze.\n");
  if(str=="wall")
   write("Muted cream wallpaper peeks out from between heavy scarlet \n"+
        "draperies.  Polished brass wall sconces separate each pair\n"+
        "of draperies and cast warm, mellow light into the room.\n");
  if(str=="walls")
   write("The muted cream of the walls peeks out from between sets of \n"+
        "heavy scarlet draperies.  Polished brass wall sconces separate\n"+
        "each pair of draperies and cast warm, mellow light into the room.\n");
  if(str=="table")
   write("The deep mahogany of the small, round table contrasts nicely\n"+
        "with the cream of the crisp linen tablecloth covering its top.\n"+
        "A polished brass candelabra scatters light across the surface\n"+
        "of the table, glinting off of the myriad of silverware and \n"+
        "crystal.  In the center of the table, just between the origami\n"+
        "napkin creations, rests a large leather-bound menu.\n");
  if(str=="tables")
   write("Each deep mahogany table has a crisp linen tablecloth \n"+
        "covering its top.  A polished brass candelabra scatters \n"+
        "light across the surface of each linen tablecloth, the \n"+
        "light glinting off of the myriad of silverware and crystal.\n"+
        "A large leather-bound menu rests in the center of each table.\n");
  if(str=="tablecloth")
   write("The crisp linen tablecloth, the color of rich cream,\n"+
        "drapes heavily over the edges of the table.\n");
  if(str=="candelabra")
   write("The intricately wrought brass candelabra rests just off\n"+
        "of the center of the table.  Atop each of the six delicate\n"+
        "spires rests a graceful cream colored dripless taper\n"+
        "whose flame flickers and dances with each stray breeze.\n");
  if(str=="candelabras")
   write("An intricately wrought brass candelabra rests just off\n"+
        "of the center of each table.  Atop each of the delicate\n"+
        "spires is a graceful cream colored dripless taper whose\n"+
        "flame flickers and dances with every stray breeze.\n");
  if(str=="napkin")
   write("The cream colored napkin of fine linen is\n"+
        "folded into the likeness of a swan.\n");
  if(str=="silverware")
     write("An intimidating array of forks, spoons, knives, and a few\n"+
        "unitentifiable utinsels rests upon each table, silently \n"+
        "mocking unsavvy diners.\n");
  if(str=="crystal")
     write("Engraved crystal goblets upon each table twinkle\n"+
        "in the candlelight.\n");
   if(str=="goblets")
     write("Engraved crystal goblets upon each table twinkle\n"+
        "in the candlelight.\n");
  if(str=="goblet")
     write("The large lead-crystal goblet twinkles in the candlelight.\n");
  if(str=="menu")
    show_menu();
  if(str=="waitress") 
    write("A beautiful young woman about 20 years old. She is wearing the\n"+
      "standard red and white uniform, however her skirt seems a bit short.\n");
  if(str) return 0;
  ::long();
}

show_menu() {
 write("\n");
 if(!(cm||mm||rmm||af||bf||cf||df)) 
  Speak("We have completely sold out...come back later.");
 else {
  write("The neatly bound menu reads:\n");
  write("1: Half Pound Hamburger ");write(cm);write(" at 20 gp\n");
  write("2: Pasta and meatballs  ");write(mm);write(" at 50 gp\n");
  write("3: Porterhouse Steak    ");write(rmm);write(" at 90 gp\n");
  write("4: Meat Ravoli          ");write(af);write(" at 50 gp\n");
  write("5: Lobster              ");write(bf);write(" at 90 gp\n");
  write("6: Crab                 ");write(cf);write(" at 90 gp\n");
  write("7: Trout                ");write(df);write(" at 50 gp\n");
  write("8: A Mug of Domestic Beer       ");write(" ");write("10gp\n");
  write("\n");
  write("Use 'buy <number>' to buy the desired Food. The food will\n"+
        "be consumed at once. Good appetite.\n\n");
 }
 return;
}

no_food() {
 Speak("Sorry - we have sold out of that.");
 if(cm||mm||rmm||af||bf||cf||df)
  Speak("Why don't you try something else ?");
 else
  Speak("Why don't you come back later ?");
 return 1;
}

pays(n) {
 if(this_player()->query_money()<n) {
  Speak("You cannot afford that.");
  return 0;
 }
 this_player()->add_money(-n);
 return 1;
}


buy(s) {
 if(!s) {
  Speak("What do you want to buy ?");
  return 1;
 }
 if(s=="1"||s=="<1>"||s=="hamburger") {
  if(!cm) return no_food();
  if(!pays(20)) return 1;
  if(!eat_ok(2)) return 1;
  write("You are served a great tasting hamburger.\n");
  write("You eat it right away.\n");
  say(Name+" orders a hamburger\n");
  this_player()->heal_self(4);
  cm=cm-1;
  return 1;
 }
 if(s=="2"||s=="<2>"||s=="pasta") {
  if(!mm) return no_food();
  if(!eat_ok(3)) return 1;
  if(!pays(50)) return 1;
  write("You are served an excellent pasta dinner.\n");
  write("You eat it right away.\n");
  say(Name+" orders pasta.\n");
  this_player()->heal_self(8);
  mm=mm-1;
  return 1;
 }

 if(s=="4"||s=="<4>"||s=="ravoli") {
  if(!af) return no_food();
  if(!eat_ok(3)) return 1; 
  if(!pays(50)) return 1;
  write("You are served an excellent ravoli dinner.\n");
  write("You eat it right away.\n");
  say(Name+" orders ravoli.\n");
  this_player()->heal_self(8);
  af=af-1;
  return 1;
 }
 if(s=="7"||s=="<7>" || s=="trout") {
  if(!af) return no_food();
  if(!eat_ok(3)) return 1;  
  if(!pays(50)) return 1; 
  write("You are served an excellent trout dinner.\n");
  write("You eat it right away.\n");
  say(Name+" orders trout.\n");
  this_player()->heal_self(8);
  df=df-1; 
  return 1; 
 }

/* rich man's meal, price 90, heals 12, preferably for levels 13+ */ 
 if(s=="3"||s=="<3>"||s=="steak") {
  if(!rmm) return no_food();
  if(!eat_ok(5)) return 1;
  if(!pays(90)) return 1;
  write("You are served an excellent porterhouse steak cooked to your liking.\n");
  write("You eat it right away.\n");
  say(Name+" orders a porterhouse steak\n");
  rmm=rmm-1;
  return 1;
 }
 if(s=="5"||s=="<5>"||s=="lobster") {
  if(!bf) return no_food();
  if(!eat_ok(5)) return 1;  
  if(!pays(90)) return 1;
  write("You are served a large lobster dinner.\n");
  write("You eat it right away.\n");
  say(Name+" orders lobster.\n");
  bf=bf-1;
  return 1;
 }
 if(s=="6"||s=="<6>"||s=="crab") {
  if(!bf) return no_food(); 
  if(!eat_ok(5)) return 1;  
  if(!pays(90)) return 1;   
  write("You are served a large crab dinner.\n");           
  write("You eat it right away.\n");
  say(Name+" orders crab.\n");         
  bf=bf-1; 
  return 1; 
 }

 if(s=="8"||s=="<8>"||s=="mug"||s=="beer") {
  if(!pays(10)) return 1;
  if(!this_player()->drink_alcohol(2)) {
   Speak("You look a little too drunk for that..let me take it back.");
   this_player()->add_money(10);
   return 1;
  }
  write("You drink a mug of first class beer - That feels good.\n");
  say(Name+" drinks a beer.\n");
  return 1;
 }
 Speak("We have no such number on the menu, try 1, 2 or 3.");
 return 1;
}



eat_ok(arg) {
    if (!call_other(this_player(), "eat_food", arg))
      {
         Speak("You look like you're full.\n");
         return 0;
       }
     return 1;
}
