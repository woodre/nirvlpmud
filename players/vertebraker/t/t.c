#include "/players/vertebraker/ansi.h"

#define O_MARKER HIR + "O" + NORM
#define X_MARKER HIB + "X" + NORM

mapping Board, Combos;
int turns;
object o, x;
string turn;

void
clean_me_hoe()
{
    Board = ([ 1 : "1", 2 : "2", 3 : "3", 4 : "4", 5 : "5",
               6 : "6", 7 : "7", 8 : "8", 9 : "9" ]);
    o = 0;
    x = 0;
    turns = 0;
    turn = 0;
    if(environment())
      tell_room(environment(), "TicTacToe Resetting.\n");
}

void
reset(int arg)
{
    if(arg) return;

    clean_me_hoe();

    Combos = ([ 1 : ({ ({ 2, 3 }), ({ 4, 7 }), ({ 5, 9 }) }),
                2 : ({ ({ 1, 3 }), ({ 5, 8 }) }),
                3 : ({ ({ 2, 1 }), ({ 5, 7 }), ({ 6, 9 }) }),
                4 : ({ ({ 1, 7 }), ({ 5, 6 }) }),
                5 : ({ ({ 1, 9 }), ({ 2, 8 }), ({ 3, 7 }),
                       ({ 4, 6 }), }),
                6 : ({ ({ 3, 9 }), ({ 4, 5 }) }),
                7 : ({ ({ 1, 4 }), ({ 8, 9 }), ({ 5, 3 }) }),
                8 : ({ ({ 2, 5 }), ({ 7, 9 }) }),
                9 : ({ ({ 7, 8 }), ({ 5, 1 }), ({ 6, 3 }) }) ]);
}

status
id(string str)
{
    return str == "game" || str == "tic-tac-toe" || str == "tictactoe" || str == "TicTacToe";
}

void
tell_o(string str)
{
    if(o) tell_object(o, str);
}

void
tell_x(string str)
{
    if(x) tell_object(x, str);
}

string
short()
{
    return "A game of " + HIR + "T" + NORM + "ic" + HIB + "T" + NORM + "ac" + HIY + "T" + NORM + "oe";
}

mapping
get_map()
{
    return Board;
}

string
show_board()
{
    return ("\n\
\t" + BOLD + "|" + NORM + Board[1] + BOLD + "|" + NORM 
+ Board[2] + BOLD + "|" + NORM + Board[3] + BOLD + "|\n\
\t|" + NORM + Board[4] + BOLD + "|" + NORM + Board[5] + BOLD + 
"|" + NORM + Board[6] + BOLD + "|\n\
\t|" + NORM + Board[7] + BOLD + "|" + NORM + Board[8] + BOLD +
 "|" + NORM + Board[9] + BOLD + "|\n\n" + NORM);
}

void
long()
{
    if(x) write("\tX's: " + (string)x->query_name() + "\n");
    else write("Nobody is playing X's.\n");
    if(o) write("\tO's: " + (string)o->query_name() + "\n");
    else write("Nobody is playing O's.\n");
    write(show_board());
    if(!turn)
      write("Anybody can start playing first.\n");
    else
      write("It's " + turn + "'s turn.\n");
    write("'forfeit' is for wimps.\n");
    if(!x) write("You can 'x #' to start playing.\n");
    if(!o) write("You can 'o #' to start playing.\n");
    write("\n\tMail Vertebraker with any suggestions.\n");
}

void
init()
{
    add_action("cmd_forfeit", "forfeit");
    add_action("cmd_x", "x");
    add_action("cmd_o", "o");
    add_action("cmd_x", "X");
    add_action("cmd_o", "O");
}

status
compute_cross(int space)
{
    int i, j, s, t;
    mixed *data, *foo;

    s = sizeof(data = Combos[space]);
    while(s --)
    {
      foo = data[s..s];
      t = sizeof(foo);
      while(t --)
     {
        if(Board[foo[t][0]] == Board[foo[t][1]] &&
           Board[foo[t][0]] == Board[space])
          return 1;
      }
    }
    turns ++;
    return 0;
}

void
announce_winner(object ob, int flag)
{
    if(ob == x)
    {
      if(flag)
        tell_object(x, (string)o->query_name() + " forfeits.\n");
      tell_object(x, BOLD + "\n\t\tYOU WIN!\n\n" + NORM);
      tell_object(o, BOLD + "\n\t\tYOU LOSE!\n\n" + NORM);
    }
    else
    {
      if(flag)
        tell_object(o, (string)x->query_name() + " forfeits.\n");
      tell_object(o, BOLD + "\n\t\tYOU WIN!\n\n" + NORM);
      tell_object(x, "\n\t\tYOU LOSE!\n\n");
    }

    clean_me_hoe();
}


void
show_board_to_both()
{
    if(o)
      tell_object(o, show_board());
    if(x)
      tell_object(x, show_board());
}

