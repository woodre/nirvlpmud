inherit "obj/armor";
reset(arg){
   ::reset(arg);
if (arg) return;
set_short("Crystal Necklace");
set_long(
"This is a beautiful crystal necklace.  There is a large opal that\n"+
"hangs in the center.  The opal appears to pulsate with a life\n"+
"of it's own.\n");
   set_ac(1);
   set_weight(1);
   set_value(6000);
set_alias("necklace");
set_name("crystal necklace");
set_type("misc");
    call_out("check_heal", 1);
}


check_heal() {
object ob;
if (!environment(this_object())) return;
 if(worn_by && worn_by->query_hp() < 35) {
tell_object(worn_by,"Your neckace flashes a bright blue light!\n"+
       "The item crumbles to powder, but your wounds are healed.\n");
   worn_by->heal_self(200);
      destruct(this_object());
   return 1;
       }
 call_out("check_heal", 1);
}
