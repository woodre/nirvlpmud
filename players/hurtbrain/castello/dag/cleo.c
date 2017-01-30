inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
	set_short( "Cleopatra") ;
        set_long("A beautiful woman is staring at you. Perhaps you can comfort her.\n") ;
        set_name ("cleopatra") ;
        set_gender( "female") ;
        set_level(18);
        set_hp(450);
  	set_al(100);
  	set_wc(26);
  	set_ac(15);
        ob1 = clone_object ("/players/hurtbrain/castello/dag/ring") ;
        move_object(ob1,this_object());
	ob2 = clone_object ("/players/hurtbrain/castello/dag/fangs") ;
        move_object(ob2,this_object());
        set_race("human") ;
}

