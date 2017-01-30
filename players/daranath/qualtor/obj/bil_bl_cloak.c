inherit "obj/armor";

reset(arg){
  ::reset(arg);
                  
  set_name("black cloak");
  set_short("A billowing black cloak");
  set_alias("cloak");
  set_long("A black cloak made from way too much material, it moves\n"+
           "and shifts with the slightest of breezes, making it seem\n"+
           "almost alive.\n");
  set_type("misc");
/*
This was set at ac 3 for a purpose that was to be used within my guild
but wizards cannot keep thier nose outa anything that is different
from everything else, so I made it ac 1 for the time being.
AC 3 was APPROVED....  let me repeat that....
AC 3 was APPROVED in the first place....

wizards who think I am ragging on them are free to mail me with
any comments, complaints, insults or whatever...
I aim to please...    -Daranath
  set_ac(3);
*/
  set_ac(1);
  set_weight(2);
  set_value(1750);
}

query_save_flag() {return 1; }
