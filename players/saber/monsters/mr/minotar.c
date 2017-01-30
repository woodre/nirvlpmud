/*
 * A large minotar
 *
 */

inherit "/obj/monster";

object ob, gold;

reset(arg) {
  ::reset(arg);   

if (!arg){

  gold = clone_object("obj/money");
    gold->set_money(4500 + random(200));
    move_object(gold,this_object());

    ob = clone_object("/players/saber/weapons/tree.c");
    move_object(ob,this_object());
     
     init_command("wield tree");     

     set_name("giant minotar");
     set_short("A Giant Minotar");
     set_race("minotar");
     set_alias("giant");
     set_long(
      "A HUGE Minotar, tall as the hills and with arms as long and trees.\n"+
      "It's hide is a dull brown, and it's dark ivory horns gleam in the\n"+
      "sunlight.  The Minotar has the very distinct oder of rotting flesh.\n");
     set_gender("creature");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(550);
     set_al(-900);
     set_aggressive(1);
     set_chat_chance(6);
     set_a_chat_chance(5);
     set_dead_ob(this_object());
     load_chat("The Giant Minotar looks to the sky.\n");
     load_chat("The Giant Minotar looks around.\n");
     load_a_chat("The Giant Minotar slams it's fist into you!\n");
     load_a_chat("The Giant Minotar kicks you with a HUGE hoof.\n");
     set_spell_mess1("The Giant Minotar SLAMS it's opponent with a small tree!");
     set_spell_mess2("The Giant Minotar SLAMS you with a small tree!");
     set_chance(10);
     set_spell_dam(30);
      
set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
        }
        }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("The Giant Minotar looks at "+who+" and yells \"LUNCH\".\n");
  }  }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The Giant Minotar staggers for a moment, and then falls to the ground.\n\n");
  return 0;
        }
