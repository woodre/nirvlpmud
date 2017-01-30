inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob4 = clone_object("/players/saber/gems/amber.c");
move_object(ob4, this_object());
ob2 = clone_object("/players/saber/weapons/battleaxe.c");
move_object(ob2, this_object());
ob = clone_object("/players/saber/armor/dshield.c");
move_object(ob, this_player());
ob3 = clone_object("/players/saber/armor/dhelmet.c");
move_object(ob3, this_object());
     set_name("donrock");
     set_short("Donrock the Dwarf");
     set_race( "dwarf");
     set_gender("male");
     set_long(
     "A stocky dwarf with a dark red beard and muscular arms.\n"+
     "He has flaming red hair, and glares out at you with dark eyes.\n"+
     "Donrock is wielding a battle axe and and carrying a shield.\n");
     set_level(16);
     set_ac(13);
     set_wc(22);
     set_hp(400);
     set_al(-600);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Donrock looks up at you with an evil smile.\n");
     load_a_chat("Donrock smashes your kneecap!\n");
     load_chat("Donrock looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Donrock punches you across the face!\n");
     load_a_chat("Donrock kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Donrock smites his opponent upon the kneecap.");
     set_spell_mess2("Donrock smites your kneecap soundly!");
 set_chance(10);
 set_spell_dam(10);
   }

}
