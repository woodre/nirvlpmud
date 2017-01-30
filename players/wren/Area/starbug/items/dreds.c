	/* Lister's hat with dreds */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("dreds");
   set_alias("hat");
   set_short("Lister's crusty deerstalker with dreds.");
   set_long("This is Lister's favorite hat. He goes almost nowhere    \n"+
            "without it. When Rimmer took control of his body and     \n"+
            "made him cut off his dreds, he attached them to the cap. \n"+
            "It also has some pins and patches from places Lister has \n"+
            "seen. It could use a good scrub.\n");
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(300);
}
