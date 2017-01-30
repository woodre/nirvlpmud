
inherit "obj/monster";

reset(arg){
::reset(arg);
if(arg) return;
set_name("myconid");
set_level(6);
set_wc(10);
set_ac(5);
set_hp(90);
set_short("A myconid");
set_long("The myconid people are a strange fungal-humanoid race known\n"+
"for their reclusiveness and pacifism.  They are extremely difficult\n"+
"to defeat in battle because of their hallucinogenic spores.  Why are\n"+
"you attacking such a peaceful creature that just wants to be left alone?\n");
}

init(){
add_action("kill", "kill");
::init();

}

kill(){
   write("The myconid would rather die than do violence, so it does.\n");
   write("Its corpse blows away in a strange wind.\n");
   destruct(this_object());
return 1; 
}

heart_beat() {
  if(!environment(this_object())) return;
  if(query_attack()) { kill(); return; }
::heart_beat();
}
