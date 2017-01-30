inherit "obj/monster";


reset(arg)
{
  int a;
  ::reset(arg);
  if(arg) return;
  a = random(4) + 1;
  set_name("Wyrm");
  set_race("dragon");
  set_alias("wyrm");

  if (a == 1)
  {
    set_short("A pink fire wyrm");
    set_long("You see a soft-skinned lizard. It stands three\n"+
         "feet high. Under its thin coat of scales appears to\n"+
         "be a soft exposed belly.\n");
    set_level(11);
    set_chance(5);
    set_spell_dam(5);
  }
  if (a == 2)
  {
    set_short("A yellow fire wyrm");
    set_long("The yellow-striped wyrm is a large scaly lizard.\n"+
         "Its long tongue hangs out, as if searching\n"+
         "for some food to land on it.\n");
    set_level(11);
    set_chance(5);
    set_spell_dam(10);
  }
  if (a == 3)
  {
    set_short("An orange fire wyrm");
    set_long("This wyrm is orange-dotted. Where there\n"+
         "are no dots, there is white scaly skin.\n"+
         "Two black-as-coal eyes stare at you.\n");
    set_level(12);
    set_chance(10);
    set_spell_dam(15);
  }
  if (a == 4)
  {
    set_short("A red fire wyrm");
    set_long("The red wyrm is the largest of its species.\n"+
         "Fully developed scales grow upon its back and\n"+
         "belly. A good set of sharp teeth hang from its mouth.\n");
    set_level(12);
    set_chance(10);
    set_spell_dam(20);
  }

  set_hp(random(20)+165);
  set_al(0);
  set_wc(15);
  set_ac(9);
  set_move_at_reset();

  set_spell_mess1("The fire wyrm spits on you!");
  set_spell_mess2("The fire wyrm scratches you!");
}
