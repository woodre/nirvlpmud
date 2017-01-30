#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";
int n, check;
object ob, ob2;

reset(arg) {
ob = clone_object("/players/saber/weapons/rapier.c");
move_object(ob,this_object());
   ::reset(arg);
if (!arg){
     set_name("man");
     set_short("A man dressed in black");
     set_alias("chris");
     set_race( "human");
     set_gender("male");
     set_long(
       "This non descript man seems to radiate a slight aura of power.\n"+
       "He is dressed all in black.\n");
     set_level(19);
     set_ac(35);
     set_wc(20);
     set_hp(475);
     set_al(900);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The man looks at you.\n");
     load_chat("You hear the man whisper something to himself.\n");
     load_chat("You hear the man whisper the word \"\quest\"\n");
     load_chat("The man says \"\Tell me what you do...\"\n");
     load_a_chat("The man looks at you and shakes his head.\n");
     set_chance(25);
     set_spell_dam(35);
     set_spell_mess1("The man touches his foe with one finger");
     set_spell_mess2("The man touches you with one finger.\n"+
       "You feel your brain expolde with fire.");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
   }

}
notify(str)  {
  say(str);
}

init()  {
  ::init();
  add_action("quest_check","tell");
        }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("The man nods at "+who+".\n");
}  }


quest_check(str)  {
string who;
if(str == "man quest")  {
if(check < 1)  {
  check = check + 1;
  notify("The man says \"\You will need this.\"\n");
  write("The man hands you a pouch of sand.\n");
move_object(clone_object("/players/saber/closed/quest/items/sand.c"),this_player());
  return 1;
        }
  write("The man says \"\I no longer have the item you seek...\"\n");
  return 1;
        }  }
