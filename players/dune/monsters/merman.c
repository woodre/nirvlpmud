inherit "obj/monster";


int a, x, v;


reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  a = random(4) + 1;
  set_name("Merman");
  set_race("merman");
  set_alias("merman");

  if (a == 1)
  {
    set_short("A short green scaly merman");
    set_long("You see a half-man half-fish with lots of scales\n"+
         "covering its body. He has several green fins flipping about.\n");
    set_level(9);
    set_hp(random(10)+130);
    set_wc(13);
    set_ac(7);
  }
  if (a == 2)
  {
    set_short("A blue scaly merman");
    set_long("The merman stands 5' tall and wears nothing but\n"+
         "the big slimy tail below its waist.\n");
    set_level(10);
    set_hp(random(10)+145);
    set_wc(14);
    set_ac(8);
  }
  if (a == 3)
  {
    set_short("A red scaly merman");
    set_long("This merman has long red hair mixed with seashells\n"+
         "and seaweed. Large red scales cover his entire body.\n");
    set_level(11);
    set_hp(random(10)+160);
    set_wc(15);
    set_ac(9);
  }
  if (a == 4)
  {
    set_short("A tall black scaly merman");
    set_long("The huge black merman doesn't look happy.\n"+
         "He has seen the likes of land people like you\n"+
         "who abuse his kindred. He dearly wishes to drown\n"+
         "you in your own blood.\n");
    set_level(12);
    set_hp(random(10)+180);
    set_wc(16);
    set_ac(9);
  }

  set_al(0);

  gold=clone_object("obj/money");
  if (a == 1) gold->set_money(random(100)+350);
  if (a == 2) gold->set_money(random(100)+400);
  if (a == 3) gold->set_money(random(100)+450);
  if (a == 4) gold->set_money(random(100)+550);
  move_object(gold,this_object());

  x = random(2);
  for (v = 1; v <= x; v++)
  {
    if (!present("gem2"))
    {
      move_object(clone_object("/players/dune/objects/gem2.c"),
        this_object());
    }
  }
}
