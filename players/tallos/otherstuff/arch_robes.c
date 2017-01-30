/*
Robes from /pl/s/MONSTERS/glarvinthal
ac4, non-storeable, with limited sp addition
*/
 
#define TP this_player()
#define TPN TP->query_name()
 
inherit "obj/armor";
 
int charges;

/* 
query_save_flag() { return 1; }
 If we save the charges value, this cloak can be savable. -Bp */
locker_arg() {
  string blah;
  blah="--"+charges+"--";
  return blah;
}
locker_init(arg) { 
  int blah;
  sscanf(arg,"--%d--",blah);
  charges = blah;
}


init() {
  ::init();
add_action("focus_robes","focus");
}
 
reset(arg){
   ::reset(arg);
   set_name("robes of the archwizard");
   set_short("Robes of the Archwizard");
   set_alias("robes");
   set_long(
"Shining white robes formerly worn by the Archwizard Glarvinthal.\n"+
"You should be able to 'focus' the robes' power into your own.\n");
   set_type("armor");
   set_ac(4);
   set_weight(1);
   set_params("other|magical", 2, 10, "do_spec");
   set_value(10000);
charges = 5;
}
 
 
focus_robes() {
  if(TP->query_level() < 10) {
    write("You are not powerful enough to focus the robes' powers!\n");
return 1;
  }
  if(charges == 0) {
    write("The Archwizard's robes have no more power to give!\n");
return 1;
  }
else
  write("You focus the power of the Archwizard's robes into your own!\n");
  say(TPN+
" closes "+TP->query_possessive()+" eyes and is surrounded by a powerful aura!\n");
call_other(TP,"add_spell_point",50);
charges = charges -1;
  if(charges == 0) {
    write(
"You have absorbed all the power from the Archwizard's robes.\n");
  }
return 1;
}


do_spec(object owner){
     if(!random(3)){
       tell_object(owner,
       "The robes glow faintly under the magical attack!\n");
       return 1002;
       }
return 0;
}
