inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_short("A vase");
  set_long("This is a porcelain vase with tiny violets in geometric\n"+
           "patterns painted on it.\n");
  set_value(1000);
  set_id("vase");
  set_weight(2);
}
