inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Ragged cloak");
set_short("A ragged looking cloak");
set_alias("cloak");
set_long("A tattered and torn peice of clothing, the cloak used to be protective\n"+
         "both during a fight and from the elements. Now, in its ragged state,\n"+
         "there is no telling what its value might be.\n");
set_type("misc");
set_ac(1);
set_weight(1);
set_value(100 + random(300));
}
