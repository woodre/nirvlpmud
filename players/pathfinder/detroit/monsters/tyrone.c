inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("tyrone");
   set_race("human");
   set_alias("pusher");
   set_heal(30, 1);  /*  Added by Fred...10-10-03   */
   set_alias("dealer");
   set_short("A huge drug dealer named Tyrone");
   set_long("\n"+
"  You have to stand back and look at Tyrone, he stands a full 2 heads\n"+
"taller than you with 6 times the mass.  He is definitely not someone\n"+
"to want to mess with.  To get a list of the drugs Tyrone sells type\n"+
"'list'.\n");   
   set_level(1);
   set_hp(1500+ random(1000));
   set_al(-500);
   set_wc(25);
   set_ac(5000);
   set_chat_chance(2);
   load_chat("Tyrone says: Yo 'G, want some dope man?\n");
   load_chat("Tyrone says: to see what I got type 'list'\n");
   load_chat("Tyrone says: If ya don't wanna buy something leave!\n");
}
 
init() {
  ::init();
  add_action("list","list");
  add_action("buy","buy");
       }
       
list() {
  write("Ok guy, heres all the goodies I gots for sale...  if yous don't\n");
  write("like 'em go elsewhere, I'm sure you ain't gonna get nuthin like\n");
  write("this anywhere 'round these parts.\n");
  write("\nTo buy something type 'buy <number>'.\n");
  write("\n\n\n");
  write("   Number    Name                             Cost\n");
  write("   ------    -------------------------        ----\n");
  write("     1       Line of Cocaine                  10000\n");
  write("     2       Syringe of Heroin                10000\n");
  write("     3       Bag of Marijuana                  3000\n");
  write("\n\n\nThats it for now, ya gotz an idea mail it to Pathfinder.\n");
  write("\n\n\n");
  return 1;
  }
  
buy(arg){
  object drug,tp;
  tp=this_player();
  if(!arg){
    write("buy what?\n");
    return 1;
    }
  if(arg == "1") {
    if(this_player()->query_money() < 10000) {
      write("Tyrone slaps you in the face and calls you a thief!\n");
      return 1;
  }
  if(!call_other(this_player(),"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-10000);
  write("You hand Tyrone the cash and he passes you the cocaine.\n");
  say("You see Tyrone pass something to "+capitalize(this_player()->query_name())+".\n");
  drug=clone_object("players/pathfinder/detroit/items/cocaine");
  move_object(drug,this_player());
  return 1;
  } else if(arg == "2") {
  if(this_player()->query_money() < 10000) {
      write("Tyrone slaps you in the face and calls you a thief!\n");
      return 1;
  }
  if(!call_other(this_player(),"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  this_player()->add_money(-10000);
  write("You hand Tyrone the cash and he passes you the syringe.\n");
  say("You see Tyrone pass something to "+capitalize(this_player()->query_name())+".\n");
  drug=clone_object("players/pathfinder/detroit/items/heroin");
  move_object(drug,this_player());
  return 1;
  } else if(arg == "3") {
  if(tp->query_money() < 3000) {
    write("Tyrone slaps you 'cross the face and calls you a thief!\n");
    return 1;
  }
  if(!call_out(tp,"add_weight",2)) {
    write("It is too much for you to carry!\n");
    return 1;}
  tp->add_money(-3000);
  write("You pass Tyrone the cash as he hands you the pot.\n");
  say("You see Tyrone pass something to "+capitalize(this_player()->query_name())+"\n");
  drug=clone_object("players/pathfinder/detroit/items/marijuana");
  move_object(drug,tp);
  return 1;
  }
}
 
    
  
