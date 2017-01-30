inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
set_short("The Mane of Cerberus");
set_long("This is a the still-living mane of Cerberus.  The snake-like appendages\n"+
"still writhe about.  What a disgusting item.\n");
     set_ac(1);
     set_weight(1);
	set_value(3000);
	set_alias("helmet");
	set_name("mane");
	set_type("helmet");
        set_params("other|evil", 3, 0, "mane_spec");
        set_params("other|good", 3, 0, "mane_spec");
  }
init() {
::init();
add_action("make_evil","make_evil");
}
wear(str) {
string a,b;
::wear(str);
if (sscanf(str,"%smane%s",a,b) == 2) {
if (this_player()->query_level() > 15) {
write("You have conquered the man with your will power.  In return it has\n"+
"granted you the following power...\n"+
"Whenever you desire, you can spend your mystical energy and make yourself more\n"+
"evil.  Just type make_evil, and pay the consequences.  (50 sp).\n");
return 1; }
}
}
make_evil() {
write("You feel yourself becoming more and more sinister\n");
this_player()->add_spell_point(-50);
  if(this_player()->query_alignment() > -800)
this_player()->add_alignment(-200);
this_player()->set_al_title("Demon Lord");
return 1;
}

mane_spec() { }
