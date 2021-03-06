inherit "room/room";
/*
 * some room stuff - base ideas from Balowski@Nirvana
 * manipulated and pretty much all fudged up by Pavlik
 * Bal changed everything.  I'm still included the basic
 * room/room, just adding some other stuff.
 */

#undef SPARRING                 /* needed 1 out of 10000 */

string            *Items;
string            *Sounds;
string            *Smells;
string            *Search;
private string    *Chats;
private string    *Mons;
private int       ChatFreq, MonFreq;
private int       Players;
private int       MaxMon;


/*
 * init is called everytime a player enters the room
 */
void init()
{
  ::init();

#ifdef SPARRING

    if (this_player()->is_player() && (int) this_player()->query_pl_k() < 2) {
    this_player()->move_player("X#/room/void");
    }
#endif
    if (query_property("fight area")) {
	this_player()->set_fight_area();
    }
  if(this_player()->is_player()){
    Players++;
    add_action("move","north");
    add_action("move","south");
    add_action("move","east");
    add_action("move","west");
    add_action("move","up");
    add_action("move","down");

    add_action("room_listen","listen");
    add_action("room_smell","smell");
    add_action("room_search","search");
    add_action("area_yell","yell");

    if((string) this_object()->can_follow() == "NO")
      this_player()->clear_follow();
  }
    if (Players == 1) {
	if (ChatFreq) call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));
   if (MonFreq) call_out("Generate_Monster", (MonFreq >> 1) + random(MonFreq));
    }

}

/*
 * Applied by the driver whenever an object if removed from here
 */
void
exit(object ob)
{
    if (ob->is_player()) {
   Players--;
   if( (!Players) || (Players < 1) ){
       remove_call_out("ev_chat");
       remove_call_out("Generate_Monster");
       if(this_object()->random_room())
         this_object()->reset();
   }
	if (query_property("fight area"))
	    ob->clear_fight_area();     /* not really necessary.. */
#ifdef SPARRING
	if (query_property("spar area"))
	    ob->rm_spar();              /* removes sparring flag, if set */
#endif
    }
}

/*
 * Rewriting the move function so that player gets a
 * message when an invalid direction is tried.
 */
move(str) {
    int i;

    i = 1;
    while(i < sizeof(dest_dir)) {
        if (query_verb() == dest_dir[i]) {
            this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
            return 1;
        }
      if((dest_dir[i]=="random") && (random(33) > 21)){
           this_player()->move_player(query_verb()+"#"+dest_dir[i-1]);
           return 1;
      }
        i += 2;
    }
  write("You cannot go that way.\n");
  return 1;
}

/*
 * Rewriting of the Long function to get rid of those
 * obvious exits stuff.
 */
long(str) {
  int i;
  if(set_light(0) == 0){
    write("It is too dark to see anything.\n");
    return;
  }
  if(!str) {
    write(long_desc);
    write("\n");
  }
  if(!Items)
    return;
  i = 0;
/*
  while(i < sizeof(Items)) {
    if(Items[i] == str) {
      write(Items[i+1]);
      return;
    }
    i += 2;
  }
*/
}

/*
 * Also have to redo the short so that the obvious exits don't show
 * up there either.
 */
short() {
  if(set_light(0))
    return short_desc;
  else
    return "Dark room";
}

/*
 * Chat stuff.. quite like monsters
 */
void load_chats(string *strs)
{
    if (!Chats)	Chats = strs;
    else Chats += strs;
}

void load_chat(string str) { load_chats(({ str }));}

/*
 * Remove a previously loaded chat string.
 * First occurrence matching 'str' will be removed from array
 */
void remove_chat(string str)
{
    if (Chats) Chats -= ({ str });
}

void ev_chat()
{
    /* I let this call out run, even if no chats available */
    /* add/remove chats can then be changed at any point in time */
   /* stop the chatting if noone is here to listen */
   if (!Players) return;
    if (Chats) tell_room(this_object(), Chats[random(sizeof(Chats))]);
    if (ChatFreq) call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));
}

/* set the frequency for the chats/noise/atmosphere */
void set_chat_frequency(int x) { ChatFreq = x;}
void set_chat_chance(int x) { set_chat_frequency((x > 0) ? 200/x : 0);}

/*
 * Generate Random Monsters
 */
void Generate_Monster()
{
   /* stop making monsters if noone is here to play with them */
    if( (!Players) || (Players < 1) ) return;
   if (Mons) move_object(clone_object(Mons[random(sizeof(Mons))]), this_object());
   if (MonFreq) call_out("Generate_Monster", (MonFreq >> 1) + random(MonFreq));
}

/* set frequency for monster generator */
void set_monster_frequency(int x) { MonFreq = x; }

/*
 * Add to list of random monster generation
 */
void load_monsters(string *strs)
{
    if (!Mons)	Mons = strs;
    else Mons += strs;
}

void load_monster(string str) { load_monsters(({ str }));}

void remove_monster(string str)
{
    if (Mons) Mons -= ({ str });
}

