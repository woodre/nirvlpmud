inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("apron");
  set_alias("cloak");
  set_short("A Butcher's Apron");
  set_long("A butcher's apron that is covered in blood stains and\n" +
  "messy handprints from where the butcher wiped his hands.\n");
  set_value (600);
  set_weight(2);
  set_ac(1);
  set_type("misc");
}
