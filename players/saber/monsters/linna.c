inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, gold;

ob = clone_object("/players/saber/armor/hardsuit1.c");
ob->set_short("A light green Hardsuit");
move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(random(1000) + 3500);
move_object(gold,this_object());

     set_name("linna");
     set_short("Linna Yamazaki <Knight Saber>");
     set_race( "human");
     set_alt_name("knight saber");
     set_alias("knight");
     set_gender("female");
     set_long("A slender, athletic looking woman with short black\n"+
       "hair and a warm face.  Linna's Hardsuit is light green\n"+
       "with red leg stripes, and has two long lazer ribbons\n"+
       "trailing from the helmet.\n");
     set_level(20);
     set_ac(19);
     set_wc(27);
     set_hp(500);
     set_al(-950);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Linna cries.\n");
     load_chat("Linna whispers 'They killed her...'\n");
     load_chat("Linna sobs quietly.\n");
     load_a_chat("Linna says 'I will avenge you Sylvie!'\n");
     load_a_chat("Linna dodges nimbly away from you.\nDamn she's fast!\n");
     load_a_chat("Linna ducks under your attack.\n");
     load_a_chat("Linna speaks into her helmet radio.\n");
     set_spell_mess1("Linna punches her foe with her knucklebomber fists.\n"+
       "   * * * B O O M * * *");
     set_spell_mess2("Linna punches you with her knucklebomber fists.\n"+
       "   * * * B O O M * * *");
     set_spell_mess2("Linna swings a blade of dazzling white lazerlight.\n"+
          "You feel a numbing sensation as the blade hits you.");
 set_chance(15);
 set_spell_dam(14);
   }

}
