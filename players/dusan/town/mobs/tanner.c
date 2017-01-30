/* Thanks to Wocket for donating this code*/
#include "/players/dusan/ansi.h"
inherit "/obj/monster";

reset(arg){
    ::reset(arg);
  if(arg) return;
    set_name("henry");
    set_alias("tanner");
    set_short("Henry, the local tanner");
    set_long("   It is hard to tell what age this man that stands before you is\n"+
    "his skin seems to have the same texture as the leathers he tans.  His clothes.\n"+
    "are stout and worn, and a undeniable stench hangs around him. You might ask him\n"+
    "to 'buy' the supplies he makes.  You can also ask him for a 'list' of what he \n"+
    "can make.\n");
    set_level(15);
    set_hp(200);
    set_wc(15);
    set_ac(10);
    add_money(400);
}

init(){
    ::init();
    add_action("order","buy");
    add_action("list","list");
}

list(){
    write("Talieos says: here is my list of wares:\n");
    write("\n");
    write("  COST      ITEM\n");
    write("   30     Vraaak skin boots\n");
    write("   30     Vraaak skin gloves\n");
    write("   30     Vraaak skin cloak\n");
    write("   30     Vraaak skin cap\n"); 
    write("   200    Vraaak skin armor\n");  
    write("Note: 2 hides are needed for armor\n");
    write("\n");
return 1;
}

order(string str){
int cost;
string file;
switch(str){
case "boots":
  cost = 30;
  file = "/players/dusan/town/armors/vboots.c";
  break;
case "gloves":
  cost = 30;
  file = "/players/dusan/town/armors/vgloves.c";
  break;
case "cloak":
  cost = 30;
  file = "/players/dusan/area1/armors/vskin.c";
  break;
case "cap":
  cost = 30;
  file = "/players/dusan/town/armors/vcap.c";
  break;
case "armor":
  cost = 50;
  file = "/players/dusan/town/armors/varmor.c";
  break;
default:
  notify_fail("Henry says: Wadda you want?\n");
  return 0;
  break;
}
if(!present("vhide",this_player())){
    notify_fail("Henry says: Ya ain't got watcha need to make that.\n");
    return 0;
}
if(str == "armor" && !present("vhide 2",this_player())){
    notify_fail("Henry says: Ain't got enough skins to make that.\n");
    return 0;
}
if(this_player()->query_money() < cost){
    notify_fail("Henry says: Hey! You don't have enough money.\n");
    return 0;
}

  this_player()->add_money(-cost); 
  move_object(clone_object(file),this_player());
  destruct(present("vhide",this_player()));
  this_player()->recalc_carry();
  write("Henry takes your hide, cures the skin and works a "+str+" from it.\n");
  write("Henry hands you a "+str+" and quickly grabs your money.\n");
  say("Henry takes "+this_player()->query_name()+"'s hide and works a "+str+" from it.\n",this_player());
  say("Henry hands "+this_player()->query_name()+" a "+str+" and quickly grabs "+this_player()->query_possessive()+" money.\n",this_player());

if(str == "armor"){
  destruct(present("vhide",this_player()));
}
return 1;
}
