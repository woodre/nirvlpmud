    if (!stalker || !living(stalker)) {
	stalker = clone_object("obj/monster");
	call_other(stalker, "set_name", "stalker");
	call_other(stalker, "set_hp", 300);
call_other(stalker, "set_ac", 6);
	call_other(stalker, "set_wc", 15);
	call_other(stalker, "set_al", 200);
	call_other(stalker, "set_short", "A Dark Stalker");
	call_other(stalker, "set_long",
    "A leader of the dark creepers, it is about the size of a human.\n");
	call_other(stalker, "set_aggressive", 1);
call_other(stalker, "set_level", 14);
	move_object(stalker, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(700));
        move_object(money, stalker);
     }

