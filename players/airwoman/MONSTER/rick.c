/* Changed unset hp to 400 -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money;
    ::reset(arg);
    if(!arg) {
	set_name("ranger rick");
    set_alias("rick");
    set_level(16);
    set_hp(400);
    set_short("Ranger Rick");
    set_long("Ranger Rick thinks he can save the world\n"+
             "from destroying the environment.\n");
    set_aggressive(0);
    set_wc(22);
	set_ac(5);
    set_chat_chance(10);
    load_chat("Ranger Rick says:  Hey Kids!  Recycle!\n");
    money=clone_object("obj/money");
    money->set_money(300+random(500));
    move_object(money, this_object());
}
}
 
