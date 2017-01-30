inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Stick of Malicious Wounding");
    set_long("Hmm... Inspecting the legandary Stick of Malicious Wounding,\n"+
	"you realize that it is nothing but an aluminum baseball bat with\n"+
	"offensive words written all over it. However, when you swing it,\n"+
	"it feels crisp, and light, surely capable of living up to its name.\n");
    set_short("The Stick of Malicious Wounding");
    set_class(17);
    set_value(4000);
    set_alias("stick");
    set_weight(2);
    set_hit_func(this_object());
    }
 if(random(100) < 8) {
	write("*THUNG!* You crack someone's skull with this fine weapon.\n");
	say((this_player()->query_name())+" goes ape-shit with a Stick of Malicious Wounding!\n"+
        "You cringe in terror.\n");
	return 3 ;
	}
}

init() {
  add_action("readymenow","wield");
  ::init();
}

wield(str) {
  if(!str || str != "stick") return 0;
  write("Your eyes glimmer and you begin to drool when you wield this thing.\n");
  ::wield(str);
  return 1;
}

