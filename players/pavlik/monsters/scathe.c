inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "scatheman" );
     set_alias("scathe");
   set_short("Scathe the Terrible");
   set_long("Scathe is a 'very powerful alchemist wizard'.\n");
     set_level(4);
     set_ac(4);
     set_wc(8);
     set_hp(60);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
   load_chat("Scathe says 'The Alchs will destory all unworthy guilds!\n");
  load_chat("Scathe wimpers at the sight of your large weapon!\n");
   load_chat("Scathe says 'Alchs are the best guild! We have the biggest Attitudes!\n");
   load_a_chat("Scathe runs his feet on the carpet and shocks you!\n");
    load_a_chat("Scathe says 'Dont hurt me! Thats not nice!\n");
   load_a_chat("Scathe wimpers 'Im tellin Boltar on you!\n");
     money = (24);
   }
}

init(arg){
  if(arg) return;
  tell_object(this_player(),
  "Scathe stands up and attacks!\n");
}

/*
catch_tell(str){
  if(find_player("pavlik")){
    tell_object(find_player("pavlik"),
    "/> "+str+"\n");
  }
  return 1;
}
*/

