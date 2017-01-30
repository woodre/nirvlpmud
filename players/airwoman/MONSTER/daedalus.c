/* Changed hps (from unset resulting in 202) to 600  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money,wings;
    ::reset(arg);
    if(!arg) {
    set_name("daedalus");
    set_alias("daedalus");
    set_level(20);
    set_hp(600);
    set_short("Daedalus -- the inventor of wings");
    set_long("The legendary builder of the Cretan labyrinth and \n"+
    "the inventor of wings whereby he flew to escape imprisonment...\n");
    set_aggressive(0);
    set_wc(30);
    set_ac(17);
    set_chat_chance(10);
    load_chat("Daedalus says:  Have you seen my son Icarus?\n");
    load_chat("Daedalus says:  I have made these wings for my "+
        "son.\n");
    set_a_chat_chance(10);
    load_a_chat("Daedalus says:  You will have to take these wings "+
        "over my dead body!\n");
    money=clone_object("obj/money");
    money->set_money(500+random(500));
    move_object(money, this_object());
    wings=clone_object("players/airwoman/quest/wings");
    move_object(wings, this_object());
    }
}
 
