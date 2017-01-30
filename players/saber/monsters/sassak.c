inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
  ob2 = clone_object("/players/saber/weapons/blueblade.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/ringpro.c");
move_object(ob3,this_object());
ob = clone_object("/players/saber/armor/teddy.c");
move_object(ob,this_object());
  /* 03/13/06 Earwax: made her wear/wield */
  init_command("wear ring");
  init_command("wear teddy");
  init_command("wield weapon");

     set_name("sassak");
   set_short("Sassak the Rogue");
     set_race( "human");
   set_long("As Sassak has been enjoying a massage, she is not wearing particularly\n"+
 "much.  In fact, Sassaks black lace teddy does nothing but accent her\n"+
 "generous curves and deep crimson curls.  Be warned, however, that this\n"+
 "beguiling bandit leader has earned her position because of a strong\n"+
 "sword arm and lightning fast reflexes...\n");
     set_level(12);
     set_ac(10);
     set_wc(15);
     set_hp(180);
     set_al(-400);
     set_aggressive(0);
   set_a_chat_chance(25);
     load_a_chat("Sassak says: Interrupt my massage will you!\n");
    load_a_chat("Sassak slaps you across the face.\n");
    load_a_chat("Sassak ducks under your attack.\n");
    load_a_chat("Sassak kicks you where it hurts!\n");
    load_a_chat("Sassak punches you across the face!\n");
   set_spell_mess1("Sassak spins quickly and hits her foe with a thrust kick to the neck.\n"+
  "You see blood fly across the room.");
 set_spell_mess2("Sassak spins quickly and hits you with a thrust kick to the neck.\n"+
 "You choke and sputter blood.");
 set_chance(20);
 set_spell_dam(8);
   }

}
