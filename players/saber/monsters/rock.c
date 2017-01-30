inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
ob = clone_object("/players/saber/armor/bracers.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/gems/amber.c");
move_object(ob2, this_object());
     set_name("rock");
     set_short("Rock the gladiator");
     set_race( "human");
     set_gender("male");
     set_long("A tall man with skin that looks like bronze.  Rock has short\n"+
       "black hair and a stoic face.  Rock's muscles are hard as stone.\n");
     set_level(17);
     set_ac(12);
     set_wc(24);
     set_hp(500);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(25);
     load_chat("Rock flexes\n");
     load_chat("Rock crushes a small stone into dust.\n");
     load_chat("Rock looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Rock punches you across the face!\n");
     load_a_chat("Rock puts you in a head lock.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Rock puts you in a bear hug.\n");
     load_a_chat("Rock picks you up and slams you into the ground.\n");
     set_spell_mess1("Rock grabs his foe and squeezes them between his massive arm muscles.\n");
      set_spell_mess2("Rock grabs you and squeezes you in the bear hug from hell.\n"+
 "You choke and sputter blood.");
 set_chance(10);
 set_spell_dam(10);
   }

}
