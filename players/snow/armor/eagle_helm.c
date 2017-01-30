/*
A piece of helmet armor that can summon an attack eagle once, then destructs
*/
 
#define TO this_object()
#define ENVO environment(TO)
#define TP this_player()
 
inherit "obj/armor";
 
reset(arg){
   ::reset(arg);
   set_name("helm of the eagles");
   set_short("Helm of the Eagles");
   set_alias("helm");
   set_long(
"This is a steel helmet with a feathered plume.\n"+
"There appears to be some writing on the rim.\n");
   set_type("helmet");
   set_ac(2);
   set_weight(1);
   set_value(1000);
set_save_flag(0);
}
 
init() {
  ::init();
add_action("read_helm","read");
add_action("eagle_flight","eagle");
}
 
read_helm(arg) {
  if(!arg) {write("Read what?\n"); return 1;}
  if(arg == "helm") {
    write(
"Some faint inscriptions read:\n"+
"  To release the spirit of the Eagle from this helm, 'eagle <opponent>'\n");
return 1;
  }
}
 
eagle_flight(arg) {
  object bird;
  int lev;
bird = clone_object("/players/snow/MONSTERS/spirit_eagle.c");
lev = this_player()->query_level();
  if(!arg) {write("Release the spirit Eagle at what?\n"); return 1;}
  if(!present(arg,environment(TP))) {
    write("There is no such monster present!\n"); return 1; }
  if(!present(arg,environment(TP))->query_npc()) {
    write("The spirit Eagle will not attack players!\n"); return 1; }
else
call_other(bird,"set_wc",(lev+10));
call_other(bird,"set_ac",lev);
call_other(bird,"attack_object",arg);
call_other(bird,"set_chance",(lev*2));
call_other(bird,"set_spell_dam",(lev));
  if(worn) command("remove helm",TP);
destruct(TO);
return 1;
}
