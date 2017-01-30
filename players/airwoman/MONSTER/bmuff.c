inherit "obj/monster.talk";
 
reset(arg){
    object money,bberry;
    ::reset(arg);
    if(!arg) {
    set_name("blue berry muffin");
    set_alias("muffin");
    set_level(18);
    set_hp(1800);
    set_short("Blue Berry Muffin");
    set_long("Blue Berry Muffin loves blue berries...\n");
    set_aggressive(0);
    set_wc(26);
    set_ac(15);
    set_chat_chance(10);
    load_chat("Blueberry Muffin says: look at my eyes...\n");
    money=clone_object("obj/money");
    money->set_money(500+random(500));
    move_object(money, this_object());
    bberry=clone_object("players/airwoman/food/bberry");
    move_object(bberry, this_object());
}
}
 
init() {
  add_action("look_at_eyes", "look");
   ::init();
}
 
look_at_eyes(str)
{
   if(str == "at eyes")
   {
        write("You look at Blueberry Muffin's eyes....\n");
        write("Her eyes are as blue as blueberries...\n");
        say(this_player()->query_name()+ " looks"+
        " at Blueberry Muffin's eyes.\n");
	return 1;
    }
}
