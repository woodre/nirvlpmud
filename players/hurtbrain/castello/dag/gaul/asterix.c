inherit "obj/monster";
reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
   if(arg) return;
        set_short( "Asterix, the gaul") ;
        set_long("A strange looking man with long red mustaches. He doesn't\n"
		+"seems very menacious.\n") ;
        set_name ("asterix") ;
        set_gender( "male") ;
        set_level(21);
        set_hp(550);
        set_al(200);
        set_wc(32);
        set_ac(18);
        set_race("human") ;
        set_chat_chance (25);
        load_chat("Asterix says: 'I need the potion. Panoramix, where are you?'\n");
        load_chat("Asterix search for the ingerdients of the potion.\n");
        load_chat("Asterix sighs: 'No roman to beat here.'\n");
        set_chance(10);
        set_spell_dam(random(20)+10);
        set_spell_mess1("Asterix drinks his potion and become THOUGHT!\n");
        set_spell_mess2("Asterix drinks the potion and crashes you.\n");
        gold=clone_object("obj/money");
        ob1 = clone_object ("/players/hurtbrain/castello/dag/gaul/ast_helm") ;
        move_object(ob1,this_object());
        ob2 = clone_object ("/players/hurtbrain/castello/dag/gaul/ast_axe") ;
        move_object(ob2,this_object());
}

