#include "path.h"
/* this is the main monopoly file.  it keeps the board array and game info,
 * as well as bin functions and it is also the entrance to the game.
 *
 * I really wish I had made a separate game object for each game.  My
 * original reasons for not doing this no longer apply, and it is an
 * unbelievable *pain* having it this way.  For one thing, you can't
 * update the main room without destroying all the games.  *sigh*
 * *slaps forehead*
 * Not enough time to change it now, though
 */

/*
 * Platforms
 * ---------
 * 
 * This code has been ported to the following drivers: (With a basic mudlib)
 * 
 * 2.4.5, 3.1.2, 3.2 (amylaar), 3.12 -DR, 3.12 -CD
 * 
 * Author
 * ------
 * 
 * This code was written by David Ljung as Jubal E. Harshaw (The LPJubal)
 *                          email: dxl@fc.hp.com
 * 
 * Copyright
 * ---------
 * 
 * This code is Copyright 1993, David Ljung
 * 
 * It may not be rewritten without consent of the author, except for the sake
 * of fixing bugs or porting to new platforms.
 * 
 * It may be freely redistributed, but it may not be sold in any form.
 */

inherit "room/room";

object *games;  /* an array of games */
                 /* a game is an array of player objects */
                 /* except the first element which is the name */
string *squares;
int *monopolies;

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The entrance to Monopoly.";
  long_desc=short_desc
    +"\nThe entrance to Jubal's Monopoly.\n"
    +"To start a new game, type 'new <name>' (name the game :-)\n"
    +"To join a current game, type 'join <name>'\n"
    +"To list current games, type 'games'\n"
    +"You can enter the board by typing west\n"
    +"You can listen in on games by going to the bleachers, up.\n"
    +"  Monopoly is copyright Parker Brothers Inc.\n";

  no_castle_flag = 0;
  dest_dir =
     ({
     ENTER_FROM,EXIT_DIR,
     PATH+"/bleachers","up",
     PATH+"/_go","east",
     });
  squares=SQUARES;
  monopolies=MONOPOLIES;
  games=({});
}

square_file(i) {
  i=i%SQSZ;
  if(i<0) i=SQSZ+i;
  return PATH+"/_"+squares[i];
}

num_square(string xy){ 
  string s;
  sscanf(xy, "%s_%s", s, xy);
  return member_array(xy,squares);
}

num_monopoly(i) {
  i=i%SQSZ;
  if(i<0) i=SQSZ+i;
  return monopolies[i];
}

/* return array of all other members of monopoly for square i */
monopoly(i) {
  int *arr,j,m;

  arr=({});
  m=monopolies[i];
  for(j=0;j<SQSZ;j++)
    if(monopolies[j]==m && j!=i) arr+=({j});
  return arr;
}

query_players(gname) {
  int i;

  if((i=gamenum(gname))==-1) return !write(gname+" doesn't exist!\n");
  if(sizeof(games[i])<2) return !write(gname+" has no players!\n");
  return games[i][1..sizeof(games[i])-1];
/*  can't use extract on arrays on older drivers :(
  return extract(games[i],1);
*/
}

/* returns mobj */
query_owner(square,gname) {
  int i,h;
  object *players;

  if(intp(square)) h=square;
  else h=num_square(square);
  if(h==-1)
    WRITE("That square doesn't exist: "+square+"\n");
  players=query_players(gname);
  for(i=0;i<sizeof(players);i++)
    if(players[i]->query_house(h)!=UNOWNED) return players[i];
  return 0;
}


init() {
  ::init();

  if(!present(this_player())) return;
  add_action("join","join");
  add_action("new","new");
  add_action("show_games","games");
}

new(arg) {
  string name;

  if(!arg || sscanf(arg,"%s",name)!=1)
    FAIL("Usage: new <name>   where name is the game's name (you choose).\n");
  if(present("mobj",TP)) FAIL("You are already playing!\n");
  if(gamenum(name)!=-1) FAIL("That game already exists!\n");
  write("You start up a monopoly game called: "+name+"\n");
  say(TP->query_name()+" starts up a game called: "+name+"\n");
  games+=({({name})});
  return join(name);
}

