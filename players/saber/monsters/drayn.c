inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob3 = clone_object("/players/saber/armor/dhelmet.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/dchain.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/mstar.c");
move_object(ob2, this_object());
     set_name("drayn");
     set_short("Drayn the Dwarf");
     set_race( "dwarf");
     set_gender("male");
     set_long(
     "A stocky dwarf with a black beard and muscular arms.\n"+
     "He is wearing a suit of dwarven chain mail and a dwarven helmet.\n"+
     "Drayn is wielding a wicked looking morning star.\n");
     set_level(16);
     set_ac(13);
     set_wc(22);
     set_hp(400);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Drayn looks up at you with an evil smile.\n");
     load_a_chat("Drayn smashes your kneecap!\n");
     load_chat("Drayn looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Drayn punches you across the face!\n");
     load_a_chat("Drayn kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Drayn smites his foe with a huge morning star.");
     set_spell_mess2("Drayn smashes you with a huge morning star.");
 set_chance(10);
 set_spell_dam(10);
   }

}
