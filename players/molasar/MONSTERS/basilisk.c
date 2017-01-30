/* Set ac to 25 from 5  - Snow */


inherit "obj/monster";

reset(x) {
     object broach, statue, robe, gem;
    if(x) return;
        broach = clone_object("obj/treasure");
        call_other(broach,"set_id","broach");
        call_other(broach,"set_alias","broach");
        call_other(broach,"set_weight",1);
        call_other(broach,"set_short","A broach");
        call_other(broach,"set_long",
            "A silver broach with a pearl set in the middle.\n");
        call_other(broach,"set_value",250);
        statue = clone_object("obj/treasure");
        call_other(statue,"set_id","statue");
        call_other(statue,"set_alias","onyx statue");
        call_other(statue,"set_short","A small onyx statue");
        call_other(statue,"set_long",
            "This is a statue of a little weasle.\n");
        call_other(statue,"set_weight",2);
        call_other(statue,"set_value",375);
        robe = clone_object("players/molasar/MAGIC/robe_items");
        gem = clone_object("obj/treasure");
        call_other(gem,"set_id","emerald");
        call_other(gem,"set_alias","gem");
        call_other(gem,"set_weight",1);
        call_other(gem,"set_short","An emerald");
        call_other(gem,"set_value",500);
        set_name("basilisk");
        set_level(19);
        set_hp(800);
        set_ac(25);
        set_wc(22);
        set_al(-200);
        move_object(broach,this_object());
        move_object(statue,this_object());
        move_object(robe,this_object());
        move_object(gem,this_object());
}


