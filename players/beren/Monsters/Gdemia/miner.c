/* Changed from level 16 to level 10 (since guards are level 14 about), wc27,ac17,hp500 -Snow 3/00 */
inherit "/obj/monster";
object ob, ob1;

reset (arg) {
:: reset (arg);
if (!arg) {
	set_name ("gdemia");
/* This jewel is not existant. -Snow
	ob1 = clone_object ("players/beren/Objects/jewel");
	move_object (ob1, this_object ());
* Replacing jewel with 500 coins. */
      money = random(300)+350;
	set_alias ("miner");
        set_short ("Gdemia miner");
        set_race ("gdemia");
        set_long ("You see Gdemia Miner. He is busy working.\n");
        set_level (12);
        set_ac (random(5)+7);
        set_wc (random(11)+10);
        set_hp (random(60)+160);
        set_al (-150);
        set_aggressive (1);
        set_chat_chance (10);
        set_a_chat_chance (10);
        load_chat ("Miner says: Get out of a here! I am busy!\n");
        load_a_chat ("Miner cries: Our leaders will kill you for this!\n");
        call_out ("another", 5);
}
}

another () {
if(!environment(this_object())) return 1;
   if(query_attack() && random(25) < 2)
        {
          ob = clone_object ("players/beren/Monsters/Gdemia/miner.c");
	  move_object (ob, environment (this_object ()));
	say ("Oh! You can't believe your eyes! Another Miner entered the room to help his\nfriend! But you haven't heard somebody calling him! Maybe it's transfer\nof thoughts!?\n");
    ob->attack_object(this_object()->query_attack());
        }
	call_out ("another", 15);
return 1;
}
