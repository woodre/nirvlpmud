inherit "/obj/monster";
object ob1;
reset (arg) {
:: reset (arg);
if (!arg) {
        set_name ("gdemia");
	set_alias ("guard");
        set_short ("Gdemia Guard");
        set_race ("gdemia");
        set_long ("You see Gdemia Guard. He looks taller than other"+
                  " gdemia.\n");
	set_level (14);
        set_ac (10);
        set_wc (18);
	set_hp (100);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
        load_chat ("Gdemia says: You aren't Gdemia! Be gone!\n");
       load_a_chat ("Gdemia cries: Our leaders will kill you for this!\n");
/* Some benefit.. -Snow 3/00 */
money = random(300)+100;
	call_out ("another", 5);
}
}

another () {
  if(!environment()) return;
	if ((this_player()->query_attack()) && (random (20) < 2))
        {
	  ob1 = clone_object ("players/beren/Monsters/Gdemia/guard2.c");
	  move_object (ob1, environment (this_object ()));
          say ("Another guard entered the room! Nobody called him!\n"+
	       "Gdemia surely transfer thoughts!\n");
        }
        call_out ("another", 5);
}
