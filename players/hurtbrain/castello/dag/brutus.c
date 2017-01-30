inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "Brutus, Emperor's son") ;
        set_long("A young man that is sharpening a knife. He seems to be nervous.\n");
        set_alias("son") ;
        set_name ("brutus") ;
        set_gender( "male") ;
        set_level(19);
        set_hp(480);
  	set_al(-700);
  	set_wc(29);
  	set_ac(17);
        set_whimpy();
        gold=clone_object("obj/money");
        gold->set_money(900 + random(400));
        move_object(gold,this_object());
        ob3 = clone_object ("/players/hurtbrain/castello/dag/knife") ;
        move_object(ob3,this_object());
        ob1 = clone_object ("/players/hurtbrain/castello/dag/tunic") ;
        move_object(ob1,this_object());
        set_race("human") ;
        set_chat_chance (15);
        load_chat("Brutus mumbles, 'My father is ready to die!'\n");
        load_chat("Brutus looks at you, suspiciously hiding his knife.\n");
        load_chat("Brutus says, 'I have to wait for Cassius' letter.'\n");
}

