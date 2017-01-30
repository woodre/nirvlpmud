inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("golem");
set_short("Stone golem");
set_long("This stone golem is here to stop players over 5th level from\n" +
          "entering the newbie haven.  He will kill any who attack him.\n");
set_al(-400);
set_level(20);
set_ac(13);
set_wc(25);
set_hp(2000);
set_aggressive(0);
}
 
