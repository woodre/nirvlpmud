/*
 *  Armor for the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/armor";

reset(arg){
   ::reset(arg);
   
   set_name("parrying dagger");
   set_short("A parrying dagger");
   set_alias("dagger");
    set_long("A translucent gray dagger of gleaming storm crystal.\n"+
             "It has a large hilt guard, and a three pronged blade.\n"+
             "On the hilt is both the Rune of Crysea and the Bardic Rune.\n");
   set_type("shield");
   set_ac(1);
   set_weight(1);
   set_value(50);
        
        }
