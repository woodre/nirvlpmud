/*
 *  Armor for the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/armor";

reset(arg) {
   ::reset(arg);
   
   set_name("storm steel chainmail");
   set_short("A suit of storm steel chainmail");
   set_alias("chainmail");
   set_long("A suit of chainmail forged from links of storm steel.\n"+
            "It is of quality workmanship, and offers fine protection.\n");
   set_ac(4);
   set_weight(3);
   set_value(500);
        
        }
