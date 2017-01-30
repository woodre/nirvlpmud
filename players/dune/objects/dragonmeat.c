inherit"obj/food";

string food;

reset(arg) {
::reset(arg);
if(!arg) {
   int i;
   i = random(5) + 1;
   set_name("dragonmeat");
   if (i == 1) {
set_short("A piece of human leg");
food = "leg";}
   if (i == 2) {
set_short("A piece of gnome head");
food = "head";}
   if (i == 3) {
set_short("A piece of elf torso");
food = "torso";}
   if (i == 4) {
set_short("A piece of pet flesh");
food = "flesh";}
   if (i == 5) {
set_short("A piece of dwarf throat");
food = "throat";}
   set_alt_name(food);
   set_long("This looks like some dragon food.\n"+
    "You wonder how such a thing could possibly taste.\n");
   set_eater_mess("You eat the "+food+", it tastes like chicken\n");
   set_eating_mess(capitalize(this_player()->query_real_name())+
    " eats the "+food+" hungrily.\n");
   set_strength(random(50)+1);
   set_value(50);
}
}
