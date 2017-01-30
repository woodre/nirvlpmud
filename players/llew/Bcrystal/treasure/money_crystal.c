inherit "obj/treasure";

reset(agr) {
   if(agr) return;
   set_id("crystal");
   set_alias("BC_money_crystal");
   set_short("A small clear crystal");
   set_long("The clear crystal flickers with any light.\n"+
            "It is shaped to perfection and looks quite\n"+
            "valuable.  It is light and small.\n");
   set_value(750+random(500));
   set_weight(1);
   set_dest_flag(1);
}
