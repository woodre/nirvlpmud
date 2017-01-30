inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("skeeza");
   set_race("human");
   set_alias("pusher");
   set_alias("dealer");
   set_heal(30, 1);
   set_short("A drug dealer named Skeeza");
   set_long("\n"+
"  You look at the drug dealer named Skeeza.  He is a fairly nice fella,\n"+
"considering what he does.  He is wearing a trenchcoat and looks extremely\n"+
"threatening to you.  He is someone you wouldn't wanna meet in a dark alley\n"+
"...  then why are you here, in a dark alley!?!?!?  To see what he has type\n"+
"'list'.\n");
   set_level(1);
  set_hp(50+ random(40));
   set_al(-500);
  set_wc(6);
  set_ac(4);
   set_chat_chance(2);
   load_chat("Skeeza asks: Hey homes, wanna get high?\n");
   load_chat("Skeeza says: to see what I sell type 'list'\n");
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
  write("\n\n\nThats it for now, ya gotz and idea mail it to Pathfinder.\n");
  write("\n\n\n");
  return 1;
  }
  
buy(arg){
  object drug,tp;
  tp=this_player();
  if(!arg){
    Write("Buy What?\n");
    return 1;
    }
  if(arg == "1") {
    if(tp->query_money() < 10000) {
    write("Skeeza bitches about you not having enuf cash.\n");
      return 1;
  }
  if(!call_other(tp,"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  tp->add_money(-10000);
  write("You hand Skeeza the cash and he passes you the cocaine.\n");
  say("You see Skeeza pass something to "+capitalize(tp->query_name())+"\n");
  drug=clone_object("players/pathfinder/detroit/items/cocaine");
  move_object(drug,tp);
  return 1;
  } else if(arg == "2") {
  if(tp->query_money() < 10000) {
    write("Skeeza bitches about you not having enuf cash.\n");
      return 1;
  }
  if(!call_other(tp,"add_weight",1)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  tp->add_money(-10000);
  write("You hand Skeeza the cash and he passes you the syringe.\n");
  say("You see Skeeza pass something to "+capitalize(tp->query_name())+"\n");
  drug=clone_object("players/pathfinder/detroit/items/heroin");
  move_object(drug,tp);
  return 1;
  } else if(arg == "3") {
  if(tp->query_money() < 3000) {
    write("Skeeza bitches about you not having enuf cash.\n");
    return 1;
  }
  if(!call_other(tp,"add_weight",2)) {
    write("It is too heavy for you to carry!\n");
    return 1;
  }
  tp->add_money(-3000);
  write("You pass your cash to Skeeza as he hands you da pot.\n");
  say("You see Skeeza pass something to "+capitalize(tp->query_name())+"\n");
  drug=clone_object("players/pathfinder/detroit/items/marijuana");
  move_object(drug,tp);
  return 1;
  }
}
 
    

