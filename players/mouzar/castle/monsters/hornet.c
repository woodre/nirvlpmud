inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hornet");
set_short("An angry hornet");
set_long("This is a hornet and boy is he angry! He has been disturbed\n" +
         "and now you must pay!\n");
set_al(-20);
set_level(6);
set_wc(10);
set_ac(5);
set_hp(90);
set_aggressive(1);
}
 
