	/* Lister's guitar */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("guitar");
set_alias("axe");
set_short("Lister's guitar");
set_long("This is Lister's most prized possession. He's protected it \n"+
         "against all attacks. It is a little odd in that its only got\n"+
         "three strings and two are E. It probably would be offensive \n"+
         "in nature if played.  \n");

set_type("axe");   /*sword,knife,club,axe,bow,polearm */
set_class(16);
set_weight(3);
set_value(500);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>=7)  {
    say(this_player()->query_name()+ " strums on the guitar thinking they are a vertuoso. Oh that isn't right. \n");
    write("You rock out with a power chord like the ghost of Hendrix. \n");
    return 3;
          }
return;
}
