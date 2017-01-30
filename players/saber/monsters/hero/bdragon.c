inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    
    object ob, ob2, gold;
    
    ob = clone_object("/players/saber/weapons/blue.c");
    move_object(ob,this_object());
    gold = clone_object("obj/money");
    gold->set_money(1000);
    move_object(gold,this_object());
    init_command("wield dragon");
    
    set_name( "blue dragon" );
    set_short("A martial artist named Blue Dragon");
    set_alias("blue");
    set_race("immortal");
    set_alt_name("dragon");
    set_gender("male");
    set_heal(5,25);
    set_long("  Blue Dragon is a tall man with long blond hair tied back in a pony tail,\n"+
            "deep blue eyes and fair skin.  Dark blue tattoos of oriental dragons wrap\n"+
            "around each of his arms, intertwining around his body and across his chest.\n"+
            "Blue wears loose black pants and a black T-shirt with cut off sleeves.  He\n"+
            "is rumored to be one of the most powerful martial artists ever.\n");
    set_level(21);
    set_ac(21);
    set_wc(39);
    set_hp(750);
    set_al(-950);
    set_aggressive(0);
    set_dead_ob(this_object());
    set_chat_chance(7);
    set_a_chat_chance(10);
    load_chat("Blue Dragon watches you.\n");
    load_chat("Blue Dragon brushes a lock of hair away from his eyes.\n");
    load_chat("Blue Dragon says: I'm the best martial artist in this realm.\n");
    load_chat("Blue Dragon begins a kata.\n");
    load_a_chat("Blue Dragon wipes the sweat from his brow.\n");
    load_a_chat("Blue Dragon dodges the attack.\n");
    load_a_chat("Blue Dragon grins as he dodges the attack.\n");
    add_spell("dim mak",
"\n#MN# strikes you using the deadly Dim Mak technique.\n"+
"The Death Touch drains some of your life away!\n\n",
"\n#MN# strikes #TN# using the deadly Dim Mak technique!\n\n",
10,"1d50+80","physical");
    set_wc_bonus(4); /* the monster's weapon does an average of 4 extra dam per round */
/* switched to add_spell format    -  Illarion Dec 2004
    set_spell_mess1("\nBlue Dragon uses a Dim Mark on his foe.\n");
    set_spell_mess2("\nBlue Dragon touches you with a Dim Mark.\n\n");
    set_chance(10);
    set_spell_dam(80 + random(50));
*/
  }
}

monster_died()  {
  object ob;
  tell_room(environment(this_object()),
  "\nBlue Dragon staggers, and falls to the ground.\n\n"+
  "His ghost slowly fades away.\n\n");
  tell_room(environment(this_object()),
  "\nBlue Dragon whispers to you \"\You were a worthy foe.  We shall meet again...\"\n\n");
  ob = clone_object("/players/saber/monsters/hero/statue.c");
  ob->set_id("dragon");
  ob->set_short("A statue of Blue Dragon");
  ob->set_long("A statue of the great martial artist Blue Dragon.\n");
  move_object(ob,environment(this_object()));
  return 0;
}
