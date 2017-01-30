#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

	::create();
  set_short(HIM+"Bard Charity Room"+NORM);
  set_long(HIM+
    "Bard Charity Room\n"+NORM+
    "This is the Bard guild locker rooms, where you can access your\n"+
    "equipment that has been stored in the regular lockers, as well\n"+
    "as store equipment and purchase more locker space.  There is a\n"+
    "sign on the wall with instructions on how to do so.  This is\n"+
    "also where you are encouraged to leave extra equipment for Bards\n"+
    "who are down on their luck.  There is an exit to the west leading\n"+
    "to the common room.\n"
    );
  set_items(([
    "lockers" :
    "Dozens of lockers line the walls, look at the sign for instructions.\n",
    "sign" :
    "  Command           Description\n"+
    "<><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+
    "<>buy locker        Purchase a new locker if you    <>\n"+
    "<>                  don't already have one, or      <>\n"+
    "<>                  purchase one more item of       <>\n"+
    "<>                  storage space, up to 10.        <>\n"+
    "<>withdraw <#>      Withdraws <item> from your      <>\n"+
    "<>                  locker.                         <>\n"+
    "<>deposit <item>    Deposits <item> from your       <>\n"+
    "<>                  inventory into your locker.     <>\n"+
    "<>clear <item>      Clears out locker space.        <>\n"+
    "<>list              Lists all items in your locker. <>\n"+
    "<><><><><><><><><><><><><><><><><><><><><><><><><><><>\n",
    ]));
  set_smells(([
    "default" :
    "It smells like a locker room, dirty socks included!\n",
    ]));
  set_sounds(([
    "default" :
    "It is very silent here.\n",
    ]));
  set_exits(([
    "west" : "/players/guilds/bards/bardrooms/common",
    ]));
  set_light(1);
  replace_program(ROOM);
}

init(){
::init();
add_action("withdraw","withdraw");
add_action("list", "list");
add_action("deposit","deposit");
add_action("buylocker","buy");
add_action("clear","clear");
}

deposit(str){
"/players/catwoman/tl.c"->deposit_item(str);
return 1;
}
buylocker(str){
"/players/catwoman/tl.c"->buy_locker(str);
return 1;
}
list(){
"/players/catwoman/tl.c"->list();
return 1;
}
withdraw(str){
"/players/catwoman/tl.c"->withdraw_item(str);
return 1;
}
clear(str){
"/players/catwoman/tl.c"->clear(str);
return 1;
}
