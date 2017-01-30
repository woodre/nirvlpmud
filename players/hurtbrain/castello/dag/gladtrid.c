inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "A Gladiator") ;
        set_long("Fighting for his own life against men and lions.\n") ;
        set_name ("gladiator") ;
        set_gender( "male" );
        set_level(3);
        set_hp(45);
  	set_al(-20);
  	set_wc(7);
  	set_ac(4);
	if (random(2))  {
        	gold=clone_object("obj/money");
        	gold->set_money(80 + random(50));
        	move_object(gold,this_object());
	}
	else  {        
		ob3 = clone_object ("/players/hurtbrain/castello/dag/trident") ;
        	move_object(ob3,this_object());
	}       
	set_race("human") ;
}

