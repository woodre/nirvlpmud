#define tp this_player()->query_name()
#define tg this_player()->query_gender()
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("vampire cat");
  set_alias("vampire cat");
  set_race("spirit");
  set_short("Vampire Cat");
  set_long("This Cat seems different from the rest.  It is rather large and\n"+
    "has two tails.  Its coat is a dusty grey color and its eyes are\n"+
    "a blood red.  It seems to eminate a strange aura.\n");
  set_hp(120);
  set_level(8);
  set_al(0);
  set_wc(15);
  set_ac(8);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The Vampiric Cat paces the room.\n");
  load_chat("IThe Grey Cat grins at you- a horrific sight.\n");
  load_a_chat("The Vampire Cat twitches its double tails and growls.\n");
  set_chance(10);
  set_spell_dam(15);
  set_spell_mess1("The grey coated cat pounces at "+tp+" and seems to pass through "+tg+".\n"+
    "You hear a high pitched whining noise and you see blood gush from "+tp+".\n");
  set_spell_mess2("The Vampire Cat pounces at you.  You put up your hands to block it but encounter no resistance.\n"+
    "\n\nYou feel a great sharp PAIN.  You look down and blood is gushing from a gaping hole in your chest.\n\n");
  gold=clone_object("obj/money");
  gold->set_money(random(30)+320);
  move_object(gold,this_object());
}
