#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){

  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/turtleville/OBJ/mstaff.c"),this_object());
set_name("lladious");
set_short(BOLD+"Lladious"+NORM+", the Magus");
set_alias("magus");
set_alt_name("wizard");
set_long("His robes are tattered and worn with many patches.  His beard is grey with\n"+
"streaks of white, which runs down to his tummy.  The hat upon his head was pointy,\n"+
"but has now become bent and tilted.  A magic aura seems to radiate around him\n"+
"as he makes his many potions that he sells.  You can always ask him for a 'list'\n"+
"of his wares.\n");
set_level(20);
set_hp(500);
set_wc(40);
set_ac(18);
set_spell_dam(55);
set_chance(24);
set_spell_mess1(HIY+"Lightning "+NORM+"flares from his fingertips "+HIY+"igniting"+NORM+" his advisary.");
set_spell_mess2(HIY+"Lighting "+NORM+"flares from his fingertips "+HIY+"igniting"+NORM+" his advisary.\n"+RED+"...burns tear at your body..."+NORM);
}

init(){
  ::init();
  add_action("list","list");
  add_action("ask","ask");
  add_action("ask","buy");
  add_action("ask","order");
}

list(){
  write("Lladious says: You may 'order' these things:\n\n"+
        "  COST           ITEM\n"+
        " 17000          A magical potion of 'full heal'\n"+
        " 15600          A mysterious potion of 'regen'eration\n"+
"");
return 1;
}


ask(string str){
string file_name;
int cost;

  switch(str){
  case "full heal":  file_name = "/players/wocket/turtleville/OBJ/heal_potion.c";
                  cost = 17000;
                  break;
  case "regen":  file_name = "/players/wocket/turtleville/OBJ/regen_potion.c";
cost = 15600;
               break;
  default:  write("Lladious says: I do not have that to sell.\n");
            return 1;
}
if(this_player()->query_money() < cost){
  notify_fail("Lladious says: You do not have enough money.\n");
  return 0;
}
if(!this_player()->add_weight(1)){
  notify_fail("Lladious says: You are to weak to carry that.\n");    
  return 0;
}

move_object(clone_object(file_name),this_player());
this_player()->add_money(-cost);
write("You hand Lladious some money as he gives you the "+str+".\n");
say(this_player()->query_name()+" hands Lladious some money as he gives "+this_player()->query_name()+" a "+str+".\n",this_player());
this_player()->recalc_carry();
return 1;
}  
