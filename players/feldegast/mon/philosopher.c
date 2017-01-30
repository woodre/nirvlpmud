inherit "/obj/monster.c";

void reset(int arg)
{
  int variety;
  ::reset(arg);
  if(arg) return;
  set_name("philosopher");
  variety=random(2);
  set_long(
"This is a middle-aged man wearing a clean white robe and sandals.  His\n\
bearded expression appears puzzled and thoughtful as he meditates upon the\n\
nature of 'truth'.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(8);
  set_hp(120);
  set_wc(12);
  set_ac(7);
  set_al(random(500)-100);
  switch(variety)
  {
    case 0: set_alias("Rationalist");
            set_alt_name("rationalist");
            set_short("Rationalist");
           load_chat("Rationalist says: Anything that has shape has size.\n");
           load_chat("Rationalist says: The source of a priori knowledge is not in experience!\n");
           break;
    case 1: set_alias("Empiricist");
            set_alt_name("empiricist");
            set_short("Empiricist");
            load_chat("Empiricist says: A hypothesis holds until it is disproven...\n");
            load_chat("Empiricist hypothesises: Mathematical proofs are not known a priori...\n");
             break;
  }
  set_chat_chance(5);
  load_chat(alias+" mutters: If A, then B...If B then C...Ergo if A then C...\n");
  load_chat(alias+" paces thoughtfully.\n");
  load_chat(alias+" strokes his chin and mutters under his breath.\n");
  load_chat(alias+" says: As I cannot trust my senses, what can I trust?\n");
  set_a_chat_chance(5);
  load_a_chat(alias+" attempts to disprove your existence!\n");
  load_a_chat(alias+" yells: I shall not fear oblivion!\n");
  add_money(120);
}
void monster_died(object ob)
{
  write(alias+" whispers: I die...Therefore I'm not...\n");
  this_player()->set_crime(1);
}
