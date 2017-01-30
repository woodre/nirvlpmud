inherit "/obj/armor.c";
id(str) { return str=="shirt" || str=="striped shirt" || str== "long striped shirt" || str=="long shirt"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("A long striped shirt");
 set_short("A long striped shirt");
 set_long("A long shirt that is dark pink in color, with black\n"+
          "horizontal stripes.  It is one of Piglet's favorite things.\n");
 set_type("armor");
 set_ac(1);
 set_value(210);
}
