inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("fisher");
set_short("Cave Fisher");
set_long("This is a large insectoid.  It has the characteristics of a spider\n" +
        "and a crawfish.\n");
set_al(0);
set_level(6);
set_wc(8);
set_ac(6);
set_hp(50);
set_aggressive(0);
}
 
