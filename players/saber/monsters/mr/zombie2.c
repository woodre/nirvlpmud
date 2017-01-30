inherit "/obj/monster";


reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name( "zombie" );
     set_short("A freshly animated zombie");
     set_gender("creature");
     set_race("undead");
     set_long("A freshly animated zombie.  It looks somehow familiar.\n");
     set_level(10);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(-500);
     set_dead_ob(this_object());
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("\nThe Zombie tap dances.\n\n");
     load_chat("\nThe Zombie tap dances.\n\n");
     load_chat("\nThe Zombie laughs at you.\n");
     load_chat("\nThe Zombie moans \"This crowd - you guys kill me\"!\n");
     load_chat("\nThe Zombie moans \"You hear the one about the dog and his skeleton boss\"?\n"+
               "                 \"Talk about chewing out your boss\"!\n");
     load_chat("\nThe Zombie moans \"You hear the one about the skeleton diviner\"?\n"+
               "                 \"He had a real bone to pick\"!\n");
     load_chat("\nThe Zombie moans \"You hear the one about the jumping skeleton\"?\n"+
               "                 \"He always came out a head above the rest\"!\n");
     load_chat("\nThe Zombie moans \"What do skeletons yell at frat parties and during reviews\"?\n"+
               "                 \"Bone-us  Bone-us\"!\n");
     load_a_chat("\nThe Zombie tap dances.\n\n");
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
     "\nThe zombie falls to pieces.\n\n");
  return 0;
        }
