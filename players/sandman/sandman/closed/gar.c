inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("blue garter");
set_alias("garter");
set_short("Pale Blue Garter");
set_long(
"A pale blue garter trimmed with lace, resting high on your perfect thigh.\n");
set_weight(1);
set_value(0);
set_ac(1);
set_type("amulet");
set_arm_light(1);
}

init() {
  ::init();
}

throw(str) {
  if(str == "garter") {
  say("Sandman kneels before China and raises her dress, slowly\n");
  say("revealing her shapely thigh.\n\n");
   say("Sandman gently pulls down her lacey blue garter, then stands and\n");
   say("turns towards the crowd. He then tosses the garter high in the\n");
  say("air\n\n");
  say("The garter flies through the air and lands in Jebuly's stunned hands\n");
  write("Sandman kneels before you and slowly raises your dress.\n");
  write("He runs his hand slowly up your shapely thigh, making you shiver\n");
  write("Taking it down and off, he stands and throws it into the air\n\n");
  write("The garter sails through the air and lands in Jebuly's stunned\n");
  write("hands.\n");
move_object(clone_object("/players/sandman/closed/gar"),find_player("sandman"));
destruct(this_object());
return 1;
   }
   return 1;
}
