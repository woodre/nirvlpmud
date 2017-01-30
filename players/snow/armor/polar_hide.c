/* Polar Bear Hide found on ~/MONSTERS/polar_bear.c */

#define TP this_player()
#define TO this_object()
#define ENV environment
#define TPN TP->query_name()
#define TPRN TP->query_real_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("polar hide");
   set_short("A polar bear hide");
   set_alias("hide");
   set_long(
"This is the hide of a polar bear. It is dazzlingly white in some parts and\n"+
"hideously bloody in others. It is very thick and looks like it would \n"+
"provide good protection against blows. It also looks like you could eat it\n"+
"if you were in really bad shape...\n");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(5000);
}

init() {
  ::init();
  add_action("eat_hide","eat");
   }

eat_hide(str) {
  if(!str) { write("Eat what?\n"); return 1; }
  if(str != "hide") { notify_fail("Eat what?\n"); return 0; }
  if(str == "hide") {
    say(TPN+" gnaws a polar bear hide to shreds!\n"+
        capitalize(TP->query_possessive())+" body seems to heal.\n");
    write("You gnaw the polar bear hide to shreds!\n"+
          "Your body loses almost all trace of wounds!\n");
    TP->heal_self(200);
    if(worn(TO)) command("remove hide", TP);
    destruct(TO);
    return 1;
   }
}
