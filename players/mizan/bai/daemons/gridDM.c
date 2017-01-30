/*****************************************************************************
 *      File:                   gridDM.c
 *      Function:               Responsible for common grid related functions
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "../definitions.h"
#include "/obj/ansi.h"

static int width, height;
static int viewport_width_radius, viewport_height_radius;
static string *numbers;

string short() { return "A server named (grid)"; }


void reset(int arg)
{

    width = 120;
    height = 60;

    viewport_width_radius = 6;
    viewport_height_radius = 5;

    if (!numbers)
    {
        numbers = ( {"no", "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine" });
    }

    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    call_other("/players/mizan/bai/daemons/gridboxDM.c", "???");
}


/*
 * This function is called when we render a map from ../core/room.c
 *
 *
 */
string render_map(int x, int y, int index, int cellrange)
{
    /* First we need to determine our window constraints. */
    int start_index;
    int effective_x;
    int effective_y;
    int effective_index;
    int player_index;
    int temp_index;
    int render_width;
    int render_height;
    int i;
    int j;
    int dest_x;
    int dest_y;
    int temp_1;
    int temp_2;
    int distance;

    string temp;
    string tempfile;
    string result;
    object ob;


    /*
    	result = "Maze dimensions: " + width + " x " + height + "\n";
    	result += "Received X:" + x + ", Y: " + y + "\n";
     */
    result = "    Visible terrain:\n\n";


    /* This is done in a few steps. Just by knowing our X and Y position we can derive
     * what the center of our screen should be relative to the whole map.
     */


    /* Calculating Y extent */
    /* This gives us the starting Y extent for our screen. */

    if (y < (viewport_height_radius - 1))
    {
        effective_y = (viewport_height_radius - 1);
    }
    else if (y > (height - viewport_height_radius))
    {
        effective_y = (height - viewport_height_radius);
    }
    else effective_y = y;


    /* Calculate our constraints towards the left(west)
    /* This gives us the starting X extent for our screen. */
    if (x < (viewport_width_radius - 1))
    {
        effective_x = (viewport_width_radius - 1);
    }
    else if (x > (width - viewport_width_radius))
    {
        effective_x = (width - viewport_width_radius);
    }
    else effective_x = x;


    /* Now that we have our starting point, we get its index number,
     * and in an orderly fashion we hit up the rooms in that list.
     * The responses we get back for what icon the room is, we present to the
     * player.
     */

    /*	result += "Effective X: " + effective_x + ", Effective Y: " + effective_y + "\n";*/

    effective_index = (width * effective_y) + effective_x;
    player_index = (width * y) + x;
    start_index = effective_index - (width * (viewport_height_radius - 1)) - (viewport_width_radius - 1);
    temp_index = start_index;
    render_width = (viewport_width_radius * 2) - 1;
    render_height = (viewport_height_radius * 2) - 1;

    /* this outer loop recurses vertically for each row to be rendered. */
    for (j = effective_y; j < (effective_y + render_height); j ++)
    {
        for (i = temp_index; i < (temp_index + render_width); i ++)
        {

            tempfile = "players/mizan/bai/CELLS/C" + i;

            /* write(tempfile + "\n"); */
            ob = find_object(tempfile);

            if (i == player_index)
            {
                result += " " + HBWHT + HIBLK + FLASH + "@" + NORM;
            }
            else if (ob)
            {
                /* we calculate our distance to this object. */
                dest_x = (int) ob->query_x();
                dest_y = (int) ob->query_y();

                /* distance formula, broken into chunks. We don't need to sqrt the final result */
                temp_1 = x - dest_x;
                temp_1 = temp_1 * temp_1;
                temp_2 = y - dest_y;
                temp_2 = temp_2 * temp_2;
                distance = temp_1 + temp_2;

                if(distance < (cellrange * cellrange))
	                temp = (string) ob->query_current_icon();
		else
			temp = GRY + "." + NORM;

		/* if we got a zero, the icon didn't load up right... we compensate with a red dot for now. */
		if(temp == 0) temp = RED + "." + NORM;

                result += " " + temp;
            }
            else result += " " + RED + "." + NORM;

        }


        /* increment our start index */
        temp_index += width;
        result += "\n";
    }
    return result;
}



