inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("artist");
set_alias("hack");
set_short("A Hack Artist");
    set_race("man");
    set_long(
"This is your standard hack artist.  He makes a living making cheap copies of\n"+
"other peoples work.  Right now he is busy changing the label on a soup can to\n"+
"read 'CAVIAR'.  That devil!  Boy what you wouldn't give to have some of\n"+
"those crayons.\n");
/*
move_object(clone_object("/players/unsane/closed/extra/crayons.c"),this_object());
*/
   set_level(20);
   set_ac(18);
   set_wc(31);
   set_hp(500);
   set_al(-300);
set_chance(20);
set_spell_dam(25);
set_spell_mess2("The artist sings Morrisey at you!\nRun Away!");
set_spell_mess1("The Artist assaults his foe with Smith's songs.");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Artist sings: I'm human and I need to be loved...\n");
load_chat("Artist says: Have anything you need scribbled on?\n");
load_chat("Artist sticks out his tongue and dilligently goes to work scribbling labels.\n");
load_chat("Artist begins humming 'Meat is Murder'.\n");
load_a_chat("Artist says: Right!  I'll do you for that.\n");
load_a_chat("Artist gets his panties in a bind.\n");
load_a_chat("Artist says: C'mon crayon, lets show this guy.\n");
}
}
