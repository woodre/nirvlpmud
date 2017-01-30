inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A Roman soldier") ;
        set_long("This is one of the many soldiers protecting the Emperor.\n") ;
        set_name ("soldier") ;
        set_gender( "male" );
        set_level(14);
        set_hp(210);
        set_al(-100);
        set_wc(18);
        set_ac(11);
        gold=clone_object("obj/money");
        gold->set_money(630 + random(50));
        move_object(gold,this_object());
        ob3 = clone_object("/players/hurtbrain/castello/dag/dagger") ;
        move_object(ob3,this_object());
        set_race("human") ;
}

