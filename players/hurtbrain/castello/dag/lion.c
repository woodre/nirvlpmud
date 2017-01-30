inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
	set_short( "A lion") ;
        set_long("This is a hungry lion. He is fighting for his life.\n") ;
        set_name ("lion") ;
        set_gender( "male" );
        set_level(5);
        set_hp(75);
  	set_al(0);
  	set_wc(9);
  	set_ac(5);
       	gold=clone_object("obj/money");
       	gold->set_money(180 + random(50));
       	move_object(gold,this_object());
	set_race("lion") ;
}

