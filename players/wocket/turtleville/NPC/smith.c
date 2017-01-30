#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
    ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/turtleville/OBJ/shellmail.c"),this_object());
move_object(clone_object("/players/wocket/turtleville/OBJ/shellhelmet.c"),this_object());
    set_name("talieos");
    set_alias("smith");
    set_short(BOLD+"Talieos"+NORM+", the shell smith");
    set_long("Talieos is a middle-aged man with muscles bulging from the hard work\n"+
    "that he does from making shell armor.  He is dressed in dirty leather garb.\n"+
    "If you would like him to forge you something you need to bring him\n"+
    "the supplies and 'buy' what you want.  You can also ask him for\n"+
    "a 'list' of what he can make.\n");
    set_level(20);
    set_hp(550);
    set_wc(30);
    set_ac(16);
    add_money(3000);
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
    write("   25     shellhelmet\n");
    write("   35     shellshield\n");
    write("   15     shellamulet\n");
    write("   20     shellboots\n");
    write("   10     shellring\n");
    write("   20     shellsash\n");
    write("   50     shellmail\n");
    write("\nNote: 3 shells are needed for shellmail\n");
    write("\n");
return 1;
}

order(string str){
int cost;
string file;
switch(str){
case "shellhelmet":
  cost = 25;
  file = "/players/wocket/turtleville/OBJ/shellhelmet.c";
  break;
case "shellshield":
  cost = 35;
  file = "/players/wocket/turtleville/OBJ/shellshield.c";
  break;
case "shellamulet":
  cost = 15;
  file = "/players/wocket/turtleville/OBJ/shellamulet.c"; 
  break;
case "shellboots":
  cost = 20;
  file = "/players/wocket/turtleville/OBJ/shellboots.c";
  break;
case "shellring":
  cost = 10;
  file = "/players/wocket/turtleville/OBJ/shellring.c";
  break;
case "shellsash":
  cost = 20;
  file = "/players/wocket/turtleville/OBJ/shellsash.c";
  break;
case "shellmail":
  cost = 50;
  file = "/players/wocket/turtleville/OBJ/shellmail.c";
  break;
default:
  notify_fail("Talieos says: What was that you wanted to buy?\n");
  return 0;
  break;
}
if(!present("aturtleshell",this_player())){
    notify_fail("Talieos says: You lack the neccesary components.\n");
    return 0;
}
if(str == "shellmail" && !present("aturtleshell 3",this_player())){
    notify_fail("Talieos says: I will need more shells to complete that project.\n");
    return 0;
}
if(this_player()->query_money() < cost){
    notify_fail("Talieos says: You lack the neccesary funds.\n");
    return 0;
}

  this_player()->add_money(-cost); 
  move_object(clone_object(file),this_player());
  destruct(present("aturtleshell",this_player()));
  this_player()->recalc_carry();
  write("Talieos takes your shell and forges a "+str+" from it.\n");
  write("Talieos hands you a "+str+" and quickly takes your money.\n");
  say("Talieos takes "+this_player()->query_name()+"'s shell and forges a "+str+" from it.\n",this_player());
  say("Talieos hands "+this_player()->query_name()+" a "+str+" and quickly takes "+this_player()->query_possessive()+" money.\n",this_player());

if(str == "shellmail"){
  destruct(present("aturtleshell",this_player()));
  destruct(present("aturtleshell",this_player()));
}
return 1;
}
