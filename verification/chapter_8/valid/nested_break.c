int main(void) {
  int ans = 0;
  int i;
  int j;

  for (i = 0; i < 10; i = i + 1)
    for (j = 0; j < 10; j = j + 1)
      if ((i / 2) * 2 == i)
        break;
      else
        ans = ans + i;
  return ans;
}
