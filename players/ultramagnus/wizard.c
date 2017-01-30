inherit "obj/monster.c";

reset(arg)
{
    set_heart_beat(1);
set_name("wizard");
set_wc(20);
set_ac(14);
set_level(18);
set_al(800);
set_hp(450);
set_short("An old Wizard...Drinking from the river");
set_long("An Old Man...Dressed in Grey and Blue.\n" +
       "Looking closer you see that he seems to be quite\n" +
       "healthy for his age. There is a long staff at his waist.\n");
::reset(0);
}
