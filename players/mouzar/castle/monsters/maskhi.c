inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("maskhi");
set_alias("shapeshifter");
set_short("Maskhi");
set_long("This female appears to be lean and wiry man-sized humanoid.  Her face.\n"+  
         "has elongated features, but still appear remarkably human.  She has\n"+
         "cerulean eyes, blond hair tied back in long flowing manes or braids\n"+
         "down her back.  Her skin it taned with short, light hair, lending her\n"+
         "skin a fuzzy, peach-like appearance.  She has six-fingered hands and\n"+
         "six-toed feet, her digits ending in talon-like claws.\n");
set_al(0);
set_level(18);
set_wc(26);
set_ac(19);
set_hp(450);
set_aggressive(1);
}
 
