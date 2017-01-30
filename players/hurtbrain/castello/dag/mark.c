inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
        set_short( "Mark Anthony") ;
        set_long("A young charming man. His eyes seems to hypnotize you.\n") ;
        set_name ("mark") ;
        set_alias ("anthony");
        set_gender( "male") ;
        set_level(15);
        set_hp(250);
        set_al(100);
        set_wc(20);
        set_ac(12);
        set_race("human") ;
        ob1 = clone_object ("/players/hurtbrain/castello/dag/tunic2") ;
        move_object(ob1,this_object());
        ob2 = clone_object ("/players/hurtbrain/castello/dag/necklace") ;
        move_object(ob2,this_object());
}
