inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("vine");
     set_short("A thorned vine crawls about the shrine");
     set_alias("thorn");
     set_alt_name("thorned vine");
     set_race("plant");
     set_gender("creature");
     set_long("Crawling about the ruins of the shrine just to the north\n"+
              "of the UnderDark, the vines are more of a menace then\n"+
              "anything else. Dark green in color, the vines have sharp\n"+
              "thorns running down their length. The vines are angry\n"+
              "in nature and violent to creatures.\n"); 
     set_level(18);
     set_ac(15);
     set_wc(26);
     set_hp(500);
     set_al(-1000);
     set_aggressive(1);

     set_chat_chance(20);
     set_a_chat_chance(15);
     load_chat("The vine moves about the area.\n");
     load_chat("The vines grow about the area, covering everything.\n");
     load_a_chat("The vine slams into you with its thorns.\n");
     load_a_chat("The vine tries to wrap itself about you.\n");

     set_chance(10);
     set_spell_dam(40);
     set_spell_mess2("The vine wraps itself about your neck.\n");
     set_spell_mess1("The vine wraps itself about it foe.\n");
     }
    }
