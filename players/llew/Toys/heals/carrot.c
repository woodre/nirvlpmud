inherit "obj/food";

reset(arg) {
   if(arg) return;
   set_name("carrot");
   set_short("A carrot");
   set_long("The stuffed orange carrot looks good enough to eat.\n");
   set_value(100);
   set_weight(1);
   set_strength(15);
   set_eater_mess("You munch down on the carrot.  It's quite good, even\n"+
         "with the stuffing stuck in your teeth.\n");
}
