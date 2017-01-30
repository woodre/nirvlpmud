inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("uniform");
   set_short("A Crimson Guard's Uniform");
   set_alias("uni");
   set_long("The uniform of the Crimson Guard consists of several layers\n"+
            "of strong leather, covered in small metal studs. The leather\n"+
            "has a redish tinge to it, thus give the Crimson Guard\n"+
            "their name.\n");
   set_type("armor");
   set_ac(3);
   set_weight(2);
   set_value(1750);
}
