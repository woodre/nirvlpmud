/* moved the heartbeat to reset and changed it to a calout 
  - mythos <5-17-96> */
inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Golden Katana of Lions");
set_alias("katana");
set_short("Golden Katana of Lions");
set_value(3000);
set_long("This is the fabled Katana of great line of the Lawwnum\n" +
         "family. This Great Family of Lion Men were a great \n" +
         "on their home planet, before the emperor came.\n");
set_weight(2);
set_class(17);
set_hit_func(this_object());
call_out("fake_beat",3);
}
weapon_hit(attacker) {
if(random(100) < 30) {
write(attacker->query_name()+" is engulfed in black fury\n");
say(attacker->query_name()+" is engulfed in black fury\n");
/* return changed from 8 to 5. should actually work better. -Snow */
return 5;
}
return 0;
}
fake_beat() {
if(random(100) < 5) {
say("Katana says: listen friend, we could do great things together.\n");
    say("Katana says: just remember, I am on your side!\n");
}
call_out("fake_beat",3);
return 1;
}
