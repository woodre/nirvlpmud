inherit "obj/monster.c";

reset(arg)
{
object armor;
::reset(arg);
if(arg) return;
set_name("sauron");
set_wc(25);
set_ac(15);
set_level(18);
set_al(-10000);
set_hp(450);
set_short("An Evil Dark Mage Dressed in a Pure Black Robe");
set_long("An Evil Dark Mage Dressed in a Pure Black Robe.\n" +
	"He peers at you with dark black eyes.  You feel as if he is\n" +
	"looking straight through you and staring at your soul!!!\n");
set_aggressive(1);
}
