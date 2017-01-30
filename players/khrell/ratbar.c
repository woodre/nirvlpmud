#include "/players/khrell/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define rate 6
#define USER this_player()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()
inherit "room/room";

int cost,heal_for;
string type;
string mess;
object guard;
reset(arg) {
if(!present("bar_owner", this_object())){
move_object(clone_object("/players/khrell/monster/skaven/skwikswik.c"),
this_object());
}               
  if(arg) return;
set_light(-1);
add_property("no_fight");
set_short("+GRN+"Fester Peak"+NORM+" "+HIR+"["+HIK+"The Rat Hole"+HIR+"]"+NORM+");
set_long("\n
  This is a small, crude building made of stone and supported\n\
by wooden posts. A long counter can be seen towards the back\n\
of the bar, and a sign hangs behind it. There are a few tables\n\
and stools lining the walls. A door leads back out to the street.\n");

items = ({
  "counter", "A long counter made of a rotten wood. It has seen better days",
  "sign", "A large sign that is a readable menu. You can 'read' it",
  "tables", "A few tables made of wood",
  "stools", "Several stools that are made of wood and are in poor condition",
  "door", "Splintered wooden door with a holes in it",
  "posts", "Gnarled and knobby pieces of wood poorly made to be supports",
  
});

dest_dir = ({
  "/players/khrell/area/skaven/ss11.c","out",
  
});

}

init(){
  ::init();
    add_action("read_it", "read");
    add_action("order_item", "order");
}

        
  

read_it(string str){
        if(!str){ write("Read what?\n"); return 1; }
          if(str = "sign"){
        write("      The sign reads.....\n\n");
        write(
"\t "+HIR+"################################################\n"+
"\t ##"+HIR+"********************************************"+NORM+HIR+"##\n"+
"\t ##"+HIR+"*                                          *"+NORM+HIR+"##\n"+
"\t ##"+HIR+"*             "+NORM+HIW+"The Rat Hole"+NORM+HIR+"                 *##\n"+ 
"\t ##"+HIR+"*  "+NORM+RED+"----------------"+HIW+"SPIRITS"+NORM+RED+"--------------- "+HIR+" *##\n"+
"\t ##"+HIR+"*  "+NORM+CYN+"Grog..........................50 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+BLU+"Blackale.....................250 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+HIB+"Darkwine.....................500 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+RED+"-----------------"+HIW+"DRINKS"+NORM+RED+"---------------  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+CYN+"Water.........................50 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+BLU+"Swampsludge..................250 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+HIB+"SwampWater...................500 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+RED+"------------------"+HIW+"FOODS"+NORM+RED+"---------------  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+CYN+"Swampcorn.....................50 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+NORM+BLU+"Blackwheat...................250 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*  "+HIB+"Ratsteak.....................500 coins  "+HIR+"*##\n"+
"\t ##"+HIR+"*                                          *"+NORM+HIR+"##\n"+
"\t ##"+HIR+"********************************************"+NORM+HIR+"##\n"+
"\t "+HIR+"################################################"+NORM+"\n"+
"\t        You may '"+BOLD+BLINK+"order"+NORM+"' any item listed.                \n");
        return 1;
        }
  return;
  }
order_item(string str){
if(!present("bar_owner", this_object())){
write("You don't see anyone here that can serve you!\n");
return 1;
}               
   if(!str){ 
        write("The waiter says: I'm sorry, order what?\n");
        return 1;
      }
else if(str == "grog" || str == "Grog"){
        cost = 50;
        type = "drink_alcohol";
        heal_for = 5;
        }
else if(str == "ale" || str ==  "blackale"){
        cost = 250;
        type = "drink_alcohol";
        heal_for = 15+random(20);
        }
else if(str == "wine" || str ==  "darkwine"){
        cost = 500;
        type = "drink_alcohol";
                heal_for = 40+random(20);
        }
else if(str == "water" || str ==  "Water"){
        cost = 50;
        type = "drink_soft";
        heal_for = 5;
        }
else if(str == "swampsludge" || str ==  "Swampsludge" || str == "sludge"){
        cost = 250;
        type = "drink_soft";
        heal_for = 15+random(20);
        }
else if(str == "swampwater" || str ==  "Swampwater" || str == "water"){
        cost = 500;
        type = "drink_soft";
        heal_for = 40+random(20);
        }
else if(str == "swampcorn" || str ==  "Swampcorn" || str == "corn"){
        cost = 50;
        type = "eat_food";
                heal_for = 5;
        }
else if(str == "blackwheat" || str ==  "Blackwheat" || str == "wheat"){
        cost = 250;
        type = "eat_food";
        heal_for = 15+random(20);
        }
else if(str == "ratsteak" || str == "Ratsteak" || str == "steak"){
        cost = 500;
        type = "eat_food";
        heal_for = 40+random(20);
        }
else{ 
        write("The Bartender squeaks: We no-no got that.\n");
        return 1;
        }
if(this_player()->query_money() < cost){
        write(
"The Bartender squeaks: 'You no-no gots enough money!'\n");
        return 1;        }
if (!call_other(this_player(), type, rate)) {
        write(
"The Bartender looks at you and chitters with laughter.\n");      
return 1;
      }

if(type == "drink_soft" || type =="drink_alcohol")
        mess = "drink";

else mess = "eat";

write(
"You order a "+HIG+""+capitalize(str)+""+NORM+".\n"+
"You quickly "+mess+" it.\n");

    call_other(this_player(), "heal_self", heal_for);
write(
"     <<-HP "+HIC+""+HP+""+NORM+"/"+HIC+""+MHP+""+NORM+"->>"+
"     <<-SP "+HIC+""+SP+""+NORM+"/"+HIC+""+MSP+""+NORM+"->>\n");


say(
this_player()->query_name()+" quickly "+mess+"'s a "+str+".\n");
    call_other(this_player(), "add_money", - cost);
write("You have "+this_player()->query_money()+" coins left.\n");
    return 1;
    }
    