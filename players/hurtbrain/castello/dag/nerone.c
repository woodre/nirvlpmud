inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
        if(arg) return;
        set_short( "Nero, the tyrant") ;
        set_long("You tremble as you see his red glowing eyes. He is \n"+
        "trying to set fire to everything here.\n") ;
        set_name ("nero") ;
        set_alias ("tyrant");
        set_gender( "male") ;
        set_level(17);
        set_hp(425);
        set_al(-1000);
        set_wc(24);
        set_ac(14);
        set_race("human") ;
        set_chance(10);
        set_spell_dam(20+random(10));
        set_spell_mess1("Nero sets fire to all the room.\n");
        set_spell_mess2("Nero sets fire to you!\n");
        ob1 = clone_object ("/players/hurtbrain/castello/dag/shtunic") ;
        move_object(ob1,this_object());
}

