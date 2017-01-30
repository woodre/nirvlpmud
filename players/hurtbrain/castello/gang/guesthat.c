
inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
if(arg) return;
        set_short( "A guest of the party") ;
        set_long("A well-dressed man. He's one of the guest of that party.\n"+
                "He probably is searching someone to talk to.\n");
        set_name ("guest") ;
        set_gender( "male" );
        set_level(6);
        set_hp(90);
        set_al(50);
        set_wc(10);
        set_ac(5);
        set_chat_chance (15);
	load_chat("Guest asks for a glass of champagne.\n");
	load_chat("Guest says: '..Ahem , sir.. can i introduce myself?'\n");
	load_chat("Guest giggles.\n");
        if (random(3) > 0)  {
                gold=clone_object("obj/money");
                gold->set_money(200 + random(50));
                move_object(gold,this_object());
        }
        else  {        
                ob3 = clone_object("/players/hurtbrain/castello/gang/hat") ;
                move_object(ob3,this_object());
        }       
        set_race("human") ;
}

