inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("crucifix");
   set_short("A silver crucifix");
   set_alias("cross");
   set_long("A stunning crucifix of worked silver.  The crucifix has long\n"+
            "been a symbol of protection from evil.\n");
   set_type("necklace");
   set_ac(1);
   /* protection from evil added by illarion dec 2004 */
   set_params("other|evil",0,20,0);
   set_weight(1);
   set_value(1000);
}

quest_ob()  { return 1; }
