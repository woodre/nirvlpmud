/* Made so snake leaves if snake weapon is not wielded -Snow 6/99 */
inherit "obj/monster";
object ownn;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_race("reptile");
  set_short("A little red snake");
  set_long("A small snake called to existance by the green snake!\n");
  set_hp(50);
  set_level(1);
  set_al(0);
  /* make part of it poison, less total damage - ill
  set_wc(18);
  */
  set_wc(8);
  set_weapon_params("other|poison",8,0);
  set_ac(5);
  set_heal(5,10);
  set_aggressive(0);
  set_a_chat_chance(15);
  load_a_chat("A snake lashes out!\n");
  load_a_chat("Hsssssssss!\n");
   ownn = 0;
  call_out("check",6);
}

check() {
  object wep;
  if(!environment(this_object()) ) return 1; 
  if(!ownn) { destruct(this_object()); return 1; }
   if(!(this_object()->query_attack()) || !ownn->query_attack()) {
   tell_room(environment(this_object()),"A snake leaves...\n");
   destruct(this_object());
   return 1;}
  wep = ownn->query_weapon();
  if(!wep || !wep->id("snake") ) {
   tell_room(environment(this_object()),"A snake leaves...\n");
   destruct(this_object());
   return 1;}
call_out("check",6);
return 1;}

set_owner(object ob) { ownn =  ob; }
query_npc(){ return 0; }
