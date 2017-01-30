	/* Sparehead 3 hehe*/

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("sparehead");
set_alias("head");
set_short("Kryten's sparehead 3.");
set_long("This is Kryten's sparehead 3. It's been left alone too long \n"+
         "and has developed droid rot. It sputters and growls at you. \n"+
         "It sounds much like a crazy welshman.\n");

set_type("other");   /*sword,knife,club,axe,bow,polearm */
set_class(16);
set_weight(3);
set_value(1000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(35);
if(W>=26)  {
    say("Sparehead mutters: 'I may 'ave droid rot and be all la de da but i know what i am'. \n");
    write("Sparehead mutters: 'I may 'ave droid rot and be all la de da but i know what i am'. \n");
    return 7;
          }
if(W<=5) {
    say("Sparehead mutters: 'Running around with your fancy smancy human body, who needs you.'\n");
    write("Sparehead mutters: 'Running around with your fancy smancy human body, who needs you.'\n");
    return 5;
            }
if(W==15) {
    say("Sparehead grumbles and sparks angrily.\n");
    write("Sparehead grumbles and sparks angrily.\n");
    return 15;
         }
return;
}
