inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("coral warplate");
   set_short("A suit of coral warplate");
   set_alias("warplate");
   set_long("The coral warplate is a piece of art.\n"+
            "Jagged polished shells stud the metal.\n"+
            "The inside of the armor is lined with\n"+
            "comfortable leather.\n");
   /* ac6 is right out...    ill
   set_ac(random(4)+3);
  */
  set_ac(random(3)+3);
  set_params("magical",3,0,0);
  set_params("other|water",0,20,0);
  set_params("other|earth",0,-20,0);
   set_weight(random(3)+5);
   set_value(600);
}
