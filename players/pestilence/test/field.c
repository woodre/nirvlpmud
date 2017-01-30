#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";
int peeps;

reset(arg) {
  if(arg) return;

/*
if (!present("stoner")) {
  move_object(clone_object("/players/pestilence/ozfest/mobs/stoner.c"),
        this_object()); }
*/
short_desc = ""+HIK+"Getting High in the "+HIW+"OZ Fest"+NORM+"";
long_desc =
  "This is a part of the open field where some of the audience\n"+
  "gathers to get high.  It seems everyone here is smoking a big \n"+
  "fatty.  Smoke fills the air in every direction.  Theres enough\n"+
  "second hand smoke here to get anyone high.  To the far north\n"+
  "you can see the main stage and to the far east and west are the\n"+
  "secondary stages.\n";


set_light(1);

items = ({
  "stages","You can't see them through the thick smoke.",
  "fatty","There is a large fatty in almost everyone's hand.",
  "smoke","Thick smoke coming from a blunt.",
});

dest_dir = ({
  "/players/pestilence/ozfest/field.c","west",
});

}
init()
{
    ::init();
    if(this_player() && this_player()->is_player())
            /* if someone has entered the room manually, and the flag isn't on */
    {
      peeps ++;
      if(peeps == 1)
      call_out("intox_da_ppl", 10);
    }
}

intox_da_ppl()
{
    object ob, oc;

    ob = first_inventory(this_object());
    while(ob)
    {
      oc = next_inventory(ob);
      if(!random(4))
        tell_object(ob, "The blunt smoke.. is getting you f'd up..\n");
      ob->add_intoxination(12 + random(22));
      ob = oc;
    }
    call_out("intox_da_ppl", 10);
}

/* func called when 'ob' leaves the room */
exit(ob)
{
    if(ob && ob->is_player())
    {
      /* reset the flag */
      peeps --;
      /* kill the call out til it doesn't exist */
      if(peeps <= 0)
      while(remove_call_out("intox_da_ppl") != -1);
    }
}
