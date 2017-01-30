inherit "obj/weapon.c";
int x;

reset(arg) {
  ::reset();
  set_name("staff of nature");
  set_alias("staff");
  set_class(1000);
  set_weight(4);
set_save_flag(1);
  set_value(15000);
  set_short("Staff of Nature");
  set_long("This long staff is enscripted with the runes and sigils of\n"+
         "Eldain. Composed of a strange red-tinged wood, the staff hums\n"+
         "softly in anticipation.\n");
  set_read("They seem to spell out the word 'inferno' in several different\n"+
           "tongues.\n");

}

init() {
::init();
add_action("inferno", "inferno");
add_action("read", "read");
}

read(str) {
if (str=="runes") {
write(
  "They seem to spell out the word 'inferno' in several different tongues\n");
return 1;
}
return 0;
}

inferno() {
if (!(wielded==1)) {
write("But you are not wielding the Staff of Nature!\n");
return 1;
}
write("Your staff explodes into flames as the fire elemental bound within\n"+
      "the staff is released to fight for you!\n");
x=0;
set_hit_func(this_object());
return 1;
}

destroy() {
write("With a final burst of flame, the staff melts in your hands, drips\n"+
      "down and forms a shapeless puddle at your feet.\n");
say(this_player()->query_name() + "'s staff explodes into bursting flames!\n");
destruct(this_object());
return 1;
}

weapon_hit(target) {
int i;
i = random(60);
x=x+1;
if (x> 20+random(7)) {
destroy();
return 1;
}
if (i<10) {
write("Your opponent is fried by the magical flames of Eldain\n");
return 40;
}
if (i<20) {
write("Your opponent is scorched by the magical flames of Eldain\n");
return 30;
}
if (i<30) {
write("Your opponent is burnt by the magical flames of Eldain\n");
return 20;
}
if (i<40) {
write("Your opponent is singed by the magical flames of Eldain\n");
return 15;
}
if (i<50) {
write("Your opponent cringes back from the fierce flames of Eldain\n");
return 10;
}
else {
write("You heat up your opponent's armor\n");
return 5;
}
}
