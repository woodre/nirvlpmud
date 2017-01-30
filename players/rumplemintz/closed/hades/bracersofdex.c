inherit "obj/armor";
object gloves;
string str;
reset(arg) {
   if (!arg) {
      set_name("bracers of dexterity");
      set_alias("bracers");
      set_type("misc");
      set_short("Bracers of Dexterity");
      set_long("The Bracers glow with an eerie purplish tint.\n Other than a small inscription, they are rather plain.\n");
      set_ac(1);
      set_value(2000);
      set_weight(3);
   }
}
init() {
   ::init();
   add_action("read_insc","read");
}
read_insc(str) {
   if(lower_case(str) == "inscription") {
      write("The Inscription reads:  ***IMPORTANT***\n");
      write("These bracers were blessed by the Great Priest Molgrock.\n");
      return 1;
   }
   return 0;
}
id(str) {return str == "bracers_dexterity" || str == "bracers";}

