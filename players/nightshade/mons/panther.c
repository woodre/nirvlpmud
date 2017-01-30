inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("panther");
   set_alias("panther");
   set_short("Guenhwyvar");
set_long(
"Guenhwyvar is a beautiful creature. His sleek, glossy fur\n"+
"shines with a magical brilliance while the huge corded muscles knot beneath.\n"+
"White 4 inch fangs line his maw and black razor sharp claws line each\n"+
"foot. Good thing he is on your side.\n");
   set_level(1);
   set_hp(150);
   set_al(0);
   set_wc(15);
   set_ac(5);
   set_chance(30);
   set_spell_dam(15);
set_spell_mess1("Guenhwyvar rips at his opponent with claws and teeth!");
set_spell_mess2("Long sharp claws and teeth greet your face head on!");
}
