
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("accordian")) {
    object ob;
    ob=clone_object("obj/treasure");
    ob->set_short("An accordian");
    ob->set_id("accordian");
    ob->set_weight(2);
    ob->set_value(875);
    ob->set_long(
    "This is a hideous compromise between a piano and a bagpipe.\n"+
    "Inspector Bumstead carried this heavy instrument to remind\n"+ 
    "him of the recent death of his aunt.\n");
    move_object(ob,this_object());
  }
  if(arg) return;
  set_name("inspector bumstead");
  set_alt_name("inspector");
  set_alias("bumstead");
  set_short("Inspector Bumstead");
  set_long(
"Inspector Bumstead is a solemn man in his forties, tall\n"+
"and handsome but not particularly friendly.  He is the\n"+
"second detective to be assigned to finding the serial\n"+
"killer who is stalking the streets of his city.\n"
);
  set_gender("male");
  set_race("human");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(225);
  set_al(500);
  set_chat_chance(5);
  load_chat("Inspector Bumstead says: Who is killing these women?");
  set_a_chat_chance(5);
  load_a_chat("Inspector Bumstead shoots you with his revolver.");
}
