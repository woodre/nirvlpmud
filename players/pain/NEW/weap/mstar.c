inherit "players/pain/NEW/weap/p_weap.c";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      	set_alias("morningstar");
	set_short("A huge iron morningstar");
	set_long("A large, surprisingly wieldy iron morningstar from Bigelow.\n");
	set_class(18);
	set_weight(3);
	set_value(3000);
	set_name("morningstar");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
string attn;
string tpn;

attn = attacker->query_name();
tpn = this_player()->query_name();
  i=random(100);

if (i>89) {
say(tpn+"'s morningstar whips around and sinks into "+attn+" with "+
    "a sickening crunch.\n");
write("Your morningstar sinks into "+attn+" with a sickening crunch.\n");
tell_object(attacker, tpn+"'s morningstar sinks into you with a "+
	"sickening crunch.\n");
return random(8)+3;
}
if (i>79) {
say(tpn+"'s morningstar smashes into "+attn+" spraying blood and flesh "+
	"across the room.\n");
write("Your morningstar smashes into "+attn+" spraying blood and flesh "+
	"across the room.\n");
tell_object(attacker, tpn+"'s morningstar smashes into you, spraying your "+
	"flesh and blood across the room.\n");
return random(4)+5;
}
if(i>69) {
say(tpn+"'s morningstar hits "+attn+" with bonecrushing force.\n");
write("Your morningstar hits "+attn+" with bonecrushing force.\n");
tell_object(attacker, tpn+"'s morningstar hits you with bonecrushing "
	+"force.\n");
return random(4)+2;
}
   return 0;
}
