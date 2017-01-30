
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A policeman") ;
        set_long("The policeman is controlling the men in this room\n"+
                "looking for something that can lead them to the boss.\n");
        set_name ("policeman") ;
        set_alias ("man") ;
        set_gender( "male" );
        set_level(8);
        set_hp(120);
        set_al(100);
        set_wc(12);
        set_ac(7);
        set_chat_chance (15);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(300 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/cudgel") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

