  int me, mylevel;
  object ob;
object obj;
  string atype;

id(str) {
  if(previous_object()) {
/*
if(this_player()->query_guild_rank() < 8){
return str == "generic_wc_bonus"|| str == "dknight_ob"  ||  str == "no_spell"  ||  str == "dark aura" || str == "aura" || str == "notarmor"  || str == "pro_object"  || str == "dark_sight_object"  || str == "no_mini"  || str == "party_object"; }
*/
  if(!test_my_wear(previous_object())) {
return str == "generic_wc_bonus"|| str == "dknight_ob"  ||  str == "no_spell"  ||  str == "dark aura" || str == "aura" || str == "pro_object"  || str == "dark_sight_object"  || str == "no_mini"; }

}
return str == "generic_wc_bonus"|| str == "dknight_ob"  ||  str == "no_spell"  ||  str == "dark aura" || str == "aura" || str == "pro_object"  || str == "dark_sight_object"  || str == "no_mini"; }

test_my_wear(ob) {
  me = environment();
  if(!me) return;
  mylevel = me->query_level();
 if(mylevel < 5) return 1;
  atype = ob->query_type();
   if(!atype) return;
 if(mylevel < 20) {
 if(ob->query_type() == "shield"){
   tell_object(USER, "This armor would block the path of darkness.\n");
   return 0;
   }
   if(ob->query_type() == "helmet"){
   tell_object(USER, "This armor would block the path of darkness.\n");
   return 0;
   }
   if(ob->query_type() == "boots"){
   tell_object(USER, "This armor would block the path of darkness.\n");
   return 0;
   }
  if(ob->query_type() == "armor" && !no_knight(ob)){
   tell_object(USER, "You wouldn't want to embarrass yourself wearing this.\n");
   return 0;
   }
/*
  if(ob->query_type() == "armor" && ob->query_weight() > 1){
   tell_object(USER, "This armor is too heavy for you!\n");
   return 0;
   }
*/
    else return 1; }
}
/*
test_my_wear(ob) {
  me = environment();
  if(!me) return;
  mylevel = me->query_level();
  if(mylevel < 5) return 1;
  atype = ob->query_type();
  if(!atype) return;
  if(mylevel < 20) {
    if(atype == "shield" || atype == "boots" ||
      atype == "helmet") return 0;
    else return 1; }
  else return 1; }
*/
no_knight(object ob){
if(call_other(ob,"id", "habit") || call_other(ob, "id", "robe") ||
   call_other(ob, "id", "veil") || call_other(ob, "id", "robes") ||
   call_other(ob, "id", "cloak") || call_other(ob, "id", "tunic") ||
   call_other(ob, "id", "cape") || call_other(ob, "id", "wings") ||
   call_other(ob, "id", "duster") || call_other(ob, "id", "vest") ||
   call_other(ob, "id", "coat") || call_other(ob, "id", "shirt") ||
   call_other(ob, "id", "hide") || call_other(ob, "id", "skin"))
   return 0;
else return 1;
}
long() {
write("A dark aura engulfs your body.\n"+
      "You sense an air of honor, with a touch of evil\n"+
      "in your soul.\n"+ 
      "<"+BOLD+"dhelp"+NORM+"> to see the dark order help files.\n");
  }
get() { return 0;}

extra_look() {
write(environment()->query_name()+" is encircled with a "+HIK+"dark"+NORM+" aura around "+
  environment()->query_possessive()+" body.\n");
}