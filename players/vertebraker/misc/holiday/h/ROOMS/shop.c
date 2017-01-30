#include "../std.h"

inherit ROOM;

string *choices;

reset(x)
{
   if(x) return;
   set_light(1);
   set_short("Verte's "+HIR+"Hal"+NORM+BOLD+BLK+"lowe"+HIR+"en"+NORM+" Shop");
   set_long(
      "  You stand in Verte's Halloween Shop, a small little hovel.\n"+
      "Cheap cotton batting hangs from the rafters as cobwebs, and\n"+
      "little rubber bats float carelessly around the room.  A short\n"+
      "wooden counter stands to the side, and a sign hangs on the\n"+
      "back wall.  Costumes line the walls, and a bunch of pumpkin\n"+
      "shaped pails sit on a bench near you.\n");
   add_item(({"cotton","battin","cobwebs"}),
      "Thick, puffy cobwebs hang perilously from the rafters of this\n"+
      "small shop");
   add_item(({"rubber bats","bats"}),
      "Whoa!  A bat almost hit ya in the noggin!  Better watch out :) ..");
   add_item("counter","A small wooden counter");
   add_item("pails","A bunch of jack-o-lantern like pails");
   add_object(PATH+"NPC/lil_verte");
   choices = ({ "clinton", "ghost", "mummy", "pirate", "shardak",
         "corpse", "jason", "nixon", "reagan", "witch", "myers", "binladen" });
   add_exit("/room/narr_alley","out");
}

id(str) { return str == "sign"; }

long(str)
{
   if(str == "sign")
      {
      write(
         BOLD+BLK+"  _______ ________ ______________ _________________ __ ____\n\n"+
         HIR+"       V e R t E ' S   H a L l o W e E n   S t U f F\n"+NORM+
         BOLD+BLK+"  _______ ________ ______________ _________________ __ ____\n\n"+NORM+
         "  "+HIR+"1]"+NORM+" We got costumes!    COST: 25 coins\n"+
         "       Dress up as Jason Voorhees, the homicidal maniac from Friday\n"+
         "       the 13th, or even Bill Clinton!  Just type <"+BOLD+BLK+"buy costume"+NORM+">\n"+
         "  "+HIR+"2]"+NORM+" We got candy pails! COST: 25 coins\n"+
         "       Buy one of these cheap, cheap pails and trick or treat from\n"+
         "       all the good guy NPC's out there! <"+BOLD+"buy pail"+NORM+">\n"+
         "  "+HIR+"3]"+NORM+" We got glosticks! COST: 50 coins\n"+
         "       Buy a cheap glostick and impress all your friends with your\n"+
         "       glostick-wavin' skills!  <"+BOLD+"buy glostick"+NORM+">\n\n");
   }
   else ::long();
}

init()
{
   ::init();
   add_action("cmd_list","list");
   add_action("cmd_buy","buy");
   add_action("cmd_buy","purchase");
   add_action("cmd_sell","sell");
}

verte_me()
{
   tell_room(TO,"Verte runs into the room.\n");
   MO(CO(PATH+"NPC/lil_verte"),TO);
   return 1;
}

cmd_buy(str)
{
   if(!present("lil_verte",TO)) verte_me();
   if(!str)
      {
      write("Buy what?\n");
      return 1; }
   if(str == "costume")
      {
      if(TP->query_money() < 25)
         {
         write("Verte says: You don't have enough money.\n");
         return 1;
      }
      write("What costume do you want to buy?\n"+
         "Choices: [reagan, nixon, clinton, jason, shardak,\n"+

         "          pirate, witch, mummy, corpse, ghost, binladen, myers] ");
      input_to("choose_costume");
      return 1; }
   if(str == "glostick" || str == "stick")
      {
      if(TP->query_money() < 50)
         {
         write("Verte says: You don't have enough cash.  You need 50 coins.\n");
         return 1;
      }
      write("You purchase a "+HIG+"glostick"+NORM+".\n");
      write("Verte hands it to you and smiles.\n");
      MO(CO(PATH+"OBJ/glo"),TP);
      TP->add_money(-50);
      return 1; }
   if(str == "pail" || str == "bucket" || str == "halloween pail")
      {
      if(TP->query_money() < 25)
         {
         write("Verte says: You don't have enough cash.  You need 25 coins.\n");
         return 1;
      }
      write("You purchase a "+HIR+"halloween pail"+NORM+".\n");
      write("Verte hands it to you and smiles.\n"+
         "He adds, 'Don't drop it now!  Oh, and just type trickortreat <npc> to use.'\n");
      TP->add_money(-25);
      MO(CO(PATH+"OBJ/pail"),TP);
      return 1; }
   write("Verte says: We don't sell that here!\n"+
      "            Read da sign!\n");
   return 1;
}

cmd_sell()
{
   if(!present("lil_verte",TO)) verte_me();
   write("Verte says: Uh, no.   We don't buy anything.\n");
   return 1;
}

choose_costume(str)
{
   if(member_array(str,choices) == -1)
      {
      write("That is not a choice.\n");
      command("buy costume",TP);
      return 1;
      return 1;}
   write("You purchase a "+BOLD+CAP(str)+NORM+" costume.\n"+
      "Verte takes your money happily.\n");
   MO(CO(PATH+"OBJ/costumes/"+str),TP);
   TP->add_money(-25);
   return 1;
}

cmd_list()
{
   TP->look("at sign");
   return 1;
}
