
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A bodyguard") ;
        set_long("This is a very impressive man , 6'10\" tall 220 lbs weight\n"+
                "and with a very evil grin on his face.\n");
        set_name ("bodyguard") ;
        set_gender( "male" );
        set_level(9);
        set_hp(135);
        set_al(-200);
        set_wc(13);
        set_ac(7);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(350 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/mgun") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

