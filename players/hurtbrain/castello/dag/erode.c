inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
	set_short( "Erode, the slaughter") ;
        set_long("You tremble in fear! You see this man killing kids\n"+
	"without reason. Perhaps he is mad?\n") ;
        set_name ("erode") ;
        set_gender( "male") ;
        set_level(19);
        set_hp(470);
  	set_al(-1000);
  	set_wc(27);
  	set_ac(16);
        set_aggressive(1);
        if(random(2)) set_whimpy();
        ob1 = clone_object ("/players/hurtbrain/castello/dag/tunic") ;
        move_object(ob1,this_object());
	ob2 = clone_object("/players/hurtbrain/castello/dag/ero_sword") ;
        move_object(ob2,this_object());
        set_race("human") ;
        set_chat_chance (25);
        load_chat("Erode shouts: 'Kill Him! I have to kill Him!'\n");
        load_chat("Erode says: 'If i don't kill Him he'll destroy me.'\n");
        load_chat("Erode shouts: 'Let's kill all male kids.'\n");
}

