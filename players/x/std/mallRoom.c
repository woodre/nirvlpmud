#include "/players/x/x.h"

inherit ROOM;

string mall_position;
int    is_shop;

void set_position(string x)
{
 mall_position = x;
}

string query_position()
{
 return mall_position;
}

void set_shop(int x)
{
 is_shop = x;
}

int query_shop()
{
 return is_shop;
}

void set_short(string str)
{
 short_desc = (MALL_SHORT+" "+str);
}

string realm() { return "NT"; }
status okay_follow() { return 1; }
