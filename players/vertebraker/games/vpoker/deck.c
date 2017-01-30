
string *cards;
string *suits;
string *faces;

void reset(status arg)
{
  int i;

  if(arg) return;

  suits=({"C","S","D","H"});
  faces=({"J","Q","K","A"});
  cards=({});

  for(i=0;i<4;i++) {

    int j;
    for(j=0;j<9;j++) {
      cards += ({ ""+(j+2)+suits[i] });
    }
    for(j=0;j<4;j++) {
      cards += ({ faces[j]+suits[i] });
    }
  }
}

void printout()
{
  write(implode(cards, "\n"));
}

void print_random()
{
  write(cards[random(sizeof(cards))]+"\n");
}
