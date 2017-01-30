#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
reset(arg) {
   if (arg) return;
   set_light(1);
   long_desc =
   "    A small square room made of solid, cold steel.  To the\n"+
   "north a large computer comsumes the entire length and\n"+
   "width of the wall.   A medium sized box sits in front of the\n"+
   "computer.  A message continuously flashes on the monitor\n";
   items = ({
         "room","A small, cold, square room made completely of steel",
         "computer","A large, highly advance computer terminal.\nA huge monitor flashes a message",
         "message","   "+BLINK+YEL+"Buy digimon"+NORM+" for "+HIY+"5000 coins"+NORM+".\n   "+BLINK+YEL+"Buy digivolver"+NORM+" for "+HIY+"100 coins"+NORM+"",
         "box","A medium sized box which comes from under the computer",
});
}

init() {
   add_action("buy","buy");
}


short() {
   return "A secret chamber";
}


buy(str) {
   object digimon;
   int coins;
   if(str == "digivolver"){
      if(TP->query_money() < 100){ write("You do not have enough coins to purchase a digivolver.\n"); return 1; }
   MOCO("/players/jaraxle/digimon/digidevice"), TP);
    write("You purchase a DigiVolver!\n");
      TP->add_money(-100);
      return 1; }
if(str != "digimon"){ write("You can only buy DigiMon here.\n"); return 1; }

if(TP->query_money() < 5000){
   write("You do not have enough coins to purchase a DigiMon.\n");
   return 1;
}
digimon = clone_object("players/jaraxle/digimon/pet2");
digimon->set_level(10);
digimon->set_ac(3);
digimon->set_wc(8);
digimon->set_hp(150);
digimon->patch_owner(this_player());
move_object(digimon, this_object());
tell_room(environment(TP), "A small DigiMon walks out of the metal box.\nThe DigiMon proclaims "+TPN+" its Trainer!\n");
this_player()->add_money(-5000);
return 1;
}
