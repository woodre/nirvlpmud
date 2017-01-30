/*
 * Kept in a separate file so the weapon won't lose its special if saved
 */
#pragma strict_types
inherit "obj/weapon";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;
   set_name("A Huge Double Bladed Axe");
   set_alt_name("axe");
   set_short("A Huge Double Bladed Axe");
   set_long("\
This huge battle axe is approximately 5 feet long, and is extremely\n\
heavy.  It has two tremendously large half moon blades that are\n\
brightly polished, and the light gleams off the razor sharp edges.\n\
As you swing the axe, an eerie whistling sound shivers you to your\n\
soul.....\n");
   set_class(18);
   set_hit_func(this_object());
   set_weight(9);
   set_value(1500);
}

mixed weapon_hit(object opponent) {
    if (random(200) < 20) {
        write("You crush your opponent with the might of the Death Axe.\n");
        say("The Axe gleams as it tastes the blood of its foe.\n");
        return 4;
    }
}
