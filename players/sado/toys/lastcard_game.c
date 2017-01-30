object drawpile;
object discardpile;

array players;

int turn_order;
int current_player;

reset(arg)
{
  if(arg) return;
  drawpile = discardpile = 0;
  turn_order = current_player = 0;
}

short()
{
   return "A card table for playing 'last card'";
}

long()
{
  if(turn_order == 0)
  {
    write("To start a game, type 'play <name1>...<nameX>' where 1 <= X <= 4\n");
  }
}

id(str)
{
  return "lastcard" == str;
}

init()
{
  add_action("start","start");
  add_action("draw","draw");
  add_action("play","play");
  add_action("abort","abort");
  add_action("reshuffle","reshuffle");
}

reshuffle(str)
{
  object card;
  array a;
  int i;
  if(turn_order == 0)
  {
    write("There's no game in progress.\n");
    return 1;
  }

  card = discardpile->query_topcard();
  a = all_inventory(discardpile);
  for(i=0; i<sizeof(a); i++) move_object(a[i],drawpile);
  discardpile->discard(card);
  drawpile->shuffle();
  drawpile->shuffle();
  drawpile->shuffle();
  drawpile->shuffle();

  write("You reshuffle the discarded cards and replace them as the draw pile.\n");
  say(this_player()->query_name() + " takes the discard pile and reshuffles it.\n", this_player());

  return 1;
}

abort(str)
{
  if(turn_order == 0)
  {
    write("There's no game in progress.\n");
    return 1;
  }

  remove_call_out("turn_reminder");
  say("The game has been cancelled\n");
  turn_order = current_player = 0;
  deallocate(players);
  return 1;
}

draw(str)
{
  object card;
  if(turn_order == 0)
  {
    write("There's no game in progress.\n");
    return 1;
  }

  if(this_player() != players[current_player])
  {
    write("It's not your turn dumfuk!\n");
    return 1;
  }

  card = drawpile->topCard();
  move_object(card,present("hand",this_player()));
  write("You draw the " + card->short() + "\n");
  say(this_player()->query_name() + " draws a card", this_player());
  return 1;
}

play(str)
{
  int c;
  object card;

  if(turn_order == 0)
  {
    write("There's no game in progress.\n");
    return 1;
  }

  if(this_player() != players[current_player])
  {
    write("It's not your turn dumfuk!\n");
    return 1;
  }

  sscanf(str,"%d",c);

  card = present("hand",this_player())->getCard(c);
  write("You play the " + card->short() + "\n");
  say(this_player()->query_name() + " plays the " + card->short() + "\n", this_player());
  discardpile->discard(card);

  next_turn();

  return 1;
}

start(str)
{
  array player_strs;
  int i;

  if(turn_order != 0)
  {
    write("There's already a game in progress.  Sit and watch.\n");
    return 1;
  }

  player_strs = explode(str," ");
  if(sizeof(player_strs) > 4)
  {
    write("Homey don't play dat!  Try 4 or fewer players.\n");
    return 1;
  }

  players = allocate(sizeof(player_strs));

  for(i=0; i<sizeof(player_strs); i++)
  {
    players[i] = find_player(player_strs[i]);
    if(!players[i] || environment(players[i])!=environment(this_object()))
    {
      deallocate(players);
      write("Try picking some players in this room dumbass.\n");
      return 1;
    }
  }

  for(i=0; i<sizeof(players); i++)
  {
    move_object(clone_object("/players/sado/toys/hand.c"),players[i]);
  }

  drawpile = clone_object("/players/sado/toys/deck.c");
  move_object(drawpile,environment(this_object()));
  drawpile->shuffle();
  drawpile->shuffle();
  drawpile->shuffle();
  drawpile->shuffle();

  discardpile = clone_object("/players/sado/toys/pile.c");
  move_object(discardpile,environment(this_object()));

  write("You deal to each player and turn a card up on the pile.\n");
  say(this_player()->query_name() + " deals to each player and turns up a card onto the pile.\n", this_player());

  deal();

  turn_order = 1;
  current_player = 0;

  next_turn();

  return 1;
}

deal()
{
  object dest;
  int i,j;
  for(j=0; j<5; j++)
  {
    for(i=0; i<sizeof(players); i++)
    {
      dest = present("hand",players[i]);
      move_object(drawpile->topCard(),dest);
    }
  }

  discardpile->discard(drawpile->topCard());
}

next_turn()
{
  current_player += turn_order;
  if(current_player >= sizeof(players)) current_player = 0;
  else if(current_player < 0) current_player = sizeof(players)-1;

  tell_room(environment(this_object()),"It is " + players[current_player]->query_name() + "'s turn!\n");
  remove_call_out("turn_reminder");
  call_out("turn_reminder",60);
}

turn_reminder()
{
  tell_room(environment(this_object()),"Someone please tell " + players[current_player]->query_name() + " to play!\n");
}
