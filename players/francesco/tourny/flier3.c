#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()


reset(arg){
if (arg) return;
set_id("flier");
set_alias("flier");
set_short(HIG+"A "+HIC+"flier"+HIR+" about"+HIW+" Francesco's"+HIY+" race"+NORM);
set_long(HIB+"A folded flier, made by cardboard, tough and resistant.\n"+
         "It can be 'read'.\n"+NORM);
info = ({ });
}

init() {
  ::init();
    add_action("read_book","read");
  if(TP != environment(TO)) 
  return; 
}


read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "flier") {
      write("The flier contains several info you can have about the race:\n"+
            "You can:  'read goal'          'read rules'          \n"+
            "          'read rating'        'read prizes'         \n");
     return 1;}
     if(str == "goal") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"F R A N C E S C O ' S   C O N T E S T"+NORM+"           |\n"+
           "    |  "+HIW+"The goal of the contest is to make as much as possible"+NORM+"  |\n"+
           "    |  "+HIW+"experience and coins within thirty minutes.         "+NORM+"    |\n"+
           "    |  "+HIW+"There is one basic feature in this contest:  the    "+NORM+"    |\n"+
           "    |  "+HIW+"participants are not allowed to have neither coins  "+NORM+"    |\n"+
           "    |  "+HIW+"nor heals when the race begins.  "+NORM+"                       |\n"+
          "     ----------------------------------------------------------\n");
/*
the goal of this contest is to gather as much experience and
coins as possible within a set amount of time.  The only
rule for the start: that participants may have neither coins 
nor heals at the start of the race. 
*/
     return 1; }
     if(str == "rules") {
     write("     ----------------------------------------------------------\n"+
           "    |                 "+HIR+"C O N T E S T   R U L E S  "+NORM+"              |\n"+
           "    |  "+HIW+"At the start of the race:                           "+NORM+"    |\n"+
           "    |  "+HIW+"       - have any kind of gear                   "+NORM+"       |\n"+
           "    |  "+HIW+"       - not have any heal                          "+NORM+"    |\n"+
           "    |  "+HIW+"       - not have any casheable or barterable item "+NORM+"     |\n"+
           "    |  "+HIW+"       - not have any special item which could let     "+NORM+" |\n"+
           "    |  "+HIW+"         them make easy coins or heals, such as the   "+NORM+"  |\n"+
           "    |  "+HIW+"         stethoscope or other similar objects       "+NORM+"    |\n"+
           "    |  "+HIW+"       - not have any coins                      "+NORM+"       |\n"+
           "    |  "+HIW+"When the race is running the players can:           "+NORM+"    |\n"+
           "    |  "+HIW+"       - party with whomever they like to "+NORM+"              |\n"+
           "    |  "+HIW+"         including pets, mudkids, daemons etc. etc."+NORM+"     |\n"+
           "    |  "+HIW+"         all companions MUST be included in a party"+NORM+"     |\n"+
           "    |  "+HIW+"       - sell every items they accumulated        "+NORM+"      |\n"+
           "    |  "+HIW+"         during the race                          "+NORM+"      |\n"+
           "    |  "+HIW+"       - not receive any item nor coins by any other"+NORM+"    |\n"+
           "    |  "+HIW+"         player, kids, pets, even if they are not"+NORM+"       |\n"+
           "    |  "+HIW+"         participating in the race"+NORM+"                      |\n"+
           "    |  "+HIW+"       - not go and retrieve any item from their "+NORM+"       |\n"+
           "    |  "+HIW+"         lockers or hotel or motel rooms            "+NORM+"    |\n"+
           "    |  "+HIW+"When the race ends the players can:                 "+NORM+"    |\n"+
           "    |  "+HIW+"       - not sell their items anymore            "+NORM+"       |\n"+
           "    |  "+HIW+"       - (must) have at least the same gear they    "+NORM+"    |\n"+
           "    |  "+HIW+"         had when the race started                  "+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "rating") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"F I N A L   R A T I N G          "+NORM+"           |\n"+
           "    |    "+HIW+" The final rating will be calculated according        "+NORM+"|\n"+
           "    |    "+HIW+" to the following basic rules:                     "+NORM+"   |\n"+
           "    |    "+HIW+" experience will be counted as:                    "+NORM+"   |\n"+
           "    |    "+HIY+"               exp_gained / player_level              "+NORM+"|\n"+
           "    |    "+HIW+" coins will be counted as:                     "+NORM+"       |\n"+
           "    |    "+HIY+"               coins_earned / player_level     "+NORM+"       |\n"+
           "    |    "+HIW+" These two figures will be summed and the total   "+NORM+"    |\n"+
           "    |    "+HIW+" will make the list of the winners         "+NORM+"           |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "prizes") {
     write("     ----------------------------------------------------------\n"+
           "    |      "+HIR+"       C O N T E S T    P R I Z E S"+NORM+"                 |\n"+
           "    |  "+HIW+"   The winners will have three choices:       "+NORM+"          |\n"+
           "    |  "+HIW+"   1) have a legal personalized item               "+NORM+"     |\n"+ 
           "    |  "+HIW+"   2) have half of the exp gotten during the race    "+NORM+"   |\n"+
           "    |  "+HIW+"   3) have half of the coins gotten during the race"+NORM+"     |\n"+
           "    |  "+HIW+"   Best qualified will choose first, then the others"+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
return 1;}


/*
the goal of this contest is to gather as much experience and
coins as possible within a set amount of time.  The only
rule for the start: that participants may have neither coins 
nor heals at the start of the race. 

At the start of the race:  - no coins in the possesion of
the character/player   - any type of gear is allowed except
for special items which would allow one easy access to coins 
and heals. for example a stethoscope or similar gear and/or
items
          
- no heals allowed in your inventory or stored (i.e.
lockers, hotel, motel, guild room)    
sell all items accumulated during the race  -take nor
receive any items and/or coins by another player or      
character, kid, or pet. Even if they are not participating   
in the race  -retrieve any item storage such as a hotel   
room, locker, motel or guild room/hall   
 when the race ends the participants can:  - not sell items 
-(must) have at least the same type of gear they started the
race with 
More: (line 21) 
EOF
->> */
