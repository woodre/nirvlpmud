inherit "obj/weapon";
int die, attacker, pain;
status do_it;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("axe");
                set_class(19);
                set_value(10000);
                set_weight(3);
                set_alias("axe");
set_alias("cleaver");
set_short("Drow Cleaver");
set_long(
"This axe was forged back in the days of the Great Elven war, in which\n"+
"the Drow elves decided to exact their revenge on their surface dwelling\n"+
"cousins who forced them into an existence underground. It is forged\n"+
"from black diamond taken from the heart of the active volcano Mt. Juregar.\n"+
"The blade is jet black with gold runes of a language long ago forgootten\n"+
"and now lost. The handle is a silver grip with the carving of a gold\n"+
"dragon in it. It is very old and very powerfull.\n");
set_save_flag(1);
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if (!do_it) {
call_out("do_magic",20);
do_it = 1;
}
if(random(100) < 30) return 2;
}
do_magic()
{
object duh;
do_it = 0;
if (!wielded_by || !wielded_by->query_attack()) return;
duh = wielded_by->query_attack();
say(wielded_by->query_name()+"'axe fucks up "+duh->query_name()+"!\n");
tell_object(wielded_by, "The axe glows a bright blue with the power of a thousand generations and a lighning bolt shoots towards "+duh->query_name()+"!\n");
tell_object(duh,"You see the axe glow with power as a lightning bolt shoots from it towards you.\n");
duh->hit_player(15);
return;
}
