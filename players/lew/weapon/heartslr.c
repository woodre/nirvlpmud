inherit "obj/weapon";

reset(arg) {
  if(!arg) {

    set_id("heartslayer");
    set_alias("sword");
    set_short("The Heart Slayer");
    set_long("The Heart Slayer.\n"+
             "This is the anchient sword of hearts.\n"+
             "If your heart has been broken, use it for\n"+
             "revenge against the one whom broke you heart\n"+
             "But remember, it does have two edges.\n"+
             "Only the song of the broken heart will send it for..\n"+
             "REVENGE!!\n");
    set_class(18);
     set_value(7500);
    set_weight(8);
    set_save_flag(0);
    set_hit_func(this_object());
}
}
weapon_hit(attacker) {
   if(attacker->query_npc()) {
   if(attacker->query_level()<15) {
    call_other(this_object(), "set_class", 10);
    call_other(this_player(), "set_wc", 10);
    return 1;
   }
  }
    call_other(this_object(), "set_class", 18);
    call_other(this_player(), "set_wc", 18);
  write("You grin as you slice "+attacker->query_real_name()+"'s throat.\n");
  tell_object(attacker, capitalize(this_player()->query_real_name())+
      "slices your throat with the bloodsword.\n");
say(capitalize(this_player()->query_real_name())+" slices his enemy's throat.\n");
/*   before this next line was attakcer->hit_player(random(100))
     I have hopefully fixed it so that it doesn't cause instant
     death.
*/
  attacker->hit_player(random(30));
  return 1;
}
init(){
     ::init();

     add_action("seek","seek");
}

seek(str){ return "test\n";}