/* This function is called whenever init() is triggered locally by the room.
 * It serves to mark whatever the "dominant" icon in the room is at the time.
 * The item which is set by this function is then called later by the function
 * render_map() in gridDM.c, which builds up a listing of what terrain types
 * are to be depicted in the top-down map. Shit, I really didn't make a whole
 * lot of sense explaining that, did I?
 */
void render_icon(object arg)
{
    object ob;
    string current_icon;



    /* if we are not inside this room, discard */
    if (!this_player()) return;
    if (this_player() &&
            environment(this_player()) &&
            (environment(this_player()) != arg)) return;

    ob = first_inventory(arg);

    /* certain properties of this cell will override whatever
      * is occupying it.
     */
    /* not supported yet
     * if(is_portal) return TERRAIN_DM->get_icon(10);
     */

    /* our current icon is our terrain icon, unless something below overrides it. */
    arg->set_current_icon(arg->query_terrain_icon());
    while (ob)
    {
        /* the order of operations is simple */
        if (ob->is_boss()) {
            arg->set_current_icon(BYEL + HIR + "*" + NORM);
            break;
        }
        else if (ob->is_miniboss()) {
            arg->set_current_icon(BYEL + RED + "*" + NORM);
            break;
        }
        else if (ob->is_player() && ob != this_player()) {
            arg->set_current_icon(BYEL + BLK + "@" + NORM);
            break;
        }

        else if (ob->is_vehicle()) {
            arg->set_current_icon(BYEL + HIW + "O" + NORM);
            break;
        }
        /*              else if(ob->is_player() && !ob->query_invis()) { current_icon = BYEL + HIC + "*" + NORM; break; } */
        /*              else if(ob->is_npc()) return TERRAIN_DM->get_icon(8); */
        else if (ob->is_exit_blocker()) {
            arg->set_current_icon(BYEL + RED + "*" + NORM);
            break;
        }
        else if (ob->query_value() > 100 || ob->is_money()) {
            arg->set_current_icon(BYEL + HIY + "*" + NORM);
            break;
        }
        ob = next_inventory(ob);
    }

}


/*
 * This is a crude function which loads up the 8 cells neighboring the
 * location we have been asked to work from.
 * What happens is that we give the player a 1-cell 'buffer' to navigate with
 * so that they aren't stumbling around completely blind in the maze.
 * Sometimes the rooms don't load up fast enough so their current icon will
 * return a '0'. That's okay because in the render_map function, I look for
 * these zeroes and replace them with the generic red dot until such time
 * that they do get to fully load.
 *
 */
void load_neighbors(int index)
{
    int i;
    /* brute force stupidity - trying to invoke neighboring rooms */


    if(index > 1) call_other(("/players/mizan/bai/CELLS/C" + (index - 1)), "???");
/*    call_other(("/players/mizan/opl/CELLS/C" + index), "???");    -- duh */
    if(index < (width * height)) call_other(("/players/mizan/bai/CELLS/C" + (index + 1)), "???");

    i = (index - 1) - width;
    if(index > width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

    i = index - width;
    if(index > width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

    i = (index + 1) - width;
    if(index > width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

    i = (index - 1) + width;
    if(index < (width * height) - width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

    i = (index + width);
    if(index < (width * height) - width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

    i = (index + 1) + width;
    if(index < (width * height) - width) call_other(("/players/mizan/bai/CELLS/C" + i), "???");

}


/* These functions are from the streamlining/daemonization of room.c */

string * query_numbers()
{
    return numbers;
}

mixed query_number_index(int arg)
{
    return numbers[arg];
}

string convert_dir(string str)
{
    /* we don't need all the extra directions */
    switch (str)
    {
    case "n":
        return "north";
    case "e":
        return "east";
    case "s":
        return "south";
    case "w":
        return "west";
    case "d":
        return "down";
    case "u":
        return "up";
    }
    return str;
}

