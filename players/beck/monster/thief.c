inherit "obj/monster";
string wealthy;
reset(arg){
   object gold;
   ::reset(arg);
  if(arg || root()) return; /* verte */
/*
   restore_object("players/beck/save/THIEF");
*/
chat_str = 0;
a_chat_str = 0;
   set_name("thief");
   set_race("human");
   set_short("A Sneaky Thief");
   set_long("This is a small man, wearing a dark green cloak.\n"+
      "He has tiny black eyes that stare coldly at you.\n"+
      "Though he doesn't seem threating from his small size\n"+
      "you know this guy means business.\n"+
      "I'd just give him some COINS if I were you.\n"+
      "");
   set_wc(30);
   set_al(0);
   set_ac(17);
   set_level(20);
   set_hp(600);
   set_chat_chance(10);
   load_chat("Give me your money and you may pass.\n");
   load_chat("You seem to have plenty of money to give me.\n");
   set_dead_ob(this_object());
   call_out("check",40);
}
set_wealthy(arg){
   wealthy = arg;
   return 1;
}
init(){
   add_action("halt","east");
   add_action("halt","west");
}
halt(){
   write("The thief says: How dare you try and escape me.\n"+
      "The thief then takes his knife and puts it to your throat, drawing some blood.\n"+
"Give me some money!\n"+
      "");
   return 1;
}
add_money(arg){
   ::add_money(arg);
/*
   save_object("players/beck/save/THIEF");
*/
   if(this_player()->query_money() > 35000 && arg < 300){
      write("The thief says: I think you have more than that to give.\n");
      return 1;
   }
   write("The thief jumps back into the bushes and disappears.\n");
   destruct(this_object());
   return 1;
}
monster_died(ob){
   money = 0;
/*
   save_object("players/beck/save/THIEF");
*/
   return 0;
}
check(){
   if(!present(wealthy, environment(this_object()))){
      destruct(this_object());
      return 1;
   }
   call_out("check",40);
   return 1;
}
