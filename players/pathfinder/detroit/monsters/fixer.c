inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("fixer");
   set_race("human");
   set_alias("dealer");
   set_alias("man");
   set_heal(20, 1);
   set_short("A weapons fixer");
   set_long("\n"+
"  You look at the man standing the the center of the room.  He is\n"+
"not tall, short in fact, he has thick glasses that look like they should\n"+
"be used for some experiment rather than to see through.  He looks like he\n"+
"is the keeper of the assortment of weapons.  He notices you and says\n"+
"if you'd like a list of my warez type 'list', to buy something type\n"+
"buy <number>\n");   
   set_level(1);
   set_hp(20+ random(50));
   set_al(-500);
   set_wc(5);
   set_ac(5);
   set_chat_chance(2);
   load_chat("Fixer says: Wanna buy a kewl weapon?\n");
   load_chat("Fixer says: to see what I got type 'list'\n");
   load_chat("Fixer mumbles about business being slow.\n");
}
 
init() {
  ::init();
  add_action("list","list");
  add_action("buy","buy");
       }
       
list() {
  write("Here is a list of all the goodies I got for sale for ya.\n");
  write("You probably won't find a better selection in all of Detroit!\n");
  write("\n\n\n");
  write("   Number    Name                             Cost\n");
  write("   ------    -------------------------        ----\n");
  write("     1       9mm Beretta                      3000\n");
  write("     2       9mm Beretta clip                  400\n");
  write("     3       9mm Uzi                          3000\n");
  write("     4       9mm Uzi clip                      600\n");
  write("     5       Machete                          5000\n");
  write("\n\n\nThats it for now, ya gotz and idea mail it to Pathfinder.\n");
  write("\n\n\n");
  return 1;
  }
  
buy(arg){
  object item;
  if(!arg){
    Write("Buy What?\n");
    return 1;
    }
  if(arg == "1") {
    if(this_player()->query_money() < 3000) {
      write("The fixer pulls out a pistol and calls you a thief!\n");
      return 1;
  } else
  if(!call_other(this_player(),"add_weight",4)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-3000);
  write("You pass the cash to the fixer and he hands you the pistol.\n");
  say("You see the fixer give "+capitalize(this_player()->query_name())+" a pistol.\n");
  item=clone_object("players/pathfinder/detroit/weapons/9mm");
  move_object(item,this_player());
  return 1;
  } else if(arg == "2") {
  if(this_player()->query_money() < 400) {
      write("The fixer pulls out a pistol and calls you a thief!\n");
        return 1;
  } else
  if(!call_other(this_player(),"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-400);
  write("You give the fixer the money as he passes you the clip.\n");
  say("You see the fixer hand a clip to "+capitalize(this_player()->query_name())+".\n");
  item=clone_object("players/pathfinder/detroit/weapons/clipb");
  move_object(item,this_player());
  return 1;
  } else if(arg == "3") {
  if(this_player()->query_money() < 4000) {
      write("The fixer pulls out a pistol and calls you a thief!\n");
        return 1;
  } else
  if(!call_other(this_player(),"add_weight",7)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-4000);
  write("You give the fixer the money as he passes you the Uzi.\n");
  say("You see the fixer hand a Uzi to "+capitalize(this_player()->query_name())+".\n");
  item=clone_object("players/pathfinder/detroit/weapons/uzi");
  move_object(item,this_player());
  return 1;
  } else if(arg == "4") {
  if(this_player()->query_money() < 600) {
      write("The fixer pulls out a pistol and calls you a thief!\n");
        return 1;
  } else
  if(!call_other(this_player(),"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-600);
  write("You give the fixer the money as he passes you the clip.\n");
  say("You see the fixer hand a clip to "+capitalize(this_player()->query_name())+".\n");
  item=clone_object("players/pathfinder/detroit/weapons/clip");
  move_object(item,this_player());
  return 1;
  } else if(arg == "5") {
  if(this_player()->query_money() < 5000) {
      write("The fixer pulls out a pistol and calls you a thief!\n");
        return 1;
  } else
  if(!call_other(this_player(),"add_weight",7)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-5000);
  write("You give the fixer the money as he passes you the machete.\n");
  say("You see the fixer hand a machete to "+capitalize(this_player()->query_name())+".\n");
  item=clone_object("players/pathfinder/detroit/weapons/machete");
  move_object(item,this_player());
  return 1;
 
}
}
    