join(arg) {
  string name;
  int i;
  object mobj;

  if(!arg || sscanf(arg,"%s",name)!=1)
    FAIL("Usage: join <name>   where name is the game's name.\n");
  if(present("mobj",TP)) FAIL("You are already playing!\n");
  if((i=gamenum(name))==-1)
    FAIL("You cannot join a game that doesn't exist.\n");
  write("You join the monopoly game "+name+" and move to Go.\n");
  write("Your brief mode is "+(TP->query_brief()?"on":"off")+"\n");
  write("Type \"mhelp monopoly\" or \"mhelp rules\" for help\n");
  say(TP->query_name()+" joins the game: "+name+".\n");
/*
  gameshout(TP->query_name()+" joins the game.\n",i);
*/
  mobj=clone_object(MOBJ);
  move_object(mobj,TP); 
  mobj->add_bin();
  mobj->start_game(name,TP);
  games[i]+=({mobj});
  return 1;
}

remove_player(object who) {
  object mobj;
  int i,index;
  string gamename;

  if(!who) return 0;
  if(!(mobj=present("mobj",who)))
    return !tell_object(who,"You aren't playing.\n");
  if((i=gamenum(mobj->query_gamename()))==-1) {
    tell_object(who,"That game doesn't exist anymore!\n");
    return 1;
  }
  games[i]-=({mobj});  /* don't need to check if they are in the array */
  if(sizeof(games[i])==2 && games[i][1]) winner(games[i][1]);
  if(sizeof(games[i])<2) {
    gameshout("This game has ended -- "+mobj->query_cname()
              +" has left the game.\n",i);
    games-=({games[i]});
  }
  else gameshout(mobj->query_cname()+" leaves the game.\n",i);
  return 1;
}

winner(ob) {
  if(ob->query_turn()<10) return;
  tell_object(ob->query_player(),"YOU WIN AT MONOPOLY!\n");
  log_file(LOGFILE,ob->query_cname()+" wins with (total worth) "
                         +MS+ob->query_worth()+"\n");
}

/* this also cleans up the game array by checking for all players */
gameshout(str,which) {
  object blch;
  int i,num;

  if(stringp(which)) num=gamenum(which);
  if(intp(which)) num=which;
  if(num<0) WRITE("Couldn't find game: "+which+"\n");
  for(i=1;games[num] && i<sizeof(games[num]);i++)
    if(games[num][i] && games[num][i]->query_player()) {
      if(games[num][i]->query_player()!=TP)
        tell_object(games[num][i]->query_player(),str);
    } else {
      games[num]-=({games[num][i]});
      if(sizeof(games[num])<2) {
        games-=({games[num]});
        return;
      }
    }
  blch=find_object(PATH+"/bleachers");
  if(blch) tell_room(blch,games[num][0]+": "+str);
}

gamenum(name) {
  int i;

  i=0;
  while(i<sizeof(games) && sizeof(games[i]) && games[i][0]!=name) i++;
  if(!(i<sizeof(games) && sizeof(games[i]))) return -1;
  return i;
}

show_games() {
  int i,j;

  if(sizeof(games)==0) WRITE("There are no current games.\n");
  write("  Game        Players\n");
  for(i=0;i<sizeof(games);i++) {
    write(PAD(games[i][0],12));
    for(j=1;j<sizeof(games[i]);j++)
      write(PAD(games[i][j]->query_cname(),14));
    write("\n");
  }
  return 1;
}

/* utilities */

/* _pad:  for portability */
/* use " " for padchar not ' ' because of stupid types.. :-(  any ideas? */
_pad(str,len,padchar,dontcut) {
  int num,i,j,rtjust;

  if(!padchar) padchar=" ";
  if(len>0) {
    rtjust=0;
    num=len-strlen(str);
  } else {
    rtjust=1;
    num=-len-strlen(str);
  }
  if(num<=0)
    if(!dontcut)
      if(rtjust) return extract(str,strlen(str)+len);
      else return extract(str,0,len-1);
    else return str;
  if(rtjust)
    for(i=0;i<num;i++) str=padchar+str;
  else
    for(i=0;i<num;i++) str=str+padchar;
  return str;
}

