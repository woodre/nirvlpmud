inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("uniform");
   set_short("A torn Crimson Guard's Uniform");
   set_alias("uni");
   set_long("A Crimson Guard Uniform that has been torn beyond use.\n"+
            "The bottom half of the uniform is missing and several \n"+
            "long tears run across the torso area. You would be \n"+
            "quite exposed wearing this uniform.\n");
   set_type("armor");
   set_ac(1);
   set_weight(1);
   set_value(350);
}
