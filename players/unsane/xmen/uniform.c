inherit "obj/armor";
reset(arg){
   if(arg) return;
   ::reset();
   set_name("uniform");
   set_alias("suit");
   set_short("An X-men Uniform");
   set_value(1000);
   /* lowered weight from 4 to 2.  */
   set_weight(2);
   set_ac(4);
   set_type("armor");
   set_long("This is a dark blue uniform with an insignia of a black X in a red circle.\n"+
      "It was worn by one of the X-men and it appears to be pretty good armor.  It\n"+
      "should be.  After all, It is made of unstable molecules.\n");
   set_params("other|electric", 4, 0, "xmen_special");
   set_params("other|fire", 4, 0, "xmen_special");
   set_params("other|ice", 4, 0, "xmen_special");
  set_params("other|laser", 4, 0, "xmen_special");
}

xmen_special() { /* eh.. fuck it */ }
