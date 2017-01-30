inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "A Roman soldier") ;
        set_long("This is one of the many soldiers protecting the Emperor.\n") ;
        set_name ("soldier") ;
        set_alias("roman");
        set_gender( "male" );
        set_level(5);
        set_hp(75);
  	set_al(-100);
  	set_wc(9);
  	set_ac(5);
	if (random(2))  {
        	gold=clone_object("obj/money");
        	gold->set_money(180 + random(50));
        	move_object(gold,this_object());
	}
	else  {        
		ob3 = clone_object("/players/hurtbrain/castello/dag/dagger") ;
        	move_object(ob3,this_object());
	}       
	set_race("human") ;
}

