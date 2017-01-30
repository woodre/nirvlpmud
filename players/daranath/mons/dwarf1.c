inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/arms/dwarf_chain.c"),this_object());
move_object(clone_object("/players/daranath/arms/dwarf_helm.c"),this_object());
move_object(clone_object("/players/daranath/weps/dwarf_hammer.c"),this_object());

     set_name("Dwarven Warrior");
     set_short("Armored Dwarven Warrior");
     set_alias("dwarf");
     set_alt_name("warrior");
     set_race("dwarf");
     set_gender("male");
     set_long("Hanging down to his knees, a black bristly beard dominates\n"+
              "the figure of the dwarven warrior before you. Behind that\n"+
              "beard the dwarf is armed and armored for war. Heavy silver\n"+
              "chainmail is draped across the shoulders of the dwarf, and a\n"+
              "heavy warhammer is carried with ease.\n");
     set_level(14);

     init_command("wear helmet");
     init_command("wear chainmail");
     init_command("wield hammer");

     set_ac(12);
     set_wc(18 + random(4));
     set_hp(260 + random(30));
     set_al(1000);
     set_aggressive(0);
     set_a_chat_chance(10);
     load_a_chat("Dwarven warrior smashes you with his heavy warhammer.\n");
     load_a_chat("The dwarf lowers his head and charges you.\n");

   }
}
