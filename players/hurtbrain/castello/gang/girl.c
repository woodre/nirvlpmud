inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A old-fashion girl") ;
        set_long("A strange girl , wearing a dress with paillettes and\n"+
                "a scarf of ostrich feathers.\n");
        set_name ("girl") ;
        set_gender( "female" );
        set_level(5);
        set_hp(75);
        set_al(0);
        set_wc(9);
        set_ac(5);
        set_chat_chance (15);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(150 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/feathers") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

