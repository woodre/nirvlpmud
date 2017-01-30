inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
      
if (!arg){

     set_name("constrictor snake");
     set_short("A huge constrictor snake");
     set_alias("constrictor");
     set_race("snake");
     set_long(
        "A huge constrictor snake.  It moves with a lithe grace.\n");
     set_gender("creature");
     set_level(18);
     set_ac(15 + random(3));
     set_wc(25 + random(3));
     set_hp(400 + random (50));
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n");
     load_chat("The snake hisses at you.\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     load_a_chat("The snake hisses at you.\n"); 
     set_chance(10);
     set_spell_dam(30);
     set_spell_mess1("The giant constrictor snake coils around its foe.\n");
     set_spell_mess2("The giant constrictor snake coils around you!\n");
        }
        }
