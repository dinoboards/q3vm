int a(void);
int b(int a);

int main(void) { return a() + b(2); }

int a(void) { return 1; }

int b(int a) { return a; }
