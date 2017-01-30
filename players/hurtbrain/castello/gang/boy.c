inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A young boy") ;
        set_long("You see this boy trying to steal guest's wallet,\n"+
                "while another boy is distracting him.\n");
        set_name ("boy") ;
        set_gender( "male" );
        set_level(5);
        set_hp(75);
        set_al(-50);
        set_wc(9);
        set_ac(5);
        set_chat_chance (15);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(170 + random(30));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/knife") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

