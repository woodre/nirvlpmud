inherit "obj/monster";


reset(arg)
{
  int a;
  object gold;
  ::reset(arg);
  if(arg) return;
  a = random(4) + 1;
  set_name("Drake");
  set_race("dragon");
  set_alias("drake");

  if (a == 1)
  {
    set_short("A red-spotted fire drake");
    set_long("The red-spotted drake is a rather large\n"+
         "mean-looking mini-dragon. It stands 9' tall\n"+
         "and is covered with young dragon scales.\n");
    set_level(13);
    set_chance(15);
    set_spell_dam(25);
  }
  if (a == 2)
  {
    set_short("A red-mottled fire drake");
    set_long("This drake has begun to loose its spots, but\n"+
         "displays bigger colorations of red upon its body.\n"+
         "It has many sharp teeth for chomping on prey.\n");
    set_level(13);
    set_chance(15);
    set_spell_dam(30);
  }
  if (a == 3)
  {
    set_short("An orange-reddish fire drake");
    set_long("The orange-reddish drake stands 11' tall.\n"+
         "Large claws grow upon its feet, and the scales\n"+
         "upon its back form into spikes.\n");
    set_level(15);
    set_chance(20);
    set_spell_dam(35);
  }
  if (a == 4)
  {
    set_short("A black and red fire drake");
    set_long("This drake is mightiest of its kind.\n"+
         "It resembles a miniature dragon, but possesses\n"+
         "a mean breath and sharp claws.\n");
    set_level(15);
    set_chance(20);
    set_spell_dam(40);
  }

  set_hp(random(100)+300);
  set_al(0);
  set_ac(20);
  set_ac(13);
  set_move_at_reset();
  set_spell_mess1("The fire drake snorts fire on you!");
  set_spell_mess2("The fire drake mauls you!");

  gold=clone_object("obj/money");
  if (a <= 2) gold->set_money(random(800)+100);
  if (a > 2)  gold->set_money(random(900)+200);
  move_object(gold,this_object());
}
