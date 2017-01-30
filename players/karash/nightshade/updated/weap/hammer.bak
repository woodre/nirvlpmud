/* This weapon looked made for abuse with the entire damage located
 * in weapon_hit(). Has some uses in relation to guild restrictions.
 * interesting that a player was able to figure this out.
 * Changed damage from weapon_hit to wc. -Snow 12/99
*/
inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("hammer");
                set_class(1);
/*Changing wc*/
set_class(16);
                set_value(10000);
                set_weight(3);
                set_alias("aegis-fang");
                set_short("Aegis-fang");
set_long(
"A very large magical war hammer. Intricate carvings of dragons and\n"+
"dwarves line the handle while the head has the dwarven god Rerox \n"+
"on one side and a balanced scale on the other. The whole of the \n"+
"hammer is made of pure, shining mithril, the head having a gold \n"+
"band around the middle of it.\n");
set_hit_func(this_object());
}
}
/* Commenting out weapon_hit
weapon_hit(attacker)
  {
int yy;
yy=random(10);
yy+=8;
return yy;
}
*/
