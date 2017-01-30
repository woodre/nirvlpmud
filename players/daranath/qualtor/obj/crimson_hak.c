inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("hakama");
   set_short("A worn cotton Hakama");
   set_alias("trousers");
    set_long("A pair of trousers, the Hakama is commonly found amongst the\n"+
             "Crimson Guard to stay warm. They often wear them under the\n"+
             "uniform.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(100);
}
