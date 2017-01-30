
inherit "/obj/treasure.c";

reset ( int arg ) {
   if ( arg ) return;
   set_id("heart");
   set_short("A broken heart");
   set_long("This is Bastion's broken heart. It was torn to shred's by a " +
            "cruel hand.\n");
}

drop () { return 1; }

query_auto_load () { return "/players/bastion/obj/heart:"; }
