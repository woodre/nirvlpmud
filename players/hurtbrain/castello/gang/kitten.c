inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A kitten") ;
        set_long("A cute little kitten. I hope you don't want to kill him!\n");
        set_name ("kitten") ;
        set_gender( "male" );
        set_level(3);
        set_hp(45);
        set_al(100);
        set_wc(7);
        set_ac(4);
        set_chat_chance (10);
        load_chat("MMMIIIAAAAOOO\n");
        gold=clone_object("obj/money");
        gold->set_money(50 + random(50));
        move_object(gold,this_object());
        set_race("cat") ;
}

