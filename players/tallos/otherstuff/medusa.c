inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

ob2 = clone_object("/players/saber/stuff/chaosegg.c");
ob = clone_object("/players/saber/weapons/longbow.c");
gold = clone_object("obj/money");
gold->set_money(random(500) + 2500);
move_object(gold, this_object());
move_object(ob,this_object());
move_object(ob2,this_object());
init_command("wield bow");

     set_name( "myshna" );
     set_short("A Medusa of NuNuth");
     set_race( "spirit");
     set_alt_name("medusa");
     set_gender("female");
     set_heal(5,25);
     set_long("Myshna is a Nu Nuth Medusa of stunning beauty.  Her skin is pale and\n"+
       "figure lithe and full of vitality.  It is her dark green eyes, though,\n"+
       "which attract your gaze, as they burn with a feverish vitality that\n"+
       "causes your body to feel a tinge of petrification.  Myshna's serpentine\n"+
       "hair hangs down across her shoulders, hissing softly at you.\n");
     set_level(21);
     set_ac(18);
     set_wc(30);
     set_hp(650);
     set_al(-950);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("Myshna glares at you with dark eyes of stone.\n");
     load_chat("Myshna whispers \"\Hissssss...\"\n");
     load_chat("Myshna whispers \"\Do you wish to taste my poisonssss?\"\n");
     load_chat("Myshna runs a finger along the edge of an arrow.\n");
     load_chat("Myshna's hair hisses at you.\n");
     load_chat("Myshna whispers \"\All sssshall be ssstone...\"\n");
     load_a_chat("Myshna whispers \"\Hisssssss...\"\n");
     load_a_chat("Myshna screams at you.\n");
     load_a_chat("Myshna smashes her tail across your chest.\n");
     load_a_chat("Myshna hisses softly.\n");
     load_a_chat("Myshna screams \"\ALL SHALL BE STONE!\"\n");
     load_a_chat("Myshna dips an arrow in her poisoness blood.\n");

     set_spell_mess2("Myshna shoots you with a poisoned arrow!\nYou feel poison seeping into you.");
     set_spell_mess1("Myshna shoots her foe with a poisoned arrow.\n");
     set_chance(12);
     set_spell_dam(30);
     call_out("freeze_player",10);
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "\nMyshna slumps to the ground, blood flowing from her wounds.\n\n"+
  "\nMyshna, Medusa of Nu Nuth gasps \"\Though my blood now covers the ground...\"\n"+
  "        \"\One day it shall burn within you...\"\n\n");
  tell_room(environment(this_object()),
  "\nMyshna hisses one last time, and then is still.\n\n");
  ob = clone_object("/players/saber/monsters/hero/statue.c");
  ob->set_id("myshna");
  ob->set_long("A statue of Myshna, Medusa of NuNuth");
  ob->set_short("A statue of Myshna");
  move_object(ob,environment(this_object()));
  return 0;
        }

freeze_player()  {
object target, HERE;
int a;

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Myshna")  {
  if(living(HERE))  {
  if(call_other(HERE, "query_attrib", "wil") < random(300))  {
  target = clone_object("/players/saber/closed/evil/stone.c");
  move_object(target,HERE);
  tell_room(environment(this_object()),
   "\nMyshna looks at "+HERE->query_name()+" with her deadly face.\n"+
    HERE->query_name()+" is covered with a thin layer of stone.\n\n");
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }
call_out("freeze_player",random(35));
  return 1;
        }
