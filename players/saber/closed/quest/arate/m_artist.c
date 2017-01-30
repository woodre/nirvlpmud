inherit "/obj/monster";
object ob, ob2, ob3, gold;

reset(arg) {
  ::reset(arg);
  
  gold = clone_object("obj/money");
    gold->set_money(2000 + random(500));
    move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/fallen_angel.c");
    move_object(ob,this_object());
  ob2 = clone_object("/players/saber/armor/arateam.c");
    move_object(ob2, this_object());
  ob3 = clone_object("/players/saber/armor/bracerpro.c");
    move_object(ob3, this_object());
    
if (!arg){

     init_command("wear amulet");
     init_command("wield martial art");
     init_command("wear bracers");

     set_name("martial artist");
     set_short("A dark martial artist");
     set_alt_name("artist");
     set_alias("monk");
     set_race("human");
     set_long(
        "A long haired, ebony eyed martial artist.  She moves with a fluid\n"+
        "grace, and wears an unholy amulet of Arate.  The martial artist is\n"+
        "a champion of fallen angel kung fu.\n");
     set_gender("female");  
     set_level(21);
     set_ac(17);
     set_wc(33);
     set_hp(550);
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     set_dead_ob(this_object());
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     load_a_chat(short()+" screams \"\Call out the guards!\"\n");
     set_chance(10);
     set_spell_dam(30);
     set_spell_mess1("\nThe dark martial artist prays to Arate.\n");
     set_spell_mess2("\nThe dark martial artist prays to Arate.\n+
                     "You feel your head explode with fire.\n");

        }
        }

monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The martial artist spins once and then falls to the to the ground,\n"+
  "blood dripping from her many wounds.\n\n");
  return 0;
        }
