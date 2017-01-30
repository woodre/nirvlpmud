inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("crusader shield");
   set_short("White shield with a Red Cross");
   set_alias("shield");
   set_long("A full length white battle shield painted in the insignia\n"+
            "of the crusades. Very good protection in a fight.\n");
   set_type("shield");
   set_ac(1);
   set_weight(1);
   set_value(275);
}
