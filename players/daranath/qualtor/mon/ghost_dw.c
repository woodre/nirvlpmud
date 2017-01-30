inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Ghost of Dwarven Noble");
     set_short("Ghostly form of a Dwarven Noble");
     set_alias("dwarf");
     set_alt_name("ghost");
     set_race("undead");
     set_gender("male");
     set_long("The ghost of a dwarven noble sits here upon a ghostly chair, his\n"+
              "head drooping down and resting within his hands. The long\n"+
              "beard of the dwarf is not visible, his cleanly shorn face showing\n"+
              "a tremendous measure of shame and disrespect. The dwarf looks\n"+
              "at you with a sadness in his eyes, begging you for release.\n");
     set_level(10);
     set_ac(8);
     set_wc(20);
     set_hp(145);
     set_al(900);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("A chilling breeze fills the small chamber.\n");
     load_chat("The ghost seems to try to speak to you....\n");
     load_a_chat("The ghost of the dwarf seems pleased you are releasing him from his torment.\n");

     }
    }
