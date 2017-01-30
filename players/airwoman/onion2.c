inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("onion2");
  set_alias("onion");
  set_weight(1);
  set_value(25);
  set_strength(5);
  set_short("A peeled onion");
  set_long("A peeled onion which can make\n"+
   	"heaven cry.  Perhaps you should raise onion to \n"+
        "heaven so the tears will fall faster.\n");
  set_eating_mess(" indulges in an onion?\n");
}