status
am_i_alone()
{
    object ob;

    ob = first_inventory(environment(this_player()));
    while(ob)
    {
      if((status)ob->is_player() && (ob != this_player())) return 0;
      ob = next_inventory(ob);
    }

    return 1;
}

status
cmd_x(string str)
{
    int z;

    if(!str)
    {
      notify_fail("\
Put an x where?\n");
      return 0;
    }

    if(!(z = atoi(str)) || z < 1 || z > 9)
    {
      notify_fail("\
You can't put an X there.\n\
Dork.\n");
      return 0;
    }

    if(!x)
    {
      if(am_i_alone())
      {
        notify_fail("You're the only one here!\n");
        return 0;
      }
      x = this_player();
      say((string)x->query_name() + " starts playing tic-tac-toe.\n");
      tell_o((string)x->query_name() + " starts playin' X's.\n");
    }

    else if(x != this_player())
    {
      notify_fail("\
Duh.  You ain't the X guy.\n");
      return 0;
    }

    if(turn && turn != "X")
    {
      notify_fail("\
*fbog*  How about waitin' yer turn there, Tex?\n");
      return 0; 
    }

    if(Board[z] == X_MARKER)
    {
      notify_fail("\
You fuggin' moron.\n\
You already have an X there.\n");
      return 0;
    }

    if(Board[z] == O_MARKER)
    {
      notify_fail("\
Rule #1 to tic-tac-toe:\n\
\tYou can't put a damn X where an O is!\n");
      return 0;
    }

    Board[z] = X_MARKER;
    write("You slap a big ol' " + X_MARKER + " down.\n");
    tell_o((string)this_player()->query_name() + " \
slaps an X into the " + z + " slot.\n"); 
    turn = "O";

    show_board_to_both();

    if(compute_cross(z))
    {
      announce_winner(this_player(), 0);
      return 1;
    }

    if(turns == 9)
    {
      tell_o("\nStalemate.\nGame over.\n");
      tell_x("\nStalemate.\nGame over.\n");
      clean_me_hoe();
      return 1;
    }
    while(remove_call_out("turn_up") != -1);
    call_out("turn_up", 60);

    return 1;
}

void
turn_up()
{
    if(turn == "X")
      if(o && x)
      {
        tell_o((string)x->query_name() + " \
has taken far too long for " + possessive(x) + " turn.\n");
        tell_x("You have taken far too long for your turn.\n");
        announce_winner(o, 0);
        return;
      }
    if(turn == "O")
      if(o && x)
      {
        tell_x((string)o->query_name() + " \
has taken far too long for " + possessive(o) + " turn.\n");
        tell_o("You have taken far too long for your turn.\n");
        announce_winner(x, 0);
        return;
      }
}


status
cmd_o(string str)
{
    int z;

    if(!str)
    {
      notify_fail("\
Put an o where?\n");
      return 0;
    }

   if(!(z = atoi(str)) || z < 1 || z > 9)
    {
      notify_fail("\
You can't put an O there.\n\
Dork.\n");
      return 0;
    }

    if(!o)
    {
      if(am_i_alone())
      {
        notify_fail("You're the only one here!\n");
        return 0;
      }
      o = this_player();
      say((string)o->query_name() + " starts playing tic-tac-toe.\n");
      tell_x((string)o->query_name() + " starts playin' O's.\n");
    }

    else if(o != this_player())
    {
      notify_fail("\
Duh.  You ain't the O guy.\n");
      return 0;
    }

    if(turn && turn != "O")
    {
      notify_fail("\
*fbog*  How about waitin' yer turn there, Tex?\n");
      return 0; 
    }

    if(Board[z] == O_MARKER)
    {
      notify_fail("\
You fuggin' moron.\n\
You already have an O there.\n");
      return 0;
    }

    if(Board[z] == X_MARKER)
    {
      notify_fail("\
Rule #2 to tic-tac-toe:\n\
\tYou can't put a damn O where an X is!\n");
      return 0;
    }

    Board[z] = O_MARKER;
    write("You slap a big ol' " + O_MARKER + " down.\n");
    tell_x((string)this_player()->query_name() + " \
slaps an O into the " + z + " slot.\n"); 
    turn = "X";

    show_board_to_both();

    if(compute_cross(z))
    {
      announce_winner(this_player(), 0);
      return 1;
    }
    if(turns == 9)
    {
      tell_o("\nStalemate.\nGame over.\n");
      tell_x("\nStalemate.\nGame over.\n");
      clean_me_hoe();
      return 1;
    }
    while(remove_call_out("turn_up") != -1);
    call_out("turn_up", 60);

    return 1;
}

status
cmd_forfeit()
{
    if(!x || !o)
    {
      notify_fail("Uh, nothing to forfeit there buddy.\n");
      return 0;
    }
    if(x == this_player())
    {
      write("\t\tWimp.\n");
      announce_winner(o, 1);
      return 1;
    }
    if(o == this_player())
    {
      write("\t\tOh blah.\n");
      announce_winner(x, 1);
      return 1;
    }
    return 0;
}

status
get()
{
    return 0;

}
