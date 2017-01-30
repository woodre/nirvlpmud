#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  short_desc="Dark Myre";
long_desc=
 "As you slosh through the swamp, you get the continous feeling\n"+
 "that eyes are upon you, although when you look around, you see nothing...\n";

items=({
 "myre","Yes, you are in the Dark Myre",
 });

  dest_dir=({
 "/players/daranath/dar/rooms/swamp1.c","north",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  if(this_player()->is_player())  {
    call_out("monster_check",5);
        }
}

search() {
write("You find nothing but filth.\n");
say (tp +" searches the area\n");
 return 1;  }

monster_check()  {
object ob, HERE;
int temp, chance;
  HERE = first_inventory(this_object());
  while(HERE)  {
    if(HERE->is_player()) temp = 1;
  HERE = next_inventory(HERE);
        }
  if(temp > 0)  {
  chance = random(100);
  if(chance < 20)  {
  ob = call_other("/players/daranath/dar/gen.c","make_monster");
  ob = find_living("summon_me");
  ob->set_alt_name("monster");
  move_object(ob, this_object());
  say("A "+ob->query_name()+" wanders in.\n");
  remove_call_out("monster_check");
  call_out("monster_check",40);
  return 1;
        }
        }
  remove_call_out("monster_check");
  call_out("monster_check",40);
        }
