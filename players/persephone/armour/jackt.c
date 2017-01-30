inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("jacket");
  set_alias("armor");
  set_short("Cool Black Jacket");
  set_long("A cool looking black leather jacket like bikers wear in\n" +
           "fact you can see the Coffin Cheaters insignia on the back\n" +
           "and a chains hanging from the shoulders\n");
  set_value (600);
  set_weight(2);
  set_ac(2);
  set_type("armor");
}
