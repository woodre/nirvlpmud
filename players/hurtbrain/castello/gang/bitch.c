
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A young bitch") ;
        set_long("The bitch stares at you winking and giggling. Probably she\n"+
                "is looking for a client.\n");
        set_name ("bitch") ;
        set_gender( "female" );
        set_level(7);
        set_hp(105);
        set_al(-50);
        set_wc(11);
        set_ac(6);
        set_chat_chance (15);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(250 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/ring") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

