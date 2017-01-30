/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison Mid-Level Area
//  Create Date:  2005.06.03
//	Thanks to everyone who helped me...
//  especially Illarion & Vertebraker
//  Modified from Code by Pestilence..thanks Pesty
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "players/vertebraker/closed/std/room.c";

object item;
int cost;
string what;
reset(arg) {

if (!present("joey_the_snitch")) {
  move_object(clone_object("/players/tristian/realms/ClubFed/mobs2/joey.c"),
    this_object());
}
if(arg) return;

short_desc = ""+HIR+"Joey's Cell "+NORM+"in "+HIG+"Club Fed"+NORM+"";
long_desc =
  " This is an isolation cell, not on the standard cellblocks in the\n"+
  "prison.  The inmate here must be either a special case, dangerous,\n"+
  "or warrants special treatment.  There are no windows in this interior\n"+
  "cell, but the same bed that has been seen in the rest of the prison is\n"+
  "here.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
"bed",
  "Its a Sealy Posturpedic mattress on a metal bed frame",
"sealy",
  "A Sealy Posturpedic mattress, much higher quality than a standard prison mattress",
"mattress",
  "A Sealy Posturpedic mattress, much higher quality than a standard prison mattress",
"frame",
  "A simple metal bed frame",
});

dest_dir = ({
RMS+"hall_com_01",  "west",
});
}

init(){
::init();   
  AA("buy_it", "buy");
  AA("list","list");
}

list(){
  if(!present("joey_the_snitch", this_object())){
    write("Joey isn't here, and you have no idea where he hid\n"+
          "his junk! Come back later!!\n");
    return 1;
 }else{
    write("Joey shows you his secret stash.\n\n"+
          "1. Eight Ball___________________________4100 coins.\n"+
          "2. Heroin_______________________________4100 coins.\n"+
          "3. Crack Cocaine________________________4100 coins.\n"+
        "Buy "+HIG+"<Number>"+NORM+"\n\n");
    return 1;
  }
}
buy_it(str){
  if(!present("joey_the_snitch", this_object())){
    write("Joey isn't here, and you have no idea where he hid\n"+
    "his junk! Come back later!!\n");
    say(TPN+" tries to find Joey's stash, but fails.\n");
    return 1;
    }
    if(str == "1")
    {
    cost = 4100;
    item = clone_object(OBJ+"eightball.c");
    what = "Eight Ball";
    }

    else if(str == "2")
    {
    cost = 4100;
    item = clone_object(OBJ+"heroin.c");
    what = "Heroin";
    }

    else if(str == "3")
    {
    cost = 4100;
    item = clone_object(OBJ+"crack.c");
    what = "Crack Cocaine";
    }
         
    else
    {
    write("Buy what?\n");
    return 1;
    }
    
    if (call_other(this_player(), "query_money", 0) < cost) 
    {
    write("Joey says, 'You trying to cheat me buddy? Go away till you\n"+
    "got the cash!!'\n");
    destruct(item);
    return 1;
    }          
    if(!TP->add_weight(item->query_weight()))
    {
    write("Joey says, 'It doesn't look like you can carry that, wimp.\n"+
    "Go work out on the weight pile some more.\n");
    say(TPN+" tries to buy some illegal drugs, but is so weak they can't carry em.\n");
    destruct(item);
    return 1;
    }                 
    write("You pay "+cost+" coins for a "+what+".\n");
    say(TPN+ " purchases a "+what+".\n");
    move_object(item,this_player());
    TP->add_money(-cost);
    return 1;
}
