	/* Lister's hat with dreds */

inherit "obj/armor";

void
set_type(string str) { type = str; }

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("dreds");
   set_alias("cap");
   set_short("Lister's crusty deerstalker with dreds.");
   set_long("This is Lister's favorite hat. He goes almost nowhere    \n"+
            "without it. When Rimmer took control of his body and     \n"+
            "made him cut off his dreds, he attached them to the cap. \n"+
            "It also has some pins and patches from places Lister has \n"+
            "seen. It could use a good scrub.\n");
   set_ac(1);
   set_type("hat");
   set_weight(1);
   set_value(300);
}
