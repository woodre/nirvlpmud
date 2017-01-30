/* check()/reset() func totally rewritten by Vertebraker [5.31.01] */
#define STORE_ROOM "/players/saber/tower/tower14+1"
#define OB find_object(STORE_ROOM)

#define tp this_player()->query_name()
inherit "room/room";

int search_count, clone_count, mcount, t;
object ob, OBJ;

void
reset(int arg)
{
    if(arg) return;
    search_count = 1;
    move_object(
       clone_object("/players/mythos/closed/guild/forest/misc/xb.c"), 
       this_object() ); 
    move_object(clone_object("/players/saber/effects/barfight.c"), 
     this_object());
    move_object(clone_object("/players/saber/food/fightpub.c"),
     this_object());
    move_object(clone_object("/players/saber/monsters/merc.c"),
     this_object()); 
    move_object(clone_object("/players/saber/monsters/orc.c"),
     this_object());
    move_object(clone_object("/players/saber/monsters/amazon.c"),
     this_object());
    move_object(clone_object("/players/saber/monsters/thief.c"),
     this_object());
    move_object(clone_object("/players/saber/monsters/barbarian.c"),
     this_object());
    set_light(1);
    short_desc="Eternal Bar Fight";
  long_desc=
   "You are in the common room of a pub which\n"+
   "has seen much better days. Chairs, tables\n"+
   "and bodies are scattered haphazardly about\n"+
   "the chamber, and the overpowering smell of\n"+
   "alcohol pervades the air.  There is a SIGN\n"+
   "upon the wall.\n";

  items=({
   "portal","A dark stone portal filled with a hazy blue aura",
   "floor","The floor is covered with broken furniture and broken people",
   "chair","A broken chair lying in multiple pieces on the floor",
   "table","A smashed table leaning agaist the wall",
   "pub","The common room of a nameless Inn",
   "chamber","The common room of a nameless Inn",
   "bodies","Many bodies strewn in random places about the room",
   "barmaid","A comely young barmaid serving out drinks to the patrons",
   });

    dest_dir=({
 "/players/saber/tower/tower6.c","portal",
 "/players/saber/tower/tower14+1.c","east",
  "/players/saber/tower/tower14+2","down",
           });
    call_out("check",60);
} 

init(){
 ::init();
  add_action("search","search");
add_action("east","east");
}

east() {
if (call_other(this_player(), "query_level", 0) < 20) {
 write("There is too much broken furniture in the way.\n");
 say(tp+" tries to move east, but is blocked by the broken furniture.\n");
 return 1;   }
write("You manage to wiggle through the broken furniture...\n");
say(tp+" leaves east.\n");
call_other(this_player(), "move_player",
"east#players/saber/tower/tower14+1.c");
 return 1;    }

search() {
if (search_count == 2)
{
search_count = search_count + 1;
 write("You find a small gem on one of the unconscious bodies.\n");
 say(tp+" searches the area.\n");
ob = clone_object("/players/saber/gems/amber.c");
transfer(ob,this_player());
return 1;
}
else
{
search_count = search_count + 1;
write("You don't find anything worth keeping.\n");
say (tp +" searches the area\n");
 return 1;  }
}


check()  
{

   string verte_id, verte_path;

   clone_count = -1;

   while(clone_count ++ < 5)
   {
     switch(clone_count)
     {
       case 0:
         verte_id = "saber_mercenary";
         verte_path = "merc";
         break;
       case 1:
         verte_id = "saber_orc";
         verte_path = "orc";
         break;
       case 2:
         verte_id = "saber_amazon";
         verte_path = "amazon";
         break;
       case 3:
         verte_id = "saber_thief";
         verte_path = "thief";
         break;
       case 4:
         verte_id = "saber_barbarian";
         verte_path = "barbarian";
         break;
     }

     if(!OB) STORE_ROOM->load_me();
    if(!present(verte_id) && !present(verte_id, OB))
       move_object(clone_object("/players/saber/monsters/" + verte_path),
            "/players/saber/tower/tower14+1");
    }

    call_out("check", 60);
}
