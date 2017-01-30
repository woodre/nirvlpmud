
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A crime boss") ;
        set_long("He is a pitiless , heartless man. He seems harmless but\n"+
                "don't turn the shoulders to him!\n");
        set_name ("boss") ;
        set_gender( "male" );
        set_level(10);
        set_hp(150);
        set_al(-300);
        set_wc(14);
        set_ac(8);
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(400 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/jacket") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

