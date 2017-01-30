inherit "/obj/monster";

object find;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

gold = clone_object("obj/money");
gold->set_money(random(101) + 550);
move_object(gold,this_object());

     set_name("dream");
     set_short("Ozymandias, the King of Kings");
     set_alias("ghost");
     set_race( "dream");
     set_alt_name("ozy");
     set_long("Your eyes can not make out the distinct features of a dream.\n");
     set_level(12);
     set_ac(8 + random(3));
     set_wc(15 + random(3));
     set_hp(160 + random(40));
     set_al(-500);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(20);
     load_chat("The dream fades from view.\n");
     load_chat("The dream moves very slowly.\n");
     load_a_chat("Winnie yells 'Kick some ass, Darling!'\n");
     load_a_chat("Winnie yells 'Get off him, you BASTARD!!!\n");
     load_a_chat("Winnie yells 'Hey pal, get your own boyfriend!\n");

   }
  }

monster_died()  {
object ob, OBJ, OBJ2;
  tell_room(environment(this_object()),
   "The ghost of Ozymandias falls to the ground, mortally wounded.\n"+
   "Winnie cries out, and rushes to her dying husband.\n"+
  "\nWinnie wails in anguish as Ozymandias dies in her arms.\n"+
  "\n");
  tell_room(environment(this_object()),
  "\nWith a final sob, the ghost of Winnie collapses atop the corpse.\n"+
  "\nSlowly, the entwined lovers fade back into the realm of dreams.\n");

  find = find_living("win");
destruct(find);
OBJ = clone_object("/players/saber/armor/ozring.c");
move_object(OBJ, this_object());
OBJ2 = clone_object("/players/saber/armor/winring.c");
move_object(OBJ2,this_object());
  return 0;
        }

