inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
ob2 = clone_object("/players/saber/gems/ruby.c");
move_object(ob2, this_object());
ob = clone_object("/players/saber/weapons/dance.c");
move_object(ob,this_object());
init_command("wield kung fu");
     set_name("artist");
     set_short("A Martial Artist dressed in blue");
     set_race( "human");
     set_gender("female");
     set_alt_name("blue");
     set_long("A small, thin lady with flowing raven black hair.\n"+
       "She moves with a grace that takes your breath away.\n");
     set_level(18);
     set_ac(16);
     set_wc(26);
     set_hp(450);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(0);
     load_chat("The martial artist dressed in blue practices her kata.\n");
     load_chat("The martial artist dressed in blue practices her high kicks.\n");
     load_chat("The martial artist dressed in blue practices her punches.\n");
   }

}
