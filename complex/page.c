/* paper.c */

inherit "complex/item";

mixed contents;

object shreds;

string parchment;

reset(arg)
{
	if(arg) return;
	set_id( ({ "paper", "page", "\nComplex#paper" }) );
	set_short( "A paper" );
	set_long( "It seems to be the torn out page of a book.\n" );
	set_encumbrance( 50 );
	set_value( 1 );
	set_contents("\
     ,-----------------------,	\n\
    /	                     |	\n\
    \\	                     |	\n\
    <	                     |	\n\
    |	                     |	\n\
     >	                     |	\n\
    /	                     |	\n\
   /	                     |	\n\
   \\	                     |	\n\
   /	                     |	\n\
   \\	                     |	\n\
   <	                     |	\n\
    \\	                     |	\n\
    /_	                     |	\n\
      '----------------------'	\n"
	);
}

set_contents(cont)
{
	if( !stringp( cont ) ){
		return;
	}
	else{
		contents = cont;
	}
}

query_contents()
{
	return contents;
}

init()
{
	add_action( "peruse", "read" );
	add_action( "destroy", "rip" );
	add_action( "destroy", "tear" );
}

peruse(str)
{
	if( !id( str ) ){
		return;
	}
	else if( id( str )
	||   present( str ) == this_object()
	||   ( sscanf( str, "the %s", parchment )
	&&   ( id( parchment ) || present( parchment ) == this_object() ) ) )
	{
		write( contents );
		say(
this_player()->query_name()+" studies a piece of paper.\n"
		);
		return 1;
	}
}

destroy(str)
{
	if( id( str ) ){
		write( "Tear paper? To pieces or what?\n" );
		say(
this_player()->query_name()+" eyes a piece of paper aggressively.\n"
		);
		return 1;
	}
	if( ( sscanf( str, "the %s into pieces", parchment )  == 1
	||    sscanf( str, "the %s to pieces",   parchment )  == 1
	||    sscanf( str, "%s into pieces",     parchment )  == 1
	||    sscanf( str, "%s to pieces",       parchment )  == 1 )
	&&  id( parchment ) )
	{
		if( environment() != this_player() ){
			write( "First you will have to get it.\n" );
			say(
this_player()->query_name()+" eyes a piece of paper indecisively.\n"
			);
		}
		else{
			shreds = clone_object( "complex/item" );
			shreds->set_id( ({
"scraps", "scraps of paper", "remains", "shreds"
			}) );
			shreds->set_short( "Scraps of paper" );
			shreds->set_long(
"This seems to be the remains of a piece of paper torn to shreds.\n"
			);
			shreds->set_value( 0 );
			shreds->set_encumbrance( query_encumbrance() );
			set_encumbrance( 0 );
			move_object( shreds, this_player() );
			write( "You tear the paper to shreds.\n" );
			say( this_player()->query_name()+
" tears a piece of paper to shreds.\n"
			);
			destruct( this_object() );
		}
		return 1;
	}
	return;
}
