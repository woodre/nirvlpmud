inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, gold;

ob = clone_object("/players/saber/stuff/trink.c");
move_object(ob,this_object());

     set_name("cynthia");
     set_short("A small girl named Cynthia");
     set_race( "human");
     set_alias("girl");
     set_gender("female");
     set_long("A little girl with golden yellow hair and an aura of\n"+
       "innocence.  She is wearing a dirty blue and white dress.\n"+
       "Cynthia appears to be lost.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(75);
     set_al(500);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("Cynthia says 'I don't have any parents'.\n");
     load_chat("Cynthia says 'Where am I?'\n");
     load_chat("Cynthia says 'BA - KA?'\n");
     load_chat("Cynthia sniffles.\n");
     load_a_chat("Cynthia yells 'Priss, help!'\n");
     load_a_chat("Cynthia wimpers.\n");
     load_a_chat("Cynthia cowers 'Don't hurt me...'\n");
     set_spell_mess1("A huge white flash of light surrounds you!\n"+
       "The whole world seems to explode!!!");
     set_spell_mess2("A huge flash of white light surrounds you!\n"+
       "You feel your body melting around you!!!");
     set_chance(10);
       set_spell_dam(65);
   }

}
