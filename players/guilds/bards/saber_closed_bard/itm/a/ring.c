/*
 *  Armor for the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("signet ring");
   set_short("A signet ring");
   set_alias("ring");
   set_long("A signet ring of the Bardic Guild of Ryllian.\n"+
            "It has the silver Rune of Crysea upon it.\n");
   set_type("ring");
   set_ac(1);
   set_weight(0);
   set_value(50);

        }
