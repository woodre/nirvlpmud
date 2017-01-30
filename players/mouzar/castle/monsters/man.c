inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("man");
set_short("Half dead man");
set_long("This half dead man is warning everyone not to enter the cave.  He\n" +
         "went in and barely survived.\n");
set_al(-200);
set_level(6);
set_wc(3);
set_ac(5);
set_hp(100);
set_aggressive(0);
}
 
