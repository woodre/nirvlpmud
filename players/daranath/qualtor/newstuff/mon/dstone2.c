#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;

move_object(clone_object(ROOT+"weps/dstone_krog.c"),this_object());

set_name("Darkstone Giant");
set_alias("darkstone");
set_alt_name("Giant");
set_race("giant");
set_short("Darkstone Giant");
set_long("The Darkstone giants have come down from the mountains north of the\n"+
         "of Qual'tor, hoping to quell any talk of the city rebuilding.\n"+
         "They have a strong hatred for human life, and are here to scout\n"+
         "the area for thier king...\n");
set_level(19);

init_command("wield krog");

set_hp(400+random(200));
set_al(-(250+random(250)));
set_wc(26+random(8));
set_ac(16);
set_aggressive(0);

set_chance(15);
set_spell_dam(30);
set_spell_mess1("Darkstone giant pummels its foe!\n");
set_spell_mess2("Darkstone giant slams the Krog into the ground, shaking the area.\n");

}
