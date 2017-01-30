inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "A Roman Centurion") ;
        set_long("This is one of the many guards protecting Giulius from his enemies.\n") ;
        set_name ("centurion") ;
        set_gender( "male") ;
        set_level(15);
        set_hp(250);
  	set_al(0);
  	set_wc(19);
  	set_ac(11);
        gold=clone_object("obj/money");
        gold->set_money(100 + random(200));
        move_object(gold,this_object());
        ob3 = clone_object ("/players/hurtbrain/castello/dag/dagger") ;
        move_object(ob3,this_object());
        ob1 = clone_object ("/players/hurtbrain/castello/dag/helmet") ;
        move_object(ob1,this_object());
        set_race("human") ;
        set_a_chat_chance (10);
        load_a_chat("The centurion fights for his Emperor.\n");
        load_a_chat("Centurion says, 'You have to kill us to go to the emperor!\n");
}

