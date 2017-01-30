/*
 * Weapon data:
 *      Longbow, no save, class 18, 1/3 chance of +1
 *      same 1/3 chance of extra hit_player for players only
 *      extra costs wielder 10 hps and 10 sps, damage is 15 + random(10)
 */
#pragma strict_types
inherit "obj/weapon";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;

   set_name("longbow of might");
   set_alias("bow");
   set_short("Longbow of Force");
   set_long("\
A mighty bow that summons energy to fire force bolts.\n\
You might get winded by using this powerful weapon.\n");
   set_class(18);
   set_hit_func(this_object());
   set_type("bow");
   set_weight(2);
   set_value(5000);
}

/*
*/

mixed weapon_hit(object opponent) {
    if (random(12) < 4){
        write("You pierce the heart of the enemy with a mighty force bolt.\n");
        say(this_player()->query_name() +
            " shoots a speeding force bolt into the heart of the target.\n");

        if (interactive(this_player())
        &&  (int) opponent->query_hp() > 45
        &&  (int) this_player()->query_sp() > 9) {
            opponent->hit_player(15 + random(10));
            this_player()->heal_self(-10);
            say(this_player()->query_name() +
                " draws swiftly and fires another force bolt.\n");
            write("You draw swiftly and fire another force bolt.\n");
        }
        return 1;
    }
}
