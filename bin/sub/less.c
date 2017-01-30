/*
 *  The "less" file reader from /obj/tools/manual
 *
 *  command_less (string file)
 *  command_lessF (string file)
 *  command_lessM (string file)
 *  find_expr (string expr, int dir)
 *  pager (string str)
 */

#pragma strong_types   // Coogan, 24-Aug-01

#include <prop/player.h>
#include <kernel.h>

virtual inherit ACCESS;

static int page_size = 21;

void reset(int arg) {
  if (!arg)
    set_privilege(1);
}

varargs void pager ();

string  last_find_expr, *man_selection;
int     man_position, pager_position, pager_length;

public int command_less (string file) {
    man_selection = filter (
        map (explode (file, " "), "command_lessM", this_object()),
        "command_lessF", this_object());
    man_position = 0;
    if (man_selection && sizeof (man_selection))
        pager();
    return 1;
}

int command_lessF (string file) {
    return !!file;
}

string command_lessM (string file) {
    return file;
}

int find_expr (string expr, int dir) {
    string *lines, *match;

    if (!expr || !expr[0])
        expr = last_find_expr;
    else last_find_expr = expr;

    if (!expr) return 0;

    if (dir) {
        if (!(lines = explode (read_file (man_selection[man_position],
                pager_position, -1), "\n")))
            return 0;
        if (!(match = regexp (lines, expr)) || !sizeof (match))
            return 0;
        return member(lines, match[0]) + pager_position;
    } else {
        int i, j;

        if (!(lines = explode (read_file (man_selection[man_position],
                0, pager_position-page_size-1), "\n")))
            return 0;
        if (!(match = regexp (lines, expr)) || !sizeof (match))
            return 0;
        while (lines
                && (i = member(lines, match[sizeof(match)-1])) >= 0) {
            j += i;
            lines = lines[i+1..sizeof(lines)];
        }
        return j+1;
    }
}

varargs void pager (string str) {
    if (!str) {
        if (!man_selection || man_position >= sizeof (man_selection))
            return;
        pager_position = 1;
    } else if (str!="") {  // if() added, Coogan, 28-Sep-2010{
        switch (str[0]) {
        case 'n':
        case 'N':
            man_position++;
            pager ();
            return;
        case 'q':
        case 'Q':
        case 'x':
        case 'X':
            return;
        case 'u':
        case 'U':
        case 'b':
        case 'B':
            pager_position -= page_size+page_size;
            if (pager_position < 1)
                pager_position = 1;   /* Perle 13-Dec-1997, 0 war falsch */
            break;
        case 0:
            break;
        case '?':
        case '/':
            if (pager_length = find_expr (str[1..strlen(str)], str[0]=='/')) {
                pager_position = pager_length;
            } else {
                write ("No match to "+(str[0]=='/'?"BOTTOM":"TOP")+" : " +
                       (this_player()->query_property(P_PROMPT_TERMINATOR) ||
                        ""));
                input_to ("pager");
                return;
            }
            break;
        default:
            if (sscanf (str, "%d", pager_position) == 1)
                break;
            write ("[q:quit u:up b:up n:next /:search ?:search num:goto] : " +
                   (this_player()->query_property(P_PROMPT_TERMINATOR) || ""));
            input_to ("pager");
            return;
        }
    }

    if (pager_position == 1)
        write ("["+man_selection[man_position]+"] :\n");

    pager_length =
    cat (man_selection[man_position], pager_position, page_size);
    pager_position += pager_length;

    if (pager_length == page_size ||
      man_position < sizeof (man_selection) - 1)
        write ("["+man_selection[man_position]+"] ("+pager_position+") : " +
               (this_player()->query_property(P_PROMPT_TERMINATOR) || ""));

    if (pager_length < page_size) {
        if (++man_position == sizeof (man_selection)) {
            man_selection = 0;
            return;
        }
        pager_position = 1;
    }
    input_to ("pager");
}

