int me;

id(str)
{
  return str == (""+me);
}

set_card(i)
{
  me = i;
}

query_card()
{
  return me;
}

short()
{
  string str;
  int suit;
  int spot;

  suit = me / 13;
  spot = me % 13;

  switch(spot)
  {
  case 12: str = "King"; break;
  case 11: str = "Queen"; break;
  case 10: str = "Jack"; break;
  case 0:  str = "Ace"; break;
  default: str = "" + (spot+1);
  }

  switch(suit)
  {
  case 0: return str + " of Spades";
  case 1: return str + " of Hearts";
  case 2: return str + " of Diamonds";
  case 3: return str + " of Clubs";
  }
}
