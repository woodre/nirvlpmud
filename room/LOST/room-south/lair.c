object wyrm;

reset(started)
{
     if (!started)
	 set_light(0);
     extra_reset();
}

init()
{
    add_action("up"); add_verb("up");
}

short()
{
    return "The bottom of the well";
}

long()
{
    write("You are standing at the bottom of the well, about thirty feet below the\n" +
	  "surface. Bones lie strwen about in a random fashion, many of them broken\n" +
	  "or shattered.\n" +
	  "\tThe only way out is the way in, back up the ladder.\n");
}

up()
{
    call_other(this_player(), "move_player", "up the ladder#room/south/sislnd17");
    return 1;
}

extra_reset()
{
     if (!wyrm || !living(wyrm))
	 {
      object monger,coins, jem;
	     int jemnum;
	     wyrm = clone_object("obj/monster");
	     call_other(wyrm, "set_name", "wyrm");
	     call_other(wyrm, "set_level", 17 );
	     call_other(wyrm, "set_hp", 350);
	     call_other(wyrm, "set_al", -900);
	     call_other(wyrm, "set_short", "The Wyrm of Arcanarton");
	     call_other(wyrm, "set_long",
"The giant undead dragon you see before you is the result of one of\n"+
"Arcanarton's magic experiments.\n");
	     call_other(wyrm, "set_wc", 25);
	     call_other(wyrm, "set_ac", 7);
	     call_other(wyrm, "set_spell_chance", 50);
	     call_other(wyrm, "set_spell_dam", 100);
	     call_other(wyrm, "set_spell_mesg",
"Arcanarton's wyrm turns his head and breathes death at you.\n");
             coins = clone_object("obj/money");
	     call_other(coins, "set_amount", random(500));
	     move_object(coins, wyrm);
/*
     monger = clone_object("players/deathmonger/ASSASSIN/questob3.c");
     move_object(monger, wyrm);
*/
	     jem = clone_object("obj/treasure");
             jemnum = random(3);
	     if (jemnum == 0)
		 {
		     call_other(jem, "set_id", "diamond");
		     call_other(jem, "set_short", "a diamond");
		 }
	     if (jemnum == 1)
		 {
		     call_other(jem, "set_id", "emerald");
		     call_other(jem, "set_short", "an emerald");
		 }
	     if (jemnum == 3)
		 {
		     call_other(jem, "set_id", "sapphire");
		     call_other(jem, "set_short", "a sapphire");
		 }
 	     call_other(jem, "set_alias", "jem");
	     call_other(jem, "set_value", random(250) + 300);
	     move_object(jem, wyrm);
	     move_object(wyrm, this_object());
	 }
}
