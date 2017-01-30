inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("kobold crown");
   set_short("A shining golden crown");
   set_alias("crown");
   set_long("The golden crown which symbolizes the king of the kobold clan,\n"+
            "it seems to have been stolen from somewhere.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(750);
}
