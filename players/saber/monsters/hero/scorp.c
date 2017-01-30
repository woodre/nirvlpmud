inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

ob2 = clone_object("/players/saber/food/bigwine.c");
ob = clone_object("/players/saber/armor/dragonhelm.c");
gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold, this_object());
move_object(ob,this_object());
move_object(ob2,this_object());
init_command("wear helm");

     set_name( "vishra" );
     set_short("Vishra the Manscorpion");
     set_alias("manscorpion");
     set_race( "spirit");
     set_alt_name("scorpion");
     set_gender("creature");
     set_heal(5,25);
     set_long("Vishra is of the feared race of Manscorpions, the ancient terrors of the Methi\n"+
        "and enemy to all dragon kin.  It stands six footlengths at the shoulder, with\n"+
        "a muscular humaniod head and chest and the lower body of a giant scorpion.\n"+
        "Vishra has a long stinger tipped tail which twitches slowly back and forth as\n"+
        "it watches you with dark, hungy eyes...\n");
     set_level(21);
     set_ac(17);
     set_wc(37);
     set_hp(755);
     set_al(-950);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("Vishra glares at you with dark eyes.\n");
     load_chat("Vishra says \"\You will be mine, oh yes, you will be mine...\"\n");
     load_chat("Vishra says \"\Attack me and die...\"\n");
     load_chat("Vishra takes a drink of wine.\n");
     load_chat("Vishra's tail twitches slightly...\n");
     load_a_chat("Vishra snears at you.\n");
     load_a_chat("Vishra rakes you with his claw like fingers.\n");
     load_a_chat("Vishra strikes at you with its tail, but misses.\n");
     load_a_chat("Vishra screams \"\I will feast upon your flesh!\"\n");
     load_a_chat("Vishra hisses softly.\n");

     add_spell("poison stinger",
"\n#MN# thrusts #MP# $HG$poison$N$ stinger deep into your chest!\n\n",
"\n#MN# thrusts #MP# $HG$poison$N$ stinger deep into #TN#'s chest!\n\n",
10,({"1d20+15","1d20+15"}),({"physical","other|poison"}),6,
"poison_check");
     /* for the poison object */
     set_wc_bonus(5);
     
     /* changed to add_spell format
        the spell handles doing damage and adding the poison object
        to the target in question if it fails its luck check
     set_spell_mess2("Vishra thrusts its stinger deep into your chest!\nYou feel poison seeping into you.");
     set_spell_mess1("Vishra thrusts its stinger deep into the chest of its foe.");
     set_chance(10);
     set_spell_dam(30 + random(40));
     call_out("poison_player",10);
     */
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "\nVishra falls to the ground, blood dripping from his dark lips.\n\n"+
  "Vishra gasps \"\You haven't seen the last of me.  I shall have my revenge...\"\n\n");
  tell_room(environment(this_object()),
  "\nVishra's tail twitches one last time, and then is still.\n\n");
  ob = clone_object("/players/saber/monsters/hero/statue.c");
  ob->set_id("vishra");
  ob->set_short("A statue of Vishra");
  ob->set_long("A statue of Vishra the Manscorpion.\n");
  move_object(ob,environment(this_object()));
  return 0;
        }
poison_check(object target, object room, int damage) {
  if(target && target->is_player() && target->query_name()!="some mist"
     && random(target->query_attrib("luc")) < random(12)) {
    object poison;
    poison=clone_object("/players/saber/closed/poison.c");
    move_object(poison,target);
    call_other(poison,"poison");
    tell_object(target,"The poison has taken hold!\n\n"+
                       "You begin to feel sick.\n");
    tell_room(room,target->query_name()+" begins to look sick.\n\n",
              ({target,this_object()}));
  } 
}
        
/* Removed old poison code - Illarion Dec 2004 */
