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
     set_short("Winnie, Queen of the Damned");
     set_alias("ghost");
     set_race( "dream");
     set_alt_name("win");
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
     load_a_chat("Ozymandias yells 'Tag Dear...Tag!  TAG!!!'\n");
     load_a_chat("Ozymandias yells 'Hey, get the @#%&! off her, you f*ckin #$#*!'\n");
     load_a_chat("Ozymandias gives you some pointers on how to hit on Winnie.\n");
     load_a_chat("Ozymandias yells 'Hay, pick on someone your own size!\n");

   }
  }

monster_died()  {
object ob, OBJ, OBJ2;
  tell_room(environment(this_object()),
   "The ghost of Winnie falls to the ground, mortally wounded.\n"+
   "Ozymandias cries out, and rushes to his lovers side.\n"+
  "\nOzymandias glares at you, tears of blood streaming down his face.\n"+
  "\nOzymandias hisses \"\Damn you.\"\n"+
  "\n");
  tell_room(environment(this_object()),
  "\nOzymandias wails in anguish as Winnie dies in his arms.\n"+
  "\nWith a final sob, the ghost of Ozymandias collapses atop the corpse.\n"+
  "\nSlowly, the entwined lovers fade back into the realm of dreams.\n");

find = find_living("ozy");
destruct(find);
OBJ = clone_object("/players/saber/armor/ozring.c");
move_object(OBJ,this_object());
OBJ2 = clone_object("/players/saber/armor/winring.c");
move_object(OBJ2, this_object());
  return 0;
        }

