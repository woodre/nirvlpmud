/****************************************************************************
	type.c -- An interface for types written by Ugh May-23-1997
****************************************************************************/
private string type;

void
set_type(string r)
{
  type = r;
}

string
query_type()
{
  return type;
}
