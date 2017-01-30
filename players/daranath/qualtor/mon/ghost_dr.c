inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Ghost of Draggonar");
     set_short("Ghostly form of Draggonar");
     set_alias("draggonar");
     set_alt_name("ghost");
     set_race("undead");
     set_gender("male");
     set_long("The ghost of a dark figure wearing a blackened suit of\n"+
              "platemail, Draggonar was one of the first and most highly\n"+
              "sought after kills in the fighting of Qual'tor. A viscious\n"+
              "man while he was alive, many good women and children were\n"+
              "tortured at his hands.\n");
     set_level(18);
     set_ac(15);
     set_wc(29);
     set_hp(450);
     set_al(-1000);
     set_aggressive(0);
set_chat_chance(4);
     set_a_chat_chance(10);
     load_chat("A chilling breeze fills the small chamber.\n");
     load_chat("The ghost seems to try to speak to you....\n");
     load_a_chat("The Ghost howls in acknowledgment of the taste of combat.\n");

     }
    }
