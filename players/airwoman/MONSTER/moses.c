inherit "obj/monster.talk";
 
reset(arg){
    object money,cotton;
    ::reset(arg);
    if(!arg) {
    set_name("moses");
    set_alias("moses");
    set_level(18);
    set_hp(1800);           
    set_short("Moses the best cotton cropper");
    set_long("Havent you watched the movie: Places in the Heart?\n"+
              "Good movie...And Moses was the best cotton farmer\n");
    set_aggressive(0);
    set_wc(15);
    set_ac(26);
    set_chat_chance(10);
    load_chat("Moses says:  This year our cotton is the best in the"+
             "  south. \n");
    money=clone_object("obj/money");
    money->set_money(500+random(500));
    move_object(money, this_object());
    cotton=clone_object("players/airwoman/food/cotton");
    move_object(cotton, this_object());
}
}
 
 
  
