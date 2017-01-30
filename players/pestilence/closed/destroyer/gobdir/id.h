  int me, mylevel;
  object ob;
  object obj;
  string atype;

id(str) {
  if(previous_object()) {
  if(!test_my_wear(previous_object())) {
return str == "generic_wc_bonus"|| str == "destroyer_ob"  ||   str == "brand"  ||  str == "no_spell"  ||  str == "notarmor"  ||  str == "muscles" || str == "pro_object"  ||  str == "pesty_guild"; }
}
return str == "generic_wc_bonus"|| str == "brand"  || str == "destroyer_ob"  ||  str == "no_spell"  ||  str == "muscles" || str == "pro_object"  ||  str  == "pesty_guild"; }
test_my_wear(ob) {
  me = environment();
  if(!me) return;
  mylevel = me->query_level();
 if(mylevel < 10) return 1;
  atype = ob->query_type();
   if(!atype) return;
 if(mylevel < 20) {
 if(ob->query_type() == "underwear"){
   tell_object(USER, "Your enhanced DNA prevents you from wearing such armor.\n");
   return 0;
   }
   if(ob->query_type() == "helmet"){
   tell_object(USER, "Your enhanced DNA prevents you from wearing such armor.\n");
   return 0;
   }
   if(ob->query_type() == "boots"){
   tell_object(USER, "Your enhanced DNA prevents you from wearing such armor.\n");
   return 0;
   }
    else return 1; }
}

long() {
write("This is the mark of Pestilence's elite army.  To\n"+
      "enhance your physical strength, you have been injected with\n"+
      "a test drug that has mutated your DNA.\n"+
      "<"+BOLD+"dhelp"+NORM+"> is the command to see the help files.\n");
  }
get() { return 0;}
 

/*
extra_look() {
write(environment()->query_name()+" has "+HIW+">"+HIR+"A.o.P"+HIW+"<"+NORM+" branded onto "+
  environment()->query_possessive()+" forehead.\n");
}
*/
