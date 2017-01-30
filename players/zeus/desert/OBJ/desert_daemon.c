/* Inculta Creperum [dark desert] Monster and Quest Daemon */

string *enpc, *hnpc, *area;

load_npcs()
{
  object where;
  object npc;
  int easy, hard, a, size;
  size = sizeof(area);
  for(a = 0; a < size; a++)
  {
    if (!(where = find_object(area[a])) )
      continue;
    if (sizeof(all_inventory(where)))
      return;
  }
  easy = 5 + random(12);
  hard = 3 + random(5);
  for(a = 0; a < easy; a++)  /* easy NPCs */
  {
    if((npc = clone_object(enpc[random(sizeof(enpc))])))
      move_object(npc, area[random(sizeof(area))]);
    else
      write_file("/players/zeus/log/desert", ctime(time())+" easy error\n");
  }
  for(a = 0; a < hard; a++)  /* hard NPCs */
  {
    if((npc = clone_object(hnpc[random(sizeof(hnpc))])))
      move_object(npc, area[random(sizeof(area))]);
    else
      write_file("/players/zeus/log/desert", ctime(time())+" hard error\n");
  }
                             /* lord NPC */
  npc = clone_object("/players/zeus/desert/NPC/brute_lord.c");
  move_object(npc, area[8]);
                             /* quest items */
  a = 1;
  while(a < 4)
  {
    easy = random(sizeof(area));              /* pick a random room      */
    if(sizeof(all_inventory(area[easy])) > 0  /* if an npc was put here  */
      && !area[easy]->query_wand_piece())     /* and a wand piece wasn't */
    {
      area[easy]->set_wand_piece(a);          /* place a wand piece here */
      a++;
    }
  }
}

/* if the area is loaded, what rooms have wand pieces in them */
void show_what_rooms_have_wand_pieces(object me){
  int a, b, size;
  if(!me) return;
  size = sizeof(area);
  tell_object(me, "Wand Piece Locations:\n");
  for(a = 0; a < size; a++) /* all rooms */
  {
    if((b = (int)area[a]->query_wand_piece()))
      tell_object(me, " Room: "+area[a]+" has wand piece "+b+".\n");
  }
}

/* return 0 if area can't reset-- player is in it         */
/* dest all rooms */
int reset_area(){
  int a, b, size, siz;
  string r;
  object *hmm, *them;
  them = users();
  size = sizeof(them);
  for(a = 0; a < size; a++)
  {
    if(environment(them[a]) && 
      sscanf(file_name(environment(them[a])), "/players/zeus/desert/r/%s", r))
      return 0;
  }
  size = sizeof(area);
  for(a = 0; a < size; a++)
#ifndef __LDMUD__ /* Rumplemintz */
    destruct(area[a]);
#else
    if (find_object(area[a]))
      destruct(find_object(area[a]));
#endif
  return 1;
}

void reset(mixed arg){

  area = ({
    "players/zeus/desert/r/ec1",
    "players/zeus/desert/r/ec2",
    "players/zeus/desert/r/ec3",
/*  "players/zeus/desert/r/ec4",  */
    "players/zeus/desert/r/ec5",
    "players/zeus/desert/r/ec6",
    "players/zeus/desert/r/ec7",
    "players/zeus/desert/r/ec8",
    "players/zeus/desert/r/ec9",
    "players/zeus/desert/r/ec10",
    "players/zeus/desert/r/ec11",
    "players/zeus/desert/r/ec12",
    "players/zeus/desert/r/ec13",
    "players/zeus/desert/r/ec14",
    "players/zeus/desert/r/ec15",
    "players/zeus/desert/r/ec16",
    "players/zeus/desert/r/ec17",
    "players/zeus/desert/r/ec18",
    "players/zeus/desert/r/ec19",
    "players/zeus/desert/r/ec20",
    "players/zeus/desert/r/ec21",
    "players/zeus/desert/r/ec22",
  });

  enpc = ({ 
    "/players/zeus/desert/NPC/digger.c",
    "/players/zeus/desert/NPC/hunter.c",
    "/players/zeus/desert/NPC/nomad.c",
    "/players/zeus/desert/NPC/peasant.c",
    "/players/zeus/desert/NPC/scorpion.c",
  });

  hnpc = ({
    "/players/zeus/desert/NPC/brute.c",
    "/players/zeus/desert/NPC/desert_bat.c",
    "/players/zeus/desert/NPC/fiend.c",
    "/players/zeus/desert/NPC/fiend_large.c",
    "/players/zeus/desert/NPC/snake.c",
    "/players/zeus/desert/NPC/spirit.c",
  });
}
/*
    "item = clone_object("players/eurale/Fiend/OBJ/tea.c");
  value = 2400;
  m = 1; }

if(m) {
if(tp->query_money() < value) {
  write("You'll need more coins to purchase that!\n");
  return 1; }

if(!call_other(tp,"add_weight",call_other(item,"query_weight"))) {
  write("You can't carry this item with that load...\n");
  return 1; }

tp->add_money(-value);
move_object(item,tp);
write("You order a "+BOLD+str+NORM+" to go!
*/
