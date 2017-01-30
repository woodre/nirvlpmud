inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
  ob2 = clone_object("/players/saber/gems/sapphire.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/crusifix.c");
move_object(ob3,this_object());
ob = clone_object("/players/saber/armor/blackcloak2.c");
move_object(ob,this_object());
     set_name("selena");
     set_short("A beautiful dark skinned woman");
     set_alt_name("woman");
     set_gender("female");
     set_race( "undead");
     set_long("Selena is a strikingly beautiful dark skinned woman standing just over five\n"+
       "and one half foot-lengths tall.   She wears a dark black cloak of exquisite\n"+
       "workmanship draped loosely over an otherwise bare body.   Selena moves with\n"+
       "an exaggerated feline grace, exposing brief glimpses of generous curves and\n"+
       "soft flesh as her cloak slides across her sleek skin.  Long strands of soft\n"+
       "silky black hair fall across her smooth face and full red lips.  From under\n"+
       "these strands of silk Selena's eyes blaze forth a captivating shade of deep\n"+
       "emerald green.\n");
     set_level(20);
     set_ac(18);
     set_wc(29);
     set_hp(500);
     set_al(-700);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(15);
      set_a_chat_chance(15);
     load_chat("Selena looks you over carefully.\n");
     load_chat("Selena runs her hands down your body.\n");
     load_chat("Selena whispers: You're all mine...\n");
      load_chat("Selena licks her lips, running her tongue over sharp white fangs.\n");
     load_a_chat("Selena glares at you with eyes of red fury.\n");
     load_a_chat("Selena hisses: How could you attack me?\n");
     load_a_chat("Selena licks her lips, running her tongue over sharp white fangs.\n");
     load_a_chat("Selena slides her hands down your body.\n");

     set_spell_mess2("Selena sinks her sharp white fangs into your neck and drains a pint of blood!\n"+
          "Selena licks her lips.\n"+
          "You feel faint.");
     set_spell_mess1("Selena sinks her sharp white fangs into her prey's neck and drains some blood!\n"+
          "Selena licks her lips.");
 set_chance(12);
 set_spell_dam(15);
   }

}
