inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("shoes");
  set_alias("boots");
  set_short("Ent Shoes");
  set_long("While some might call these big wooden objects shoes they\n" +
           "look more like tree roots and consequently heavy but they\n" +
           "they do look comfortable.\n");
  set_value (1000);
  set_weight(3);
  set_ac(1);
  set_type("boots");
}
