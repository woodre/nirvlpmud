
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_name("coinspinner");
   set_alias("sword");
   set_alt_name("longsword");
   set_class(18);
   set_weight(2);
   set_value(600);
   set_short("A longsword");
   set_long("A magnificent looking longsword.  Emblazoned on the hilt\n"+
            "of the sword is a picture of a pair of dice.  Below that\n"+
            "you can see a faint inscription.\n");
   set_read("Who holds Coinspinner knows good odds.\n");
}

