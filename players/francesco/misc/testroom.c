#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

init() {
        add_action("ww","ww");
add_action("fight_monsters","fight");
}
reset(arg) {
  if(arg) return;



set_light(1);

short_desc = "Village green";
long_desc =
     "   \n"+
     "    Of course..... nothing else than a bed in this room.\n\n",

dest_dir =({
   "/players/francesco/workroom.c","n",
   "/players/francesco/workroom.c","w",
   "/players/francesco/workroom.c","e",

});
}


fight_monsters(string str) {
string npc1, npc2;
object npc11, npc12;
if(!sscanf(str, "%s %s", npc1, npc2)) return 0;
npc11=present(npc1,environment(this_player()));
npc12=present(npc2,environment(this_player()));
npc11->attack_object(npc12);
return 1;
}
ww() {
  call_other(this_player(), "move_player", "ww#players/francesco/workroom");
  return 1;
  }

