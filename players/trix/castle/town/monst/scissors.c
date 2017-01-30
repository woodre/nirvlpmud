/*
  Changed the wc from 18 to 15 for thematic reasons.
  They can still poke your eye out though.
   -Feldegast 9-23-00
*/
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("scissors");
   set_alt_name("pair of scissors");
   set_alias("scissor");
   set_short("A pair of scissors");
   set_long(
"This is a pair of scissors.  They're used to cut hair but they'd hurt if\n"+
"you stuck anybody with them.\n");
  set_class(15);
   set_weight(2);
   set_value(2000);
}

