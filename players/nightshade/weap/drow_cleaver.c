/* made sure the weapon doesnt save and changed the rnd from 35 to 50
   - mythos <5-10-96> */

inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("axe");
                set_class(19);
                set_value(10000);
                set_weight(6);
                set_alias("cleaver");
set_short("Drow Cleaver");
set_long(
"This axe was forged back in the days of the Great Elven war, in which\n"+
"the Drow elves decided to exact their revenge on their surface dwelling\n"+
"cousins who forced them into an existence underground. It is forged\n"+
"from black diamond taken from the heart of the active volcano Mt. Juregar.\n"+
"The blade is jet black with gold runes of a language long ago forgotten\n"+
"and now lost. The handle is a silver grip with the carving of a gold\n"+
"dragon in it. It is very old and very powerfull.\n");
set_hit_func(this_object());
}
}

weapon_hit(attacker)
{
if(call_other(this_player(), "query_attrib", "str") > random(50))
{
write("The axe glows bright green and shoots a stream of acid!\n");
return 5;
}
}
