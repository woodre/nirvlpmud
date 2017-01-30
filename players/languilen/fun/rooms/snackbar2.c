#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
      if(arg) return;
   set_light(1);

   short_desc = HIG+"Fun"+HIB+"house"+HIY+" Snack"+HIR+"bar"+NORM;
   long_desc =
"     A large L shaped bar is sectioned off by a partition which prevents\n\
anyone from seeing or leaving in any direction except the one which was\n\
entered.  A large sign above the snackbar lists what may be bought here.\n\
A small door marked 'exit' leads out to the lobby.\n";

   items = ({
      "partition","It streches from the corner of the bar to the entrance to the south.\n\
There is no way to get around it",
      "bar","The smooth low counter is perfect for younger guests",
      "sign","Its' neon letters flash bright colors urging you to read what it says",
      "exit","a one way door back outside",
   });

   dest_dir = ({
	AREA+"gameroom.c","north",
        AREA+"lobby.c","exit",
   });
}

init(){
     ::init();
     add_action("buy_snack","buy");
     add_action("read_sign","read");
     add_action("listening","listen");
}
read_sign(str){
     if(!str || str != "sign"){
        notify_fail("Are you trying to 'read' the 'sign' or what?\n");
        return 0;
     }
     write("\n"+
           HIG+"     =-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+NORM+"\n"+
           HIG+"     =                                                     "+HIR+" ="+NORM+"\n"+
           HIG+"     =                   Fun"+HIB+"house "+HIY+"Snack"+HIR+"bar"+HIR+"                  =  "+NORM+"\n"+
           HIG+"     =                                                     "+HIR+" ="+NORM+"\n"+           
           HIG+"     ="+HIW+"         Wacky "+HIG+"w"+HIB+"i"+HIY+"l"+HIR+"d"+HIG+"e"+HIB+"r"+HIY+"b"+HIR+"e"+HIG+"r"+HIB+"r"+HIY+"y '"+HIG+"j"+HIB+"u"+HIW+"i"+HIY+"c"+HIR+"e"+HIW+"':  640 coins."+HIR+"      ="+NORM+"\n"+
           HIG+"     =                                                     "+HIR+" ="+NORM+"\n"+
           HIG+"     ="+HIW+"          Fluffy cotton '"+HIM+"candy"+HIW+"':      960 coins."+HIR+"      ="+NORM+"\n"+
           HIG+"     =                                                "+HIR+"      ="+NORM+"\n"+
           HIG+"     =-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+HIG+"=-"+HIB+"=-"+HIY+"=-"+HIR+"=-"+NORM+"\n");
     return 1;
}
buy_snack(str){
     object item;
     int value, d;
     d = 0;

     if(str == "candy" || str == "cotton" || str == "cotton candy") {
        item = clone_object(OBJ+"ccandy.c");
        value = 960;
        d = 1;
     }
     if(str == "juice" || str == "wild juice") {
        item = clone_object(OBJ+"wjuice.c");
        value = 640;
        d = 1;
     }
     if(d) {
        if(this_player()->query_money() <value) {
           write("You do not have enough money to buy that! \n");
           return 1;
        }
        if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
           write("You can't carry that much!\n");
           return 1;
        }
        this_player()->add_money(-value);
        move_object(item,this_player());
        write("A snackbar attendant rushes over and gives you "+lower_case(item->short())+".\n");
        say(this_player()->query_name()+" buys some "+lower_case(item->short())+".\n");
     } else {
        write("You can't buy that here. \n");
     }
     return 1;
}

listening(){
     write("Shrill whistles and clamouring bells make hearing much else a chore.\n");
     return 1;
}


realm(){ return "NT"; }
