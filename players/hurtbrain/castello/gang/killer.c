
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A hired killer") ;
        set_long("This man has a strange look in his eyes. He stares at you\n"+
                "and you feel a cool chill running on your spine.\n");
        set_name ("killer") ;
        set_gender( "male" );
        set_level(7);
        set_hp(105);
        set_al(-100);
        set_wc(11);
        set_ac(6);
        set_chat_chance (15);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(250 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/rifle") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

