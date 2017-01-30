inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A shoeshine") ;
        set_long("A child dressed in dirty and teared jacket and trousers that\n"+
		"probably someone else used before. He is waiting for some clients.\n");
        set_name ("shoeshine") ;
        set_gender( "male" );
        set_level(4);
        set_hp(60);
        set_al(50);
        set_wc(8);
        set_ac(4);
        set_chat_chance (15);
        load_chat("Shoeshine asks: 'Do you want i clean your shoes?'\n");
        load_chat("Shoeshine cleans your shoes.\n");
        load_chat("Shoeshine says: '.. only few coins .. I need it, please!'\n");
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(100 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object ("/players/hurtbrain/castello/gang/brush") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

