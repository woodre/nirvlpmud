inherit "obj/treasure";

reset(arg) {
 if(arg) return;
   set_short("A long ladder");
    set_alias("ladder");
  set_long("This is a long ladder.  It looks like it could be a very\n"+
 "useful item.\n");
   set_weight(4);
    set_value(150);
}
 id(str) { return str == "ladder" || str == "ESP ladder"; }

