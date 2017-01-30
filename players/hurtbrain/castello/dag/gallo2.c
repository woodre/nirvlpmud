inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "A Gaul") ;
        set_long("A Gaul soldier. He seems to have fighted a hard battle.\n") ;
        set_name ("gaul") ;
        set_gender( "male" );
        set_level(3);
        set_hp(45);
  	set_al(20);
  	set_wc(7);
  	set_ac(4);
       	gold=clone_object("obj/money");
       	gold->set_money(80 + random(50));
       	move_object(gold,this_object());
	set_race("human") ;
}
