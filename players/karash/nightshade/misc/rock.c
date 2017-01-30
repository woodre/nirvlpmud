inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("A rock");
set_long
("This is a chunk of black diamond. It has a small dagger which glows\n"+
"a soft blue light sticking out of it. Maybe you could extricate it.\n");
set_weight(1000);
set_alias("rock");
set_value(0);
}
