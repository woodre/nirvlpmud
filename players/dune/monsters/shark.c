inherit "obj/monster";


reset(arg)
{
  int a;
  ::reset(arg);
  if(arg) return;
  a = random(2) + 1;
  set_name("shark");
  set_race("shark");
  set_alias("shark");

  if (a == 1)
  {
    set_short("A huge tiger shark");
    set_long("The tiger shark is striped and possesses nasty\n"+
         "jagged teeth.  It swims around you, waiting for\n"+
         "its chance to strike.\n");
    set_level(7);
    set_hp(random(20)+90);
    set_wc(10);
    set_ac(7);
  }
  if (a == 2)
  {
    set_short("A great white shark");
    set_long("A great white preys on you.  Its huge set\n"+
         "of horrible teeth and its massiveness put\n"+
         "you in grave danger.\n");
    set_level(8);
    set_hp(random(25)+100);
    set_wc(11);
    set_ac(8);
  }

  set_al(0);
  set_move_at_reset();
  set_aggressive(1);
}
