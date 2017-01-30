inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "A viper") ;
        set_long("A little but very poisoned viper.\n") ;
        set_name ("viper") ;
        set_gender( "neutral" );
        set_level(3);
        set_hp(45);
  	set_al(-200);
  	set_wc(30);
  	set_ac(15);
       set_aggressive(1);
       	gold=clone_object("obj/money");
       	gold->set_money(80 + random(50));
       	move_object(gold,this_object());
	set_race("viper") ;
    set_chance(10);
    set_spell_dam(100);
    set_spell_mess2("The viper's poison bursts into your veins!\n");
    set_spell_mess1("The viper's fangs impale its prey!\n");
}

