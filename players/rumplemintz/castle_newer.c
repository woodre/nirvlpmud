/* ========================================================================= */
/*    castle.c                                                               */
/*    (c) 2007 Rumplemintz@Nirvana                                           */
/*                                                                           */
/*    As the castle's purpose is to be an entrance to a wizard's area, an    */
/*    easier version can be used more often, than having to code an actual   */
/*    castle entrance (i.e. with 'enter', short(), etc   functions           */
/*                                                                           */
/*   1/16/2007 - Will not work if extra_long is not implemented in dest room */
/*   1/16/2007 - add_item implemented strangely (with '.' and \n) so that    */
/*                        using this syntax, you'll get an extra '.' and an  */
/*                        extra linebreak, this should be changed in item    */
/*                        coding (not everything needs a '.' - what about !  */
/* ========================================================================= */

inherit "/players/rumplemintz/basic/create";

#define DEST "/players/rumplemintz/workroom"  /* Destination for castle */

void
create ()
{
   move_object (this_object(), DEST);
   environment()->add_item (
      "path", "It is a well traveled path, it leads off to the west.\n"
   );
   environment()->add_exit (
      "/players/rumplemintz/room/thorad/thorad_gates", "west"
   );
}

string
extra_long ()
{
   return "A path leads west following a well traveled path.\n";
}
