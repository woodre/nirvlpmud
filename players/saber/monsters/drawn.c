inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob2 = clone_object("/players/saber/weapons/maxes.c");
move_object(ob2, this_object());
     set_name("drawn");
     set_short("Drawn the Dwarf");
     set_race( "dwarf");
     set_gender("male");
     set_long(
     "A stocky dwarf with a dark brown beard and arms thick with muscles.\n"+
     "He is wearing a suit of dwarven chain mail and a dwarven helmet.\n"+
     "Drawn is wielding two very sharp hand axes.\n");
     set_level(15);
     set_ac(12);
     set_wc(21);
     set_hp(300);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Drawn looks up at you with an evil smile.\n");
     load_a_chat("Drawn smashes your kneecap!\n");
     load_chat("Drawn looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Drawn punches you across the face!\n");
     load_a_chat("Drawn kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Drawn cleaves his foe with a swipe fron one of his axes.");
     set_spell_mess2("Drawn cleaves you with one of his magical axes.");
 set_chance(10);
 set_spell_dam(10);
   }

}
