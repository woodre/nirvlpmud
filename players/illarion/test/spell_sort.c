spell_sort(string spell1, string spell2) {
  if(spell_level(spell1) != spell_level(spell2))
    return spell_level(spell1) > spell_level(spell2)
  return spell1 > spell2;
}
