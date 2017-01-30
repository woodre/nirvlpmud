inherit "room/room";

reset(arg) {

  object warrior;
  if (!arg){
    set_light(0);
    short_desc = "Prison Cell";
      long_desc = 
        "You are in the end prison cell, and much to your suprise, there is\n" +
        "no prisoner in here, just a warrior that wants to revenge his honor.  Looks\n" +
        "like you're a dead man.\n\n";
    dest_dir = 
        ({
                "players/paulasx/prison/cellhall5.c", "east",
        });
     }

  if(!present("warrior", this_object())){
    warrior=clone_object("obj/monster");
    call_other(warrior,"set_name","warrior");
     call_other(warrior,"set_level",20);
    call_other(warrior,"set_hp",400);
/* Changed from wc22 to 40 -Snow */
    call_other(warrior,"set_wc",40);
    call_other(warrior,"set_ac",12); /* Added by Feldegast 9-24-00 */
    call_other(warrior,"set_short","A battle warrior");
    call_other(warrior,"set_long",
               "The warrior is following your movements with his eyes.\n"+
               "Maybe you should leave while you can.\n");
    call_other(warrior,"set_al",-200);
/* Changed from 5000 to 2000 -Snow */
/* Changed to 4000 -Feldegast */
    warrior->add_money(3000+50*random(40));
    move_object(clone_object("/players/feldegast/wep/sword.c"),warrior);
    move_object(warrior,this_object());
  }
}
