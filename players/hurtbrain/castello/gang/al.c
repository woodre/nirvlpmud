
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "Al Capone") ;
        set_long("He is the boss' boss. Only one command and you found yourself\n"+
	"in a cement block. He is a pitiless , heartless man. He seems harmless but\n"+
                "don't turn the shoulders to him!\n");
        set_name ("al") ;
	set_alias ("capone");
        set_gender( "male" );
        set_level(14);
        set_hp(210);
        set_al(-500);
        set_wc(18);
        set_ac(11);
	set_chat_chance(20);
	load_chat("Al says: 'What do you want to do you little cute rabbit?!'\n");
	load_chat("Al shoots his bullets against you.\n");
	load_chat("Al grins evilly and light a cigar\n");
        ob1 = clone_object("/players/hurtbrain/castello/gang/mgun") ;
        move_object(ob1,this_object());
        ob3 = clone_object("/players/hurtbrain/castello/gang/jacket") ;
        move_object(ob3,this_object());
        set_race("human") ;
}

