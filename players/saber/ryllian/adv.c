#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  t = 0;
short_desc="Bard Training Chamber- Ruins";
long_desc=
 "A hollow depression is all that remains of the healing pool bards once\n"+
 "splashed in, when times were good.  The water must have evaporated in the\n"+
 "heat of vengeful fire.  A single card, singed at one corner, lies forgotten\n"+
 "on the stone floor.\n";

items=({
 "depression","This used to be a pool whose waters healed those who drank",
 "card","You pick up the card, startled by what is on it.  This is the\n"+
        "Tower, the card depicting chaos and destruction.  Its survival\n"+
        "mocks the gentle wisdom of a small girl who once lived here.\n"+
        "You let the card slide from your fingers, and it falls to the floor",
 });

  dest_dir=({
 "/players/saber/closed/old_bard/room/tel.c","east",
 "/players/saber/closed/old_bard/room/lo.c","south",
           });
  }   }

  init() {
  ::init();
  if(!t) { t = 1; call_out("flicker",5); }
}

flicker() {
object ob;
int h,i;
  h = i = 0;
  ob = all_inventory(this_object());
  while(i < sizeof(ob) || !h) {
    if(ob[i]->query_real_name()) 
      if(find_player(ob[i]->query_real_name())) h = 1;
  i++; }
  tell_room(this_object(),
  "Searing heat can be felt from the east.\n"+
  "The noise is deafening and the light is blinding.\n");
  if(h) call_out("flicker",5+random(100));
  else t = 0;
return 1; }