/*
 * Hearing Atmosphere.
 * you can add/change/remove atmosphere attributes
 * on the fly
 */
room_listen(str) {
  int i;

  if(!Sounds){
    write("You don't hear anything special.\n");
    return 1;
  }

  if(!str) str = "default";

  while(i<sizeof(Sounds)){
    if(Sounds[i] == str){
      tell_object(this_player(), Sounds[i+1]);
      return 1;
    }
    i+=2;
  }
  tell_object(this_player(), "You don't hear anything special.\n");
  return 1;
}

/*
 * Smell Atmosphere
 * you can add/change/remove atmosphere attributes
 * on the fly
 */
room_smell(str) {
  int i;

  if(!Smells){
    write("You don't smell anything special.\n");
    return 1;
  }

  if(!str) str = "default";

  while(i<sizeof(Smells)){
    if(Smells[i] == str){
      tell_object(this_player(), Smells[i+1]);
      return 1;
    }
    i+=2;
  }
  tell_object(this_player(), "You don't smell anything special.\n");
  return 1;
}

/*
 * Search Attributes
 * you can add/change/remove atmosphere attributes
 * on the fly
 */
room_search(str) {
  int i;

  if(!Search){
    write("You don't find anything special.\n");
    return 1;
  }

  if(!str) str = "default";

  while(i<sizeof(Search)){
    if(Search[i] == str){
      tell_object(this_player(), Search[i+1]);
      return 1;
    }
    i+=2;
  }
  tell_object(this_player(), "You don't find anything special.\n");
  return 1;
}

/*
 * Items - different from the standard room/room items
 * because these can be added/changed/removed on the fly
 */
id(str) {
  int i;

  if(!Items) return;

  if(str == "pavall"){
    while(i < sizeof(Items)){
      write(i+") "+Items[i]+"\n");
      i++;
    }
    return 1;
  }


  while(i < sizeof(Items)){
    if(Items[i] == str){
      tell_object(this_player(), Items[i+1]);
      return 1;
    }
    i += 2;
  }
  return 0;
}

/*
 * Change Atmosphere attribute.
 * changes the description for an atmosphere
 */
change_atmo(typ, str, chge){
  string *atmo;
  int i;

  if(!typ) return;

  if(typ == "sound") atmo = Sounds;
  else if(typ == "smell") atmo = Smells;
  else if(typ == "search") atmo = Search;
  else if(typ == "item") atmo = Items;

  if(!atmo) return;

  while(i<sizeof(atmo)){
    if(atmo[i] == str)
      atmo[i+1] = chge;
    i+=2;
  }
  if(typ == "sound") Sounds = atmo;
  else if(typ == "smell") Smells = atmo;
  else if(typ == "search") Search = atmo;
  else if(typ == "item") Items = atmo;

  return 1;
}

/*
 * Remove atmosphere
 * completely removes the atmosphere
 */
remove_atmo(typ, str){
  string *atmo, str2;
  int i;

  if(typ == "sound") atmo = Sounds;
  else if(typ == "smell") atmo = Smells;
  else if(typ == "search") atmo = Search;
  else if(typ == "item") atmo = Items;

  if(!atmo) return;

  while(i<sizeof(atmo)){
    if(atmo[i] == str)
      str2 = atmo[i+1];
    i+=2;
  }
  atmo -= ({str});
  atmo -= ({str2});

  if(typ == "sound") Sounds = atmo;
  else if(typ == "smell") Smells = atmo;
  else if(typ == "search") Search = atmo;
  else if(typ == "item") Items = atmo;
}

/*
 * Add Atmopshere
 * add a new atmopshere to the room
 */
add_atmo(typ, *str1, *str2){
  string *atmo;
  if(!typ) return;
  if(typ == "sound") atmo = Sounds;
  else if(typ == "smell") atmo = Smells;
  else if(typ == "search") atmo = Search;
  else if(typ == "item") atmo = Items;

  if(!atmo){
    atmo = str1;
    atmo += str2;
  }
  else {
    atmo += str1;
    atmo += str2;
  }
  if(typ == "sound") Sounds = atmo;
  else if(typ == "smell") Smells = atmo;
  else if(typ == "search") Search = atmo;
  else if(typ == "item") Items = atmo;
  return 1;
}

query_players(){ return Players; }

area_yell(str){
  if(environment(this_player())->query_area()=="sewers"){
    ("players/pavlik/tiny/enter.c")->sewer_yell(str);
    return 1;
  }
  write("You don't think that will do any good.\n");
  return 1;
}


/*
 * This function returns the level of the higest leveled player
 * in the room.  This is primary for monsters to auto-adjust
 * to the players level.
 */
get_highest_level(){
  object obj;
  int i, lvl;

  obj = all_inventory(this_object());
  for(i=0; i<sizeof(obj); i++){
    if(obj[i]->is_player())
      if(obj[i]->query_level() >= lvl)
        lvl = obj[i]->query_level();
  }

  return lvl;
}
