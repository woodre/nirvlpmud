inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
   set_name("hayhook");
  set_alias("hook");
  set_short("A Hayhook");
set_long(
"A common hayhook, that might be found on any farm.  You notice that\n"+
"this one has a VERY sharp point!\n");
  set_class(8);
  set_weight(1);
  set_value(30);
  set_hit_func(this_object());
}
 weapon_hit(attacker){
int W;
W = random(22);
if(W>11) {
say(capitalize(this_player()->query_name())+" rips chuncks of flesh from his foe with the hook.\n");
write("You hear your opponent scream as the hook connects!\n");
return 1;
    }
   return;
}
