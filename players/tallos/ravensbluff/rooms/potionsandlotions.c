#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
inherit "/players/fred/closed/std/room";

string what;
string str;
int cost;
object item, clerk1;


reset(arg) {
if(!present("clerk1")){
  clerk1  = clone_object("/players/tallos/ravensbluffnpcs/clerk1.c");
  move_object(clerk1, this_object());
  }
if(arg) return;
set_light(1);

short_desc = BOLD+HIB+"Raven's Bluff"+NORM+":"+NORM+""+BLU+" Potions"+NORM+" and "+HIB+"Lotions"+NORM;
long_desc =
"  "+HIG+"This is the famous "+NORM+""+BLU+"Potions"+HIG+" and "+HIB+"Lotions"+HIG+" shop in\n"+ 
""+HIB+"Raven's Bluff"+HIG+".  All the greatest "+HIY+"adventurers"+HIG+" buy\n"+
"their "+HIC+"healing "+HIB+"potions"+HIG+" from this location.  There\n"+
"is a list of "+HIM+"items"+HIG+" sold by the "+NORM+""+YEL+"register"+NORM+".\n";
  
dest_dir = ({
  "/players/tallos/examples/7tigersrooms/portalroom.c","south",
});
}

query_no_fight(){
  return 1;
}

init(){
    ::init();
    add_action("buy_it","buy");
    add_action("list_it","list");
   }
list_it(){
write(
      ""+YEL+"=================================================\n\n"+
      ""+YEL+"= "+NORM+"1."+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIC+" Light Wounds"+NORM+BOLD+"      1200 gp "+NORM+""+YEL+"="+NORM+"\n"+
      ""+YEL+"= "+NORM+"2."+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIR+" Moderate Wounds"+NORM+BOLD+"   1800 gp "+NORM+""+YEL+"="+NORM+"\n"+
      ""+YEL+"= "+NORM+"3."+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIM+" Serious Wounds"+NORM+BOLD+"    2600 gp "+NORM+""+YEL+"="+NORM+"\n"+
      ""+YEL+"= "+NORM+"4."+HIB+" A Potion"+NORM+" of "+HIG+"Heal              "+NORM+BOLD+"    10000 gp "+NORM+""+YEL+"="+NORM+"\n"+
      ""+YEL+"= "+NORM+"5."+HIB+" A Potion"+NORM+" of "+NORM+""+BLU+"Ether                "+NORM+BOLD+"  1200 gp "+NORM+""+YEL+"="+NORM+"\n"+
      ""+YEL+"= "+NORM+"6."+HIG+" Good"+HIR+"berry"+NORM+""+NORM+""+MAG+" Juice              "+NORM+BOLD+"      1200 gp "+NORM+""+YEL+"="+NORM+"\n"+   
      ""+YEL+"================================================="+NORM+"\n\n"+
      "To purchase simply: buy #"+NORM+"'.\n\n");
      return 1; 
      }  
buy_it(string str){
        int buy;
        buy = str;
        if(!present("clerk")){
        write("The clerk doesn't appear to be here right now.\n");
        return 1;
        }
        if(!buy){ write("To purchase use: buy 1-6.\n"); return 1; }
        if(buy == "1"){
          cost = 1200;
          item = clone_object("/players/tallos/heals/curelight.c");
          what = ""+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIC+" Light Wounds"+NORM+"";
          }
        else if(buy == "2"){
          cost = 1800;
          item = clone_object("/players/tallos/heals/curemoderate.c");
          what = ""+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIR+" Moderate Wounds"+NORM+"";
          }
        else if(buy == "3"){
          cost = 2600;
          item = clone_object("/players/tallos/heals/cureserious.c");
          what = ""+HIB+" A Potion"+NORM+" of "+HIG+"Cure"+HIM+" Serious Wounds"+NORM+"";
          }
        else if(buy == "4"){
          cost = 10000;
          item = clone_object("/players/tallos/heals/pheal.c");
          what = ""+HIB+" A Potion"+NORM+" of "+HIG+"Heal"+NORM+"";
          }
        else if(buy == "5"){
          cost = 1200;
          item = clone_object("players/tallos/heals/ether.c");
          what = ""+HIB+" A Potion"+NORM+" of "+NORM+""+BLU+"Ether"+NORM+"";
          }
        else if(buy == "6"){
          cost = 1200;
          item = clone_object("players/tallos/heals/goodberryj.c");
          what = ""+HIG+" Good"+HIR+"berry"+NORM+""+NORM+""+MAG+" Juice"+NORM+"";
          }          
        else{
          write("What? Thats not in the shop.\n");
          return 1;
        }       
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("The clerk says, \"You do not have enough gold for that.\"\n");
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("The clerk says, \"You need to lighten your load. You're too encumbered.\"\n");
    destruct(item);
    return 1; }  
 write("You give the clerk "+cost+" gp and take "+what+".\n");                
 say(this_player()->query_name() + " purchases "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }   